#ifndef PRIORITYLIST_HPP
#define PRIORITYLIST_HPP

#include <iostream>
#include "types.hpp"



class PriorityList {
public:
    struct Node {
        Occurrence occurrence;
        int priority; //quando criar o nó ele vai dar um get na prioridade do Occurence;
        Node* nextNode;
    };
    PriorityList(); //construtor
    ~PriorityList(); //destrutor

    //métodos
    Node* newNode(Occurrence oc); //cria um novo nó a partir de uma ocorrencia
    void addNode(Occurrence oc, int capacity);//adiciona nó na ista com prioridade 
    void remNode(int index);//remove o nó --> tem duas condições pra remover o nó;
    int getPriority(Occurrence* oc); //pega a prioridade da struct occurrence e retorna o valor dela;
    unsigned int countNodes() const;//conta os nós e mantém uma quantidade fixa de nós... mesmo que essa não seja a função da lista com prioridade
    unsigned int findVal(int value) const;//verifica se a ocorrencia ja foi atendida
    void showList() const; //teoricamente mostraria na tela (?)
    int* isFull(int capacity); //vê se a lista tá cheia, porque a tela não é infinita e precisamos manejar a quatidade simultanea;
    Node* findNode(unsigned int index);

private:
    Node* firstElement;
    int capacity;
    //método privado auxiliar
};

#endif 
