#ifndef CIRCULARLIST_HPP
#define CIRCULARLIST_HPP

#include "types.hpp"
#include <iostream> 
#include <fstream>
#include <string>
#include <vector>

class CircularList{

public:
    struct Node {
        Occurrence occurrence;
        Node* next;
    };
    CircularList(); //construtor
    ~CircularList();//destrutor

    //métodos - falta passar alguns parametros
    void addNode(Occurrence* oc); //adicionar os nós na lista circular
    void removeNode(Occurrence oc); //vai remover os nós já roletados
    Node* chooseOne(int spin); //função que vai roletar e remover o nó roletado
    bool loadCSV(std::string path);

private:
    Node* head; //sentinela de cabeça da lista

};

#endif