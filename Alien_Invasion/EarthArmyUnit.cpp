#include "EarthArmyUnit.h"
#include "Game.h"

int EarthArmyUnit::nextId = 1;

EarthArmyUnit::EarthArmyUnit() {}

EarthArmyUnit::EarthArmyUnit(int health, int power, int cap, int timeStamp, UnitType type, Game* pg) :
    ArmyUnit(nextId++, health, power, cap, type, timeStamp, pg) {

}

// EarthSoldier

EarthSoldier::EarthSoldier() {}

EarthSoldier::EarthSoldier(int health, int power, int cap, int timeStamp, Game* pg) :
    EarthArmyUnit(health, power, cap, timeStamp, ES, pg) {  
}

void EarthSoldier::setUMLjoinTime(int Tj)
{
    UMLjoinTime = Tj;
}

int EarthSoldier::getUMLjoinTime()
{
    return UMLjoinTime;
}

void EarthSoldier::attack() {
    cout << "ES " << this->ID << " shots [";
    ArrayStack<AlienSoldier*> templist;
    for (int i = 0; i < capacity; i++) {
        AlienSoldier* u;
        if (Pgame->getAlienArmy()->getAlienSoldiers().dequeue(u))
        {
            /* Just To print in console */
            if (i == capacity - 1) cout << u->getID();
            else cout << u->getID() << ", ";

            u->setTa(Pgame->getTimeStep());
            int hel = u->getHealth();
            int damage = (this->health * this->power / 100) / pow(hel, 0.5);
            int newhel = hel - damage;
            if (newhel < 0)
            {
                u->setTd(Pgame->getTimeStep());
                Pgame->addToKilled(u);
            }
            else
            {
                u->setHealth(newhel);
                templist.push(u);
            }
        }
    }
    cout << "]\n";
    while (!templist.isEmpty())
    {
        AlienSoldier* u;
        templist.pop(u);
        Pgame->getAlienArmy()->addUnit(u);
    }
}

// EarthTank

EarthTank::EarthTank() {}

EarthTank::EarthTank(int health, int power, int cap, int timeStamp, Game* pg) :
    EarthArmyUnit(health, power, cap, timeStamp, ET, pg) {
}

void EarthTank::setUMLjoinTime(int Tj)
{
    UMLjoinTime = Tj;
}

int EarthTank::getUMLjoinTime()
{
    return UMLjoinTime;
}

void EarthTank::attack() {
    cout << "ET " << this->ID << " shots [";
    ArrayStack<AlienMonster*> templist;
    ArrayStack<AlienSoldier*> templist2;

    AlienArmy* alienArmy = Pgame->getAlienArmy();

    int ESCount = Pgame->getEarthArmy()->getEarthSoldiers().getCount();
    int ASCount = Pgame->getAlienArmy()->getAlienSoldiers().getCount();
    int MScount = alienArmy->getMonstersCount();
    bool attackSoldiersFlag = ((double)ESCount / ASCount < 0.3);

    for (int i = 0; i < capacity; i++) {

        AlienMonster* m;
        //srand(time(0));
        //int randNum = rand() % (MScount + 1);
        //m = alienArmy->getAlienMonsters()[randNum];
        m = alienArmy->getAlienMonsters()[MScount];
        if (m)
        {
            cout << m->getID() << ", ";
            //alienArmy->removeMonster(randNum);
            alienArmy->removeMonster(MScount);
            int hel = m->getHealth();
            int damage = (this->health * this->power / 100.0) / pow(hel, 0.5);
            int newhel = hel - damage;
            if (newhel < 0)
            {

                Pgame->addToKilled(m);
            }
            else
            {
                m->setHealth(newhel);
                templist.push(m);
            }
        }
        
        
        if ((double)ESCount / ASCount > 0.8) attackSoldiersFlag = false;

        if (attackSoldiersFlag)
        {
            AlienSoldier* u;
            if (alienArmy->getAlienSoldiers().dequeue(u))
            {
                cout << u->getID() << ", ";
                int hel = u->getHealth();
                int damage = (this->health * this->power / 100.0) / pow(hel, 0.5);
                int newhel = hel - damage;
                if (newhel < 0)
                {
                    Pgame->addToKilled(u);
                }
                else
                {
                    u->setHealth(newhel);
                    templist2.push(u);
                }
            }
        
        }
        
    }
    cout << "]\n";
    while (!templist.isEmpty())
    {
        AlienMonster* m; // creation in or out?
        templist.pop(m);
        Pgame->getAlienArmy()->addUnit(m);
    }

    while (!templist2.isEmpty())
    {
        AlienSoldier* u; // creation in or out?
        templist2.pop(u);
        Pgame->getAlienArmy()->getAlienSoldiers().enqueue(u);
    }
}

