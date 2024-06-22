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
void LinkedList::addEnd(int value) {
    Node* newNode = createNode(value); //cria um nó com o novo valor

    // Caso a lista esteja vazia, o novo nó se torna o primeiro
    if (head == nullptr) {
        head = newNode;
    } else {
        // Encontra o último nó
        Node* aux = head;
        while (aux->next != nullptr) {
            aux = aux->next;
        }
        // Adiciona o novo nó no final
        aux->next = newNode;
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
