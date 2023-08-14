#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "include/linkedList.h"
#include "include/pokemon.h"

using namespace std;

void readPokemonsCSV(string filename, list &lst) {
    ifstream fileDatas(filename);

    if (!fileDatas.is_open()) {
        cout << "Erro ao abrir o arquivo csv" << "\n";
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


}