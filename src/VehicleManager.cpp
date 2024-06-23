#include "VehicleManager.hpp"

VehichleManager::VehichleManager(int numOfUnits, Graph* graph) :
    numOfUnits_(numOfUnits),
    graph_(graph)
{
    automobiles = (Vehicle*)malloc(sizeof(Vehicle) * numOfUnits_);
}

Vehicle* VehichleManager::getVehicle(int id){
    return &(automobiles[id]);
}

// faz a interpolação entre a origem e destino no grafo, de acordo com o tempo passado.
sf::Vector2f VehichleManager::getVehiclePos(Vehicle* ve, sf::Clock* gameClock){
    Vertice* startVert = graph_->getVertice(ve->source);
    if(ve->traveling){
        Vertice* endVert = graph_->getVertice(ve->destination);
        float dt = gameClock->getElapsedTime().asSeconds() - ve->travelStartTime;

        /*
        v = s/t
        s_andado = v_carro t_na_estrada
        s_andado / s_total = t
        */
        float t = (ve->speed * dt)/graph_->getWeight(ve->source, ve->destination);
        return lerp(
            sf::Vector2f(startVert->posX, startVert->posY), 
            sf::Vector2f(endVert->posX, endVert->posY),
            t
        );
    }else{
        return sf::Vector2f(startVert->posX, startVert->posY);
    }
    
}

void VehichleManager::vehiclesDebugMenu(){
    if(ImGui::CollapsingHeader("Vehicles spawn")){
        if(ImGui::Button("spawn")){
        }
    }
    if(ImGui::CollapsingHeader("Vehicles list")){
        for(int i = 0; i<numOfUnits_; i++){
            Vehicle* ve = getVehicle(i);
            char nodeName[32];
            sprintf(nodeName, "vehichle id:%d", i);
            if (ImGui::TreeNode(nodeName)){
                ImGui::Checkbox("traveling", &(ve->traveling));
                ImGui::InputInt("source", &(ve->source));
                ImGui::InputInt("destination", &(ve->destination));
                ImGui::InputInt("speed", &(ve->speed));
                ImGui::InputInt("capacity", &(ve->capacity));
                ImGui::TreePop();
            }
        }
    }
}

void VehichleManager::spawnVehichle(Vehicle* ve, int nodeID){
    ve->source = nodeID;
    ve->traveling = false;
    graph_->setVeichle(nodeID, ve);
}

void VehichleManager::updateVehicle(Vehicle* ve, sf::Clock* gameClock){

}

void VehichleManager::update(sf::Clock* gameClock){

}


VehichleManager::~VehichleManager(){
    free(automobiles);
}

const sf::Vector2f VehichleManager::lerp(sf::Vector2f a, sf::Vector2f b, float t){
    return sf::Vector2f(
        (1-t) * a.x + t * b.x ,
        (1-t) * a.y + t * b.y
    );
}

