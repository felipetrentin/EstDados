#ifndef EMSMANAGER_HPP
#define EMSMANAGER_HPP

#include "PriorityList.hpp"

//função que vai ser rodada a cada segundo para reduzir as prioridades

class EMSManager{
public:
    EMSManager(int lives);
    //~EMSManager();
    void update();

private:
    /* data */
    PriorityList currentEvents;
    int lifes;
};


#endif