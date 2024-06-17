#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>
#include <stdexcept>

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
    void push(int value);

    // Função pop
    int pop();

    // Função seek - mostra o topo
    int seek() const;

    // Função para verificar se a pilha está vazia
    bool isEmpty() const;

    // Função para verificar se a pilha está cheia
    bool isFull() const;

    // Função para exibir os elementos da pilha
    void display() const;
};

#endif