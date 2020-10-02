#include "Highway.h"

#include "Vehicle.h"
#include "Car.h"
#include "Motorcycle.h"
#include "SemiTruck.h"

#include <cassert>

void Highway::changeSpeed(int newSpeed)
{
    speedLimit = newSpeed;
    for( auto* vehicle : vehicles )
    {
        vehicle->setSpeed(speedLimit);
    }
}

void Highway::addVehicleInternal(Vehicle* v)
{
    //assert(false);

    if (auto* car = dynamic_cast<Car*>(v))
    {
        car->closeWindows();
    }
    else if (auto* mcycle = dynamic_cast<Motorcycle*>(v))
    {
        mcycle->lanesplitAndRace(110);
    }
    else if (auto* truck = dynamic_cast<SemiTruck*>(v))
    {
        truck->longDistanceDrive();
    }

    /*
    depending on the derived type, call the member function that doesn't evade the cops. 
    */
}

void Highway::removeVehicleInternal(Vehicle* v)
{
    //assert(false);

    if (auto* car = dynamic_cast<Car*>(v))
    {
        car->tryToEvade();
    }
    if (auto* mcycle = dynamic_cast<Motorcycle*>(v))
    {
        mcycle->tryToEvade();
    }
    if (auto* truck = dynamic_cast<SemiTruck*>(v))
    {
        truck->pullOver();
    }

    /*
    depending on the derived type, call the member function that tries to evade the cops. 

    trucks pull over, but cars and bikes try to evade!!
    */
}

void Highway::addVehicle(Vehicle* v)
{
    vehicles.push_back(v);
    addVehicleInternal(v);
}
void Highway::removeVehicle(Vehicle* v)
{
    vehicles.erase(std::remove(vehicles.begin(), 
                               vehicles.end(), 
                               v), 
                   vehicles.end());
    removeVehicleInternal(v);
}

