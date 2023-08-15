#include <iostream>
#include "include/linkedList.h"
#include "include/pokemon.h"
#include "include/pokemonUtils.h"
#include "include/readerCSV.h"

const std::string FILE_NAME = "data/pokemonData.csv";

int main(int argc, char **argv) {
    // Esse é o arquivo principal, ainda em teste!!
    
    list pokemons;
    
    readPokemonsCSV(FILE_NAME, pokemons);
    system("clear");
    showList(pokemons, printPokemon);

    Pokemon newPokemon;
    newPokemon = readNewPokemon();
    system("clear");
    createPokemon(pokemons, newPokemon);
    quickSort(pokemons, 0, pokemons.count - 1, comparePokemonID);
    std::cout << "Por ID:\n";
    showList(pokemons, printPokemon);
    std::cout << "\n";
    std::cout << "\n";
    std::cout << "\n";
    std::cout << "\n";
    std::cout << "\n";
    std::cout << "\n";
    std::cout << "\n";
    newPokemon = readNewPokemon();
    createPokemon(pokemons, newPokemon);
    std::cout << "Por NOME:\n";
    quickSort(pokemons, 0, pokemons.count - 1, comparePokemonName);
    showList(pokemons, printPokemon);
    

    cleanList(pokemons);
    return 0;
}
