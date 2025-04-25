#include <filesystem>
#include <functional>
#include <iostream>
#include <string>

/// @brief Show ussage
void show_ussage() {
  std::cout << "Usage: ./task_35.6.3 path extension" << std::endl;
}

int main(int argc, const char *argv[]) {
  if (argc == 1 && std::string(argv[1]) == "--help") {
    show_ussage();
    return EXIT_SUCCESS;
  }
  if (argc != 3) {
    show_ussage();
    return EXIT_FAILURE;
  }
  const char *path = argv[1];
  const std::string extension = argv[2];

  [&](std::filesystem::path path, const std::string extension) {
    for (auto &p : std::filesystem::recursive_directory_iterator(path)) {
      if (p.is_regular_file() && p.path().extension().compare(extension)) {
        std::cout << p.path() << '\n';
      }
    }
  }(path, extension);
  return EXIT_SUCCESS;
}
