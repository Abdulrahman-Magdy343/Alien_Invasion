#include "SUArmy.h"

void SUArmy::destructSUArmy()
{
	SUArmyUnit* s;
	while (!SaverUnits.isEmpty())
		SaverUnits.dequeue(s);
}

void SUArmy::addUnit(SUArmyUnit* newUnit)
{
	SaverUnits.enqueue((SUArmyUnit*)newUnit);
}

void SUArmy::Attack()
{
	if (!SaverUnits.isEmpty()) {
		SUArmyUnit* s;
		SaverUnits.peek(s);
		s->attack();
	}
}

void SUArmy::Print()
{
	cout << "================= Allied Army alive units ================" << endl;

	cout << SaverUnits.getCount() << " SU [";
	SaverUnits.print();
	cout << "]\n";
}

LinkedQueue<SUArmyUnit*>& SUArmy::getSaverUnits()
{
	return SaverUnits;
}
