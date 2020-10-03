#pragma once
#include "Vehicle.h"

struct Car : public Vehicle
{
    Car(const std::string& s);
    Car(const Car&);
    Car& operator=(const Car&);

    ~Car() override;

    void closeWindows();
    void tryToEvade() override;
};

