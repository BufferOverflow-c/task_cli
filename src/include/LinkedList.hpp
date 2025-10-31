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
  void updateTask(const int task_id, const std::string &rTask_description);
  void updateTask(const int task_id, const std::string &rTask_name = "",
                  const std::string &rTask_description = "");
  void updateTask(const int task_id, const std::string &rTask_name = "",
                  Status status = Status::ToDo,
                  const std::string &rTask_description = "");

  void setTaskName(Node &rNode, const std::string &rTask_name);
  void setTaskStatus(Node &rNode, const Status status);
  void setTaskDescription(Node &rNode, const std::string &rTask_description);

private:
  Node *pHead;
  int mSize;
};

#endif // TASK_CLI_LINKEDLIST_HPP
