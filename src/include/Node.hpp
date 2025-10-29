//
// Created by - on 10/25/25.
//

#ifndef TASK_CLI_NODE_HPP
#define TASK_CLI_NODE_HPP

#include <map>
#include <string>

#include <iostream>

class Node {
public:
    Node() : pPrev(nullptr), pNext(nullptr), mTask_id(0), mTask_status(status_map[Status::ToDo]) {}

    enum Status {
        ToDo,
        InProgress,
        Done
    };

    std::map <Status, std::string> status_map = {
        {Status::ToDo, "todo"},
        {Status::InProgress, "In-Progress"},
        {Status::Done, "Done"}
    };

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