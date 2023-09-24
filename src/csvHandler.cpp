#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "include/linkedList.h"
#include "include/pokemon.h"
#include "include/pokemonUtils.h"

using namespace std;

void readPokemonsCSV(string filename, list &lst) {
    ifstream fileDatas(filename);

    if (!fileDatas.is_open()) {
        cout << "Erro ao abrir o arquivo CSV" << "\n";
        return;
    }

    string line;
    while (getline(fileDatas, line)) {
        stringstream ss(line);
        string field;

        Pokemon pokemon;
        getline(ss, field, ';');
        pokemon.ID = stoi(field);
        getline(ss, field, ';');
        pokemon.name = field;
        getline(ss, field, ';');
        pokemon.type = field;
        getline(ss, field, ';');
        pokemon.gen = stoi(field);

        append(lst, pokemon);
    }

    fileDatas.close();
}

void writePokemonCSV(string filename, list &lst) {
    ofstream fileDatas(filename);

    if (!fileDatas.is_open()) {
        cout << "Erro ao abrir o arquivo CSV" << "\n";
        return;
    }

    node *aux = lst.head;
    for (int i = 0; i < lst.size; i++) {
        string line = splitPokemon(aux->data);
        fileDatas << line << "\n";
        aux = aux->next;
    }


    fileDatas.close();
}