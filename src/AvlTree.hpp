#ifndef AVL_TREE_HPP
#define AVL_TREE_HPP

#include <iostream>

template <typename T>
class AVLTree {
public:
    AVLTree();
    ~AVLTree();
    void insert(const T& val, int key);
    void remove(int key);
    T* get(int key);

private:
    struct Node {
        T val;
        int key;
        Node* left;
        Node* right;
        int height;
        Node(int k, const T& v) : key(k), val(v), left(nullptr), right(nullptr), height(1) {}
    };
    Node* root;
    Node* insert(Node* node, const T& val, int key);
    Node* remove(Node* node, int key);
    Node* find(Node* node, int key);
    Node* minValueNode(Node* node);
    int height(Node* node);
    int getBalance(Node* node);
    Node* rightRotate(Node* rNode);
    Node* leftRotate(Node* rNode);
    void deleteTree(Node* node);
};

#include "AvlTree.hxx"

#endif
