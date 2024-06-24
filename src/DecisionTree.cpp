#include <stdio.h>
#include <stdlib.h>
#include "DecisionTree.hpp"
#include "Dijkstra.hpp"

DecisionTree::DecisionTree() {
    root = nullptr;
//consertar isso
}

TreeNode* DecisionTree::createNode(int attributeIndex, int decision) {
    TreeNode *newNode = (TreeNode*)malloc(sizeof(TreeNode));
    if (newNode == NULL) {
        perror("Erro, sem memória");
        exit(EXIT_FAILURE);
    }
    newNode->attributeIndex = attributeIndex;
    newNode->decision = decision;
    newNode->leftChild = NULL;
    newNode->rightChild = NULL;
    return newNode;
}

// Liberando memória
void DecisionTree::treeFree(TreeNode *newNode) {
    if (newNode != NULL) {
        treeFree(newNode->leftChild);
        treeFree(newNode->rightChild);
        free(newNode);
    }
}

// Previsão
int DecisionTree::predict(TreeNode *root, int *instance) {
    TreeNode *current = root;
    while (current->decision == -1) {
        if (instance[current->attributeIndex] == 0) {
            current = current->leftChild;
        } else {
            current = current->rightChild;
        }
    }
    return current->decision;
}