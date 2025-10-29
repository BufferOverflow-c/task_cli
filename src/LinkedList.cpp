#include "LinkedList.hpp"

LinkedList::LinkedList() : pHead(nullptr), pTail(nullptr), mSize(0) {
}

LinkedList::~LinkedList() {
}

void LinkedList::addTask(const std::string &task_name) {
}

void LinkedList::addTask(const std::string &task_name, Node::Status status) {
}

void LinkedList::removeTask(const int &task_id) {
}

void LinkedList::updateTask(const int &task_id, Node::Status status) {
}

void LinkedList::updateTask(const int &task_id, const std::string &task_description) {
}

void LinkedList::updateTask(const int &task_id, const std::string &task_name, const std::string &task_description) {
}

void LinkedList::updateTask(const int &task_id, const std::string &task_name, Node::Status status,
    const std::string &task_description) {
}

void LinkedList::setTaskID(const Node &node) {
}

void LinkedList::setTaskName(const int id, const std::string &rTask_name) {
}

void LinkedList::setTaskStatus(const int id, const std::string &rTask_status) {
}

void LinkedList::setTaskDescription(const int id, const std::string &rTask_description) {
}
