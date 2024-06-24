#ifndef DECISIONTREE_HPP
#define DECISIONTREE_HPP

#include <iostream>

struct TreeNode {
    int attributeIndex;  
    int decision;         
    struct TreeNode *rightChild;
    struct TreeNode *leftChild;  
};

class DecisionTree{
    public:
    //Construtor
    DecisionTree();

    void treeFree(TreeNode *newNode) ;
    int predict(TreeNode *root, int *instance);//mudar os atributos: tempo(peso) e 

    private:
    TreeNode* createNode(int attributeIndex, int decision);
    TreeNode* root;
};
#endif