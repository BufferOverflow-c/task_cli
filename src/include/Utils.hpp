#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>
#include <stdexcept>

#include "LinkedList.hpp"
#include "Menu.hpp"

namespace Utils {
// TODO: implement validation for all std::stoi();
void getUpdateChoice(LinkedList &list);

inline void getInput(LinkedList &list) {
  bool is_valid = false;
  while (!is_valid) {
    Menu::printOptions();
    std::string input;
    std::getline(std::cin, input);
    int choice;
    try {
      choice = std::stoi(input);
    } catch (std::invalid_argument &e) {
      std::println("Invalid input!");
      continue;
    } catch (std::out_of_range &e) {
      std::println("Input out of range!");
      continue;
    }
    switch (choice) {
    case 1:
      std::println("Enter task name:");
      std::getline(std::cin, input);
      std::println("Adding task..");
      list.addTask(input);
      std::println("Task added!");
      break;
    case 2:
      std::println("Enter task ID:");
      std::getline(std::cin, input);
      std::println("Removing task..");
      list.removeTask(std::stoi(input));
      std::println("Task removed!");
      break;
    case 3:
      getUpdateChoice(list);
      break;
    case 4:
      std::println("Printing tasks..\n");
      list.printTasks();
      std::println("\nTasks printed!");
      break;
    case 0:
      std::println("Exiting..");
      std::exit(0);
    default:
      std::println("Invalid option!");
      break;
    }
  }
}

inline void getUpdateChoice(LinkedList &list) {
  bool is_valid = false;
  while (!is_valid) {
    Menu::printUpdateOptions();
    bool is_valid = false;
    Status new_status{Status::ToDo};
    std::string input;
    std::string id;
    std::string name;
    std::string status;
    std::string description;
    std::getline(std::cin, input);
    int choice;
    try {
      choice = std::stoi(input);
    } catch (std::invalid_argument &e) {
      std::println("Invalid input!");
    }
    switch (choice) {
    case 1:
      std::println("Enter task ID:");
      std::getline(std::cin, id);
      std::println("Enter task name:");
      std::getline(std::cin, name);
      list.updateTask(std::stoi(id), name);
      std::println("Task name updated!");
      break;
    case 2:
      std::println("Enter task ID:");
      std::getline(std::cin, id);
      while (!is_valid) {
        Menu::printStatusOptions();
        std::getline(std::cin, status);
        int status_int;
        try {
          status_int = std::stoi(status);
        } catch (std::invalid_argument &e) {
          std::println("Invalid status!");
          continue;
        }
        switch (status_int) {
        case 1:
          new_status = Status::ToDo;
          is_valid = true;
          break;
        case 2:
          new_status = Status::InProgress;
          is_valid = true;
          break;
        case 3:
          new_status = Status::Done;
          is_valid = true;
          break;
        case 0:
          getInput(list);
          break;
        default:
          std::println("Invalid status!");
          break;
        }
      }
      list.updateTask(std::stoi(id), name, new_status);
      std::println("Task status updated!");
      break;
    case 3:
      std::println("Enter task ID:");
      std::getline(std::cin, id);
      std::println("Enter task description:");
      std::getline(std::cin, description);
      list.updateTask(std::stoi(id), name, new_status, description);
      std::println("Task description updated!");
      break;
    case 4:
      std::println("Enter task ID:");
      std::getline(std::cin, id);
      std::println("Enter task name:");
      std::getline(std::cin, name);
      while (!is_valid) {
        Menu::printStatusOptions();
        std::getline(std::cin, status);
        int status_int;
        try {
          status_int = std::stoi(status);
        } catch (std::invalid_argument &e) {
          std::println("Invalid status!");
          continue;
        }
        switch (std::stoi(status)) {
        case 1:
          new_status = Status::ToDo;
          is_valid = true;
          break;
        case 2:
          new_status = Status::InProgress;
          is_valid = true;
          break;
        case 3:
          new_status = Status::Done;
          is_valid = true;
          break;
        case 0:
          getInput(list);
          break;
        default:
          std::println("Invalid status!");
          break;
        }
      }
      list.updateTask(std::stoi(id), name, new_status);
      std::println("Task name & status updated!");
      break;
    case 5:
      std::println("Enter task ID:");
      std::getline(std::cin, id);
      while (!is_valid) {
        Menu::printStatusOptions();
        std::getline(std::cin, status);
        int status_int;
        try {
          status_int = std::stoi(status);
        } catch (std::invalid_argument &e) {
          std::println("Invalid status!");
          continue;
        }
        switch (status_int) {
        case 1:
          new_status = Status::ToDo;
          is_valid = true;
          break;
        case 2:
          new_status = Status::InProgress;
          is_valid = true;
          break;
        case 3:
          new_status = Status::Done;
          is_valid = true;
          break;
        case 0:
          getInput(list);
          break;
        default:
          std::println("Invalid status!");
          break;
        }
      }
      std::println("Enter task description:");
      std::getline(std::cin, description);
      list.updateTask(std::stoi(id), name, new_status, description);
      std::println("Task status and description updated!");
      break;
    case 6:
      std::println("Enter task ID:");
      std::getline(std::cin, id);
      std::println("Enter task name:");
      std::getline(std::cin, name);
      std::println("Enter task description:");
      std::getline(std::cin, description);
      list.updateTask(std::stoi(id), name, new_status, description);
      std::println("Task name and description updated!");
      break;
    case 7:
      std::println("Enter task ID:");
      std::getline(std::cin, id);
      std::println("Enter task name:");
      std::getline(std::cin, name);
      while (!is_valid) {
        Menu::printStatusOptions();
        std::getline(std::cin, status);
        switch (std::stoi(status)) {
        case 1:
          new_status = Status::ToDo;
          is_valid = true;
          break;
        case 2:
          new_status = Status::InProgress;
          is_valid = true;
          break;
        case 3:
          new_status = Status::Done;
          is_valid = true;
          break;
        case 0:
          getInput(list);
          break;
        default:
          std::println("Invalid status!");
          break;
        }
      }
      std::println("Enter task description:");
      std::getline(std::cin, description);
      list.updateTask(std::stoi(id), name, new_status, description);
      std::println("Task name, status, and description updated!");
      break;
    case 0:
      getInput(list);
      break;
    default:
      std::println("Invalid option!");
    };
  }
}
} // namespace Utils

#endif
