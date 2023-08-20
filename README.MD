# Trabalho Sistema cadastral (POKEDEX) com listas encadeadas
Repositório para o trabalho 1 da Disciplinas de Estrutura de Dados 1 FCEE - UERJ 2023.1
Ministrado pelo Professor Denis Couple

Informações do Sistema Operacional em que o programa foi testado:
* Distributor ID:	Pop
* Description:	Pop!_OS 22.04 LTS
* Release:	22.04
* Codename:	jammy

# Resumo
Esse projeto tem como objetivo, além de aprendizado, fazer um sistemas de CRUD simples em um 
arquivo .CSV em companhia de uma lista duplamente encadeada.

|  **Membros da Dupla**  |
|------------------------|
| Gabriel Villarinho     |
| Marcelo Bromonschenkel |
|                        |

# Utilidades:
    1 - Utilização de lista duplamente encadeadas ;
    2 - Possibilidade de Criar, Ler, atualizar, deletar e organizar por nome ou ID por meio do sistema de QUICKSORT;
    3 - Implementação na função de leitura por meio de Busca Binária
    
# Implementação da lista duplamente encadeada
![](https://github.com/Villlas/Pokedex/blob/main/img/lista_Duplamente_Encadeada.png)
**Explicação:**
   - A cada Node nessa implementação de uma lista duplamente encadeada, serão armazenados um DATA que será 
        do tipo Pokemon **(struct em src/include/pokemon.h)**, e os ponteiros para o node **NEXT** e node **PREV**.
   - A lista se inicia com um node chamado de **HEAD**, o qual o **NEXT** apontado para os próximos nodes e o **PREV** recebe NULL justamente para
        simbolizar o inicio da lista. e finaliza com um node chamado ***AIL** com o seu **NEXT** recebendo NULL para demonstrar o final da lista.

# MENU PRINCIPAL
![](https://github.com/Villlas/Pokedex/blob/main/img/print_menu.png) 

## Algoritmo de ordenação principal (quick sort)
    Resolvemos utilizar devido a sua alta performace em ordenação por comparação, se tornado o mais eficiente em média. Nele
    se escolhe um elemento de denominamos como **PIVÔ**, que no caso do nosso trabalho será escolhido o elemento central, 
    e partir dele particionamos a lista para que todo os elementos à esquerda do **PIVÔ** sejam os menores e o direita sejam
    os maiores. Após isso, verifica-se se há elementos para ordenar a esquerda e a direita do **PIVÔ** e se houver, é feita
    uma chamada recursiva empilhando o processo dependendo da necessidade (Esquerda ou direita);
### Comparação do tempo de complexidade com outros algoritmos de ordenação

|  **ALGORITMO**   |    **TEMPO DE COMPLEXIDADE**    |
|------------------|---------------------------------|
|      -*=*-       | **MELHOR** | **MÉDIA** |**PIOR**|     
|------------------|------------|-----------|--------|
|    QUICKSORT     |O(nlog(n))  | O(nlog(n))| O(n^2) | => O(n)               
|    BUBBLESORT    | O(n)       | O(n^2)    | O(n^2) | => O(1)
|    INSERTIONSORT | O(n)       | O(n^2)    | O(n^2) | => O(1)


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
            $ make run
        
