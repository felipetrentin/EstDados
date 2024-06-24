#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "CircularList.hpp"
#include "types.hpp"

CircularList::CircularList() : head(nullptr) {} //implementa o construtor, em que o sentinela de cabeça é nulo

CircularList::~CircularList(){
  Node* currElement = head->next;
  while (currElement !=head){
    Node* next = currElement->next;
    delete currElement;
    currElement = next;
  }
  delete head;
  head = nullptr;
} //destrutor

//métodos
Node* CircularList::newNode(Occurrence oc){
  Node* newElement = (Node*) malloc (sizeof (Node*)); //alocação dinâmica dos nós
  newElement->occurrence = oc; 
  newElement->next = nullptr;
  return newElement;
} //cria um nó com a ocorrência e um ponteiro nulo que vai deixar de ser nulo na adição

void CircularList::addNode(Occurrence oc, Node* head){
  Node *currElement = newNode(oc); //too many arguments 
  if (head==nullptr){
    head = currElement;
    currElement->next = head;
  }
  else{
    Node *temp = head;
    while (temp->next != head){
      temp = temp->next;
    }
    temp = currElement;
    currElement->next = head;
  }
} //adiciona os nós no fim da lista circular

void CircularList::removeNode(Occurrence oc, Node* head){
  Node* previous = nullptr;
  Node* currElement = head;

  do{
    if(currElement->occurrence == oc) { //ele não sabe comparar struct --> precisa comparar outros atributos
      if (previous == nullptr){
        previous->next = currElement->next;
        if (currElement == head){
          head = currElement->next;
        }
        delete currElement;
        return;
      }
      else{
        Node* last = head;
        while (last->next != head){
          last = last->next;
        } //aqui eu garanto que o last é o último da lista percorrendo a lista toda
        if (last == head){
          delete head;
          head = nullptr;
          return;
        } else{
          last->next = head->next;
          delete head;
          head = last;
          return; 
        }

      }
    }
  }while(currElement!=head);
} //remover um nó 

Node* CircularList::chooseOne(Node *head, int spin){
  
} //função que vai roletar e remover o nó roletado






