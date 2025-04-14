#include "film.h"
#include "nlohmann/json.hpp"

void from_json(const nlohmann::json& j, Actor& actor) {
    actor.first_name = j.at("first_name");
    actor.last_name = j.at("last_name");
}

void from_json(const nlohmann::json& j, Character& character) {
    character.name = j.at("name");
    character.description = j.at("description");
    character.actor = j.at("actor");
}

void from_json(const nlohmann::json& j, Film& film) {
    film.country = j.at("country");
    film.year_of_production = j.at("year_of_production");
    film.studio = j.at("studio");
    film.scriptwriter = j.at("scriptwriter");
    film.director = j.at("director");
    film.producer = j.at("producer");
    film.main_characters = j.at("main_characters");
}
