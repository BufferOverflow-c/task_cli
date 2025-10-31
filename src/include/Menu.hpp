//
// Created by - on 10/28/25.
//

#ifndef TASK_CLI_MENU_HPP
#define TASK_CLI_MENU_HPP

#import <print>

class Menu {
public:
  static void print() {
    std::println("Select an option from the menu:");
    std::println("A - Add");
    std::println("R - Remove");
    std::println("U - Update");
    std::println("D - Display");
    std::println("E - Exit");
  }
};

#endif // TASK_CLI_MENU_HPP
