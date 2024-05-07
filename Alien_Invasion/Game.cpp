#include "Game.h"

Game::Game(): randGenObj(alienArmy, earthArmy)
{
}

void Game::go()
{
	randGenObj.setGame(this);
	ReadFormInputFile();
	while(1)
	{
		randGenObj.generate();

		earthArmy.Attack();
		alienArmy.Attack();


		//Printing Part

		cout << "Current timestep: " << timeStep << endl;
		earthArmy.Print();
		alienArmy.Print();
		cout << "================= Killed list ================" << endl;
		cout << killedList.getCount() << " units [";
		killedList.print();
		cout << "]\n";

		char x;
		cin >> x;
		cout << "\n\n\n";
		// at end of each iteration
		timeStep++;


	}
}


//Read from the input file
void Game::ReadFormInputFile()
{
	int armyUnitsNo;
	int ES_percent, ET_percent, EG_percent, AS_percent, AM_percent, AD_percent;
	int E_minPower, E_maxPower, E_minHealth, E_maxHealth, E_minAttCap, E_maxAttCap;
	int A_minPower, A_maxPower, A_minHealth, A_maxHealth, A_minAttCap, A_maxAttCap;
	int prob;

	//Choose Input file difficulty
	int n = 1;
	cout << "Choose difficulty level  \n1-Easy \n2-Normal \n3-Hard" << endl;
	cin >> n;

	// Easy Input file

	if (n == 1)
	{
		ifstream file("InputFileEasy.txt");

		if (!file.is_open()) {
			cout << "Input File not founded" << endl;
			return;
		}


		file >> armyUnitsNo
			>> ES_percent >> ET_percent >> EG_percent
			>> AS_percent >> AM_percent >> AD_percent
			>> prob
			>> E_minPower >> E_maxPower >> E_minHealth >> E_maxHealth >> E_minAttCap >> E_maxAttCap
			>> A_minPower >> A_maxPower >> A_minHealth >> A_maxHealth >> A_minAttCap >> A_maxAttCap;
		file.close();
	}

	//normal Input File
	if (n == 2)
	{
		ifstream file("InputFile.txt");

		if (!file.is_open()) {
			cout << "Input File not founded" << endl;
			return;
		}


		file >> armyUnitsNo
			>> ES_percent >> ET_percent >> EG_percent
			>> AS_percent >> AM_percent >> AD_percent
			>> prob
			>> E_minPower >> E_maxPower >> E_minHealth >> E_maxHealth >> E_minAttCap >> E_maxAttCap
			>> A_minPower >> A_maxPower >> A_minHealth >> A_maxHealth >> A_minAttCap >> A_maxAttCap;
		file.close();
	}

	//Hard Input File
	if (n == 3)
	{
		ifstream file("InputFileHard.txt");
		if (!file.is_open()) {
			cout << "Input File not founded" << endl;
			return;
		}

		file >> armyUnitsNo
			>> ES_percent >> ET_percent >> EG_percent
			>> AS_percent >> AM_percent >> AD_percent
			>> prob
			>> E_minPower >> E_maxPower >> E_minHealth >> E_maxHealth >> E_minAttCap >> E_maxAttCap
			>> A_minPower >> A_maxPower >> A_minHealth >> A_maxHealth >> A_minAttCap >> A_maxAttCap;
		file.close();
	}


	// set the values form the input file 
	randGenObj.setProb(prob);

	randGenObj.setArmyUnitsNo(armyUnitsNo);

	randGenObj.setES_percent(ES_percent);
	randGenObj.setET_percent(ET_percent);
	randGenObj.setEG_percent(EG_percent);
	randGenObj.setE_minPower(E_minPower);
	randGenObj.setE_maxPower(E_maxPower);
	randGenObj.setE_minHealth(E_minHealth);
	randGenObj.setE_maxHealth(E_maxHealth);
	randGenObj.setE_minAttCap(E_minAttCap);
	randGenObj.setE_maxAttCap(E_maxAttCap);

	randGenObj.setAS_percent(AS_percent);
	randGenObj.setAM_percent(AM_percent);
	randGenObj.setAD_percent(AD_percent);
	randGenObj.setA_minPower(A_minPower);
	randGenObj.setA_maxPower(A_maxPower);
	randGenObj.setA_minHealth(A_minHealth);
	randGenObj.setA_maxHealth(A_maxHealth);
	randGenObj.setA_minAttCap(A_minAttCap);
	randGenObj.setA_maxAttCap(A_maxAttCap);
}

void Game::Phase1()
{
	for (int i = 0; i < 50; i++)
	{
		
		int randNum;
		srand(time(0));
		randNum = 1 + rand() % 100;
		if (randNum <= 10)
		{
			EarthSoldier* s;
			earthArmy.getEarthSoldiers().dequeue(s);
			earthArmy.addUnit(s);
		}
		else if (randNum <= 20)
		{
			EarthTank* t;
			earthArmy.getTanks().pop(t);
			addToKilled(t);
		}
		else if (randNum <= 30)
		{
			EarthGunnery* g; int pri = 0;
			earthArmy.getEarthGunneries().dequeue(g, pri);
			g->setHealth(g->getHealth() / 2);
			earthArmy.addUnit(g);
		}
		else if (randNum <= 40)
		{
			LinkedQueue<AlienSoldier*> tempList;
			for (int i = 0; i < 5; i++)
			{
				AlienSoldier* s;
				alienArmy.getAlienSoldiers().dequeue(s);
				s->setHealth(s->getHealth() / 2);
				tempList.enqueue(s);
			}
			for (int i = 0; i < 5; i++)
			{
				AlienSoldier* s;
				tempList.dequeue(s);
				alienArmy.addUnit(s);
			}
		}
		else if (randNum <= 50)
		{
			for (int i = 0; i < 5; i++)
			{
				AlienMonster** monList = alienArmy.getAlienMonsters();
				AlienMonster* templist[5];
				int randindex = rand() % alienArmy.getMonstersCount() + 1;
				templist[i] = monList[randindex];
				monList[randindex] = monList[alienArmy.getMonstersCount()];
			}
			for (int i = 0; i < 5; i++)
			{
				AlienMonster** monList = alienArmy.getAlienMonsters();
			}
		}
	}
}

void Game::addToKilled(ArmyUnit* unit)
{
	killedList.enqueue(unit);
}

int Game::getTimeStep()
{
	return timeStep;
}

EarthArmy* Game::getEarthArmy()
{
	return &earthArmy;
}

AlienArmy* Game::getAlienArmy()
{
	return &alienArmy;
}
