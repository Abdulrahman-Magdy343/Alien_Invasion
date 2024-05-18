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
#include "SUArmy.h"
#include "LinkedQueue.h"
#include "RandGen.h"

class Game
{
	int timeStep;
	AlienArmy alienArmy;
	EarthArmy earthArmy;
	SUArmy saviorArmy;
	LinkedQueue<ArmyUnit*> killedList;
	RandGen randGenObj;
	bool GameOn;
	bool SilentMode;

public:
	Game();
	void go();
	void ReadFormInputFile();
	void Phase1();
	void addToKilled(ArmyUnit* unit);
	int getTimeStep();
	bool GetSilentMode();
	EarthArmy* getEarthArmy();
	AlienArmy* getAlienArmy();
	void writeArmyStatistics(ofstream& outputFile,  EarthArmy& earthArmy, AlienArmy& alienArmy, string armyName1, string armyName2);
	void writeArmyStatistics(ofstream& outputFile, EarthArmy& earthArmy, string armyName);
	void generateOutputFile(string filename);
	int getInfectionProb();
	int getThreshold();

};

