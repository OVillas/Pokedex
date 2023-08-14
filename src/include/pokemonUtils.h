#ifndef POKEMONUTILS_H
#define POKEMONUTILS_H

#include "pokemon.h"
#include <string>
#include <algorithm>

void printPokemon(Pokemon pokemon);

int comparePokemonID(Pokemon pokemonA, Pokemon pokemonB);

int comparePokemonName(Pokemon pokemonA, Pokemon pokemonB);
 
Pokemon readNewPokemon();

#endif
