#include "Stack.hpp"

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

    // Função push
    void push(int value) {
        if (top >= size - 1) {
            throw std::overflow_error("Stack overflow");
        }
        stackArray[++top] = value;
    }

    // Função pop
    int pop() {
        if (top < 0) {
            throw std::underflow_error("Stack underflow");
        }
        return stackArray[top--];
    }

    // Função seek - mostra o topo
    int seek() const {
        if (top < 0) {
            throw std::underflow_error("Stack is empty");
        }
        return stackArray[top];
    }

    // Função para verificar se a pilha está vazia
    bool isEmpty() const {
        return top < 0;
    }

    // Função para verificar se a pilha está cheia
    bool isFull() const {
        return top >= size - 1;
    }

    // Função para exibir os elementos da pilha (opcional)
    void display() const {
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
