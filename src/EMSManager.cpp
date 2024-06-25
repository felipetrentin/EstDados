/*
A ideia é cortar um pedaço do dataset para pegar algumas ocorrências
Nós pegamos o dataset cortado e, a partir das ocorrências dele, criamos uma lista circular para tornar esse evento randômico. 
Dessa forma, teremos uma função sortear, que sorteia um número aleatório e um ponteiro que vai da cabeça e conta até o numero que 
foi sorteado, como uma roleta. 
O valor então é removido da lista circular e é inserido na fila com prioridade. Dependendo da prioridade do evento ele precisa ser
atendido em maior ou menor tempo, em que a prioridade é dada de forma decrescente
*/

#include "EMSManager.hpp"
#include <random>

EMSManager::EMSManager(int lives) :
    lifes(lives)
{

}

//updates acontecem cad
void EMSManager::update(){
    //abaixar um em tudo
    for(int i = 0; i<40; i++){
        PriorityList::Node* current = currentEvents.findNode(i);
        current->priority --;
        if(current->priority==0){
            //ih ala ele perdeu!
            currentEvents.remNode(i);
            lifes--;
        }
    }
}

void EMSManager::addOccourence(){
    random()%50;
    
}