// Estrutura de dados fila
#ifndef QUEUE_H
#define QUEUE_H

#include <string>

class QueueVehicle {
private:
    int size;
    int* vehicle; //aqui é pra ser do tipo vehicle que é uma struct
    int front;
    int rear;
    int items; //quantidade de elementos da fila

public:
    // Construtor
    QueueVehicle(int size);

    // Destrutor
    ~QueueVehicle();

    // Métodos da fila
    void enqueue(int vehicle); //ta certo passar
    int dequeue();
    bool isFull() const;
    bool isEmpty() const;

    // exibe informações da fila
    void displayText() const;
};

#endif