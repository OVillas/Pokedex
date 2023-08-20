#include <iostream>
#include "include/linkedList.h"
#include "include/pokemon.h"
#include "include/pokemonUtils.h"
#include "include/csvHandler.h"

// Váriaveis globais
const std::string FILE_NAME = "data/pokemonData.csv";
char option;
int positionToRemoveOrChange;

const char *returnOS() {
   #ifdef _WIN32
        return "cls"; 
    #else
        return "clear";
    #endif
}
const char *OS = returnOS();


int main(int argc, char **argv) { 
    list pokemons;
    readPokemonsCSV(FILE_NAME, pokemons);
    bool stopRun = false;
    while (!stopRun) {
        system(OS);
        Pokemon PokemonAUX; //Váriavel auxiliar para as funções 
        showPokemonTitle(true);
        std::cout << "> ";
        std::cin >> option;
        quickSort(pokemons, 0, pokemons.count - 1, comparePokemonID);
        switch (option) {
        case '1': 
            //Cadastrar novo pokemon   
            system(OS);
            showPokemonTitle();
            PokemonAUX = readNewPokemon();
            createPokemon(pokemons, PokemonAUX);
            exitToPokemonTitle();
            break;
        case '2':
            //Mostrar todos os pokemons cadastrado
            system(OS);
            showPokemonTitle();
            displayList(pokemons, printPokemon);
            exitToPokemonTitle();
            break;
        case '3':
            //Pesquisar um pokemon digitando um nome
            system(OS);
            showPokemonTitle();
            std::cout << "Digite o nome do pokemons que deseja procurar\n> ";
            std::cin >> PokemonAUX.name;
            quickSort(pokemons, 0, pokemons.count - 1, comparePokemonName); //Para a pesquisa funcionar, e necessário que o objeto esteja ordenado
            PokemonAUX =  binarySearch(pokemons, PokemonAUX, 0, pokemons.count - 1, comparePokemonName);
            if (PokemonAUX.name == "NULL") {
                std::cout << "Pokemon não encontrado!!" << "\n";
            } else {
                std::cout << "\nPokemon encontrado com sucesso" << "\n";
                printPokemon(PokemonAUX);
            }
            exitToPokemonTitle();
            break;
        case '4':
            //Atualizar dados de uma pokemon
            system(OS);
            showPokemonTitle();
            std::cout << "Digite a posição do pokemon que você deseja atualizar" << "\n";
            readInterger(positionToRemoveOrChange);
            updatePokemonData(pokemons, positionToRemoveOrChange);
            exitToPokemonTitle();
            break;
        case '5':
            //Remover um pokemon
            system(OS);
            showPokemonTitle();
            std::cout << "Digite a posição do pokemon que você deseja remover" << "\n";
            readInterger(positionToRemoveOrChange);
            remove(pokemons, positionToRemoveOrChange);
            exitToPokemonTitle();
            break;
        case 'q':
            // Sair da pokedex
            system(OS);
            showPokemonTitle();
            stopRun = true; 
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
