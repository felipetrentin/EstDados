#ifndef BINSEARCHTREE_HPP
#define BINSEARCHTREE_HPP

#include "types.hpp"

class BinSearchTree
{
public:
    struct Node{
        Vehicle ve;
        int id;
        Node* smallNode;
        Node* bigNode;
    };
    BinSearchTree();
    ~BinSearchTree();
    void addNode(Vehicle ve, int id);
    void removeNode(int id);
    Node* getNode(int id);

private:
    Node* firstNode;
    Node* recursiveInsert(Node* node, int id);
    Node* createNode();
};

#endif