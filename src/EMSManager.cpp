/*
A ideia é cortar um pedaço do dataset para pegar algumas ocorrências
Nós pegamos o dataset cortado e, a partir das ocorrências dele, criamos uma lista circular para tornar esse evento randômico. 
Dessa forma, teremos uma função sortear, que sorteia um número aleatório e um ponteiro que vai da cabeça e conta até o numero que 
foi sorteado, como uma roleta. 
O valor então é removido da lista circular e é inserido na fila com prioridade. Dependendo da prioridade do evento ele precisa ser
atendido em maior ou menor tempo, em que a prioridade é dada de forma decrescente
*/

#include "EMSManager.hpp"

EMSManager::EMSManager(int lives) :
    lifes(lives)
{
    randomEvents.loadCSV("content/datasetReduzido.csv");
}

//updates acontecem cad
void EMSManager::update(){
    //abaixar um em tudo
    for(int i = 0; i<currentEvents.countNodes(); i++){
        PriorityList::Node* current = currentEvents.findNode(i);
        current->priority --;
        if(current->priority <= 0){
            //ih ala ele perdeu!
            currentEvents.remNode(i);
            lifes--;
        }
    }
}

int EMSManager::getLifes(){
    return lifes;
}

void EMSManager::showListOccourances(){
    ImGui::Begin("EMS");
    for(int i = 0; i<currentEvents.countNodes(); i++){
        PriorityList::Node* n = currentEvents.findNode(i);
        ImGui::Text("uma %s em %d de prioridade %d", n->occurrence.description.c_str(), n->occurrence.place, n->priority);
    }
    ImGui::End();
}

void EMSManager::drawOccourence(){
    Occurrence* oc = &(randomEvents.chooseOne(5)->occurrence);
    if(oc != nullptr){
        currentEvents.addNode(oc);
    }
    
}