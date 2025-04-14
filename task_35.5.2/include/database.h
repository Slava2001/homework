#pragma once

#include "film.h"

struct ActorInfo {
    const char *film_name;
    const char *role;
    const char *role_description;
};

class Database {
public:
    Database(const char *path_to_database);
    std::vector<ActorInfo> find_actor_by_first_name(const char *first_name) const;
    std::vector<ActorInfo> find_actor_by_last_name(const char *last_name) const;
private:
    std::map<std::string, Film> _films;

    std::vector<ActorInfo> find_actor_by_predicate(
        std::function<bool(const Actor *)> predicate
    ) const;
};
