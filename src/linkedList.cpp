#include "include/linkedList.h"
#include "include/pokemon.h"
#include <iostream>

using namespace std;

bool isEmpty(list &lst) {
    return lst.count == 0;
}

void add(list &lst, Pokemon data) {
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
    cout << "Memoria limpa com sucesso" << "\n";
}

void showList(list &lst, void(funcPrint)(Pokemon)) {
    node *aux = lst.head;
    while (aux != NULL) {
        funcPrint(aux->data);
        aux = aux->next;
    }
}

node *getByPosition(list &lst, uint32 position) { // Função privada para o usuário
    if (isEmpty(lst) || position > lst.count - 1) {
        cout << "Nenhum monstro visto ou capturado ainda" << "\n";
        throw exception();
    }
    node *aux = lst.head;
    for (int i = 0; i < position; i++)
        aux = aux->next;
    
    return aux;
}

void remove(list &lst, uint32 position) {
    if (isEmpty(lst) || position > lst.count) {
        cout << "Nenhum monstro visto ou capturado ainda para remover" << "\n";
        return;
    }

    node *aux = getByPosition(lst, position);
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
}

void swapNode(list &lst, uint32 positionA, uint32 positionB) { // Função privada para o usuário
    node *aux1 = getByPosition(lst, positionA);
    node *aux2 = getByPosition(lst, positionB);
    Pokemon temp = aux1->data;
    aux1->data = aux2->data;
    aux2->data = temp;
}

void quickSort(list &lst, int begin, int end, int (*funcComp)(Pokemon, Pokemon)) {
    if (begin < end) {
        int i = begin, j = end;
        int center = (begin + end) / 2; //Nesse quickSort foi debatido que o centro será sempre o pivot
        Pokemon pivotData = getByPosition(lst, center)->data;

        while (i <= j) {
            while (funcComp(getByPosition(lst, i)->data, pivotData) < 0) {
                i++;
            }
            while (funcComp(getByPosition(lst, j)->data, pivotData) > 0) {
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

