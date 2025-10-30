#include <cstdlib>
#include <cctype>
#include <iostream>

#include "LinkedList.hpp"
#include "Menu.hpp"
#include "Node.hpp"

bool checkInput(std::string &input);

int main() {
    LinkedList list;
    list.addTask("Test");
    list.addTask("Test2");
    list.addTask("Test3");
    list.addTask("Test4");

    list.printTasks();

    //bool is_active = true;
    //while (is_active) {
    //    Menu::print(true);
    //    std::string input;

    //    bool validInput{false};
    //    std::getline(std::cin, input);
    //    validInput = checkInput(input);
    //    if (!validInput) continue;
    //    std::println("Valid Input!");

    //    is_active = false;
    //}

    return 0;
}

bool checkInput(std::string &input) {
    std::ranges::transform(input, input.begin(), [] (const unsigned char c) { return std::tolower(c); });

    if (input.length() != 1) {
        std::println("Invalid input, only single character input is accepted.");
        return false;
    }

    for (const std::string validInput[5] = {"a", "r", "u", "d", "e"}; auto c : validInput) {
        if (input == c) {
            // TODO: separate the cases
            if (input == "a" || input == "r" || input == "u" || input == "d") {
                return true;
            }
            std::println("exiting..");
            std::exit(EXIT_SUCCESS);
        }
    }

    std::println("Invalid input, please make a valid selection from the Menu.");
    return false;
}