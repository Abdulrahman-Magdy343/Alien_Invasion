#pragma once
#include <iostream>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "EarthArmyUnit.h"
#include "AlienArmyUnit.h"
#include "AlienArmy.h"
#include "EarthArmy.h"
#include "LinkedQueue.h"
#include "RandGen.h"

class Game
{
	int timeStep;
	AlienArmy alienArmy;
	EarthArmy earthArmy;
	LinkedQueue<ArmyUnit*> killedList;
	RandGen randGenObj;

public:
	Game();
	void go();
	void ReadFormInputFile();
	void Phase1();
	void addToKilled(ArmyUnit* unit);
	int getTimeStep();
	EarthArmy* getEarthArmy();
	AlienArmy* getAlienArmy();
	void writeArmyStatistics(ofstream& outputFile, AlienArmy& alienArmy, string armyName);
	void writeArmyStatistics(ofstream& outputFile, EarthArmy& earthArmy, string armyName);
	void generateOutputFile(string filename);

};

