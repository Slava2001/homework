#include "database.h"
#include <iostream>

void show_found_actors(std::map<Actor, ActorInfo> actors);

int main() {
  std::cout << "Loading database..." << std::endl;
  Database base("../database.json");
  std::cout << "Loaded!" << std::endl;

  while (true) {
    std::cout << "Select option:" << std::endl
              << "1. Find actor by first name" << std::endl
              << "2. Find actor by last name" << std::endl
              << "3. Exit" << std::endl;
    int option;
    std::cin >> option;
    if (std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Invalid input. Please enter a number." << std::endl;
      continue;
    }
    if (option < 1 || option > 3) {
      std::cout << "Invalid option. Please enter a number between 1 and 3."
                << std::endl;
      continue;
    }

    switch (option) {
    case 1: {
      std::cout << "Enter first name: ";
      std::string first_name;
      std::cin >> first_name;
      show_found_actors(base.find_actor_by_first_name(first_name.c_str()));
      break;
    }
    case 2: {
      std::cout << "Enter last name: ";
      std::string last_name;
      std::cin >> last_name;
      show_found_actors(base.find_actor_by_last_name(last_name.c_str()));
      break;
    }
    case 3: {
      return EXIT_SUCCESS;
    }
    }
  }
}

void show_found_actors(std::map<Actor, ActorInfo> actors) {
  if (actors.empty()) {
    std::cout << "No actors found." << std::endl;
    return;
  }
  for (auto &actor_info : actors) {
    std::cout << "Actor: " << actor_info.first.first_name << " "
              << actor_info.first.last_name << std::endl;
    for (auto &films : actor_info.second.films_map) {
      std::cout << "Film: " << films.first << std::endl;
      for (auto &character : films.second) {
        std::cout << "    Role: " << character.name << std::endl
                  << "    Description: " << character.description << std::endl
                  << std::endl;
      }
    }
  }
}