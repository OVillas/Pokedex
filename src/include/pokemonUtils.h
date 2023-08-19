#ifndef POKEMONUTILS_H
#define POKEMONUTILS_H

#include "pokemon.h"
#include <string>
#include <algorithm>

void printPokemon(Pokemon pokemon);

void printOnlyPokemonName(Pokemon pokemon);

int comparePokemonID(Pokemon pokemonA, Pokemon pokemonB);

int comparePokemonName(Pokemon pokemonA, Pokemon pokemonB);
 
Pokemon readNewPokemon();

std::string splitPokemon(Pokemon pokemon);

void showPokemonTitle(bool showMenu = false);

void exitToPokemonTitle();

void readInterger(int &number);
#endif
