#include <cctype>
#include <cstdlib>
#include <iostream>

#include "LinkedList.hpp"
#include "Menu.hpp"

void getInput(LinkedList &list);
void getUpdateChoice(LinkedList &list);

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
    Menu::printOptions();
    getInput(list);
  }

  return 0;
}

void getInput(LinkedList &list) {
  std::string input;
  std::getline(std::cin, input);
  const int choice = std::stoi(input);
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
  }
}

void getUpdateChoice(LinkedList &list) {
  Menu::printUpdateOptions();
  std::string input;
  std::string id;
  std::string name;
  std::string status;
  std::string description;
  std::getline(std::cin, input);

  switch (std::stoi(input)) {
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
    Menu::printStatusOptions();
    std::getline(std::cin, status);
    // TODO: update task status choice
    std::println("Task status updated!");
    break;
  case 3:
    std::println("Enter task ID:");
    std::getline(std::cin, id);
    std::println("Enter task description:");
    std::getline(std::cin, description);
    list.updateTask(std::stoi(id), name, Status::ToDo, description);
    std::println("Task description updated!");
    break;
  case 4:
    std::println("Enter task ID:");
    std::getline(std::cin, id);
    std::println("Enter task name:");
    std::getline(std::cin, name);
    Menu::printStatusOptions();
    std::getline(std::cin, status);

    std::println("Task name and status updated!");
    break;
  case 5:
    std::println("Enter task ID:");
    std::getline(std::cin, id);
    Menu::printStatusOptions();
    std::getline(std::cin, status);
    std::println("Enter task description:");
    std::getline(std::cin, description);

    std::println("Task status and description updated!");
    break;
  case 6:
    std::println("Enter task ID:");
    std::getline(std::cin, id);
    std::println("Enter task name:");
    std::getline(std::cin, name);
    std::println("Enter task description:");
    std::getline(std::cin, description);

    std::println("Task name and description updated!");
    break;
  case 7:
    std::println("Enter task ID:");
    std::getline(std::cin, id);
    std::println("Enter task name:");
    std::getline(std::cin, name);
    Menu::printStatusOptions();
    std::getline(std::cin, status);
    std::println("Enter task description:");
    std::getline(std::cin, description);

    std::println("Task name and description updated!");
    break;
  case 0:

  default:
    std::println("Invalid option!");
  };
}
