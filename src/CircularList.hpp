#ifndef CIRCULARLIST_HPP
#define CIRCULARLIST_HPP

#include "types.hpp"
#include <iostream> 

class CircularList{

public:
    typedef struct Node {
        Occurrence occurrence;
        Node* next;
    };
    CircularList(); //construtor
    ~CircularList();//destrutor

    //métodos - falta passar alguns parametros
    void addNode(Occurrence oc); //adicionar os nós na lista circular
    void removeNode(Occurrence oc); //vai remover os nós já roletados
    Node* chooseOne(int spin); //função que vai roletar e remover o nó roletado
    bool loadCSV(std::string path);

private:
    //métodos privados
    Node* newNode(Occurrence oc); //cria novo nó e adiciona na lista

    Node* head; //sentinela de cabeça da lista

};

#endif