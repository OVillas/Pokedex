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
void add(list &lst, Pokemon data);
void cleanList(list &lst);
void showList(list &lst, void(*funcPrint)(Pokemon));
void quickSort(list &lst, int begin, int end, int (*funcComp)(Pokemon, Pokemon));
#endif
