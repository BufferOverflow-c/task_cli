#include "LinkedList.hpp"
#include <iostream>

LinkedList::LinkedList() : pHead(nullptr), mSize(0) {
}

LinkedList::~LinkedList() {
    Node *pCurr = pHead;
    while (pCurr) {
        Node *pNext = pCurr->pNext;
        delete pCurr;
        pCurr = pNext;
    }
}

void LinkedList::addTask(const std::string &task_name) {
    auto *pNode = new Node(task_name);
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
                     pCurr->mTask_id,
                     pCurr->mTask_name,
                     pCurr->mTask_status,
                     pCurr->mTask_description,
                     pCurr->mTask_creation_datetime,
                     pCurr->mTask_last_updated_datetime
                     );
        pCurr = pCurr->pNext;
    }
}

void LinkedList::updateTask(const int task_id, Status status) {

}

void LinkedList::updateTask(const int task_id, const std::string &task_description) {

}

void LinkedList::updateTask(const int task_id, const std::string &task_name, const std::string &task_description) {

}

void LinkedList::updateTask(const int task_id, const std::string &task_name, Status status,
    const std::string &task_description) {

}

void LinkedList::setTaskID(const Node &node) {

}

void LinkedList::setTaskName(const int task_id, const std::string &rTask_name) {

}

void LinkedList::setTaskStatus(const int task_id, const Status status) {

}

void LinkedList::setTaskDescription(const int task_id, const std::string &rTask_description) {

}
