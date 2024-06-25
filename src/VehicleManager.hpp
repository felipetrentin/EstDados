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
    VehichleManager(Graph* graph, sf::Clock* gameClock);
    ~VehichleManager();

    Vehicle* getVehicle(int id);
    void vehiclesDebugMenu();
    void update();
    void spawnVehichle(int vehicleID, int nodeID);
    sf::Vector2f getVehiclePos(Vehicle* ve);
    int getNumUnits();
    bool arrived(Vehicle* ve);
    bool setMovement(Vehicle* ve, int dest);
private:
    const sf::Vector2f lerp(sf::Vector2f a, sf::Vector2f b, float t);
    int numOfUnits_;
    AVLTree<Vehicle> automobiles;
    Graph* graph_;

    sf::Clock* gameClock;

    int spawnerId = 0;
    int spawnNode = 0;

    int moverSrcId = 0;
    int moverDestId = 0;

};

#endif