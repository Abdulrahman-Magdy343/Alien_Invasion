#include "EarthArmy.h"

bool EarthArmy::AllAreEmpty()
{
    if (Tanks.isEmpty() && EarthSoldiers.isEmpty() && EarthGunneries.isEmpty()) return true;
    else return false;
}

void EarthArmy::addUnit(EarthArmyUnit* newUnit)
{
    UnitType type = newUnit->getType();
    switch (type) {
    case ES:
        EarthSoldiers.enqueue((EarthSoldier*)newUnit);
        break;
    case ET:
        Tanks.push((EarthTank*)newUnit);
        break;
    case EG:
        EarthGunneries.enqueue((EarthGunnery*)newUnit, newUnit->getHealth() + newUnit->getPower());
        break;
    case HU:
        HealUnits.push((HealUnit*)newUnit);
        break;
    }

}

void EarthArmy::Attack()
{
    if (!EarthSoldiers.isEmpty()){
        EarthSoldier* s;
        EarthSoldiers.peek(s);
        s->attack();
    }
    if (!Tanks.isEmpty())
    {
        EarthTank* t;
        Tanks.peek(t);
        t->attack();
    }
    if(!EarthGunneries.isEmpty()){
        EarthGunnery* g; 
        int pri = 0;
        EarthGunneries.dequeue(g, pri);
        g->attack();
        EarthGunneries.enqueue(g, pri);
    }
    if(!HealUnits.isEmpty()){
        HealUnit* h;
        HealUnits.pop(h);
        h->attack();
    }
}

void EarthArmy::Print()
{
    cout << "================= Earth Army alive units ================" << endl;

    cout << EarthSoldiers.getCount() << " ES [";
    EarthSoldiers.print();
    cout << "]\n";

    cout << Tanks.getCount() << " ET [";
    Tanks.print();
    cout << "]\n";

    cout << EarthGunneries.getCount() << " EG [";
    EarthGunneries.print();
    cout << "]\n";
}

void EarthArmy::addToUML(EarthArmyUnit* newUnit)
{
    UnitType type = newUnit->getType();
    switch (type) {
    case ES:
        SoldiersUML.enqueue((EarthSoldier*)newUnit, newUnit->getInitialHealth() - newUnit->getHealth());
        break;
    case ET:
        TanksUML.enqueue((EarthTank*)newUnit);
        break;
    }
}

ArrayStack<EarthTank*>& EarthArmy::getTanks() 
{
    return Tanks;
}

LinkedQueue<EarthSoldier*>& EarthArmy::getEarthSoldiers() 
{
    return EarthSoldiers;
}

priQueue<EarthGunnery*>& EarthArmy::getEarthGunneries() 
{
    return EarthGunneries;
}

ArrayStack<HealUnit*>& EarthArmy::getHealUnits()
{
    return HealUnits;
}

priQueue<EarthSoldier*>& EarthArmy::getSoldiersUML()  {
    return SoldiersUML;
}

LinkedQueue<EarthTank*>& EarthArmy::getTanksUML()  {
    return TanksUML;
}