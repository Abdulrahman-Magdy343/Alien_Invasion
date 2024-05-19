#pragma once
#include "SUArmyUnit.h"
#include "LinkedQueue.h"


class SUArmy
{
    LinkedQueue<SUArmyUnit*> SaverUnits;


public:
    bool AllAreEmpty();
    void destructSUArmy();
    void addUnit(SUArmyUnit* newUnit);
    void Attack();
    void Print();
    //void addToUML(SUArmyUnit* newUnit);

    // Setters

    // Getters
    LinkedQueue<SUArmyUnit*>& getSaverUnits();
};

