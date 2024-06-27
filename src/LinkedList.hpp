#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include <iostream>

// Estrutura de um nó
struct Node {
    int value;
    Node* next;
};

// Classe LinkedList
class LinkedList {
private:
    Node* head; // Cabeça da lista, não armazena valor

public:
    // Construtor
    LinkedList();

    // Destrutor
    ~LinkedList();

    // Métodos
    //void printList() const; //imprime a lista
    void add(int value); //adiciona ao final da lista
    void removeNode(int value); //remove um nó
    void freeMemory(); //libera a memória
    int getSize();
    void copyLinked(LinkedList exemploDoFilho);
    Node* getNode(int id);
    Node* getLastElement();
    void addNext(Node* node, int value);
private:
    // Métodos privados
    Node* createNode(int value); //Cria um novo nó
};

#endif
