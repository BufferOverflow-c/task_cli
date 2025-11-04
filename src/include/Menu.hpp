//
// Created by - on 10/28/25.
//

#ifndef TASK_CLI_MENU_HPP
#define TASK_CLI_MENU_HPP

#import <print>

class Menu {
public:
  static void printOptions() {
    std::println("Select an option from the menu:");
    std::println("1 - Add");
    std::println("2 - Remove");
    std::println("3 - Update");
    std::println("4 - Display");
    std::println("5 - Save (JSON)");
    std::println("6 - Load (JSON)");
    std::println("0 - Exit");
  }

  static void printUpdateOptions() {
    std::println("Select an option from the menu:");
    std::println("1 - Update Task Name");
    std::println("2 - Update Task Status");
    std::println("3 - Update Task Description");
    std::println("4 - Update Task Name & Status");
    std::println("5 - Update Task Status & Description");
    std::println("6 - Update Task Name & Description");
    std::println("7 - Update Task Name, Status, & Description");
    std::println("0 - Cancel");
  }

  static void printStatusOptions() {
    std::println("Select an option from the menu:");
    std::println("1 - ToDo");
    std::println("2 - In Progress");
    std::println("3 - Done");
    std::println("0 - Cancel");
  }
};

#endif // TASK_CLI_MENU_HPP
