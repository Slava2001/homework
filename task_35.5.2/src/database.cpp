#include <fstream>
#include <exception>

#include "database.h"

Database::Database(const char *path_to_database) {
    std::ifstream cfg_file(path_to_database);
    if (!cfg_file.is_open()) {
        throw std::runtime_error("Failed to open file");
    }
    _films = nlohmann::json::parse(cfg_file);
    cfg_file.close();
}

std::vector<ActorInfo> Database::find_actor_by_predicate(
    std::function<bool(const Actor *)> predicate
) const {
    std::vector<ActorInfo> result;
    for (auto &film : _films) {
        for (auto &character : film.second.main_characters) {
            if (predicate(&character.actor)) {
                result.push_back(ActorInfo {
                    .film_name = film.first.c_str(),
                    .role = character.name.c_str(),
                    .role_description = character.description.c_str(),
                });
            }
        }
    }
    return result;
}

std::vector<ActorInfo> Database::find_actor_by_first_name(const char *first_name) const {
    return this->find_actor_by_predicate(
        [&](const Actor *a) -> bool { return a->first_name == first_name; }
    );
}

std::vector<ActorInfo> Database::find_actor_by_last_name(const char *last_name) const {
    return this->find_actor_by_predicate(
        [&](const Actor *a) -> bool { return a->last_name == last_name; }
    );
}
