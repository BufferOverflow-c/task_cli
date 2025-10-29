//
// Created by - on 10/28/25.
//

#ifndef TASK_CLI_MENU_HPP
#define TASK_CLI_MENU_HPP

#import <iostream>

class Menu {
    public:
    static void print(const bool bProvided_file) {
        if (bProvided_file) {
            std::println("Select an option from the menu:");
            std::println("A - Add");
            std::println("R - Remove");
            std::println("U - Update");
            std::println("D - Display");
            std::println("E - Exit");
        } else {
            std::println("No file was provided, you must add a new task to see the other options:");
        }
    }
};

#endif //TASK_CLI_MENU_HPP