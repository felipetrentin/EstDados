#ifndef STACKVEHICLE_HPP
#define STACKVEHICLE_HPP

#include <iostream>
#include "types.hpp"

class StackVehicle {
private:
    int top;
    int size;
    Vehicle* vehicle;

public:
    // Construtor
    StackVehicle(int size);
    // Destrutor
    ~StackVehicle();
    // Função push
    bool addOnTop(Vehicle value);
    // Função pop
    bool removeFromTop();
    // Função para verificar se a pilha está vazia
    bool isEmpty();
    // Função para verificar se a pilha está cheia
    bool isFull();

    bool getTop(Vehicle& topElement);
};

#endif