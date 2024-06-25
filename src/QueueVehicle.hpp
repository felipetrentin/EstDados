// Estrutura de dados fila
#ifndef QUEUEVEHICLE_H
#define QUEUEVEHICLE_H

#include <string>

class QueueVehicle {
private:
    int size;
    Vehicle* vehicle;
    int front;
    int rear;
    int items;

public:
    // Construtor
    QueueVehicle(int size);

    // Destrutor
    ~QueueVehicle();

    // Métodos da fila
    bool enqueue(Vehicle item); //ta certo passar
    bool dequeue();
    bool isFull() const;
    bool isEmpty() const;
};

#endif