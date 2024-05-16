#pragma once
#include "EarthArmyUnit.h"
#include "ArrayStack.h"
#include "LinkedQueue.h"
#include "priQueue.h" // Those definitions may cause a problem later and you may consider only forward declaration


class EarthArmy
{
    ArrayStack<EarthTank*> Tanks;
    LinkedQueue<EarthSoldier*> EarthSoldiers;
    priQueue<EarthGunnery*> EarthGunneries;
    ArrayStack<HealUnit*> HealUnits;
    priQueue<EarthSoldier*> SoldiersUML;
    LinkedQueue<EarthTank*> TanksUML;
    int noOfInfectedSoldiers;

public:
    bool AllAreEmpty();
    void addUnit(EarthArmyUnit* newUnit);
    void Attack();
    void Print();
    void addToUML(EarthArmyUnit* newUnit);
    void infectionSpread();
    void addInfectedSoldier();
    void decrementInfectedSoldier();
    // Setters
    void setTanks(ArrayStack<EarthTank*> tanks) { Tanks = tanks; }
    void setEarthSoldiers(LinkedQueue<EarthSoldier*> earthSoldiers) { EarthSoldiers = earthSoldiers; }
    void setEarthGunneries(priQueue<EarthGunnery*> earthGunneries) { EarthGunneries = earthGunneries; }

    // Getters
    ArrayStack<EarthTank*>& getTanks();
    LinkedQueue<EarthSoldier*>& getEarthSoldiers(); 
    priQueue<EarthGunnery*>& getEarthGunneries();
    ArrayStack<HealUnit*>& getHealUnits();
    priQueue<EarthSoldier*>& getSoldiersUML();
    LinkedQueue<EarthTank*>& getTanksUML();
    int getNumOfInfectedSoldiers();
};

