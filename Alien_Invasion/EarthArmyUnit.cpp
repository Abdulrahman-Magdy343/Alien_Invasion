#include "EarthArmyUnit.h"
#include "Game.h"

int EarthArmyUnit::nextId = 1;

EarthArmyUnit::EarthArmyUnit() {}

EarthArmyUnit::EarthArmyUnit(int health, int power, int cap, int timeStamp, UnitType type, Game* pg) :
	ArmyUnit(nextId++, health, power, cap, type, timeStamp, pg) {

}

// EarthSoldier

EarthSoldier::EarthSoldier() { isInfected = 0; }

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

void EarthSoldier::beInfected()
{
	if (!this->isImmune) {
		isInfected = 1;
		Pgame->getEarthArmy()->addInfectedSoldier();
	}
}

void EarthSoldier::attack() {
	if (!Pgame->GetSilentMode())
		cout << "ES " << this->getID() << " shots [";
	if (!this->getIsInfected()) {
		ArrayStack<AlienSoldier*> templist;
		AlienSoldier* u;
		for (int i = 0; i < capacity; i++) {

			if (Pgame->getAlienArmy()->getAlienSoldiers().dequeue(u)) {
				if (!Pgame->GetSilentMode()) {
					if (i == capacity - 1) cout << u->getID();
					else cout << u->getID() << ", ";
				}

				if (u->isAlive() && !u->gethasbeenattacked()) {
					u->setTa(Pgame->getTimeStep());
					u->setHasBeenAttacked(true);
				}

				int hel = u->getHealth();
				int damage = (this->health * this->power / 100) / pow(hel, 0.5);
				int newhel = hel - damage;
				if (newhel <= 0) { // Add killed unit only when health is zero or below
					u->setTd(Pgame->getTimeStep());
					Pgame->addToKilled(u);
					u->setHealth(0);
				}
				else {
					u->setHealth(newhel);
					templist.push(u); // Add back to templist if still alive
				}
			}
		}

		// Add back to the Alien army's queue ONLY ONCE after all attacks
		while (!templist.isEmpty()) {
			templist.pop(u);
			Pgame->getAlienArmy()->getAlienSoldiers().enqueue(u);
		}
	}
	else {
		ArrayStack<EarthSoldier*> templist;
		EarthSoldier* u;
		for (int i = 0; i < capacity; i++) {

			if (Pgame->getEarthArmy()->getEarthSoldiers().dequeue(u)) {
				if (u == this) { i--; continue; }
				if (!Pgame->GetSilentMode()) {
					if (i == capacity - 1) cout << u->getID();
					else cout << u->getID() << ", ";
				}

				if (u->isAlive() && !u->gethasbeenattacked()) {
					u->setTa(Pgame->getTimeStep());
					u->setHasBeenAttacked(true);
				}

				int hel = u->getHealth();
				int damage = (this->health * this->power / 100) / pow(hel, 0.5);
				int newhel = hel - damage;
				if (newhel <= 0) { // Add killed unit only when health is zero or below
					u->setTd(Pgame->getTimeStep());
					Pgame->addToKilled(u);
					u->setHealth(0);
				}
				else {
					u->setHealth(newhel);
					templist.push(u); // Add back to templist if still alive
					this->isInfected = 0;
					this->isImmune = 1;
					Pgame->getEarthArmy()->decrementInfectedSoldier();
				}
			}
		}

		// Add back to the Alien army's queue ONLY ONCE after all attacks
		while (!templist.isEmpty()) {
			templist.pop(u);
			Pgame->getEarthArmy()->getEarthSoldiers().enqueue(u);
		}
	}
	if (!Pgame->GetSilentMode())cout << "]\n";
}

string EarthSoldier::getID()
{
	return (isInfected) ? (to_string(this->ID) + ":(") : (to_string(this->ID));
}

