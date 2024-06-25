#include "Stack.hpp"
#include "types.hpp"

class Stack {
private:
    int top;
    int size;
    int* vehicle;

public:
    // Construtor
    Stack(int size) : size(size), top(-1) {
        vehicle = new Vehicle[size];
    }

    // Destrutor
    ~Stack() {
        delete[] vehicle;
    }

    //Função push --> Adiciona no topo da pilha
    bool addOnTop(int value) {
        if (isFull()) {
            //Caso esteja cheia
            return false;
        }
        vehicle[++top] = value;
        return true;
    }

    // Função pop --> Remove do topo da pilha
    bool removeFromTop() {
        if (isEmpty()) {
            //caso esteja vazia 
            return false;
        }
        top--;
        return true;
    }

    // mostra o topo
    bool top(int& topElement) const {
        if (isEmpty()) {
            return false;
        }
        topElement = vehicle[top];
        return true;
    }

    // verifica se está vazia
    bool isEmpty() const {
        return top < 0;
    }

    // verifica se está cheia
    bool isFull() const {
        return top >= size - 1;
    }

    // exibir os elementos da pilha para debug
    bool displayText() const {
        if (isEmpty()) {
            return false;
        }
        printf("Stack elements: ");
        for (int i = 0; i <= top; i++) {
            printf(vehicle[i] + " ");
        }
    }
};
