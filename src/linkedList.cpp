#include "include/linkedList.h"
#include "include/pokemon.h"
#include "include/pokemonUtils.h"
#include <iostream>

using namespace std;

bool isEmpty(list &lst) {
    return lst.count == 0;
}

void append(list &lst, Pokemon data) {
    node *newNode = new node;
    newNode->data = data;

    if (isEmpty(lst)) {
        lst.head = lst.tail = newNode;
        lst.count++;
        return;
    }

    newNode->prev = lst.tail;
    lst.tail->next = newNode;
    lst.tail = newNode;
    lst.count++; 
}

void cleanList(list &lst) {
    while (lst.count > 0) {
        node *aux = lst.tail;
        lst.tail = lst.tail->prev;
        delete aux;
        lst.count--;
    }
    lst.head = lst.tail = nullptr;
    cout << "Lista limpa com sucesso" << "\n";
}

void displayList(list &lst, void(funcPrint)(Pokemon), bool showPosition) {
    node *aux = lst.head;
    int i = 0;
    while (aux != NULL) {
        if (showPosition) cout << "[ " << i++ << " ]"; 
        funcPrint(aux->data);
        aux = aux->next;
    }
}

// PRIVADA Função auxiliar para o algoritmo de ordenação quickSort
node *getNodeByPosition(list &lst, uint32 position) { 
    if (isEmpty(lst) || position > lst.count - 1) {
        cout << "Nenhum monstro visto ou capturado ainda" << "\n";
        return NULL;
    }
    node *aux = lst.head;
    for (int i = 0; i < position; i++)
        aux = aux->next;
    
    return aux;
}

//PRIVADA Função auxiliar para a inserção de um novo pokemon
node *getNodeByID(list &lst, int pokemonID) { 
    if (isEmpty(lst)) {
        cout << "Nenhum monstro visto ou capturado ainda" << "\n";
        return NULL;
    }
    node *aux = lst.head;
    for (int i = 0; i < lst.count; i++) {
        if (aux->data.ID == pokemonID) 
            return aux;
        aux = aux->next;
    }

    return NULL;
}

void remove(list &lst, uint32 position) {
    if (isEmpty(lst) || position > lst.count) {
        cout << "Nenhum monstro visto ou capturado ainda para remover" << "\n";
        return;
    }

    node *aux = getNodeByPosition(lst, position);
    if (aux->next != NULL) {
        aux->next->prev = aux->prev;
    } else {
        lst.tail = aux->prev;
    }

    if (aux->prev != NULL) {
        aux->prev->next = aux->next;
    } else {
        lst.head = aux->next;
    }

    delete aux;
    lst.count--;
    cout << "Pokemon deletado com sucesso" << "\n";
}

//PRIVADA
void swapNode(list &lst, uint32 positionA, uint32 positionB) { 
    node *aux1 = getNodeByPosition(lst, positionA);
    node *aux2 = getNodeByPosition(lst, positionB);
    Pokemon temp = aux1->data;
    aux1->data = aux2->data;
    aux2->data = temp;
}

void quickSort(list &lst, int begin, int end, int (*funcComp)(Pokemon, Pokemon)) {
    if (begin < end) {
        int i = begin, j = end;
        int center = (begin + end) / 2; //Nesse quickSort foi debatido que o centro será sempre o pivot
        Pokemon pivotData = getNodeByPosition(lst, center)->data;

        while (i <= j) {
            
            while (funcComp(getNodeByPosition(lst, i)->data, pivotData) < 0) {
                i++;
            }
            while (funcComp(getNodeByPosition(lst, j)->data, pivotData) > 0) {
                j--;
            }
            if (i <= j) {
                swapNode(lst, i, j);
                i++;
                j--;
            }
        }

        if (begin < j) 
            quickSort(lst, begin, j, funcComp);
        
        if (i < end)
            quickSort(lst, i, end, funcComp);
    }
}

void createPokemon(list &lst, Pokemon pokemon) {
    Pokemon err;

    quickSort(lst, 0, lst.count - 1, comparePokemonID);
    err = binarySearch(lst, pokemon, 0, lst.count - 1, comparePokemonID);
    if (err.name != "NULL") {
        cout << "Pokemon já registrado na pokedex com esse ID: " << pokemon.ID << "\n";
        return;
    }
    
    quickSort(lst, 0, lst.count - 1, comparePokemonName);
    err = binarySearch(lst, pokemon, 0, lst.count - 1, comparePokemonName);
    if (err.name != "NULL") {
        cout << "Pokemon já registrado na pokedex com esse nome: " << pokemon.name << "\n";
        return;
    }

    append(lst, pokemon);
    cout << "Pokemon registrado com sucesso" << "\n";
}

void updatePokemonData(list &lst, int ID) {
    node *pokemonSaveInDatabase = getNodeByID(lst, ID);
    node *aux;
    if (pokemonSaveInDatabase == NULL) {
        cout << "Erro! Pokemon não existente em sua pokedex" << "\n";
        return;
    }
    Pokemon pokemon = readNewPokemon();   
    
    Pokemon err;
    quickSort(lst, 0, lst.count - 1, comparePokemonID);
    err = binarySearch(lst, pokemon, 0, lst.count - 1, comparePokemonID);
    if (err.name != "NULL") {
        cout << "Pokemon já registrado na pokedex com esse ID: " << pokemon.ID << "\n";
        return;
    }
    
    quickSort(lst, 0, lst.count - 1, comparePokemonName);
    err = binarySearch(lst, pokemon, 0, lst.count - 1, comparePokemonName);
    if (err.name != "NULL") {
        cout << "Pokemon já registrado na pokedex com esse nome: " << pokemon.name << "\n";
        return;
    }

    pokemonSaveInDatabase->data.ID = pokemon.ID;
    pokemonSaveInDatabase->data.name = pokemon.name;
    pokemonSaveInDatabase->data.type = pokemon.type;
    pokemonSaveInDatabase->data.gen = pokemon.gen;

    cout << "Dados do pokemon alterados com sucesso!" << "\n";
}

Pokemon binarySearch(list &lst, Pokemon valueSearch, int begin, int end, int (*funcComp)(Pokemon, Pokemon)) {
    if (end < begin) {
        Pokemon notFound;
        notFound.name = "NULL";
        return notFound;
    }
    int mid = (begin + end) / 2;
    Pokemon midPokemon = getNodeByPosition(lst, mid)->data;
    int compResult = funcComp(midPokemon, valueSearch);

    if (compResult == 0)
        return midPokemon;
    
    if (compResult < 0)
        return binarySearch(lst, valueSearch, mid + 1, end, funcComp);
    
    return binarySearch(lst, valueSearch, begin, mid - 1, funcComp);
}