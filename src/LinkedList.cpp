#include "LinkedList.hpp"
#include <ctime>
#include <print>

LinkedList::LinkedList() : pHead(nullptr), mSize(0) {}

LinkedList::~LinkedList() {
  Node *pCurr = pHead;
  while (pCurr) {
    Node *pNext = pCurr->pNext;
    delete pCurr;
    pCurr = pNext;
  }
}

void LinkedList::addTask(const std::string &task_name) {
  time_t now = time(nullptr);
  auto *pNode = new Node(task_name);
  pNode->mTask_creation_datetime = ctime(&now);
  if (!pHead) {
    pHead = pNode;
  } else {
    Node *pCurr = pHead;
    while (pCurr->pNext) {
      pCurr = pCurr->pNext;
    }
    pNode->mTask_id = pCurr->mTask_id + 1;
    pCurr->pNext = pNode;
  }
  mSize++;
}

void LinkedList::removeTask(const int task_id) {
  if (!pHead) {
    std::println("No tasks to remove.");
    return;
  }
  if (pHead->mTask_id == task_id) {
    Node *pTemp = pHead;
    pHead = pHead->pNext;
    delete pTemp;
    mSize--;
    return;
  }
  Node *pPrev = pHead;
  Node *pCurr = pHead->pNext;
  while (pCurr) {
    if (pCurr->mTask_id == task_id) {
      pPrev->pNext = pCurr->pNext;
      delete pCurr;
      mSize--;
      return;
    }
    pPrev = pCurr;
    pCurr = pCurr->pNext;
  }
  std::println("Task with ID {} not found.", task_id);
}

void LinkedList::printTasks() const {
  if (!pHead) {
    std::println("No tasks available.");
    return;
  }
  Node *pCurr = pHead;
  while (pCurr) {
    std::println("Task id: {}\n"
                 "Task Name: {}\n"
                 "Task Status: {}\n"
                 "Task Description: {}\n"
                 "Task Creation Date/Time: {}\n"
                 "Task Last Updated Date/Time: {}",
                 pCurr->mTask_id, pCurr->mTask_name, pCurr->mTask_status,
                 pCurr->mTask_description, pCurr->mTask_creation_datetime,
                 pCurr->mTask_last_updated_datetime);
    pCurr = pCurr->pNext;
  }
}

void LinkedList::updateTask(const int task_id, const std::string &rTask_name,
                            Status status,
                            const std::string &rTask_description) {
  Node *pNode = pHead;
  while (pNode) {
    if (pNode->mTask_id == task_id) {
      if (rTask_name != "") {
        setTaskName(*pNode, rTask_name);
      }
      if (pNode->mTask_status != status_string(status) &&
          status != Status::ToDo) {
        setTaskStatus(*pNode, status);
      }
      if (rTask_description != "") {
        setTaskDescription(*pNode, rTask_description);
      }
      time_t now = time(nullptr);
      pNode->mTask_last_updated_datetime = ctime(&now);
    }
    pNode = pNode->pNext;
  }
}

void LinkedList::setTaskName(Node &rNode, const std::string &rTask_name) {
  rNode.mTask_name = rTask_name;
}

void LinkedList::setTaskStatus(Node &rNode, const Status status) {
  rNode.mTask_status = status_string(status);
}

void LinkedList::setTaskDescription(Node &rNode,
                                    const std::string &rTask_description) {
  rNode.mTask_description = rTask_description;
}
