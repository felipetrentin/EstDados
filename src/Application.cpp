
#include "Application.hpp"

#define ncasas 20

Application::Application() : 
    //lista de inicialização do construtor
    window_(sf::VideoMode(1920, 1080), "Meanwhile in Baltimore: [compiled: " __DATE__ " " __TIME__ "]", sf::Style::Default, settings),
    map_(ncasas),
    view1(sf::FloatRect(0.f, 0.f, window_.getSize().x, window_.getSize().y))
{
    settings.antialiasingLevel = 8;
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

void Application::draw(){
    ImGui::Begin("Informações", nullptr, ImGuiWindowFlags_NoMove);
    ImGui::SetWindowPos(ImVec2(0, 0));
    ImGui::Text("x position:");
    ImGui::Text(std::to_string(view1.getCenter().x).c_str());
    ImGui::Text("y position:");
    ImGui::Text(std::to_string(view1.getCenter().y).c_str());
    ImGui::End();

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

    while(window_.isOpen()) {
        sf::Event event;
        
        while (window_.pollEvent(event)) {
            ImGui::SFML::ProcessEvent(event);
            if (event.type == sf::Event::Closed) {
                window_.close();
            }
        }

        if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Right)){
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

        ImGui::SFML::Update(window_, deltaClock.restart());

        draw();

    }

    ImGui::SFML::Shutdown();
}
