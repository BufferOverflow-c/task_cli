//
// Created by - on 10/29/25.
//

#ifndef TASK_CLI_LINKEDLIST_HPP
#define TASK_CLI_LINKEDLIST_HPP

#include <string>

#include "Node.hpp"

class LinkedList {
public:
    LinkedList();
    explicit LinkedList(const std::string &task_name);
    ~LinkedList();

    void addTask(const std::string &task_name);
    void addTask(const std::string &task_name, Node::Status status);
    void removeTask(const int &task_id);

    void updateTask(const int &task_id, Node::Status status);
    void updateTask(const int &task_id, const std::string &task_description);
    void updateTask(const int &task_id, const std::string &task_name = "", const std::string &task_description = "");
    void updateTask(const int &task_id, const std::string &task_name = "", Node::Status status=Node::Status::ToDo, const std::string &task_description = "");

    [[nodiscard]] Node *pGetHead() const { return pHead; }
    [[nodiscard]] Node *pGetTail() const { return pTail; }

    void setTaskID(const Node &node);
    void setTaskName(const int id, const std::string &rTask_name);
    void setTaskStatus(const int id, const std::string &rTask_status);
    void setTaskDescription(const int id, const std::string &rTask_description);

private:
    std::map <Node::Status, std::string> status_map = {
        {Node::Status::ToDo, "todo"},
        {Node::Status::InProgress, "In-Progress"},
        {Node::Status::Done, "Done"}
    };

    Node *pHead;
    Node *pTail;
    int mSize;
};

#endif //TASK_CLI_LINKEDLIST_HPP