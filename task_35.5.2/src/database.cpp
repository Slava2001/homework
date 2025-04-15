#include <exception>
#include <fstream>

#include "database.h"

Database::Database(const char *path_to_database) {
  std::ifstream cfg_file(path_to_database);
  if (!cfg_file.is_open()) {
    throw std::runtime_error("Failed to open file");
  }
  _films = nlohmann::json::parse(cfg_file);
  cfg_file.close();
}

std::map<Actor, ActorInfo> Database::find_actor_by_predicate(
    std::function<bool(const Actor *)> predicate) const {
  std::map<Actor, ActorInfo> result;
  for (auto &film : _films) {
    for (auto &character : film.second.main_characters) {
      if (predicate(&character.actor)) {
        auto actor_info = result.find(character.actor);
        if (actor_info != result.end()) {
          auto film_info = actor_info->second.films_map.find(film.first);
          if (film_info != actor_info->second.films_map.end()) {
            film_info->second.push_back(character);
          } else {
            actor_info->second.films_map[film.first] = {character};
          }
        } else {
          result[character.actor] =
              ActorInfo{.films_map = {{film.first, {character}}}};
        }
      }
    }
  }
  return result;
}

std::map<Actor, ActorInfo>
Database::find_actor_by_first_name(const char *first_name) const {
  return this->find_actor_by_predicate(
      [&](const Actor *a) -> bool { return a->first_name == first_name; });
}

std::map<Actor, ActorInfo>
Database::find_actor_by_last_name(const char *last_name) const {
  return this->find_actor_by_predicate(
      [&](const Actor *a) -> bool { return a->last_name == last_name; });
}
