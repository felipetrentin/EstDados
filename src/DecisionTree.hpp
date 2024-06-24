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

    void treeFree(TreeNode *node) ;
    int predict(TreeNode *root, int *sample);

    private:
    TreeNode* createNode(int attributeIndex, int decision);
};
#endif