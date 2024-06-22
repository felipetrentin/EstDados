#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>
#include <imgui-SFML.h>
#include <imgui.h>

#include "rapidxml_utils.hpp"

#include <string>
#include "graph.hpp"

class Application{
public:
    Application();
    void run();
    void draw();
    void drawGui();
    void drawAssistant();
    void close();
    void drawRoad(sf::Vector2f from, sf::Vector2f to);
    void loadGraph(std::string path);
private:
    sf::ContextSettings settings;
    sf::RenderWindow window_;
    sf::Font font_;
    Graph map_;
    sf::View view1;
    sf::Clock deltaClock;

};

#endif