// EarthGunnery

EarthGunnery::EarthGunnery() {}

EarthGunnery::EarthGunnery(int health, int power, int cap, int timeStamp, Game* pg) :
    EarthArmyUnit(health, power, cap, timeStamp, EG, pg) {  
}

void EarthGunnery::attack() {
    cout << "EG " << this->ID << " shots [";
    ArrayStack<AlienMonster*> templist;
    int AScount = Pgame->getAlienArmy()->getMonstersCount();

    ArrayStack<AlienDrone*> templist2;

    for (int i = 0; i < capacity; i++) {
        AlienMonster* m;
        srand(time(0));
        int randNum = rand() % (AScount + 1);
        /*
        while (!Pgame->getAlienArmy()->getAlienMonsters()[randNum]) {
        int randNum = rand() % (AScount + 1);
        }
        */
        m = Pgame->getAlienArmy()->getAlienMonsters()[Pgame->getAlienArmy()->getMonstersCount()-1];
        if (m) 
        {
            cout << m->getID() << ", ";
            int hel = m->getHealth();
            int damage = (this->health * this->power / 100) / pow(hel, 0.5);
            int newhel = hel - damage;
            if (newhel < 0)
            {
                Pgame->getAlienArmy()->removeMonster(Pgame->getAlienArmy()->getMonstersCount());
                Pgame->addToKilled(m);
            }
            else
            {
                m->setHealth(newhel);
                templist.push(m);
            }
        }

        AlienDrone* d1;
        AlienDrone* d2;

        if (Pgame->getAlienArmy()->getAlienDrones().removeBack(d1))
        {
            cout << d1->getID() << ", ";
            int hel = d1->getHealth();
            int newhel = hel - this->power;

            if (newhel < 0)
            {
                Pgame->addToKilled(d1);
            }
            else
            {
                m->setHealth(newhel);
                templist2.push(d1);
            }
        }
        if (Pgame->getAlienArmy()->getAlienDrones().removeFront(d2))
        {
            cout << d2->getID() << ", ";
            int hel = d2->getHealth();
            int newhel = hel - this->power;

            if (newhel < 0)
            {
                Pgame->addToKilled(d1);
            }
            else
            {
                m->setHealth(newhel);
                templist2.push(d2);
            }
        }

        
    }

    cout << "]\n";

    while (!templist.isEmpty())
    {
        AlienMonster* m; // creation in or out?
        templist.pop(m);
        Pgame->getAlienArmy()->addUnit(m);
    }
    while (!templist2.isEmpty())
    {
        AlienDrone* d;
        templist2.pop(d);
        Pgame->getAlienArmy()->addUnit(d);
    }

}

HealUnit::HealUnit()
{
}

HealUnit::HealUnit(int health, int power, int cap, int timeStamp, Game* pg):EarthArmyUnit(health, power, cap, timeStamp, HU, pg)
{
}

void HealUnit::attack()
{
    EarthArmy* earthArmy = Pgame->getEarthArmy();
    ArrayStack<EarthSoldier*> templist;
    ArrayStack<EarthTank*> templist2;
    for (int i = 0; i < capacity/2; i++) {
        EarthSoldier* s; int pri;
        if (earthArmy->getSoldiersUML().dequeue(s, pri))
        {
            if (s->getUMLjoinTime() - getJoinTime() >= 10)
            {
                Pgame->addToKilled(s);
            }
            else
            {
                int hel = s->getHealth();
                s->setHealth(hel + (this->power * this->health / 100) / pow(hel, 0.5));
                if ((double)s->getHealth() / s->getInitialHealth() > 0.2)
                {
                    earthArmy->getEarthSoldiers().enqueue(s);
                }
                else
                    templist.push(s);
            }
        }
        else break;
    }

    while (!templist.isEmpty())
    {
        EarthSoldier* m; 
        templist.pop(m);
        earthArmy->addToUML(m);
    }

    for (int i = capacity / 2; i < capacity; i++) {
        EarthTank* t;
        if (earthArmy->getTanksUML().dequeue(t))
        {
            if (t->getUMLjoinTime() - getJoinTime() >= 10)
            {
                Pgame->addToKilled(t);
            }
            else
            {
                int hel = t->getHealth();
                t->setHealth(hel + (this->power * this->health / 100) / pow(hel, 0.5));
                if ((double)t->getHealth() / t->getInitialHealth() > 0.2)
                {
                    earthArmy->getTanks().push(t);
                }
                else
                    templist2.push(t);
            }
        }
        else break;
    }

    while (!templist2.isEmpty())
    {
        EarthTank* m;
        templist2.pop(m);
        earthArmy->addToUML(m);
    }
    Pgame->addToKilled(this); // I am quite sure this would make a problem
}
