#include "AlienArmyUnit.h"
#include "Game.h"

int AlienArmyUnit::nextId = 2000;

// AlienArmyUnit


AlienArmyUnit::AlienArmyUnit()
{
}

AlienArmyUnit::AlienArmyUnit(int health, int power, int cap, int timeStamp, UnitType type, Game* pg) : ArmyUnit(nextId++, health, power, cap, type, timeStamp, pg) {

}

// AlienSoldier



AlienSoldier::AlienSoldier()
{
}

AlienSoldier::AlienSoldier(int health, int power, int cap, int timeStamp, Game* pg) : AlienArmyUnit(health, power, cap, timeStamp, AS, pg) {

}

void AlienSoldier::attack()
{
	if (!Pgame->GetSilentMode())
		cout << "AS " << this->getID() << " shots [";

	ArrayStack<EarthSoldier*> templist;
	EarthArmy* earthArmy = Pgame->getEarthArmy();
	for (int i = 0; i < capacity; i++) {
		EarthSoldier* u;
		if (earthArmy->getEarthSoldiers().dequeue(u))
		{
			if (!Pgame->GetSilentMode()) {
				if (i == capacity - 1) cout << u->getID();
				else cout << u->getID() << ", ";
			}


			if (u->isAlive()) {
				u->setTa(Pgame->getTimeStep());
			}

			int hel = u->getHealth();
			int damage = (this->health * this->power / 100) / (double)pow(hel, 0.5);
			int newhel = hel - damage;

			if (newhel <= 0)
			{
				u->setTd(Pgame->getTimeStep());
				Pgame->addToKilled(u);
				u->setHealth(0);
			}
			else
			{
				u->setHealth(newhel);
				int initHel = u->getInitialHealth();
				if ((double)newhel / initHel < 0.2)
				{
					u->setUMLjoinTime(Pgame->getTimeStep());
					earthArmy->addToUML(u);
				}
				else templist.push(u);
			}
		}


	}
	if (!Pgame->GetSilentMode())
		cout << "]\n";
	while (!templist.isEmpty())
	{
		EarthSoldier* u;
		templist.pop(u);
		Pgame->getEarthArmy()->getEarthSoldiers().enqueue(u);
	}
}

// AlienMonster



AlienMonster::AlienMonster()
{
}

AlienMonster::AlienMonster(int health, int power, int cap, int timeStamp, Game* pg) : AlienArmyUnit(health, power, cap, timeStamp, AM, pg) {

}

void AlienMonster::attack()
{
	if (!Pgame->GetSilentMode())
		cout << "AM " << this->ID << " shots [";
	ArrayStack<EarthSoldier*> templist;
	ArrayStack<EarthTank*> templist2;
	EarthArmy* earthArmy = Pgame->getEarthArmy();

	for (int i = 0; i < capacity; i++)
	{
		EarthSoldier* s;
		if (earthArmy->getEarthSoldiers().dequeue(s))
		{
			srand(time(0));
			//add the infection part
			int A = (1 + rand() % 100);
			
			if (A < Pgame->getInfectionProb()) {
				if (!s->getIsInfected())s->beInfected();
			}
			if (!Pgame->GetSilentMode())

				cout << s->getID() << ", ";

			if (s->isAlive()) {
				s->setTa(Pgame->getTimeStep());
			}

			int hel = s->getHealth();
			int damage = (this->health * this->power / 100) / pow(hel, 0.5);
			int newhel = hel - damage;
			if (newhel <= 0)
			{
				
				Pgame->addToKilled(s);
			
			}
			else
			{
				s->setHealth(newhel);
				int initHel = s->getInitialHealth();
				if ((double)newhel / initHel < 0.2)
				{
					s->setUMLjoinTime(Pgame->getTimeStep());
					earthArmy->addToUML(s);
				}
				else templist.push(s);
			}
		}

		EarthTank* t;
		if (Pgame->getEarthArmy()->getTanks().pop(t))
		{
			if (!Pgame->GetSilentMode())
				cout << t->getID() << ", ";

			if (t->isAlive()) {
				t->setTa(Pgame->getTimeStep());
			}

			int hel = t->getHealth();
			int damage = (this->health * this->power / 100) / pow(hel, 0.5);
			int newhel = hel - damage;
			if (newhel <= 0)
			{
			
				Pgame->addToKilled(t);
			
			}
			else
			{
				t->setHealth(newhel);
				int initHel = t->getInitialHealth();
				if ((double)newhel / initHel < 0.2)
				{
					t->setUMLjoinTime(Pgame->getTimeStep());
					earthArmy->addToUML(t);
				}
				else templist2.push(t);
			}
		}

	}
	if (!Pgame->GetSilentMode())
		cout << "]\n";
	while (!templist.isEmpty())
	{
		EarthSoldier* s;
		templist.pop(s);
		Pgame->getEarthArmy()->getEarthSoldiers().enqueue(s);
	}

	while (!templist2.isEmpty())
	{
		EarthTank* t;
		templist2.pop(t);
		Pgame->getEarthArmy()->getTanks().push(t);
	}
}
// AlienDrone


AlienDrone::AlienDrone()
{
}

AlienDrone::AlienDrone(int health, int power, int cap, int timeStamp, Game* pg) : AlienArmyUnit(health, power, cap, timeStamp, AD, pg) {


}

void AlienDrone::attack()
{
	if (!Pgame->GetSilentMode())cout << "AD " << this->ID << " shots [";
	ArrayStack<EarthGunnery*> templist;
	ArrayStack<EarthTank*> templist2;
	EarthArmy* earthArmy = Pgame->getEarthArmy();

	for (int i = 0; i < capacity; i++)
	{
		EarthGunnery* g; int pri;
		if (earthArmy->getEarthGunneries().dequeue(g, pri))
		{
			if (!Pgame->GetSilentMode())
				cout << g->getID() << ", ";

			if (g->isAlive()) {
				g->setTa(Pgame->getTimeStep());
			}

			int hel = g->getHealth();
			int damage = (this->health * this->power / 100) / pow(hel, 0.5);
			int newhel = hel - damage;
			if (newhel <= 0)
			{
				
				Pgame->addToKilled(g);
			
			}
			else
			{
				g->setHealth(newhel);
				templist.push(g);
			}
		}

		EarthTank* t;
		if (earthArmy->getTanks().pop(t))
		{
			if (!Pgame->GetSilentMode())
				cout << t->getID() << ", ";

			if (t->isAlive()) {
				t->setTa(Pgame->getTimeStep());
			}

			int hel = t->getHealth();
			int damage = (this->health * this->power / 100) / pow(hel, 0.5);
			int newhel = hel - damage;
			if (newhel <= 0)
			{
				Pgame->addToKilled(t);
			
			}
			else
			{
				t->setHealth(newhel);
				int initHel = t->getInitialHealth();
				if ((double)newhel / initHel < 0.2)
				{
					t->setUMLjoinTime(Pgame->getTimeStep());
					earthArmy->addToUML(t);
				}
				else templist2.push(t);
			}
		}

	}
	if (!Pgame->GetSilentMode())
		cout << "]\n";
	while (!templist.isEmpty())
	{
		EarthGunnery* g;
		templist.pop(g);
		Pgame->getEarthArmy()->getEarthGunneries().enqueue(g, g->getHealth() + g->getPower());
	}

	while (!templist2.isEmpty())
	{
		EarthTank* t;
		templist2.pop(t);
		Pgame->getEarthArmy()->getTanks().push(t);
	}

}