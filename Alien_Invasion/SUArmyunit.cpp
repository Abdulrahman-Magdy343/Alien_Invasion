#include "SUArmyunit.h"
#include "Game.h"
int SUArmyUnit::nextId = 1;

SUArmyUnit::SUArmyUnit() {}

SUArmyUnit::SUArmyUnit(int health, int power, int cap,  Game* pg):
	ArmyUnit(nextId++, health, power, cap, SU, 0, pg)
{
}

void SUArmyUnit::attack()
{
	
	if (!Pgame->GetSilentMode())
		cout << "SU " << this->getID() << " shots [";
		ArrayStack<AlienSoldier*> templist;
		AlienSoldier* u;
		for (int i = 0; i < capacity; i++) {

			if (Pgame->getAlienArmy()->getAlienSoldiers().dequeue(u)) {
				if (!Pgame->GetSilentMode()) {
					if (i == capacity - 1) cout << u->getID();
					else cout << u->getID() << ", ";
				}

				if (u->isAlive()) {
					u->setTa(Pgame->getTimeStep());
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
		if (!Pgame->GetSilentMode())
			cout << "]\n";
	
}
