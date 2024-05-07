#pragma once
#include "ArmyUnit.h"


class AlienArmyUnit : public ArmyUnit {
    static int nextId;

public:
    // Constructors
    AlienArmyUnit();
    AlienArmyUnit(int health, int power, int cap, int timeStamp, UnitType type, Game* pg); // Add UnitType parameter

     
};

class AlienSoldier : public AlienArmyUnit {
public:
    // Constructors
    AlienSoldier();
    AlienSoldier(int health, int power, int cap, int timeStamp, Game* pg); // Remove UnitType parameter
    void attack();

     
};

class AlienMonster : public AlienArmyUnit {
public:
    // Constructors
    AlienMonster();
    AlienMonster(int health, int power, int cap, int timeStamp, Game* pg); // Remove UnitType parameter
    void attack();

     
};

class AlienDrone : public AlienArmyUnit {
public:
    // Constructors
    AlienDrone();
    AlienDrone(int health, int power, int cap, int timeStamp, Game* pg); // Remove UnitType parameter
    void attack();

     
};