//
// Created by - on 10/25/25.
//

#ifndef TASK_CLI_NODE_HPP
#define TASK_CLI_NODE_HPP

#include <string>
#include <utility>

#include "Status.hpp"

class Node {
public:
    explicit Node(std::string task_name) : pPrev(nullptr), pNext(nullptr), mTask_id(0), mTask_name(std::move(task_name)), mTask_status(status_string(Status::ToDo)) {
        mTask_description = "";
        mTask_creation_datetime = "";
        mTask_last_updated_datetime = "";
    }

    ~Node() {
        delete pPrev;
        delete pNext;
    }

    Node *pPrev;
    Node *pNext;
    int mTask_id;
    std::string mTask_name;
    std::string mTask_status;
    std::string mTask_description;
    std::string mTask_creation_datetime;
    std::string mTask_last_updated_datetime;
};

#endif //TASK_CLI_NODE_HPP