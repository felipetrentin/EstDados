#include "Stack.hpp"
using namespace std;

class Stack {
private:
    int top;
    int size;
    int* stackArray;

public:
    // Construtor
    Stack(int size) : size(size), top(-1) {
        stackArray = new int[size];
    }

    // Destrutor
    ~Stack() {
        delete[] stackArray;
    }

   void push(int value) {
        if (top >= size - 1) {
            // Stack overflow
            std::cout << "Stack overflow" << std::endl;
            return;
        }
        stackArray[++top] = value;
    }

    // Função pop
    int pop() {
        if (top < 0) {
            // Stack underflow
            std::cout << "Stack underflow" << std::endl;
            return -1;
        }
        return stackArray[top--];
    }

    // Função peek - mostra o topo
    int top() const {
        if (top < 0) {
            // Stack is empty
            std::cout << "Stack is empty" << std::endl;
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

    // exibir os elementos da pilha
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
