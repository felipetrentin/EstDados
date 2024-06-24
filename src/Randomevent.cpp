#include <stdio.h>
#include <stdlib.h>

/*A ideia é cortar um pedaço do dataset e separar um número específico de ocorrências pra cada fase. Só faremos a fase 1 por enquanto.
Na fase 1 a ideia seria ter x ocorrências.
Nós pegamos o dataset cortado e, a partir das ocorrências dele, criamos uma lista circular para tornar esse evento randômico. 
Dessa forma, teremos uma função sortear, que sorteia um número aleatório e um ponteiro que vai da cabeça e conta até o numero que 
foi sorteado, como uma roleta. 
O valor então é removido da lista circular e é inserido na fila com prioridade. Dependendo da prioridade do evento ele precisa ser
atendido em maior ou menor tempo, em que a prioridade é dada de forma decrescente*/

/*
void decreasePriority(PriorityQueue* pq){
    
    priority = &pq->priority;
    missed=0;
    if (priority == 0){
        pq.dequeue;
        missed +=;
    }
    Node* current = pq->first;
    while (current != NULL) {
        current->priority--;
        current = current->next;
    }

}
*/

