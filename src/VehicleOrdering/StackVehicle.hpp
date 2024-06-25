#ifndef STACKVEHICLE_HPP
#define STACKVEHICLE_HPP

#include <iostream>

class StackVehicle {
private:
    int top;
    int size;
    int* stackArray;

public:
    // Construtor
    StackVehicle(int size);
    // Destrutor
    ~StackVehicle();
    // Função push
    bool addOnTop(int value);
    // Função pop
    bool removeFromTop();
    // Função seek - mostra o topo
    int top() const;
    // Função para verificar se a pilha está vazia
    bool isEmpty() const;
    // Função para verificar se a pilha está cheia
    bool isFull() const;
    // Função para exibir os elementos da pilha
    void displayText() const;
};

#endif