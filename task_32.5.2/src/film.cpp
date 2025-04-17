#include "film.h"
#include "nlohmann/json.hpp"

bool operator==(const Actor &lhs, const Actor &rhs) {
    return lhs.first_name == rhs.first_name && lhs.last_name == rhs.last_name;
}

bool operator<(const Actor &lhs, const Actor &rhs) {
    if (lhs.last_name < rhs.last_name) {
        return true;
    } else if (lhs.last_name == rhs.last_name) {
        return lhs.first_name < rhs.first_name;
    }
    return false;
}

void from_json(const nlohmann::json &j, Actor &actor) {
    actor.first_name = j.at("first_name");
    actor.last_name = j.at("last_name");
}

void from_json(const nlohmann::json &j, Character &character) {
    character.name = j.at("name");
    character.description = j.at("description");
    character.actor = j.at("actor");
}

void from_json(const nlohmann::json &j, Film &film) {
    film.country = j.at("country");
    film.year_of_production = j.at("year_of_production");
    film.studio = j.at("studio");
    film.scriptwriter = j.at("scriptwriter");
    film.director = j.at("director");
    film.producer = j.at("producer");
    film.main_characters = j.at("main_characters");
}
