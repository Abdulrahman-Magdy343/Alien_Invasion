#pragma once
#include "AlienArmyUnit.h"
#include "LinkedQueue.h"
#include "Deque.h"

class AlienArmy
{
    const int size = 500;
    int monstersCount = -1; //if a monster is killed don't forget to decrement 
    LinkedQueue<AlienSoldier*> AlienSoldiers;
    AlienMonster* AlienMonsters[500];
    Deque<AlienDrone*> AlienDrones;

public:
    AlienArmy();
    bool AllAreEmpty();
    void addUnit(AlienArmyUnit* newUnit);
    void Attack();
    void Print();

    // Monsters Functions
    void printMonsters() const; 
    int getMonstersCount() const;
    void incrementMonsters();
    // AlienMonster* pickAlienMonster();
    void removeMonster(int index);

    LinkedQueue<AlienSoldier*>& getAlienSoldiers();
    AlienMonster** getAlienMonsters();
    Deque<AlienDrone*>& getAlienDrones();
};

