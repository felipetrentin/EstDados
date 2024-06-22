#ifndef VEHICLE_MNGR_HPP
#define VEHICLE_MNGR_HPP

#include "types.hpp"

#define NUMBER_OF_UNITS 2

class VehichleManager{
public:
    VehichleManager();
    ~VehichleManager();

    void getvehicle();
private:
    int numOfUnits;
    Vehicle automobiles[NUMBER_OF_UNITS];
    /* data */
};

#endif