#include "LinkedList.hpp"

// Construtor
LinkedList::LinkedList() {
    head = nullptr; // Inicializa a lista como vazia
}

// Destrutor
LinkedList::~LinkedList() {
    freeMemory();
}

// Método criar um novo nó
Node* LinkedList::createNode(int value) {
    Node* newNode = new Node;
    newNode->value = value;
    newNode->next = nullptr;
    return newNode;
}

/* Método Imprimir a lista
void LinkedList::printList() const {
    Node* aux = head;
    int n = 0;
    while (aux != nullptr) {
        std::cout << aux->value << " - ";
        aux = aux->next;
        n++;
    }
    std::cout << std::endl << "O total de itens da lista foi de " << n << std::endl;
}*/

// Método para adicionar um elemento no final da lista
void LinkedList::add(int value) {
    Node* newNode = createNode(value); //cria um nó com o novo valor

    // Caso a lista esteja vazia, o novo nó se torna o primeiro
    if (head == nullptr) {
        head = newNode;
    } else {
        // define o nó como o o proximo do ultimo elemento
        getLastElement()->next = newNode;
    }
}

// Método para remover um nó com valor específico
void LinkedList::removeNode(int value) {
    // Se a lista estiver vazia, não faz nada
    if (head == nullptr) {
        return;
    }

    // Caso o nó a ser removido seja o primeiro
    if (head->value == value) {
        Node* temp = head;
        head = head->next;
        delete temp;
    } else { 
        //se não for o primeiro
        Node* aux = head;
        Node* previous = nullptr;

        // Percorre a lista em busca do nó a ser removido
        while (aux != nullptr && aux->value != value) {
            previous = aux;
            aux = aux->next;
        }

        // Se o nó foi encontrado, remove-o
        if (aux != nullptr) {
            previous->next = aux->next;
            delete aux;
        } else {
            return; //elemento não encontrado
        }
    }
}

Node* LinkedList::getNode(int id){
    Node* current = head;
    for(int i=0; i<id; i++){
        if (current->next != nullptr){
            current = current->next;
        }else{
            return nullptr;
        }
    }
    return current;
}

int LinkedList::getSize(){
    Node* thisNode = head;
    int size = 0;
    while (thisNode != nullptr)
    {
        thisNode = thisNode->next;
        size++;
    }
    return size;
}

// Liberar a memória alocada pela lista
void LinkedList::freeMemory() {
    Node* current = head;
    Node* temp;

    while (current != nullptr) {
        temp = current;
        current = current->next;
        delete temp;
    }

    head = nullptr;
}
void LinkedList::addNext(Node* node, int value){
    if(node != nullptr){
        if(node->next == nullptr){
            //se este está no final da lista
            node->next = createNode(value);
        }else{
            //se estamos adicionando no meio
            Node* aux = node->next;
            node->next = createNode(value);
            node->next->next = aux;
        }
    }
}

Node* LinkedList::getLastElement(){
    Node* aux = head;
    if(aux != nullptr){
        while (aux->next != nullptr) {
            aux = aux->next;
        }
    }
    return aux;
}

void  LinkedList::copyLinked(LinkedList exemploDoFilho){
    freeMemory();
    Node* startNode = exemploDoFilho.getNode(0); //head do exemplo
    Node* danode = head; //head desse
    if(startNode != nullptr){
        //se a lista exemplo não for nula
        for(int i = 0; i < exemploDoFilho.getSize(); i++){
            addNext(danode, startNode->value);
            startNode = startNode->next;
            danode = danode->next;
        }
    }
}
