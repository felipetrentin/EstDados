#include<stdio.h>
#include<cstdlib>
#include<random>

int fibonacci_rec(int i){
    if (i <= 0){
        return 1;
    }
    return fibonacci_rec(i-1) + fibonacci_rec(i-2);
}

int fibonacci_iter(int i){
    int lastResult = 0;
    int thisResult = 1;
    int nextTerm = thisResult;
    for(int j = 0; j<i; j++){
        lastResult = thisResult;
        thisResult = nextTerm;
        nextTerm = thisResult + lastResult;
    }
    return thisResult;
}

int arraySum_iter(int* array, int n){
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum = sum + array[i];
    }
    return sum;
}

int arraySum_rec(int* array, int n){
    if (n <= 0) 
        return 0; 
    return (arraySum_rec(array, n - 1) + array[n - 1]); 
}


int main(){
    for(int i = 0; i < 10; i++){
        printf("%d  ", fibonacci_iter(i));
        printf("%d\n", fibonacci_rec(i));
    }

    int arr[] = {10,20,30,40,50};
    printf("%d  ", arraySum_iter(arr, sizeof(arr) / sizeof(arr[0])));
    printf("%d\n", arraySum_rec(arr, sizeof(arr) / sizeof(arr[0])));
}