
#include "Application.hpp"

#define ncasas 20

Application::Application() : 
    //lista de inicialização do construtor
    settings(0, 0, 8, 1, 1, sf::ContextSettings::Default,false),
    window_(sf::VideoMode(1920, 1080), "Meanwhile in Baltimore: [compiled: " __DATE__ " " __TIME__ "]", sf::Style::Default, settings),
    map_(ncasas),
    view1(sf::FloatRect(0.f, 0.f, window_.getSize().x, window_.getSize().y)),
    vManager_(&map_, &gameClock)
{
    window_.setVerticalSyncEnabled(true);
    font_.loadFromFile("/usr/share/fonts/truetype/freefont/FreeSans.ttf");
    
}

void Application::drawAssistant(){
    ImGui::Begin("J.J Junior [Assistente]", nullptr, ImGuiWindowFlags_NoResize);
    ImGui::End();
}

void Application::drawRoad(sf::Vector2f from, sf::Vector2f to){
    sf::Vertex line[] =
    {
        from,
        to,
    };
    window_.draw(line, 2, sf::Lines);
}

void Application::drawInfo(){
    ImGui::Begin("Informações", nullptr, ImGuiWindowFlags_NoMove);

    for(int i = 0; i<IM_ARRAYSIZE(dtHist_); i++){
        if(i == IM_ARRAYSIZE(dtHist_) - 1){
            dtHist_[i] = dt_.asMicroseconds();
        }else{
            dtHist_[i] = dtHist_[i + 1];
        }
    }
    

    ImGui::SetWindowPos(ImVec2(0, 0));

    ImGui::Text("time: %7.2fs", gameClock.getElapsedTime().asSeconds());
    //info da câmera
    if(ImGui::CollapsingHeader("Câmera")){
        ImGui::Text("x position: %d", view1.getCenter().x);
        ImGui::Text("y position: %d", view1.getCenter().y);
    }
    //gráfico de performance com média
    if(ImGui::CollapsingHeader("Performance")){
        ImGui::Text("dt: %lldus", dt_.asMicroseconds());
        
        float average = 0.0f;
        for (int n = 0; n < IM_ARRAYSIZE(dtHist_); n++)
            average += dtHist_[n];
        average /= (float)IM_ARRAYSIZE(dtHist_);
        char overlay[32];
        sprintf(overlay, "avg %7.2fus", average);
        ImGui::PlotLines("", dtHist_, IM_ARRAYSIZE(dtHist_), 1, overlay, 3000.0f, 50000.0f, ImVec2(0,120));
    }

    //mostra as posições dos carros no grafo
    if(ImGui::CollapsingHeader("graphCars")){
        for(int i=0; i<ncasas; i++){
            Vertice* vertice = map_.getVertice(i);

            if(vertice != nullptr){
                if(vertice->vehicle != nullptr){
                    ImGui::Text("nó %d (%s) tem carro %p", i, vertice->name.c_str(), vertice->vehicle);
                }else{
                    ImGui::TextColored(ImVec4(1.0f, 0.3f, 0.0f, 1.0f), "nó %d (%s) vazio", i, vertice->name.c_str());
                }
            }
        }
    }

    vManager_.vehiclesDebugMenu();
    ImGui::End();
}

void Application::draw(){
    
    drawInfo();

    drawAssistant();

    sf::CircleShape shape(20.f);
    shape.setFillColor(sf::Color::Green);
    shape.setOutlineColor(sf::Color::White);
    shape.setOutlineThickness(2.0f);

    window_.clear(sf::Color::Black);
    window_.setView(view1);

    for(int i=0; i<ncasas; i++){
        Vertice* vertice = map_.getVertice(i);
        if(vertice != nullptr){
            sf::Text label(vertice->name, font_, 20);
            label.setPosition(vertice->posX+40, vertice->posY-15);
            for(int j=0; j<ncasas; j++){
                if(map_.getWeight(i, j) > 0){
                    Vertice* dstVert = map_.getVertice(j);
                    Application::drawRoad(
                        sf::Vector2f(vertice->posX+20, vertice->posY+20), 
                        sf::Vector2f(dstVert->posX+20, dstVert->posY+20)
                    );
                }
            }
            shape.setFillColor(typeColors[vertice->type]);
            shape.setPosition(vertice->posX, vertice->posY);
            window_.draw(shape);
            window_.draw(label);
        }
    }
    
    sf::CircleShape car(10.f);
    car.setFillColor(sf::Color::Transparent);
    car.setOutlineColor(sf::Color(255,100,255,255));
    car.setOutlineThickness(2.0f);

    for(int k=0; k<vManager_.getNumUnits(); k++){
        car.setPosition(vManager_.getVehiclePos(vManager_.getVehicle(k)));
        window_.draw(car);
    }
    

    ImGui::ShowDemoWindow();

    ImGui::SFML::Render(window_);
    window_.display();
}

bool Application::loadGraph(std::string path){

    rapidxml::file<> xmlFile(path.c_str()); // Default template is char
    rapidxml::xml_document<> doc;
    doc.parse<0>(xmlFile.data());

    rapidxml::xml_node<> *city = doc.first_node("city");
    if(city == nullptr){
        return false;
    }
    rapidxml::xml_node<> *nodesNode = city->first_node("nodes");
    rapidxml::xml_node<> *edgesNode = city->first_node("edges");

    if(nodesNode == nullptr){
        return false;
    }
    if(edgesNode == nullptr){
        return false;
    }

    for (rapidxml::xml_node<> *node = nodesNode->first_node("node"); node != nullptr; node = node->next_sibling()) {
        map_.setVertice(
            std::stoi(node->first_attribute("id")->value()),
            std::stoi(node->first_attribute("x")->value()),
            std::stoi(node->first_attribute("y")->value()),
            node->first_attribute("name")->value(),
            std::stoi(node->first_attribute("type")->value())
        );
    }
    
    for (rapidxml::xml_node<> *edge = edgesNode->first_node("edge"); edge != nullptr; edge = edge->next_sibling()) {
        map_.setEdges(
            std::stoi(edge->first_attribute("from")->value()), 
            std::stoi(edge->first_attribute("to")->value()), 
            std::stoi(edge->first_attribute("distance")->value())
        );
    }
    return true;
}

void Application::run() {

    // LOAD GRAPH
    if(!ImGui::SFML::Init(window_)){
        printf("\nError initialising SFML\n");
    }

    if(!loadGraph("map.xml")){
        printf("\nERROR LOADING MAP!\n");
    }

    gameClock.restart();

    while(window_.isOpen()) {
        sf::Event event;
        
        while (window_.pollEvent(event)) {
            ImGui::SFML::ProcessEvent(event);
            if (event.type == sf::Event::Closed) {
                window_.close();
            }
        }

        if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Right) && window_.hasFocus()){
            if(!scrolling){
                scrolling = true;
                scrollPos_ = sf::Mouse::getPosition();
            }else{
                sf::Vector2i mousepos = sf::Mouse::getPosition();
                view1.move(sf::Vector2f(
                    (mousepos - scrollPos_).x, 
                    (mousepos - scrollPos_).y
                ));
                sf::Mouse::setPosition(scrollPos_);
            }
        }else{
            scrolling = false;
        }
        dt_ = deltaClock.restart();
        ImGui::SFML::Update(window_, dt_);
        milisElapsedTick_ += dt_.asMilliseconds();
        if(milisElapsedTick_ >= 100){
            milisElapsedTick_ = 0;
            //game tick update
            vManager_.update();
        }

        draw();

    }

    ImGui::SFML::Shutdown();
}
