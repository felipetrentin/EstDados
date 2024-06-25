#include "Stack.hpp"
#include "types.hpp"
using namespace std;

class Stack {
private:
    int top;
    int size;
    int* stackArray;

public:
    // Construtor
    Stack(int size) : size(size), top(-1) {
        stackArray = new Vehicle[size];
    }

    // Destrutor
    ~Stack() {
        delete[] stackArray;
    }

    //Função push --> Adiciona no topo da pilha
    bool addOnTop(int value) {
        if (isFull()) {
            //Caso esteja cheia
            return false;
        }
        stackArray[++top] = value;
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
    bool top() const {
        if (isEmpty()) {
            return -1;
        }
        return stackArray[top];
    }
    // verificar se está vazia
    bool isEmpty() const {
        return top < 0;
    }

    // verificar se está cheia
    bool isFull() const {
        return top >= size - 1;
    }

    // exibir os elementos da pilha para debug
    void displayText() const {
        if (isEmpty()) {
            std::cout << "Stack is empty." << std::endl;
            return;
        }
        std::cout << "Stack elements: ";
        for (int i = 0; i <= top; i++) {
            std::cout << stackArray[i] << " ";
        }
        std::cout << std::endl;
    }
};
