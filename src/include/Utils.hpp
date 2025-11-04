#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>
#include <stdexcept>
#include <string>

#include "LinkedList.hpp"
#include "Menu.hpp"

namespace Utils {
void getUpdateChoice(LinkedList &list);
Status askStatus();

inline void getInput(LinkedList &list) {
  bool is_valid = false;
  std::string input;
  int choice;
  while (!is_valid) {
    Menu::printOptions();
    std::getline(std::cin, input);
    try {
      choice = std::stoi(input);
    } catch (std::invalid_argument &e) {
      std::println("Invalid input!");
      continue;
    } catch (std::out_of_range &e) {
      std::println("Input out of range!");
      continue;
    }
    is_valid = true;
  }
  switch (choice) {
  case 1: {
    std::println("Enter task name:");
    std::getline(std::cin, input);
    std::println("Adding task..");
    list.addTask(input);
    std::println("Task added!");
    break;
  }
  case 2: {
    bool valid_id = false;
    int id_int;
    while (!valid_id) {
      std::println("Enter task ID:");
      std::getline(std::cin, input);
      try {
        id_int = std::stoi(input);
      } catch (std::invalid_argument &e) {
        std::println("Invalid input!");
        continue;
      }
      std::println("Removing task..");
      list.removeTask(id_int);
    }
    std::println("Task removed!");
    valid_id = true;
    break;
  }
  case 3: {
    getUpdateChoice(list);
    break;
  }
  case 4: {
    std::println("Printing tasks..\n");
    list.printTasks();
    std::println("\nTasks printed!");
    break;
  }
  case 5: {
    bool valid_file_name = false;
    std::string file_name;
    while (!valid_file_name) {
      std::println("Enter a file name ending with .json:\n");
      std::getline(std::cin, file_name);
      try {
        if (file_name.substr(file_name.find_last_of(".") + 1) == "json") {
          valid_file_name = true;
        } else {
          throw std::invalid_argument("Invalid file extension");
        }
      } catch (std::invalid_argument &e) {
        std::println("Invalid file extension!");
      }
    }
    std::println("Saving tasks..\n");
    list.saveTasks(file_name);
    std::println("\nTasks saved!");
    break;
  }
  case 6: {
    bool valid_file_name = false;
    std::string file_name;
    while (!valid_file_name) {
      std::println("Enter a file name ending with .json:\n");
      std::getline(std::cin, file_name);
      try {
        if (file_name.substr(file_name.find_last_of(".") + 1) == "json") {
          valid_file_name = true;
        } else {
          throw std::invalid_argument("Invalid file extension");
        }
      } catch (std::invalid_argument &e) {
        std::println("Invalid file extension!");
      }
    }
    std::println("Loading tasks..\n");
    list.loadTasks(file_name);
    std::println("\nAll tasks deleted!");
    break;
  }
  case 0: {
    std::println("Exiting..");
    std::exit(0);
  }
  default: {
    std::println("Invalid option!");
    break;
  }
  }
}

inline void getUpdateChoice(LinkedList &list) {
  bool is_valid = false;
  while (!is_valid) {
    Menu::printUpdateOptions();
    std::string input;
    std::string id;
    std::string name;
    Status status{Status::ToDo};
    std::string description;
    std::getline(std::cin, input);
    int choice;
    try {
      choice = std::stoi(input);
    } catch (std::invalid_argument &e) {
      std::println("Invalid input!");
    }
    switch (choice) {
    case 1: {
      bool valid_id = false;
      int id_int;
      while (!valid_id) {
        std::println("Enter task ID:");
        std::getline(std::cin, id);
        try {
          id_int = std::stoi(id);
          valid_id = true;
        } catch (std::invalid_argument &e) {
          std::println("Invalid ID!");
        }
      }
      std::println("Enter task name:");
      std::getline(std::cin, name);
      list.updateTask(id_int, name);
      std::println("Task name updated!");
      is_valid = true;
      break;
    }
    case 2: {
      bool valid_int = false;
      int id_int;
      while (!valid_int) {
        std::println("Enter task ID:");
        std::getline(std::cin, id);
        try {
          id_int = std::stoi(id);
          valid_int = true;
        } catch (std::invalid_argument &e) {
          std::println("Invalid ID!");
        }
      }
      status = askStatus();
      list.updateTask(id_int, name, status);
      std::println("Task status updated!");
      is_valid = true;
      break;
    }
    case 3: {
      bool valid_id = false;
      int id_int;
      while (!valid_id) {
        std::println("Enter task ID:");
        std::getline(std::cin, id);
        try {
          id_int = std::stoi(id);
          valid_id = true;
        } catch (std::invalid_argument &e) {
          std::println("Invalid ID!");
        }
      }
      std::println("Enter task description:");
      std::getline(std::cin, description);
      list.updateTask(id_int, name, status, description);
      std::println("Task description updated!");
      is_valid = true;
      break;
    }
    case 4: {
      bool valid_id = false;
      int id_int;
      while (!valid_id) {
        std::println("Enter task ID:");
        std::getline(std::cin, id);
        try {
          id_int = std::stoi(id);
          valid_id = true;
        } catch (std::invalid_argument &e) {
          std::println("Invalid ID!");
        }
      }
      std::println("Enter task name:");
      std::getline(std::cin, name);
      status = askStatus();
      list.updateTask(id_int, name, status);
      std::println("Task name & status updated!");
      is_valid = true;
      break;
    }
    case 5: {
      bool valid_id = false;
      int id_int;
      while (!valid_id) {
        std::println("Enter task ID:");
        std::getline(std::cin, id);
        try {
          id_int = std::stoi(id);
          valid_id = true;
        } catch (std::invalid_argument &e) {
          std::println("Invalid ID!");
        }
      }
      status = askStatus();
      std::println("Enter task description:");
      std::getline(std::cin, description);
      list.updateTask(id_int, name, status, description);
      std::println("Task status and description updated!");
      is_valid = true;
      break;
    }
    case 6: {
      bool valid_id = false;
      int id_int;
      while (!valid_id) {
        std::println("Enter task ID:");
        std::getline(std::cin, id);
        try {
          id_int = std::stoi(id);
          valid_id = true;
        } catch (const std::invalid_argument &e) {
          std::println("Invalid ID!");
        }
      }
      std::println("Enter task name:");
      std::getline(std::cin, name);
      std::println("Enter task description:");
      std::getline(std::cin, description);
      list.updateTask(id_int, name, status, description);
      std::println("Task name and description updated!");
      is_valid = true;
      break;
    }
    case 7: {
      bool valid_id = false;
      int id_int;
      while (!valid_id) {
        std::println("Enter task ID:");
        std::getline(std::cin, id);
        try {
          id_int = std::stoi(id);
          valid_id = true;
        } catch (const std::invalid_argument &e) {
          std::println("Invalid ID!");
        }
      }
      std::println("Enter task name:");
      std::getline(std::cin, name);
      status = askStatus();
      std::println("Enter task description:");
      std::getline(std::cin, description);
      list.updateTask(id_int, name, status, description);
      std::println("Task name, status, and description updated!");
      is_valid = true;
      break;
    }
    case 0:
      is_valid = true;
      getInput(list);
      break;

    default: {
      std::println("Invalid option!");
    }
    };
  }
}

inline Status askStatus() {
  while (true) {
    std::println("Enter task status:\n");
    Menu::printStatusOptions();
    std::string input;
    std::getline(std::cin, input);

    try {
      int choice = std::stoi(input);
      switch (choice) {
      case 1:
        return Status::ToDo;
      case 2:
        return Status::InProgress;
      case 3:
        return Status::Done;
      default:
        std::println("Invalid status!");
      }
    } catch (const std::invalid_argument &e) {
      std::println("Invalid status!");
    }
  }
}

} // namespace Utils

#endif
