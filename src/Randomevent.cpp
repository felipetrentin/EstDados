/*A ideia é cortar um pedaço do dataset para pegar algumas ocorrências
Nós pegamos o dataset cortado e, a partir das ocorrências dele, criamos uma lista circular para tornar esse evento randômico. 
Dessa forma, teremos uma função sortear, que sorteia um número aleatório e um ponteiro que vai da cabeça e conta até o numero que 
foi sorteado, como uma roleta. 
O valor então é removido da lista circular e é inserido na fila com prioridade. Dependendo da prioridade do evento ele precisa ser
atendido em maior ou menor tempo, em que a prioridade é dada de forma decrescente*/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h> //para usar a função Sleep WINDOWS em milissegundo
//#include <unistd.h>//para usar a função sleep LINUX em segundo

#include "PriorityList.cpp"
#include "PriorityList.hpp"

//função que vai ser rodada a cada segundo para reduzir as prioridades
void decreaseAll(PriorityList prioList){
    int priority = prioList.priority;
    int missed=0;
    if (priority == 0){
        prioList.remNode();
        missed ++;
    }
    Node* current = pq->first;
    while (current != NULL) {
        current->priority--;
        current = current->next;
    }
}

//função que vai ser iniciada quando a primeira ocorrencia aparecer 
void startDecreasing(){
    int tempoPartida = 300; //tempo de partida em segundos (5min arbitrário)
    int duration = 0;
    while(duration < tempoPartida){
        decreaseAll(PriorityList* pq); //diminui a prioridade dos elementos da fila
        Sleep(1000);  //pausa por um segundo
        //sleep(1); //pausa por um segundo no linux
        duration++;
    }
} //quando a duration chegar no tamanho do tempo de partida precisa escrever fim de jogo na tela


