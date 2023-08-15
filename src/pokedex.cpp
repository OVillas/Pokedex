#include <iostream>
#include "include/linkedList.h"
#include "include/pokemon.h"
#include "include/pokemonUtils.h"
#include "include/csvHandler.h"

const std::string FILE_NAME = "data/pokemonData.csv";

int main(int argc, char **argv) {
    // Esse é o arquivo principal, ainda em teste!!
    
    list pokemons;
    
    readPokemonsCSV(FILE_NAME, pokemons);
    system("clear");
    showList(pokemons, printPokemon);
    quickSort(pokemons, 0, pokemons.count - 1, comparePokemonID);
    writePokemonCSV(FILE_NAME, pokemons);
    cleanList(pokemons);
    return 0;
}
