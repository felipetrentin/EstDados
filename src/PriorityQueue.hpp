#ifndef PRIORITYQUEUE_HPP
#define PRIORITYQUEUE_HPP

#include <iostream>

struct Node {
    int content;
    int priority;
    Node* nextNode;
};

class PriorityQueue {
private:
    Node* firstElement;

public:
    // Construtor
    PriorityQueue();

    // Destrutor
    ~PriorityQueue();

    // Métodos da fila com prioridade
    void addNode(int priority, int value);
    void remNode(unsigned int index);
    int getNode(unsigned int index) const;
    void setNode(unsigned int index, int value);
    unsigned int countNodes() const;
    void showList() const;
    unsigned int findVal(int value) const;

private:
    // Métodos privados auxiliares
    Node* findNode(unsigned int index) const;
};

#endif 
