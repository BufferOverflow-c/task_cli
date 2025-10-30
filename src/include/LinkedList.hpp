//
// Created by - on 10/29/25.
//

#ifndef TASK_CLI_LINKEDLIST_HPP
#define TASK_CLI_LINKEDLIST_HPP

#include <string>

#include "Node.hpp"
#include "Status.hpp"

class LinkedList {
public:
    LinkedList();
    ~LinkedList();

    void addTask(const std::string &task_name);
    void removeTask(const int task_id);
    void printTasks() const;

    void updateTask(const int task_id, Status status);
    void updateTask(const int task_id, const std::string &task_description);
    void updateTask(const int task_id, const std::string &task_name = "", const std::string &task_description = "");
    void updateTask(const int task_id, const std::string &task_name = "", Status status=Status::ToDo, const std::string &task_description = "");

    void setTaskID(const Node &node);
    void setTaskName(const int task_id, const std::string &rTask_name);
    void setTaskStatus(const int task_id, const Status status);
    void setTaskDescription(const int task_id, const std::string &rTask_description);

private:
    Node *pHead;
    int mSize;
};

#endif //TASK_CLI_LINKEDLIST_HPP