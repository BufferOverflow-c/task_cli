#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>
#include <stdexcept>
#include <string>

#include "LinkedList.hpp"
#include "Menu.hpp"

namespace Utils {
void getUpdateChoice(LinkedList &list);

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
      bool is_int = false;
      bool valid_status = false;
      int status_int;
      while (!valid_status) {
        while (!is_int) {
          Menu::printStatusOptions();
          std::getline(std::cin, status);
          try {
            status_int = std::stoi(status);
            valid_status = true;
          } catch (std::invalid_argument &e) {
            std::println("Invalid status!");
            continue;
          }
        }

        switch (status_int) {
        case 1:
          new_status = Status::ToDo;
          valid_status = true;
          break;
        case 2:
          new_status = Status::InProgress;
          valid_status = true;
          break;
        case 3:
          new_status = Status::Done;
          valid_status = true;
          break;
        case 0:
          getInput(list);
          is_valid = true;
          break;
        default:
          std::println("Invalid status!");
          break;
        }
      }
      list.updateTask(id_int, name, new_status);
      std::println("Task status updated!");
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
      list.updateTask(id_int, name, new_status, description);
      std::println("Task description updated!");
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
      bool is_int = false;
      bool valid_status = false;
      int status_int;
      while (!valid_status) {
        while (!is_int) {
          try {
            Menu::printStatusOptions();
            std::getline(std::cin, status);
            status_int = std::stoi(status);
          } catch (std::invalid_argument &e) {
            std::println("Invalid status!");
            continue;
          }
        }
        switch (status_int) {
        case 1:
          new_status = Status::ToDo;
          valid_status = true;
          break;
        case 2:
          new_status = Status::InProgress;
          valid_status = true;
          break;
        case 3:
          new_status = Status::Done;
          valid_status = true;
          break;
        case 0:
          getInput(list);
          is_valid = true;
          break;
        default:
          std::println("Invalid status!");
          break;
        }
      }
      list.updateTask(id_int, name, new_status);
      std::println("Task name & status updated!");
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

      bool is_int = false;
      bool valid_status = false;
      int status_int;
      while (!valid_status) {
        while (!is_int) {
          Menu::printStatusOptions();
          std::getline(std::cin, status);
          try {
            status_int = std::stoi(status);
            is_int = true;
          } catch (std::invalid_argument &e) {
            std::println("Invalid status!");
            continue;
          }
        }
        switch (status_int) {
        case 1:
          new_status = Status::ToDo;
          valid_status = true;
          break;
        case 2:
          new_status = Status::InProgress;
          valid_status = true;
          break;
        case 3:
          new_status = Status::Done;
          valid_status = true;
          break;
        case 0:
          getInput(list);
          is_valid = true;
          break;
        default:
          std::println("Invalid status!");
          break;
        }
      }
      std::println("Enter task description:");
      std::getline(std::cin, description);
      list.updateTask(id_int, name, new_status, description);
      std::println("Task status and description updated!");
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
      list.updateTask(id_int, name, new_status, description);
      std::println("Task name and description updated!");
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

      bool is_int = false;
      bool valid_status = false;
      int status_int;
      while (!valid_status) {
        while (!is_int) {
          Menu::printStatusOptions();
          std::getline(std::cin, status);
          try {
            status_int = std::stoi(status);
            is_int = true;
          } catch (const std::invalid_argument &e) {
            std::println("Invalid status!");
          }
        }
        switch (status_int) {
        case 1:
          new_status = Status::ToDo;
          valid_status = true;
          break;
        case 2:
          new_status = Status::InProgress;
          valid_status = true;
          break;
        case 3:
          new_status = Status::Done;
          valid_status = true;
          break;
        case 0:
          getInput(list);
          is_valid = true;
          break;
        default:
          std::println("Invalid status!");
          break;
        }
      }
      std::println("Enter task description:");
      std::getline(std::cin, description);
      list.updateTask(id_int, name, new_status, description);
      std::println("Task name, status, and description updated!");
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
} // namespace Utils

#endif
