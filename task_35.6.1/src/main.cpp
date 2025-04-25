#include <iostream>

int main() {
  for (auto i: std::initializer_list<int>{1, 2, 3, 4, 5}) {
     std::cout << i << std::endl;
  }
  for (auto i: {1, 2, 3, 4, 5}) {
    std::cout << i << std::endl;
  }
  return EXIT_SUCCESS;
}

