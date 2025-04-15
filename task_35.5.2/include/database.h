#pragma once

#include "film.h"

/// @brief Actor info
struct ActorInfo {
    /// Map with actor roles. Key - film name, value - vector of actor roles in this film
    std::map<std::string, std::vector<Character>> films_map;
};

/// @brief Films database
class Database {
public:
    /// @brief Construct a new Database object
    /// @param path_to_database path to database file in json format
    /// @throw std::runtime_error if database file not found
    /// @throw nlohmann::json::parse_error if database file is not valid json
    Database(const char *path_to_database);

    /// @brief Find film by first name
    /// @param name actor first name
    /// @return map where key is actor and value is info about his roles
    std::map<Actor, ActorInfo> find_actor_by_first_name(const char *first_name) const;

    /// @brief Find film by last name
    /// @param name actor last name
    /// @return map where key is actor and value is info about his roles
    std::map<Actor, ActorInfo> find_actor_by_last_name(const char *last_name) const;
private:
    std::map<std::string, Film>_films;

    /// @brief Find film by predicate
    /// @param predicate predicate to find film
    /// @return map where key is actor and value is info about his roles
    std::map<Actor, ActorInfo> find_actor_by_predicate(
        std::function<bool(const Actor *)> predicate
    ) const;
};
