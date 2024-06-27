#include "VehicleManager.hpp"

#define vagas 5

VehichleManager::VehichleManager(Graph* graph, sf::Clock* gameClock) :
    numOfUnits_(0),
    graph_(graph),
    automobiles(),
    gameClock(gameClock)
{
    
}

Vehicle* VehichleManager::getVehicle(int id){
    return automobiles.get(id);
}



// faz a interpolação entre a origem e destino no grafo, de acordo com o tempo passado.
sf::Vector2f VehichleManager::getVehiclePos(Vehicle* ve){

    if (ve == nullptr){
        return sf::Vector2f(0, 0);
    }
    Vertice* startVert = graph_->getVertice(ve->source);
    int distance = graph_->getWeight(ve->source, ve->destination);
    if(ve->traveling && distance > 0){
        Vertice* endVert = graph_->getVertice(ve->destination);
        float dt = gameClock->getElapsedTime().asSeconds() - ve->travelStartTime;

        /*
        v = s/t
        s_andado = v_carro t_na_estrada
        s_andado / s_total = t
        */
        float t = (ve->speed * dt)/distance;
        if (t > 1.0f){
            t = 1.0f;
        }
        return lerp(
            sf::Vector2f(startVert->posX, startVert->posY), 
            sf::Vector2f(endVert->posX, endVert->posY),
            t
        );
    }else{
        return sf::Vector2f(startVert->posX, startVert->posY);
    }
    
}

// desenha os menus de spawn de veículo e tmb de 
void VehichleManager::vehiclesDebugMenu(){

    // spawner
    if(ImGui::CollapsingHeader("Vehicles spawn")){
        ImGui::InputInt("id", &spawnerId);
        ImGui::InputInt("node", &spawnNode);

        if(ImGui::Button("spawn")){
            spawnVehichle(spawnerId, spawnNode);
            spawnerId ++;
        }
    }

    if(ImGui::CollapsingHeader("Trajectory")){
        ImGui::InputInt("source car id", &moverSrcId);
        ImGui::InputInt("destination", &moverDestId);
        
        if(ImGui::Button("MOVE!")){
            setMovement(getVehicle(moverSrcId), moverDestId);
        }
    }

    // listings of vehicles
    if(ImGui::CollapsingHeader("Vehicles list")){
        // variavel pra editar o numero de veículos que temos
        //de preferencia esse valor não será editado por humanos
        ImGui::InputInt("n Vehicles", &numOfUnits_);

        //para cada veiculo que temos
        for(int i = 0; i<numOfUnits_; i++){
            Vehicle* ve = getVehicle(i);
            char nodeName[32];
            sprintf(nodeName, "vehichle id:%d @ %p", i, ve);
            if(ImGui::TreeNode(nodeName)){
                if(ve == nullptr){
                    //se o veiculo não existe
                    ImGui::TextColored(ImVec4(1.0f, 0.0f, 0.2f, 1.0f), "o carro é nulo!");
                }else{
                    //valores específicos do carro
                    ImGui::Checkbox("traveling", &(ve->traveling));
                    ImGui::InputInt("source", &(ve->source));
                    ImGui::InputInt("destination", &(ve->destination));
                    ImGui::InputInt("speed", &(ve->speed));
                    ImGui::InputInt("capacity", &(ve->capacity));
                    ImGui::Text("startTime %.2f", ve->travelStartTime);
                }
                ImGui::TreePop();
            }
        }
    }
}

// number of instantiatd cars
int VehichleManager::getNumUnits(){
    return numOfUnits_;
}

// spawning the vehicles
void VehichleManager::spawnVehichle(int vehichleID, int nodeID){
    numOfUnits_ ++;
    Vehicle ve;
    ve.capacity = 100;
    ve.speed = 1;
    ve.typemask= 0;
    ve.source = nodeID;
    ve.traveling = false;
    automobiles.insert(ve, vehichleID);
    graph_->setVeichle(nodeID, &ve);
}

//destroying the vehicles
void VehicleManager::destroyVehicle(int vehicleID, int nodeID){
    numOfUnits_ --;
    automobiles.remove(vehicleID);
    graph.setVeichle(vehicleID, nullptr);
}

