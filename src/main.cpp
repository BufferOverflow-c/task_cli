#include <cctype>
#include <cstdlib>
#include <iostream>

#include "LinkedList.hpp"
#include "Menu.hpp"
#include "Node.hpp"

void getInput(LinkedList &list);

int main() {
  LinkedList list;
  list.addTask("Test");
  list.addTask("Test2");
  list.addTask("Test3");
  list.addTask("Test4");
  list.removeTask(2);
  list.printTasks();

  bool is_active = true;

  while (is_active) {
    Menu::print();
    std::string input;
    std::getline(std::cin, input);
  }

  return 0;
}

void getInput(LinkedList &list) {
  std::string input;
  std::getline(std::cin, input);
  std::ranges::transform(input, input.begin(),
                         [](char c) { return std::tolower(c); });
  const std::string options[5] = {"a", "r", "u", "p", "q"};

  if (input == options[0]) {
    std::println("Enter task name:");
    std::getline(std::cin, input);
    std::println("Adding task..");
    list.addTask(input);
    std::println("Task added!");
  } else if (input == options[1]) {
    std::println("Enter task ID:");
    std::getline(std::cin, input);
    std::println("Removing task..");
    list.removeTask(std::stoi(input));
    std::println("Task removed!");
  } else if (input == options[2]) {
    std::println("Enter task ID:");
    std::getline(std::cin, input);
    // TODO: add update options for the user to choose from
  } else if (input == options[3]) {
    std::println("Printing tasks..\n");
    list.printTasks();
    std::println("\nTasks printed!");
  } else if (input == options[4]) {
    std::println("Exiting..");
    std::exit(0);
  } else {
    std::println("Invalid option!");
  }
}
