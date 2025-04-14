#pragma once
#include <vector>
#include <string>
#include "nlohmann/json.hpp"

struct Actor {
    std::string first_name;
    std::string last_name;
};
void from_json(const nlohmann::json& j, Actor& actor);

struct Character {
    std::string name;
    std::string description;
    Actor actor;
};
void from_json(const nlohmann::json& j, Character& character);

struct Film {
    std::string country;
    std::string year_of_production;
    std::string studio;
    std::string scriptwriter;
    std::string director;
    std::string producer;
    std::vector<Character> main_characters;
};
void from_json(const nlohmann::json& j, Film& film);
