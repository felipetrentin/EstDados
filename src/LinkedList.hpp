#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include <iostream>

// Definição da estrutura de um nó
struct Node {
    int value;
    Node* next;
};

// Definição da classe LinkedList
class LinkedList {
private:
    Node* head; // Cabeça da lista, não armazena valor

public:
    // Construtor
    LinkedList();

    // Destrutor
    ~LinkedList();

    // Métodos
    void printList() const; //imprime a lista
    void addEnd(int value); //adiciona ao final da lista
    void removeNode(int value); //remove um nó
    void freeMemory(); //libera a memória

private:
    // Métodos privados
    Node* createNode(int value); //Cria um novo nó
};

#endif