// updates all cars
void VehichleManager::update(){
    for(int i = 0; i<numOfUnits_; i++){
        Vehicle* curr = automobiles.get(i);
        if(arrived(curr)){
            //chegou no destino, logo:
            //mudamos a posse no gráfico
            graph_->setVeichle(curr->source, nullptr);
            graph_->setVeichle(curr->destination, curr);

            //atualizamos a posição no grafico
            curr->source = curr->destination;
            curr->traveling = false;

            //se nó atual tem um carro e se é do tipo que estaciona o carro
            graph_->getVeichle(destination);
            switch (destination->type){ //pensei em pegar o nodetype para o switch case
            /*Fiquei na dúvida de como faria pra instanciar pilhas, filas e arrays pra tantos nós ao mesmo tempo
            Provavelmente vai precisar usar ponteiro algumas vezes. Não consegui implementar direito*/
                case 1:
                    //HOSPITAL - fila
                    QueueVehicle hospQueue = new QueueVehicle(vagas); //instancia estrutura
                    //verificação se a estrutura está vazia
                     if (hospQueue.isFull()){ 
                        //mostra um aviso que não pode mais colocar carro
                    }
                    //não está vazia:
                    else{
                        //quero inserir um carro na estrutura
                        if{
                        //pego veículo do vertice
                        hospQueue.enqueue(curr);//coloco ele na estrutura
                        //removo veiculo do vertice 
                        //removo veiculo da arvore avl 
                        }
                        //quero tirar um carro da estrutura
                        //verifica se n ta vazia
                        else{
                            if(hospQueue.isEmpty()){
                                //fala que não dá pra remover por estar vazia
                            }
                            else{
                                //adiciona na arvore
                                //adiciona no grafo
                                //remove da estrutura
                            }
                            //vertice tem o veiculo -> manda o veículo embora pra atender o chamado
                        }
                    } 
                    break;                

                case 2:
                    //POLICE - pilha
                    //instancia estrutura
                    //verificação se a estrutura está vazia
                    if (polStack.isFull()){
                        //mostra um aviso que não pode mais colocar carro
                    }
                    //não está vazia:
                    else{
                        //quero inserir um carro na estrutura
                        if{
                        //pego veículo do vertice
                        //coloco ele na pilha
                        //removo veiculo do vertice
                        //removo veiculo da arvore
                        }
                        //quero tirar um carro da estrutura
                        //verifica se n ta vazia
                        else{
                            if(polStack.isEmpty){
                                //fala que não dá pra remover por estar vazia
                            }
                            else{
                                //adiciona na arvore
                                //adiciona no grafo
                                //remove da estrutura
                            }
                            //vertice tem o veiculo -> manda o veículo embora pra atender o chamado
                        }
                    } 
                    break;

                case 3:
                    //FIREBRIGADE - array - posso tirar qual eu quiser, quando eu quiser
                    Vehicle firebrig[vagas]//instancia estrutura - aqui pode ser um array
                    //verificação se a estrutura está vazia
                    if (){
                        //mostra um aviso que não pode mais colocar carro
                    }
                    //não está vazia:
                    else{
                        //quero inserir um carro na estrutura
                        if{
                        //pego veículo do vertice
                        //coloco ele na pilha
                        //removo veiculo do vertice
                        //removo veiculo da arvore
                        }
                        //quero tirar um carro da estrutura
                        //verifica se n ta vazia
                        else{
                            if(){
                                //fala que não dá pra remover por estar vazia
                            }
                            else{
                                //adiciona na arvore
                                //adiciona no grafo
                                //remove da estrutura
                            }
                            //vertice tem o veiculo -> manda o veículo embora pra atender o chamado
                        }
                    } 
                    break;
            };
        }
    }
}

bool VehichleManager::setMovement(Vehicle* ve, int dest){
    if(graph_->getWeight(ve->source, dest) > 0 &&
       graph_->getVeichle(dest) == nullptr
    ){
        ve->destination = dest;
        ve->travelStartTime = gameClock->getElapsedTime().asSeconds();
        ve->traveling = true;
        return true;
    }else{
        return false;
    }
}

bool VehichleManager::arrived(Vehicle* ve){
    if (ve == nullptr){
        return false;
    }
    Vertice* startVert = graph_->getVertice(ve->source);
    if(ve->traveling){
        Vertice* endVert = graph_->getVertice(ve->destination);
        float dt = gameClock->getElapsedTime().asSeconds() - ve->travelStartTime;

        return (ve->speed * dt) > graph_->getWeight(ve->source, ve->destination);
    }
    return false;
}


VehichleManager::~VehichleManager(){
    automobiles.~AVLTree(); //automobiles é a arvore avl
}

// linear interpolation
const sf::Vector2f VehichleManager::lerp(sf::Vector2f a, sf::Vector2f b, float t){
    return sf::Vector2f(
        (1-t) * a.x + t * b.x ,
        (1-t) * a.y + t * b.y
    );
}

