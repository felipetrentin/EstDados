#include<stdio.h>
#include<cstdlib>

struct Stack {
    int topval;
    int size;
    float *pElem;
};

void genStack(Stack* stack, int size){
    stack->size = size;
    stack->topval = -1;
    stack->pElem = (float*) malloc(sizeof(float) * size);
}

void addStack(Stack* stack, float value){
    if(stack->topval < stack->size - 1){
        stack->topval ++;
    }
    stack->pElem[stack->topval] = value;
}

float getStack(Stack* stack){
    float value = stack->pElem[stack->topval];
    if(stack->topval > 0){
        stack->topval --;
    }

    return value;
}

void permuteStacks(Stack* remetente, Stack* destinatario){
    addStack(destinatario, getStack(remetente));
}

int main(){
    struct Stack* mystack = (struct Stack*) malloc(sizeof(struct Stack*));
    int i=0;

    genStack(mystack, 100);

    for(i=0; i<100; i++){
        addStack(mystack, i);
    }

    struct Stack* myOtherStack = (struct Stack*) malloc(sizeof(struct Stack*));
    genStack(myOtherStack, 100);

    for(i=0; i<50; i++){
        permuteStacks(mystack, myOtherStack);
    }

    printf("\n\nmystack   -   myotherstack\n");
    for(i=0; i<100; i++){
        printf("%f - %f\n", getStack(mystack), getStack(myOtherStack));
    }
    return 0;
}