#include "StackVehicle.hpp"

// Construtor
StackVehicle::StackVehicle(int size) : size(size), top(-1) {
    vehicle = new Vehicle[size];
}

// Destrutor
StackVehicle::~StackVehicle() {
    delete[] vehicle;
}

//Função push --> Adiciona no topo da pilha
bool StackVehicle::addOnTop(Vehicle value) {
    if (isFull()) {
        //Caso esteja cheia
        return false;
    }
    vehicle[++top] = value;
    return true;
}

// Função pop --> Remove do topo da pilha
bool StackVehicle::removeFromTop() {
    if (isEmpty()) {
        //caso esteja vazia 
        return false;
    }
    top--;
    return true;
}

// mostra o topo
bool StackVehicle::getTop(Vehicle& topElement){
    if (isEmpty()) {
        return false;
    }
    topElement = vehicle[top];
    return true;
}

// verifica se está vazia
bool StackVehicle::isEmpty(){
    return top < 0;
}

// verifica se está cheia
bool StackVehicle::isFull(){
    return top >= size - 1;
}

