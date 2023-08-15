# Projeto de uma POKEDEX com a matéria de Estrutura de Dados 1

**Ainda em desenvolvimento**

Desenvolvido por Gabriel Villarinho

100% construido na linguagem c++

# Resumo
Esse projeto tem como objetivo, além de aprendizado, fazer um sistemas de CRUD simples em um 
arquivo .CSV em uma lista duplamente encadeada.


# Utilidades:
    1 - Utilização de lista duplamente encadeadas ;
    2 - Possibilidade de Criar, Ler, atualizar, deletar e organizar por nome ou ID por meio do sistema de QUICKSORT;
    3 - Implementação na função de leitura por meio de Busca Binária
    
# Implementação da lista duplamente encadeada
![](https://github.com/Villlas/Pokedex/blob/main/img/lista_Duplamente_Encadeada.png)
***Explicação:***
   - A cada Node nessa implementação de uma lista duplamente encadeada, serão armazenados um DATA que será 
        do tipo Pokemon ***(struct em src/include/pokemon.h)***, e os ponteiros para o node ***NEXT*** e node ***PREV***.
   - A lista se inicia com um node chamado de ***HEAD***, o qual o ***NEXT** apontado para os próximos nodes e o ***PREV*** recebe NULL justamente para
        simbolizar o inicio da lista. e finaliza com um node chamado ***TAIL*** com o seu ***NEXT*** recebeendo NULL para demonstrar o final da lista.

# MENU PRINCIPAL
![](https://github.com/Villlas/Pokedex/blob/main/img/print_menu.png) 

# TUTORIAL 
    1 - linux:
        1.1 - instale o gcc com: 
            $ sudo apt update -y
            $ sudo apt upgrade -y
            $ sudo apt install gcc
        1.2 - Entre na pasta do arquivo  pelo terminal
        1.3 - Execute o seguinte comando para compilar o aquivo
            $ make
        1.4 - Para executar o programa escreva o seguinte comando:
            $ ./pokedex
        
