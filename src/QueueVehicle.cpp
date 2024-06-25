#include <iostream>
#include "types.hpp"
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
        vehicle = new Vehicle[size];
    }


    // Destrutor
    ~QueueVehicle() {
        delete[] vehicle;
    }

    // Enfileirar --> Adiciona o carro
    bool enqueue(int item) {
        if (isFull()) {
            return false;
        }

        vehicle[++rear] = item;
        items++;
        return true;
    }

    // Desenfileirar --> Remove o carro
    bool dequeue() {
        //se esteja vazia
        if (isEmpty()) {
            return false;
        }
        //não está vazia
        int temp = vehicle[front++];
        items--;
        return true;
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
