#include <iostream>
#include "include/linkedList.h"
#include "include/pokemon.h"
#include "include/pokemonUtils.h"
#include "include/csvHandler.h"


const std::string FILE_NAME = "data/pokemonData.csv";

int main(int argc, char **argv) { 
    list pokemons;
    readPokemonsCSV(FILE_NAME, pokemons);
    char option;
    bool run = true;

    while (run) {
        system("clear");
        showPokemonTitle();
        std::cout << "> ";
        std::cin >> option;
        switch (option) {
        case '1':
            std::cout << "Adcionando novo pokemon na pokedex" << "\n";
            exitToPokemonTitle();
            break;
        case '2':
            std::cout << "Lendo  pokemon na pokedex" << "\n";
            exitToPokemonTitle();
            break;
        case '3':
            std::cout << "atualizando pokemon na pokedex" << "\n";
            exitToPokemonTitle();
            break;
        case '4':
            std::cout << " Deletando pokemon na pokedex" << "\n";
            exitToPokemonTitle();
            break;
        case 'q':
           run = false; 
           break;
        default:
            std::cout << "Opção inválida" << "\n";
            exitToPokemonTitle();
        }    
    }
    
    std::cout << "Fim do programa" << "\n";
    return 0;
}
