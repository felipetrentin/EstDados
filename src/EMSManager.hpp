#ifndef EMSMANAGER_HPP
#define EMSMANAGER_HPP

#include "PriorityList.hpp"
#include "CircularList.hpp"
#include <imgui-SFML.h>
#include <imgui.h>
//função que vai ser rodada a cada segundo para reduzir as prioridades

class EMSManager{
public:
    EMSManager(int lives);
    //~EMSManager();
    void update();
    void drawOccourence();
    void showListOccourances();
    int getLifes();
private:
    /* data */
    PriorityList currentEvents;
    CircularList randomEvents;
    int lifes;
    int offset;
};


#endif