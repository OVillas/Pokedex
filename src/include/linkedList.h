#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include "pokemon.h"
typedef unsigned int uint32;

struct node {
    Pokemon data;
    node *next = nullptr;
    node *prev = nullptr;
};

struct list {
    node *head = nullptr;
    node *tail = nullptr;
    int count = 0;
};

bool isEmpty(list &lst);
void append(list &lst, Pokemon data);
void createPokemon(list &lst, Pokemon pokemon);
void cleanList(list &lst);
void displayList(list &lst, void(*funcPrint)(Pokemon), bool showPosition = false);
void quickSort(list &lst, int begin, int end, int (*funcComp)(Pokemon, Pokemon));
void remove(list &lst, uint32 position);
void updatePokemonData(list &lst, int ID);
#endif
