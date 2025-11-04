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
  explicit Node(
      int task_id, std::string task_name,
      std::string task_status = std::string(status_string(Status::ToDo)),
      const std::string &task_description = "",
      const std::string &task_creation_datetime = "",
      const std::string &task_last_updated_datetime = "")
      : pPrev(nullptr), pNext(nullptr), mTask_id(0),
        mTask_name(std::move(task_name)), mTask_status(std::move(task_status)),
        mTask_description(task_description),
        mTask_creation_datetime(task_creation_datetime),
        mTask_last_updated_datetime(task_last_updated_datetime) {}

  ~Node() = default;

  Node *pPrev;
  Node *pNext;
  int mTask_id;
  std::string mTask_name;
  std::string mTask_status;
  std::string mTask_description;
  std::string mTask_creation_datetime;
  std::string mTask_last_updated_datetime;
};

#endif // TASK_CLI_NODE_HPP
