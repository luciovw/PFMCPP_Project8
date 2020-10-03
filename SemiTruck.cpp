#include "SemiTruck.h"

SemiTruck::SemiTruck(const std::string& n) : Vehicle(n){}

SemiTruck::~SemiTruck() = default;
SemiTruck::SemiTruck(const SemiTruck&) = default;
SemiTruck& SemiTruck::operator=(const SemiTruck&) = default;

void SemiTruck::longDistanceDrive()
{
    setSpeed(55);
    std::cout<< "Big rigs for life!" << std::endl;
}

void SemiTruck::pullOver()
{
    setSpeed(0);
    std::cout<< "Hello Officer, I just a good ol' boy who is gonna vote for Trump in November" << std::endl;
}

