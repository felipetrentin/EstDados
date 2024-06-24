#include "BinSearchTree.hpp"

BinSearchTree::BinSearchTree()
{
    firstNode = nullptr;
}

void BinSearchTree::addNode(Vehicle ve, int id){
    if(firstNode == nullptr){
        firstNode = (Node*)malloc(sizeof(Node));
    }else{

    }
}
BinSearchTree::Node* BinSearchTree::createNode(){
    return (Node*)malloc(sizeof(Node));
}

BinSearchTree::Node* BinSearchTree::recursiveInsert(BinSearchTree::Node *node, int id)
{

}


BinSearchTree::Node *BinSearchTree::getNode(int id){

}