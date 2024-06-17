#include<stdio.h>
#include<cstdlib>
#include<random>

struct List{
    int size;
    int first;
    int last;
    int elements;
    float* memPtr;
};

void genList(List* list, unsigned int size){
    list->size = size;
    list->memPtr = (float*) malloc(sizeof(float) * size);
    list->first = 0;
    list->last = -1;
    list->elements = 0;
}

void addList(List* list, float value){
    //rollback
    if(list->last >= list->size-1){
        list->last = -1;
    }
    list->last++;
    list->memPtr[list->last] = value;
    list->elements++;
}

float remList(List* list){
    float data = list->memPtr[list->first];
    if(list->first >= list->size -1){
        list->first = 0;
    }
    list->first ++;
    list->elements--;
    return data;
}

int main(){
    List* myList = (List*) malloc(sizeof(List));

    genList(myList, 100);

    addList(myList, 2);
    addList(myList, 3);
    addList(myList, 5);

    printf("%f, ", remList(myList));
    printf("%f, ", remList(myList));
    printf("%f, ", remList(myList));
}