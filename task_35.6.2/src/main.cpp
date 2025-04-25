#include <algorithm>
#include <iostream>
#include <memory>
#include <unordered_set>
#include <vector>

int main() {
  const std::vector<int> origin_vec{1, 2, 2, 3, 3, 3, 4, 4,
                                    4, 4, 5, 5, 5, 5, 5};

  auto print_element = [](auto e) { std::cout << e << " "; };

  std::cout << "Original vector: ";
  std::for_each(origin_vec.begin(), origin_vec.end(), print_element);
  std::cout << std::endl;

  auto unique_vec = [](std::vector<int> vec) {
    std::unordered_set<int> tmp_set;
    std::vector<int> result;
    for (auto i : vec) {
      if (tmp_set.count(i) == 0) {
        tmp_set.insert(i);
        result.push_back(i);
      }
    }
    return std::make_unique<std::vector<int>>(result);
  }(origin_vec);

  std::cout << "Unique vector: ";
  std::for_each(unique_vec->begin(), unique_vec->end(), print_element);
  std::cout << std::endl;

  return EXIT_SUCCESS;
}
