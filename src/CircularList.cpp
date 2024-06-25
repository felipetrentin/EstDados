#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "CircularList.hpp"
#include "types.hpp"

CircularList::CircularList() : 
    head(nullptr) 
{} // implementa o construtor, em que o sentinela de cabeça é nulo

CircularList::~CircularList(){
    Node *currElement = head->next;
    while (currElement != head)
    {
        Node *next = currElement->next;
        delete currElement;
        currElement = next;
    }
    delete head;
    head = nullptr;
} // destrutor

void CircularList::addNode(Occurrence* oc){
    Node *currElement = new Node();
    currElement->occurrence.description = oc->description;
    currElement->occurrence.place = oc->place;
    currElement->occurrence.priority = oc->priority;
    if (head == nullptr)
    {
        head = currElement;
        currElement->next = head;
    }
    else
    {
        Node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp = currElement;
        currElement->next = head;
    }
} // adiciona os nós no fim da lista circular

void CircularList::removeNode(Occurrence oc){

    Node *previous = nullptr;
    Node *currElement = head;

    do
    {
        if (
            currElement->occurrence.place == oc.place &&
            currElement->occurrence.priority == oc.priority)
        {
            if (previous == nullptr)
            {
                previous->next = currElement->next;
                if (currElement == head)
                {
                    head = currElement->next;
                }
                delete currElement;
                return;
            }
            else
            {
                Node *last = head;
                while (last->next != head)
                {
                    last = last->next;
                } // aqui eu garanto que o last é o último da lista percorrendo a lista toda
                if (last == head)
                {
                    delete head;
                    head = nullptr;
                    return;
                }
                else
                {
                    last->next = head->next;
                    delete head;
                    head = last;
                    return;
                }
            }
        }
    } while (currElement != head);
} // remover um nó

CircularList::Node *CircularList::chooseOne(int spin){
    Node *curr = head;
    for (int i = 0; i < spin; i++)
    { // anda um
        if(curr->next != nullptr){
            curr = curr->next;
        }
    }
    //removeNode(curr->occurrence);
    return curr;
   return head;
} // função que vai roletar e remover o nó roletado

bool CircularList::loadCSV(std::string path){
    std::string segment;
    std::ifstream myfile (path);
    if (myfile.is_open())
    {
        int segId = 0;
        Occurrence* occ = nullptr;
        while (getline(myfile,segment,','))
        {
            //description,priority,HOUSE,APARTMENT,OFFICE,ROUNDABOUT,CROSSING
            switch (segId)
            {
            case 0:
                occ = new Occurrence();
                occ->description = segment;
                segId++;
                break;
            case 1:
                if(segment == "HIGH"){
                    occ->priority == HIGH;
                }else if(segment == "MEDIUM"){
                    occ->priority == MEDIUM;
                }else if(segment == "LOW"){
                    occ->priority == LOW;
                }else{
                    occ->priority == NON;
                }
                segId++;
                break;
            case 2:
                occ->place |= (segment == "1"); //coloca o bit menos sig. no priority;
                occ->place = occ->place << 1; // desloca pra esquerda
                segId++;
                break;
            case 3:
                occ->place |= (segment == "1"); //coloca o bit menos sig. no priority;
                occ->place = occ->place << 1; // desloca pra esquerda
                segId++;
                break;
            case 4:
                occ->place |= (segment == "1"); //coloca o bit menos sig. no priority;
                occ->place = occ->place << 1; // desloca pra esquerda
                segId++;
                break;
            case 5:
                occ->place |= (segment == "1"); //coloca o bit menos sig. no priority;
                occ->place = occ->place << 1; // desloca pra esquerda
                segId++;
                break;
            case 6:
                occ->place |= (segment == "1"); //coloca o bit menos sig. no priority;
                occ->place = occ->place << 1; // desloca pra esquerda
                addNode(occ);
                delete occ;
                occ = nullptr;
                segId = 0;
                break;
            }
        }
        myfile.close();
        return true;
    }else{
        return false;
    }
}
