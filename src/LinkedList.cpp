#include "LinkedList.hpp"

// Construtor
LinkedList::LinkedList() {
    head = nullptr; // Inicializa a lista como vazia
}

// Destrutor
LinkedList::~LinkedList() {
    freeMemory();
}

// Método para criar um novo nó
Node* LinkedList::createNode(int value) {
    Node* newNode = new Node;
    newNode->value = value;
    newNode->next = nullptr;
    return newNode;
}

// Método para imprimir a lista
void LinkedList::printList() const {
    Node* aux = head;
    int n = 0;
    while (aux != nullptr) {
        std::cout << aux->value << " - ";
        aux = aux->next;
        n++;
    }
    std::cout << std::endl << "O total de itens da lista foi de " << n << std::endl;
}

// Método para adicionar um elemento no final da lista
void LinkedList::addEnd(int value) {
    std::cout << "\nLISTA ANTERIOR: ";
    printList();

    Node* newNode = createNode(value);

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

    std::cout << "\nInserindo o elemento " << value << std::endl;
    std::cout << "NOVA LISTA: ";
    printList();
}

// Método para remover um nó com valor específico
void LinkedList::removeNode(int value) {
    std::cout << "\nLISTA ANTERIOR: ";
    printList();

    // Caso a lista esteja vazia
    if (head == nullptr) {
        std::cout << "Elemento não encontrado" << std::endl;
        return;
    }

    // Caso o nó a ser removido seja o primeiro
    if (head->value == value) {
        Node* temp = head;
        head = head->next;
        std::cout << "Elemento removido foi " << temp->value << std::endl;
        delete temp;
    } else {
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
            std::cout << "Elemento removido foi " << aux->value << std::endl;
            delete aux;
        } else {
            std::cout << "Elemento não encontrado" << std::endl;
        }
    }

    std::cout << "NOVA LISTA: ";
    printList();
}

// Método para liberar a memória alocada pela lista
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