bool EarthSoldier::getIsInfected()
{
	return isInfected;
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
	if (!Pgame->GetSilentMode())
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
		m = alienArmy->getAlienMonsters()[MScount];
		if (m)
		{
			if (!Pgame->GetSilentMode())
				cout << m->getID() << ", ";
			alienArmy->removeMonster(MScount);

			if (m->isAlive() && !m->gethasbeenattacked()) {
				m->setTa(Pgame->getTimeStep());
				m->setHasBeenAttacked(true);
			}

			int hel = m->getHealth();
			int damage = (this->health * this->power / 100.0) / pow(hel, 0.5);
			int newhel = hel - damage;
			if (newhel <= 0)
			{
				m->setTd(Pgame->getTimeStep());
				Pgame->addToKilled(m);
				m->setHealth(0);
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
				if (!Pgame->GetSilentMode())
					cout << u->getID() << ", ";

				if (u->isAlive() && !u->gethasbeenattacked()) {
					u->setTa(Pgame->getTimeStep());
					u->setHasBeenAttacked(true);
				}

				int hel = u->getHealth();
				int damage = (this->health * this->power / 100.0) / pow(hel, 0.5);
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
					templist2.push(u);
				}
			}

		}

	}
	if (!Pgame->GetSilentMode())
		cout << "]\n";
	while (!templist.isEmpty())
	{
		AlienMonster* m;
		templist.pop(m);
		Pgame->getAlienArmy()->addUnit(m);
	}

	while (!templist2.isEmpty())
	{
		AlienSoldier* u;
		templist2.pop(u);
		Pgame->getAlienArmy()->getAlienSoldiers().enqueue(u);
	}
}

// EarthGunnery

EarthGunnery::EarthGunnery() {}

EarthGunnery::EarthGunnery(int health, int power, int cap, int timeStamp, Game* pg) :
	EarthArmyUnit(health, power, cap, timeStamp, EG, pg) {
	srand(time(0));
}

void EarthGunnery::attack() {
	if (!Pgame->GetSilentMode())
		cout << "EG " << this->ID << " shots [";
	ArrayStack<AlienMonster*> templist;
	int AScount = Pgame->getAlienArmy()->getMonstersCount();

	ArrayStack<AlienDrone*> templist2;

	for (int i = 0; i < capacity; i++) {
		AlienMonster* m;
		srand(time(0));
		AScount = (AScount <= -1) ? (-AScount):(AScount);
		int randNum = rand() % (AScount + 1);
		m = Pgame->getAlienArmy()->getAlienMonsters()[Pgame->getAlienArmy()->getMonstersCount() - 1];
		if (m)
		{
			if (!Pgame->GetSilentMode())
				cout << m->getID() << ", ";

			if (m->isAlive() && !m->gethasbeenattacked()) {
				m->setTa(Pgame->getTimeStep());
				m->setHasBeenAttacked(true);
			}

			int hel = m->getHealth();
			int damage = (this->health * this->power / 100) / pow(hel, 0.5);
			int newhel = hel - damage;
			if (newhel <= 0)
			{
				m->setTd(Pgame->getTimeStep());
				Pgame->getAlienArmy()->removeMonster(Pgame->getAlienArmy()->getMonstersCount());
				Pgame->addToKilled(m);
				m->setHealth(0);
			}
			else
			{
				m->setHealth(newhel);
				templist.push(m);
			}
		}

		AlienDrone* d;

		if (Pgame->getAlienArmy()->getAlienDrones().removeBack(d))
		{
			if (!Pgame->GetSilentMode())
				cout << d->getID() << ", ";

			if (d->isAlive() && !d->gethasbeenattacked()) {
				d->setTa(Pgame->getTimeStep());
				d->setHasBeenAttacked(true);
			}

			int hel = d->getHealth();
			int newhel = hel - this->power;

			if (newhel <= 0)
			{
				d->setTd(Pgame->getTimeStep());
				Pgame->addToKilled(d);
				d->setHealth(0);
			}
			else
			{
				d->setHealth(newhel);
				templist2.push(d);
			}
		}

		if (Pgame->getAlienArmy()->getAlienDrones().removeFront(d))
		{
			if (!Pgame->GetSilentMode())
				cout << d->getID() << ", ";

			if (d->isAlive() && !d->gethasbeenattacked()) {
				d->setTa(Pgame->getTimeStep());
				d->setHasBeenAttacked(true);
			}

			int hel = d->getHealth();
			int newhel = hel - this->power;

			if (newhel <= 0)
			{
				d->setTd(Pgame->getTimeStep());
				Pgame->addToKilled(d);
				d->setHealth(0);
			}
			else
			{
				d->setHealth(newhel);
				templist2.push(d);
			}
		}

	}
	if (!Pgame->GetSilentMode())
		cout << "]\n";

	while (!templist.isEmpty())
	{
		AlienMonster* m;
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

HealUnit::HealUnit(int health, int power, int cap, int timeStamp, Game* pg) :EarthArmyUnit(health, power, cap, timeStamp, HU, pg)
{

}

void HealUnit::attack()
{
	EarthArmy* earthArmy = Pgame->getEarthArmy();
	ArrayStack<EarthSoldier*> templist;
	ArrayStack<EarthTank*> templist2;
	for (int i = 0; i < capacity / 2; i++) {
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
				s->setHealth(hel +0.5* (this->power * this->health / 100) / pow(hel, 0.5));
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
