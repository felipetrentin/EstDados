#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>

class Stack {
private:
    int top;
    int size;
    int* stackArray;

public:
    // Construtor
    Stack(int size);

    // Destrutor
    ~Stack();
    // Função push
    bool addOnTop(int value);
    // Função pop
    bool removeFromTop();
    // Função seek - mostra o topo
    int top() const;
    // Função para verificar se a pilha está vazia
    bool isEmpty() const;
    // Função para verificar se a pilha está cheia
    bool isFull() const;
    // Função para exibir os elementos da pilha
    void displayText() const;
};

#endif