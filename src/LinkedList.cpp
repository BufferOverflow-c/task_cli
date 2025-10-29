//
// Created by - on 10/29/25.
//

#include "LinkedList.hpp"

LinkedList::LinkedList() {
}

LinkedList::LinkedList(const std::string &task_name) {
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
