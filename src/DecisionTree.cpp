#include <stdio.h>
#include <stdlib.h>
#include "DecisionTree.hpp"

DecisionTree::DecisionTree() {

}

TreeNode* DecisionTree::createNode(int attributeIndex, int decision) {
    TreeNode *node = (TreeNode*)malloc(sizeof(TreeNode));
    if (node == NULL) {
        perror("Erro, sem memória");
        exit(EXIT_FAILURE);
    }
    node->attributeIndex = attributeIndex;
    node->decision = decision;
    node->leftChild = NULL;
    node->rightChild = NULL;
    return node;
}

// Liberando memória
void DecisionTree::treeFree(TreeNode *node) {
    if (node != NULL) {
        treeFree(node->leftChild);
        treeFree(node->rightChild);
        free(node);
    }
}

// Previsão
int DecisionTree::predict(TreeNode *root, int *sample) {
    TreeNode *current = root;
    while (current->decision == -1) {
        if (sample[current->attributeIndex] == 0) {
            current = current->leftChild;
        } else {
            current = current->rightChild;
        }
    }
    return current->decision;
}