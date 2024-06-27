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
    //randomEvents.loadCSV("content/datasetReduzido.csv");
}

//updates acontecem cad
void EMSManager::update(){
    //abaixar um em tudo
    for(int i = 0; i<currentEvents.countNodes(); i++){
        PriorityList::Node* n = currentEvents.findNode(i);
        n->priority--;
    }
    //apagar mortos
    PriorityList::Node* elem = nullptr;
    bool repeat = false;
    elem = currentEvents.findNode(0);
    if(elem != nullptr){
        if(elem->priority <= 0){
            currentEvents.remNode(0);
            lifes --;
            repeat = true;
        }else{
            repeat = false;
        }
    }
    
    /*
    for(int i = 0; i<times; i++){
        PriorityList::Node* current = currentEvents.findNode(i - offset);
        if(current != nullptr){
            if(current->priority <= 0){
                //ih ala ele perdeu!
                currentEvents.remNode(i);
                lifes--;
                i++;
                offset++;
            }else{
                current->priority --;
            }
        }
    }
    */
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
    /*
    if(lifes <= 0){
        ImGui::Begin("você perdeu o jogo");
        ImGui::Text("você perdeu!!");
        ImGui::SetWindowSize(ImVec2(500, 500));
        ImGui::SetWindowPos(ImVec2(1000, 500));
        ImGui::End();
    }
    */
}

void EMSManager::drawOccourence(){
    Occurrence oc;//= (randomEvents.chooseOne(rand()%1000)->occurrence);
    oc.description = "aaa";
    oc.place = 10;
    oc.priority = rand()%10 + 3;
    currentEvents.addNode(&oc);
    
}