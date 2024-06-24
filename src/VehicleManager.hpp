#ifndef VEHICLE_MNGR_HPP
#define VEHICLE_MNGR_HPP

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>
#include <imgui-SFML.h>
#include <imgui.h>

#include "types.hpp"
#include "graph.hpp"
#include "AvlTree.hpp"

class VehichleManager{
public:
    VehichleManager(int numOfUnits, Graph* graph);
    ~VehichleManager();

    Vehicle* getVehicle(int id);
    void vehiclesDebugMenu();
    void update(sf::Clock* gameClock);
    void spawnVehichle(int vehicleID, int nodeID);
    void updateVehicle(int vehicleID, sf::Clock* gameClock);
    sf::Vector2f getVehiclePos(Vehicle* ve, sf::Clock* deltaClock);
private:
    const sf::Vector2f lerp(sf::Vector2f a, sf::Vector2f b, float t);
    int numOfUnits_;
    AVLTree<Vehicle> automobiles;
    Graph* graph_;
    /* data */
};

#endif