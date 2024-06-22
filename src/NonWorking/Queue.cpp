#include "Queue.hpp"

class Queue {
private:
    int size;
    int* data;
    int front;
    int rear;
    int items;

public:
    // Construtor
    Queue(int size) : size(size), front(0), rear(-1), items(0) {
        data = new int[size];
    }

    // Destrutor
    ~Queue() {
        delete[] data;
    }

    // Enfileirar (add)
    void enqueue(int item) {
        if (isFull()) {
            throw std::overflow_error("Queue is full");
        }

        if (rear == size - 1) {
            rear = -1;
        }

        data[++rear] = item;
        items++;
    }

    // Desenfileirar (remove)
    int dequeue() {
        //caso a fila esteja vazia
        if (isEmpty()) {
            throw std::underflow_error("Queue is empty");
        }

        //caso a fila não esteja vazia
        int temp = data[front++];

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

    // Método para exibir informações da fila
    void display() const {
        std::cout << "Queue: ";
        for (int i = 0; i < items; ++i) {
            std::cout << data[(front + i) % size] << " ";
        }
        std::cout << std::endl;
    }
};
