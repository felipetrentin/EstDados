#include <stdio.h>

unsigned int strCounter(char* word);
void order(int* array, unsigned int size);
void swap(int* a, int* b);
bool isOrdered(int* array, unsigned int size);

int main(){
    double mydouble = 10.5;
    int myint = 100;
    char mychar = 'a';

    double* myDoubPointer = &mydouble;
    int* myIntPointer = &myint;
    char* myCharPointer = &mychar;

    printf("valor do double diretamente %f\n", mydouble);
    printf("valor do int diretamente %d\n", myint);
    printf("valor do char diretamente %c\n", mychar);

    printf("endereço do double diretamente %p\n", &mydouble);
    printf("endereço do int diretamente %p\n", &myint);
    printf("endereço do char diretamente %p\n", &mychar);

    printf("valor do meu ponteiro double %p\n", myDoubPointer);
    printf("valor do meu ponteiro int %p\n", myIntPointer);
    printf("valor do meu ponteiro char %p\n", myCharPointer);

    printf("endereço do meu ponteiro double %p\n", &myDoubPointer);
    printf("endereço do meu ponteiro int %p\n", &myIntPointer);
    printf("endereço do meu ponteiro char %p\n", &myCharPointer);

    printf("valor armazenado no endereço do ponteiro double %f\n", *myDoubPointer);
    printf("valor armazenado no endereço do ponteiro int %d\n", *myIntPointer);
    printf("valor armazenado no endereço do ponteiro char %c\n", *myCharPointer);

    printf("tamanho do double %d bytes\n", sizeof(mydouble));
    printf("tamanho do int %d bytes\n", sizeof(myint));
    printf("tamanho do char %d bytes\n", sizeof(mychar));
    printf("tamanho do ponteiro do double %d bytes\n", sizeof(myDoubPointer));
    printf("tamanho do ponteiro do int %d bytes\n", sizeof(myint));
    printf("tamanho do ponteiro do char %d bytes\n", sizeof(mychar));

    //código do contador da string

    printf("\n\nAgora digite uma string\n> ");
    char palavra[100];
    scanf("%s", &palavra);

    printf("\nvc escreveu: %s\n", palavra);

    printf("essa palavra tem %d caracteres\n", strCounter(palavra));

    int arr[12] = {10, 4, 5, 7, 13, 21, 2, 44, 5, 5, 12, 3};
    char charArr[8] = "bom dia";
    int numCharArr[8];

    for(int i=0; i<8; i++){
        numCharArr[i] = charArr[i];
    }

    order(arr, 12);
    order(numCharArr, 12);

    printf("\n");

    for(int i=0; i<12; i++){
        printf("%d, ", arr[i]);
    }

    printf("\n\n");

    for(int i=0; i<12; i++){
        printf("%c, ", numCharArr[i]&0xff);
    }

    printf("\n");
    
    return 0;
}


unsigned int strCounter(char* word){
    unsigned int i = 0;
    while (*(word + i)!= '\0'){
        i++;
    }
    return i;
}

void swap(int* a, int* b){
    int swap = *a;
    *a = *b;
    *b = swap;
}

bool isOrdered(int* array, unsigned int size){
    for(int i=0; i<size-1; i++){
        if(array[i] > array[i+1]){
            return false;
        }
    }
    return true;
}

void order(int* array, unsigned int size){
    while(!isOrdered(array, size)){
        for(int i=0; i<size-1; i++){
            if(array[i] > array[i+1]){
                swap(array + i, (array + i + 1));
            }
        }
    }
}