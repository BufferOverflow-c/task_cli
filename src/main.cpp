#include <cctype>
#include <cstdlib>
#include <iostream>

#include "LinkedList.hpp"
#include "Menu.hpp"
#include "Utils.hpp"

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
    Utils::getInput(list);
  }

  return 0;
}
