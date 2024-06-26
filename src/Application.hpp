#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>
#include <imgui-SFML.h>
#include <imgui.h>
#include <string>

#include <string>
#include "rapidxml_utils.hpp"
#include "graph.hpp"
#include "EMSManager.hpp"
#include "VehicleManager.hpp"

class Application{
public:
    Application();
    void run();
    void draw();
    void drawGui();
    void drawAssistant();
    void close();
    void drawRoad(sf::Vector2f from, sf::Vector2f to);
    bool loadGraph(std::string path);
    void drawInfo();
private:
    sf::ContextSettings settings;
    sf::RenderWindow window_;
    sf::Font font_;
    Graph map_;
    sf::View view1;
    sf::Clock deltaClock;
    sf::Clock gameClock;
    sf::Time dt_;
    float dtHist_[100];
    bool scrolling = false;
    sf::Vector2i scrollPos_ = sf::Vector2i(0,0);
    sf::Clock eventClock;
    EMSManager eventsManager;

    uint32_t milisElapsedTick_ = 0;
    VehichleManager vManager_;

    sf::Clock drawClock;
    sf::Clock vehicleTickClock;
    sf::Clock EMSTickClock;
    
    uint32_t drawTime;
    uint32_t vehicleTickTime;
    uint32_t EMSTickTime;
    

};

#endif