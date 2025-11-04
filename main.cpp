#include <iostream>

#include "src/factorial.hpp"
#include "src/BinarySearchTree.h"
#include "src/TreeMap.h"

int main() {
  std::cout << "The factorial of 5 is " << factorial(5) << std::endl;

  TreeMap map;

  map.insert("keyOne", "valueOne");
  map.insert("keyTwo", "valueTwo");
  map.insert("keyThree", "valueThree");

  // Prints out valueOne
  std::cout << map.get("keyOne") << std::endl;

  // Prints out valueThree
  std::cout << map.get("keyThree") << std::endl;

  // Prints out an empty string or some default value of your choice
  std::cout << map.get("keyDoesNotExist") << std::endl;

  // Deletes the key-value pair from the tree map
  std::cout << map.deleteKey("keyOne") << std::endl;
}
