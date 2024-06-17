#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>
#include <imgui-SFML.h>
#include <imgui.h>

#include "rapidxml_utils.hpp"

#include "graph.hpp"

#define ncasas 20

void drawAssistant(){
    ImGui::Begin("J.J Junior [Assistente]", nullptr, ImGuiWindowFlags_NoResize);
    ImGui::End();
}

void drawLine(sf::RenderWindow* window, sf::Vector2f from, sf::Vector2f to){
    sf::Vertex line[] =
    {
        from,
        to,
    };
    window->draw(line, 2, sf::Lines);
}

int main() {
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Meanwhile in Baltimore: [compiled: " __DATE__ " " __TIME__ "]", sf::Style::Default, settings);
    window.setVerticalSyncEnabled(true);
    ImGui::SFML::Init(window);
    
    sf::View view1(sf::FloatRect(
        0.f, 0.f, 
        window.getSize().x, window.getSize().y));

    sf::Clock deltaClock;

    sf::CircleShape shape(20.f);
    shape.setFillColor(sf::Color::Green);
    shape.setOutlineColor(sf::Color::White);
    shape.setOutlineThickness(2.0f);

    sf::Font font;
    font.loadFromFile("/usr/share/fonts/truetype/freefont/FreeSans.ttf");

    // LOAD GRAPH
    Graph map(ncasas);

    rapidxml::file<> xmlFile("map.xml"); // Default template is char
    rapidxml::xml_document<> doc;
    doc.parse<0>(xmlFile.data());

    rapidxml::xml_node<> *city = doc.first_node("city");
    rapidxml::xml_node<> *nodesNode = city->first_node("nodes");
    rapidxml::xml_node<> *edgesNode = city->first_node("edges");


    for (rapidxml::xml_node<> *node = nodesNode->first_node("node"); node != nullptr; node = node->next_sibling()) {
        map.setVertice(
            std::stoi(node->first_attribute("id")->value()),
            std::stoi(node->first_attribute("x")->value()),
            std::stoi(node->first_attribute("y")->value()),
            node->first_attribute("name")->value(),
            std::stoi(node->first_attribute("type")->value())
        );
    }
    
    for (rapidxml::xml_node<> *edge = edgesNode->first_node("edge"); edge != nullptr; edge = edge->next_sibling()) {
        map.setEdges(
            std::stoi(edge->first_attribute("from")->value()), 
            std::stoi(edge->first_attribute("to")->value()), 
            std::stoi(edge->first_attribute("distance")->value())
        );
    }

    //graph loaded.

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            ImGui::SFML::ProcessEvent(event);
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        
        if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Middle)){
            sf::Vector2i mousepos = sf::Mouse::getPosition();
            view1.move(mousepos.x - 1920/2, mousepos.y - 1080/2);
            sf::Mouse::setPosition(sf::Vector2(1920/2,  1080/2));
        }

        ImGui::SFML::Update(window, deltaClock.restart());

        ImGui::Begin("Informações", nullptr, ImGuiWindowFlags_NoMove);
        ImGui::SetWindowPos(ImVec2(0, 0));
        ImGui::Text("x position:");
        ImGui::Text(std::to_string(view1.getCenter().x).c_str());
        ImGui::Text("y position:");
        ImGui::Text(std::to_string(view1.getCenter().y).c_str());
        ImGui::End();

        drawAssistant();

        window.clear(sf::Color::Black);
        window.setView(view1);

        for(int i=0; i<ncasas; i++){
            Vertice* vertice = map.getVertice(i);
            if(vertice != nullptr){
                sf::Text label(vertice->name, font, 20);
                label.setPosition(vertice->posX+40, vertice->posY-15);
                for(int j=0; j<ncasas; j++){
                    if(map.getWeight(i, j) > 0){
                        Vertice* dstVert = map.getVertice(j);
                        drawLine(&window, 
                            sf::Vector2f(vertice->posX+20, vertice->posY+20), 
                            sf::Vector2f(dstVert->posX+20, dstVert->posY+20)
                        );
                    }
                }
                shape.setFillColor(typeColors[vertice->type]);
                shape.setPosition(vertice->posX, vertice->posY);
                window.draw(shape);
                window.draw(label);
            }
        }

        ImGui::SFML::Render(window);
        window.display();
    }

    ImGui::SFML::Shutdown();

    return 0;
}
