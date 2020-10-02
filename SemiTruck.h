#pragma once

#include "Vehicle.h"
#include <iostream>

struct SemiTruck : Vehicle
{
    SemiTruck(const std::string& n);

    ~SemiTruck() override;
    
    SemiTruck(const SemiTruck&);
    SemiTruck& operator = (const SemiTruck&);

    void pullOver();
    void longDistanceDrive();
};

