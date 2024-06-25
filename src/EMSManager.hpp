#ifndef EMSMANAGER_HPP
#define EMSMANAGER_HPP

#include "PriorityList.hpp"
#include "CircularList.hpp"
//função que vai ser rodada a cada segundo para reduzir as prioridades

class EMSManager{
public:
    EMSManager(int lives);
    //~EMSManager();
    void update();
    void addOccourence();

private:
    /* data */
    PriorityList currentEvents;
    int lifes;
};


#endif