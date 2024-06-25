#include <iostream>
#include "QueueVehicle.hpp"

using namespace std;

class QueueVehicle {
private:
    int size;
    int* vehicle;
    int front;
    int rear;
    int items;

public:
    // Construtor
    QueueVehicle(int size) : size(size), front(0), rear(-1), items(0) {
        vehicle = new int[size];
    }


    // Destrutor
    ~QueueVehicle() {
        delete[] vehicle;
    }

    // Enfileirar (add)
    void enqueue(int item) {
        if (isFull()) {
            throw std::overflow_error("Queue is full");
        }

        if (rear == size - 1) {
            rear = -1;
        }

        vehicle[++rear] = item;
        items++;
    }

    // Desenfileirar (remove o carro)
    int dequeue() {
        //caso a fila esteja vazia
        if (isEmpty()) {
            throw std::underflow_error("Queue is empty");
        }

        //caso a fila não esteja vazia
        int temp = vehicle[front++];

        if (front == size) {
            front = 0;
        }

        items--;
        return temp;
    }

    // Método para verificar se a fila está cheia
    bool isFull() const {
        return items == size;
    }

    // Método para verificar se a fila está vazia
    bool isEmpty() const {
        return items == 0;
    }

    void displayText() const {
        for (int i = 0; i < items; ++i) {
            if (i > 0) {
                putchar(',');
                putchar(' ');
            }
            printf("%d", vehicle[(front + i) % size]);
        }
        putchar('\n');
    }
};
