#pragma once
#include "SUArmyUnit.h"
#include "LinkedQueue.h"


class SUArmy
{
    LinkedQueue<SUArmyUnit*> SaverUnits;


public:
    bool AllAreEmpty();
    void addUnit(SUArmyUnit* newUnit);
    void Attack();
    void Print();
    void addToUML(SUArmyUnit* newUnit);

    // Setters

    // Getters
};

