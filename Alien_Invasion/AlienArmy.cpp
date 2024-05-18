#include "AlienArmy.h"

AlienArmy::AlienArmy()
{
    monstersCount = 0;
}

bool AlienArmy::AllAreEmpty()
{
	if (AlienMonsters == nullptr && AlienSoldiers.isEmpty()) return true;
	else return false;
}

void AlienArmy::addUnit(AlienArmyUnit* newUnit)
{
    static bool flag = true;
    UnitType type = newUnit->getType();
    switch (type) {
    case AS:
        AlienSoldiers.enqueue((AlienSoldier*)newUnit);
        break;
    case AM:
        AlienMonsters[++monstersCount] = (AlienMonster*)newUnit;
        //monstersCount++;
        break;
    case AD:
        if (flag) {
            AlienDrones.insertFront((AlienDrone*)newUnit);
            flag = !flag;
        }
        else
        {
            AlienDrones.insertBack((AlienDrone*)newUnit);
            flag = !flag;
        }
        break;
    }
}


void AlienArmy::Attack()
{
    if (!AlienSoldiers.isEmpty()) {
    AlienSoldier* s;
    AlienSoldiers.peek(s);
    if(s)
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
    if (monstersCount > 0) { // Check if there are monsters to attack
        srand(time(0));
        int randNum = 1+ (rand() % monstersCount); // Index will be valid (1 to monstersCount - 1)
        AlienMonster* m;
        m = AlienMonsters[randNum];
        m->attack();
    }
}

void AlienArmy::Print()
{
    cout << "================= Alien Army alive units ================" << endl;

    cout << AlienSoldiers.getCount() << " AS [";
    AlienSoldiers.print();
    cout << "]\n";

   
    cout << 1+monstersCount << " AM [";
    printMonsters();
    cout << "]\n";

    cout << AlienDrones.getCount() << " AD [";
    AlienDrones.print();
    cout << "]\n";

}

void AlienArmy::printMonsters() const {


    for (int i = 1; i < monstersCount; i++) { 
        
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
    AlienMonster* s = AlienMonsters[monstersCount];
    AlienMonsters[index] = s;
    monstersCount--;
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