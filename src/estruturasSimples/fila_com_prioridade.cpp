#include<stdio.h>
#include<cstdlib>
#include<random>

struct node{
    int content;
    int priority;
    node* nextNode;
};

void addNode(node* firstElement, int priority, int value){
    node* currElement = firstElement;
    //vai para o ultimo elemento
    while(currElement->nextNode != nullptr && currElement->priority > priority){
        currElement = currElement->nextNode;
    }
    node* newNode = (struct node*) malloc(sizeof(struct node*));
    newNode->priority = priority;
    newNode->content = value;
    if(currElement->priority <= priority){
        newNode->nextNode = currElement->nextNode;
        currElement->nextNode = newNode;
    }else{
        currElement->nextNode = newNode;
    }
}

node* findNode(node* firstElement, unsigned int id){
    node* currElement = firstElement;
    for(unsigned int i = 0; (i<id); i++){
        currElement = currElement->nextNode;
    }
    return currElement;
}

void remNode(node* firstElement, unsigned int index){
    node* currNode = findNode(firstElement, index - 1);
    node* oldNode = currNode->nextNode;
    currNode->nextNode = currNode->nextNode->nextNode;
    free(oldNode);
}


int getNode(node* firstElement, unsigned int index){
    return findNode(firstElement, index)->content;
}

void setNode(node* firstElement, int index, int value){
    findNode(firstElement, index)->content = value;
}

unsigned int countNodes(node* firstElement){
    node* currElement = firstElement;
    //vai para o ultimo elemento
    int i=1;
    while(currElement->nextNode != nullptr){
        currElement = currElement->nextNode;
        i++;
    }
    return i;
}

void showList(node* firstElement){
    node* currElement = firstElement;
    //vai para o ultimo elemento
    int i=0;
    while(currElement != nullptr){
        printf("valor: %d Prioridade %d\n", currElement->content, currElement->priority);
        currElement = currElement->nextNode;
        i++;
    }
    printf("lista com %d elementos\n", i);
}

unsigned int findVal(node* firstElement, int value){
    node* currElement = firstElement;
    int i=0;
    while(currElement->nextNode != nullptr && currElement->content != value){
        currElement = currElement->nextNode;
        i++;
    }
    return i;
}

int main(){
    struct node* myNodeTree = (struct node*) malloc(sizeof(struct node*));

    for(int j=0; j<19; j++){
        addNode(myNodeTree, j, random()%100);
    }

    showList(myNodeTree);
    addNode(myNodeTree, 500, 10101);
    addNode(myNodeTree, 10, 20000);
    showList(myNodeTree);
    return 0;
}