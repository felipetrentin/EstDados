#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include <iostream>

// Definição da estrutura de um nó
struct Node {
    int value;
    Node* next;
};

// Definição da classe ListaEncadeada
class LinkedList {
private:
    Node* head; // Cabeça da lista, não armazena valor

public:
    // Construtor
    LinkedList();

    // Destrutor
    ~LinkedList();

    // Métodos da lista encadeada
    void printList() const;
    void addEnd(int value);
    void removeNode(int value);
    void freeMemory();

private:
    // Método privado para criar um novo nó
    Node* createNode(int value);
};

#endif
