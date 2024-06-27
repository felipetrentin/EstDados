
///Teríamos problema com remoção se usasse fila;
#include "PriorityList.hpp"

PriorityList::PriorityList() : firstElement(nullptr) {} //construtor e inicializa o elemento primeiro (como se fosse o head) como ponteiro nulo

PriorityList::~PriorityList() {
    Node* currElement = firstElement;
    while (currElement != nullptr) {
        Node* temp = currElement;
        currElement = currElement->nextNode;
        delete temp;
    }
} //destrutor

//métodos
int PriorityList::getPriority(Occurrence* oc){
    return oc->priority;
} //pega a prioridade da struct occurrence e retorna o valor dela;

void PriorityList::addNode(Occurrence *oc){
    Node* newElem = new Node(*oc, oc->priority);
    if(firstElement != nullptr){
        if(firstElement->priority > newElem->priority){
            newElem->nextNode = firstElement;
            firstElement = newElem;
            return;
        }
        Node* aux = firstElement;
        while(aux->nextNode != nullptr && (aux->nextNode->priority < newElem->priority)){
            aux = aux->nextNode;
        }
        if(aux->nextNode == nullptr){
            aux->nextNode = newElem;
        }else{
            newElem->nextNode = aux->nextNode;
            aux->nextNode = newElem;
        }
    }else{
        firstElement = newElem;
    }
}//adiciona nó na ista com prioridade 

void PriorityList::remNode(int index){//remove o nó --> tem duas condições pra remover o nó;
    if (firstElement == nullptr) {
        return;
    }
    if(index == 0){
        Node* delNode = firstElement;
        firstElement = firstElement->nextNode;
        delete delNode;
        return;
    }
    Node* prevNode = findNode(index - 1);
    if (prevNode->nextNode == nullptr) {
        return; // Índice fora dos limites
    }
    if(prevNode->nextNode->nextNode == nullptr){
        delete prevNode->nextNode;
        return;
    }
    Node* oldNode = prevNode->nextNode;
    prevNode->nextNode = prevNode->nextNode->nextNode;
    delete oldNode;
}

PriorityList::Node* PriorityList::findNode(int index){
    Node* currElement = firstElement;
    for (int i = 0; i < index; ++i) {
        if (currElement == nullptr) {
            return nullptr; // Índice fora dos limites
        }
        currElement = currElement->nextNode;
    }
    return currElement;
}

int PriorityList::countNodes(){
    int i = 0;
    Node* aux = firstElement;
    while (aux != nullptr)
    {
        aux = aux->nextNode;
        i++;
    }
    return i;
    
}

/*
unsigned int PriorityList::countNodes() const{}//conta os nós e mantém uma quantidade fixa de nós... mesmo que essa não seja a função da lista com prioridade
unsigned int PriorityList::findVal(int value) const{}//verifica se a ocorrencia ja foi atendida
void PriorityList::showList() const{} //teoricamente mostraria na tela (?)
*/





/*Novo nó
Node* newNode(Occurrence oc, int priority) {
    Node* newNode = new Node;
    newNode->priority = priority;
    newNode->content = value;
    newNode->nextNode = nullptr;
    return newNode;
}

// Método para adicionar um nó na lista com base na prioridade
void PriorityList::addNode(int priority, int value) {
    Node* newNode = createNode(priority, value);

    if (firstElement == nullptr || firstElement->priority > priority) {
        newNode->nextNode = firstElement;
        firstElement = newNode;
    } else {
        Node* currElement = firstElement;
        while (currElement->nextNode != nullptr && currElement->nextNode->priority <= priority) {
            currElement = currElement->nextNode;
        }
        newNode->nextNode = currElement->nextNode;
        currElement->nextNode = newNode;
    }
}

// Método para encontrar um nó dado um índice
Node* PriorityList::findNode(unsigned int index) const {
    Node* currElement = firstElement;
    for (unsigned int i = 0; i < index; ++i) {
        if (currElement == nullptr) {
            return nullptr; // Índice fora dos limites
        }
        currElement = currElement->nextNode;
    }
    return currElement;
}

// Método para remover um nó dado um índice
void PriorityList::remNode(unsigned int index) {
    if (firstElement == nullptr) {
        return;
    }
    if (index == 0) {
        Node* oldNode = firstElement;
        firstElement = firstElement->nextNode;
        delete oldNode;
        return;
    }

    Node* currNode = findNode(index - 1);
    if (currNode == nullptr || currNode->nextNode == nullptr) {
        return; // Índice fora dos limites
    }
    Node* oldNode = currNode->nextNode;
    currNode->nextNode = currNode->nextNode->nextNode;
    delete oldNode;
}

// Método para obter o valor de um nó dado um índice
int PriorityList::getNode(unsigned int index) const {
    Node* foundNode = findNode(index);
    if (foundNode != nullptr) {
        return foundNode->content;
    }
    return -1; // Índice fora dos limites
}

// Método para definir o valor de um nó dado um índice
void PriorityList::setNode(unsigned int index, int value) {
    Node* foundNode = findNode(index);
    if (foundNode != nullptr) {
        foundNode->content = value;
    }
}

// Método para contar o número de nós na lista
unsigned int PriorityList::countNodes() const {
    Node* currElement = firstElement;
    unsigned int count = 0;
    while (currElement != nullptr) {
        currElement = currElement->nextNode;
        count++;
    }
    return count;
}

// Método para exibir a lista
void PriorityList::showList() const {
    Node* currElement = firstElement;
    int i = 0;
    while (currElement != nullptr) {
        std::cout << "Valor: " << currElement->content << " Prioridade: " << currElement->priority << std::endl;
        currElement = currElement->nextNode;
        i++;
    }
    std::cout << "Lista com " << i << " elementos" << std::endl;
}

// Método para encontrar um valor na lista e retornar seu índice
unsigned int PriorityList::findVal(int value) const {
    Node* currElement = firstElement;
    unsigned int i = 0;
    while (currElement != nullptr && currElement->content != value) {
        currElement = currElement->nextNode;
        i++;
    }
    if (currElement == nullptr) {
        return -1; // Valor não encontrado
    }
    return i;
}*/
 
