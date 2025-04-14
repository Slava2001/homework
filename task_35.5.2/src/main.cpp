#include <iostream>
#include "database.h"

int main() {
    Database base("../database.json");

    std::cout << "find_actor_by_first_name:" << std::endl;
    for (auto &f: base.find_actor_by_first_name("Matthew")) {
        std::cout << "Film: " << f.film_name << std::endl
        << "Role: " << f.role << std::endl
        << "Description: " << f.role_description << std::endl;
    }

    std::cout << "find_actor_by_last_name:" << std::endl;
    for (auto &f: base.find_actor_by_last_name("McConaughey")) {
        std::cout << "Film: " << f.film_name << std::endl
                  << "Role: " << f.role << std::endl
                  << "Description: " << f.role_description << std::endl;
    }

    return EXIT_SUCCESS;
}
