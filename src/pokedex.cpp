#include <iostream>
#include "include/linkedList.h"
#include "include/pokemon.h"
#include "include/pokemonUtils.h"
#include "include/readerCSV.h"

const std::string FILE_NAME = "data/pokemonData.csv";

int main(int argc, char **argv) {
    list pokemons;
    
    readPokemonsCSV(FILE_NAME, pokemons);
    system("clear");
    quickSort(pokemons, 0, pokemons.count - 1, comparePokemonName);
    showList(pokemons, printPokemon);

    Pokemon newPokemon;
    newPokemon = readNewPokemon();
    system("clear");
    createPokemon(pokemons, newPokemon);
    showList(pokemons, printPokemon);
    quickSort(pokemons, 0, pokemons.count - 1, comparePokemonID);
    
    
    cleanList(pokemons);
    return 0;
}
