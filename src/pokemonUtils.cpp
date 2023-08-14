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

void readInterger(int &number) {
    while (!(std::cin >> number)) {
        std::cout << "Digite um valor inteiro válido" << "\n";
        std::cin.clear();
        std::cin.ignore(123, '\n');
    }
}

Pokemon readNewPokemon() {
    Pokemon pokemon;
    std::cout << "Digite o ID do pokemon:\n> ";
    readInterger(pokemon.ID);
    std::cout << "Digite o NOME do pokemon:\n> ";
    std::cin >> pokemon.name;
    std::cout << "Digite o TIPO do pokemon (obs: ser o Pokemon possuir dois tipos use '/' para separar ex: grass/poison):\n> ";
    std::cin >> pokemon.type;
    std::cout << "Digite a geração do pokemon:\n> ";
    readInterger(pokemon.gen);
    return pokemon;
}