// Estrutura de dados fila
#ifndef QUEUE_H
#define QUEUE_H

#include <string>

class Queue {
private:
    int size;
    int* data; //aqui é pra ser do tipo vehicle que é uma struct
    int front;
    int rear;
    int items; //quantidade de elementos da fila

public:
    // Construtor
    Queue(int size);

    // Destrutor
    ~Queue();

    // Métodos da fila
    void enqueue(int data); //ta certo passar
    int dequeue();
    bool isFull() const;
    bool isEmpty() const;

    // Método para exibir informações da fila (opcional)
    void displayText() const;
};

#endif