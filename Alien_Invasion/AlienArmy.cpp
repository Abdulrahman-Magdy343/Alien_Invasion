#include "AlienArmy.h"

AlienArmy::AlienArmy()
{
}

bool AlienArmy::AllAreEmpty()
{
	if (AlienMonsters == nullptr && AlienSoldiers.isEmpty()) return true;
	else return false;
}

void AlienArmy::addUnit(AlienArmyUnit* newUnit)
{
    UnitType type = newUnit->getType();
    switch (type) {
    case AS:
        AlienSoldiers.enqueue((AlienSoldier*)newUnit);
        break;
    case AM:
        AlienMonsters[monstersCount] = (AlienMonster*)newUnit;
        monstersCount++;
        break;
    case AD:
        AlienDrones.insertFront((AlienDrone*)newUnit);
        break;
    }
}


void AlienArmy::Attack()
{
    if (!AlienSoldiers.isEmpty()) {
    AlienSoldier* s;
    AlienSoldiers.peek(s);
    s->attack();
    }

    if (AlienDrones.includePairOrMore())
    {
        AlienDrone* d1;
        AlienDrone* d2;
        AlienDrones.peekFront(d1);
        AlienDrones.peekBack(d2);
        d1->setPower(d1->getPower() + d2->getPower());
        d1->attack();
        d1->setPower(d1->getPower() - d2->getPower());
    }
    if (monstersCount>0) {

        AlienMonster* m;
        m = AlienMonsters[monstersCount-1];
        m->attack();
    
    }
}

void AlienArmy::Print()
{
    cout << "================= Alien Army alive units ================" << endl;

    cout << AlienSoldiers.getCount() << " AS [";
    AlienSoldiers.print();
    cout << "]\n";

    cout << monstersCount << " AM [";
    printMonsters();
    cout << "]\n";

    cout << AlienDrones.getCount() << " AD [";
    AlienDrones.print();
    cout << "]\n";

}

void AlienArmy::printMonsters() const
{
    for (int i = 0; i < monstersCount; i++)
    {
        cout << AlienMonsters[i]->getID() << " ";
    }
}

int AlienArmy::getMonstersCount() const
{
    return monstersCount;
}

void AlienArmy::incrementMonsters()
{
    monstersCount++;
}

void AlienArmy::removeMonster(int index)
{
    //delete AlienMonsters[index];
    //AlienMonsters[index] = AlienMonsters[monstersCount];
    //monstersCount--;
    AlienMonsters[monstersCount--] = nullptr;
}


LinkedQueue<AlienSoldier*>& AlienArmy::getAlienSoldiers() {
    return AlienSoldiers;
}
AlienMonster** AlienArmy::getAlienMonsters() {
    return AlienMonsters;
}
Deque<AlienDrone*>& AlienArmy::getAlienDrones() {
    return AlienDrones;
}