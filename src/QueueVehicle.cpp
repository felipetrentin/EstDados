#include <iostream>
#include "types.hpp"
#include "QueueVehicle.hpp"

// Construtor
QueueVehicle::QueueVehicle(int size) : size(size), front(0), rear(-1), items(0) {
    vehicle = new Vehicle[size];
}


// Destrutor
QueueVehicle::~QueueVehicle() {
    delete[] vehicle;
}

// Enfileirar --> Adiciona o carro
bool QueueVehicle::enqueue(Vehicle item) {
    if (isFull()) {
        return false;
    }

    vehicle[++rear] = item;
    items++;
    return true;
}

// Desenfileirar --> Remove o carro
bool QueueVehicle::dequeue() {
    //se esteja vazia
    if (isEmpty()) {
        return false;
    }
    //não está vazia
    Vehicle temp = vehicle[front++];
    items--;
    return true;
}

// Método para verificar se a fila está cheia
bool QueueVehicle::isFull() const {
    return items == size;
}

// Método para verificar se a fila está vazia
bool QueueVehicle::isEmpty() const {
    return items == 0;
}
