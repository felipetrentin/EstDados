#ifndef AVL_TREE_HPP
#include "AvlTree.hpp"
#endif

template <typename T>
AVLTree<T>::AVLTree() : 
    root(nullptr) 
    {

    }

template <typename T>
AVLTree<T>::~AVLTree() {
    deleteTree(root);
}

template <typename T>
void AVLTree<T>::insert(const T& val, int key) {
    root = insert(root, val, key);
}

template <typename T>
void AVLTree<T>::remove(int key) {
    root = remove(root, key);
}

template <typename T>
typename AVLTree<T>::Node* AVLTree<T>::insert(Node* node, const T& val, int key) {
    // se o nó estiver vazio, podemos adicionar aí
    if (node == nullptr)
        return new Node(key, val);

    //aqui tratamos como uma arvore binaria normal, adicionando menores a esquerda e maiores a direita
    if (key < node->key)
        node->left = insert(node->left, val, key);
    else if (key > node->key)
        node->right = insert(node->right, val, key);
    else
        return node;

    
    node->height = 1 + std::max(height(node->left), height(node->right));
    int balance = getBalance(node);

    if (balance > 1 && key < node->left->key)
        return rightRotate(node);
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

template <typename T>
typename AVLTree<T>::Node* AVLTree<T>::remove(Node* node, int key) {
    if (node == nullptr)
        //não achou
        return node;
    if (key < node->key)
        //pega a subarvore esquerda
        node->left = remove(node->left, key);
    else if (key > node->key)
        //pega a subarvore direita
        node->right = remove(node->right, key);
    else {
        // está no nó certo

        if ((node->left == nullptr) || (node->right == nullptr)) {
            // ta faltando um dos 2

            //pega o nó que tiver
            Node* temp = node->left ? node->left : node->right;

            if (temp == nullptr) {
                //ta faltando os 2
                temp = node;
                node = nullptr;
            } else
                //ta faltando um só
                *node = *temp;
            delete temp;
        } else {
            //tem dois filhos
            Node* temp = minValueNode(node->right);
            node->key = temp->key;
            node->right = remove(node->right, temp->key);
        }
    }

    if (node == nullptr)
        return node;

    node->height = 1 + std::max(height(node->left), height(node->right));
    int balance = getBalance(node);

    if (balance > 1 && getBalance(node->left) >= 0)
        return rightRotate(node);
    if (balance > 1 && getBalance(node->left) < 0) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && getBalance(node->right) <= 0)
        return leftRotate(node);
    if (balance < -1 && getBalance(node->right) > 0) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

template <typename T>
typename AVLTree<T>::Node* AVLTree<T>::minValueNode(Node* node) {
    Node* current = node;
    while (current->left != nullptr)
        current = current->left;
    return current;
}

template <typename T>
int AVLTree<T>::height(Node* node) {
    if (node == nullptr)
        return 0;
    return node->height;
}

template <typename T>
int AVLTree<T>::getBalance(Node* node) {
    if (node == nullptr)
        return 0;
    return height(node->left) - height(node->right);
}

template <typename T>
typename AVLTree<T>::Node* AVLTree<T>::rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = std::max(height(y->left), height(y->right)) + 1;
    x->height = std::max(height(x->left), height(x->right)) + 1;

    return x;
}

template <typename T>
typename AVLTree<T>::Node* AVLTree<T>::leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = std::max(height(x->left), height(x->right)) + 1;
    y->height = std::max(height(y->left), height(y->right)) + 1;

    return y;
}

template <typename T>
void AVLTree<T>::deleteTree(Node* node) {
    if (node != nullptr) {
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }
}

template <typename T>
T* AVLTree<T>::get(int key){
    
}

template <typename T>
typename AVLTree<T>::Node* AVLTree<T>::find(Node* node, int key){
    return nullptr;
}