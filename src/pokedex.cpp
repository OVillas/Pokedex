#include <iostream>
#include "include/linkedList.h"
#include "include/pokemon.h"
#include "include/pokemonUtils.h"
#include "include/readerCSV.h"

const std::string FILE_NAME = "data/pokemonData.csv";

int main(int argc, char **argv) {
    list pokemons;
    readPokemonsCSV(FILE_NAME, pokemons);
    quickSort(pokemons, 0, 9, comparePokemonID);
    showList(pokemons, printPokemon);
    cleanList(pokemons);
    return 0;
}
