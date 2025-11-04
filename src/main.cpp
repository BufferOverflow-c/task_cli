#include <cctype>
#include <cstdlib>

#include "LinkedList.hpp"
#include "Utils.hpp"

int main() {
  LinkedList list;

  while (true) {
    Utils::getInput(list);
  }

  return 0;
}
