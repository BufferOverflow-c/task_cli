#include "LinkedList.hpp"
#include <ctime>
#include <fstream>
#include <nlohmann/json.hpp>
#include <print>
#include <stdexcept>

using json = nlohmann::json;

LinkedList::LinkedList() : pHead(nullptr), mSize(0) {}

LinkedList::~LinkedList() {
  Node *pCurr = pHead;
  while (pCurr) {
    Node *pNext = pCurr->pNext;
    delete pCurr;
    pCurr = pNext;
  }
}

void LinkedList::addTask(const std::string &rTask_name, std::string rTask_id,
                         const std::string &rTask_status,
                         const std::string &rTask_description,
                         const std::string &rTask_creation_datetime,
                         const std::string &rTask_last_updated_datetime) {
  time_t now = time(nullptr);
  try {
    if (rTask_id.empty()) {
      rTask_id = "0";
    }
    auto *pNode = new Node(std::stoi(rTask_id), rTask_name, rTask_status,
                           rTask_description, rTask_creation_datetime,
                           rTask_last_updated_datetime);
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
  } catch (std::invalid_argument &e) {
    std::println("Invalid task ID: {}", e.what());
    return;
  }
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

void LinkedList::saveTasks(const std::string &filename) {
  std::ofstream file(filename);
  if (!file.is_open()) {
    std::println("Failed to open file for writing.");
    return;
  }
  Node *pCurr = pHead;
  while (pCurr) {
    if (pCurr == pHead) {
      file << "[\n";
    } else {
      file << ",\n";
    }
    json data = {{"id", pCurr->mTask_id},
                 {"name", pCurr->mTask_name},
                 {"status", pCurr->mTask_status},
                 {"description", pCurr->mTask_description},
                 {"creation_datetime", pCurr->mTask_creation_datetime},
                 {"last_updated_datetime", pCurr->mTask_last_updated_datetime}};
    file << data.dump();
    pCurr = pCurr->pNext;
  }
  file << "\n]";
  file.close();
}

void LinkedList::loadTasks(const std::string &filename) {
  std::ifstream file(filename);
  if (!file.is_open()) {
    std::println("Failed to open file for reading.");
    return;
  }
  std::string task_id;
  std::string task_name, task_status, task_description, task_creation_datetime,
      task_last_updated_datetime;
  while (file >> task_id) {
    std::getline(file, task_name);
    std::getline(file, task_status);
    std::getline(file, task_description);
    std::getline(file, task_creation_datetime);
    std::getline(file, task_last_updated_datetime);
    addTask(task_id, task_name, task_status, task_description,
            task_creation_datetime, task_last_updated_datetime);
  }
  file.close();
}

void LinkedList::updateTask(const int task_id, const std::string &rTask_name,
                            Status status,
                            const std::string &rTask_description) {
  Node *pNode = pHead;
  while (pNode) {
    if (pNode->mTask_id == task_id) {
      time_t now = time(nullptr);
      pNode->mTask_last_updated_datetime = ctime(&now);
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
