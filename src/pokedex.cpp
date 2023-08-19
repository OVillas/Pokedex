#include <iostream>
#include "include/linkedList.h"
#include "include/pokemon.h"
#include "include/pokemonUtils.h"
#include "include/csvHandler.h"


const std::string FILE_NAME = "data/pokemonData.csv";
char option;
int positionToRemoveOrChange;

int main(int argc, char **argv) { 
    list pokemons;
    readPokemonsCSV(FILE_NAME, pokemons);
    bool run = true;

    while (run) {
        system("clear");
        Pokemon newPokemon;
        showPokemonTitle(true);
        std::cout << "> ";
        std::cin >> option;
        quickSort(pokemons, 0, pokemons.count - 1, comparePokemonID);
        switch (option) {
        case '1':    
            system("clear");
            showPokemonTitle();
            newPokemon = readNewPokemon();
            createPokemon(pokemons, newPokemon);
            exitToPokemonTitle();
            break;
        case '2':
            system("clear");
            showPokemonTitle();
            displayList(pokemons, printPokemon);
            exitToPokemonTitle();
            break;
        case '3':
            system("clear");
            showPokemonTitle();
            std::cout << "Digite a posição do pokemon que você deseja atualizar" << "\n";
            readInterger(positionToRemoveOrChange);
            updatePokemonData(pokemons, positionToRemoveOrChange);
            exitToPokemonTitle();
            break;
        case '4':
            system("clear");
            showPokemonTitle();
            std::cout << "Digite a posição do pokemon que você deseja remover" << "\n";
            readInterger(positionToRemoveOrChange);
            remove(pokemons, positionToRemoveOrChange);
            exitToPokemonTitle();
            break;
        case 'q':
            system("clear");
            showPokemonTitle();
            run = false; 
           break;
        default:
            std::cout << "Opção inválida" << "\n";
            exitToPokemonTitle();
        }    
    }
    
    writePokemonCSV(FILE_NAME, pokemons);
    cleanList(pokemons);
    std::cout << "Fim do programa" << "\n";
    return 0;
}
