#include "include/pokemonUtils.h"
#include <iostream>

void printPokemon(Pokemon pokemon) {
    std::cout << "ID: " << pokemon.ID << "\n";
    std::cout << "name: " << pokemon.name << "\n";
    std::cout << "type: " << pokemon.type << "\n";
    std::cout << "gen: " << pokemon.gen << "\n\n";
}

int comparePokemonID(Pokemon pokemonA, Pokemon pokemonB) {
    return pokemonA.ID - pokemonB.ID;
}

int comparePokemonName(Pokemon pokemonA, Pokemon pokemonB) {
    std::string pokemonAUpper = pokemonA.name;
    std::string pokemonBUpper = pokemonB.name;

    std::transform(pokemonAUpper.begin(), pokemonAUpper.end(), pokemonAUpper.begin(), ::toupper);
    std::transform(pokemonBUpper.begin(), pokemonBUpper.end(), pokemonBUpper.begin(), ::toupper);

    return pokemonAUpper.compare(pokemonBUpper);
}
