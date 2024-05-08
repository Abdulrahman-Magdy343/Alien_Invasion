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
	int ES_percent, ET_percent, EG_percent, AS_percent, AM_percent, AD_percent, EEU_percent;
	int E_minPower, E_maxPower, E_minHealth, E_maxHealth, E_minAttCap, E_maxAttCap;
	int A_minPower, A_maxPower, A_minHealth, A_maxHealth, A_minAttCap, A_maxAttCap;
	int prob;
	int Infection_prob;

	//Choose Input file difficulty
	int n = 1;
	cout << "Choose difficulty level  \n1- ModerateEarth ModerateAliens \n2- StrongEarth WeakAliens" <<
		"\n3- StrongEarth ModerateAliens \n4- StrongEarth StrongAliens \n5- WeakEarth WeakAliens "<<
		"\n6- WeakEarth ModerateAliens \n7- WeakEarth StrongAliens " << endl;
	cin >> n;

	// Easy Input file

	if (n == 1)
	{
		ifstream file("ModerateEarth_ModerateAliens.txt");

		if (!file.is_open()) {
			cout << "Input File not founded" << endl;
			return;
		}


		string line;

		getline(file, line);
		armyUnitsNo = stoi(line);

		getline(file, line);
		stringstream ss2(line);
		getline(ss2, line, ',');
		ES_percent = stoi(line);
		getline(ss2, line, ',');
		ET_percent = stoi(line);
		getline(ss2, line, ',');
		EG_percent = stoi(line);
		getline(ss2, line, ',');
		EEU_percent = stoi(line);

		getline(file, line);
		stringstream ss3(line);
		getline(ss3, line, ',');
		AS_percent = stoi(line);
		getline(ss3, line, ',');
		AM_percent = stoi(line);
		getline(ss3, line, ',');
		AD_percent = stoi(line);

		getline(file, line);
		prob = stoi(line);

		getline(file, line);
		stringstream ss5(line);
		getline(ss5, line, '-');
		E_minPower = stoi(line);
		getline(ss5, line, ',');
		E_maxPower = stoi(line);
		getline(ss5, line, '-');
		E_minHealth = stoi(line);
		getline(ss5, line, ',');
		E_maxHealth = stoi(line);
		getline(ss5, line, '-');
		E_minAttCap = stoi(line);
		getline(ss5, line, ',');
		E_maxAttCap = stoi(line);

		getline(file, line);
		stringstream ss6(line);
		getline(ss6, line, '-');
		A_minPower = stoi(line);
		getline(ss6, line, ',');
		A_maxPower = stoi(line);
		getline(ss6, line, '-');
		A_minHealth = stoi(line);
		getline(ss6, line, ',');
		A_maxHealth = stoi(line);
		getline(ss6, line, '-');
		A_minAttCap = stoi(line);
		getline(ss6, line, ',');
		A_maxAttCap = stoi(line);
		
		getline(file, line);
		Infection_prob = stoi(line);
		
		file.close();
	}

	//normal Input File
	if (n == 2)
	{
		ifstream file("StrongEarth_WeakAliens.txt");

		if (!file.is_open()) {
			cout << "Input File not founded" << endl;
			return;
		}


		string line;

		getline(file, line);
		armyUnitsNo = stoi(line);

		getline(file, line);
		stringstream ss2(line);
		getline(ss2, line, ',');
		ES_percent = stoi(line);
		getline(ss2, line, ',');
		ET_percent = stoi(line);
		getline(ss2, line, ',');
		EG_percent = stoi(line);
		getline(ss2, line, ',');
		EEU_percent = stoi(line);

		getline(file, line);
		stringstream ss3(line);
		getline(ss3, line, ',');
		AS_percent = stoi(line);
		getline(ss3, line, ',');
		AM_percent = stoi(line);
		getline(ss3, line, ',');
		AD_percent = stoi(line);

		getline(file, line);
		prob = stoi(line);

		getline(file, line);
		stringstream ss5(line);
		getline(ss5, line, '-');
		E_minPower = stoi(line);
		getline(ss5, line, ',');
		E_maxPower = stoi(line);
		getline(ss5, line, '-');
		E_minHealth = stoi(line);
		getline(ss5, line, ',');
		E_maxHealth = stoi(line);
		getline(ss5, line, '-');
		E_minAttCap = stoi(line);
		getline(ss5, line, ',');
		E_maxAttCap = stoi(line);

		getline(file, line);
		stringstream ss6(line);
		getline(ss6, line, '-');
		A_minPower = stoi(line);
		getline(ss6, line, ',');
		A_maxPower = stoi(line);
		getline(ss6, line, '-');
		A_minHealth = stoi(line);
		getline(ss6, line, ',');
		A_maxHealth = stoi(line);
		getline(ss6, line, '-');
		A_minAttCap = stoi(line);
		getline(ss6, line, ',');
		A_maxAttCap = stoi(line);
		
		getline(file, line);
		Infection_prob = stoi(line);

		file.close();
	}

	//Hard Input File
	if (n == 3)
	{
		ifstream file("StrongEarth_ModerateAliens.txt");
		if (!file.is_open()) {
			cout << "Input File not founded" << endl;
			return;
		}

		string line;

		getline(file, line);
		armyUnitsNo = stoi(line);

		getline(file, line);
		stringstream ss2(line);
		getline(ss2, line, ',');
		ES_percent = stoi(line);
		getline(ss2, line, ',');
		ET_percent = stoi(line);
		getline(ss2, line, ',');
		EG_percent = stoi(line);
		getline(ss2, line, ',');
		EEU_percent = stoi(line);

		getline(file, line);
		stringstream ss3(line);
		getline(ss3, line, ',');
		AS_percent = stoi(line);
		getline(ss3, line, ',');
		AM_percent = stoi(line);
		getline(ss3, line, ',');
		AD_percent = stoi(line);

		getline(file, line);
		prob = stoi(line);

		getline(file, line);
		stringstream ss5(line);
		getline(ss5, line, '-');
		E_minPower = stoi(line);
		getline(ss5, line, ',');
		E_maxPower = stoi(line);
		getline(ss5, line, '-');
		E_minHealth = stoi(line);
		getline(ss5, line, ',');
		E_maxHealth = stoi(line);
		getline(ss5, line, '-');
		E_minAttCap = stoi(line);
		getline(ss5, line, ',');
		E_maxAttCap = stoi(line);

		getline(file, line);
		stringstream ss6(line);
		getline(ss6, line, '-');
		A_minPower = stoi(line);
		getline(ss6, line, ',');
		A_maxPower = stoi(line);
		getline(ss6, line, '-');
		A_minHealth = stoi(line);
		getline(ss6, line, ',');
		A_maxHealth = stoi(line);
		getline(ss6, line, '-');
		A_minAttCap = stoi(line);
		getline(ss6, line, ',');
		A_maxAttCap = stoi(line);

		getline(file, line);
		Infection_prob = stoi(line);

		file.close();
	}
	if (n == 4)
	{
		ifstream file("StrongEarth_StrongAliens.txt");
		if (!file.is_open()) {
			cout << "Input File not founded" << endl;
			return;
		}

		string line;

		getline(file, line);
		armyUnitsNo = stoi(line);

		getline(file, line);
		stringstream ss2(line);
		getline(ss2, line, ',');
		ES_percent = stoi(line);
		getline(ss2, line, ',');
		ET_percent = stoi(line);
		getline(ss2, line, ',');
		EG_percent = stoi(line);
		getline(ss2, line, ',');
		EEU_percent = stoi(line);

		getline(file, line);
		stringstream ss3(line);
		getline(ss3, line, ',');
		AS_percent = stoi(line);
		getline(ss3, line, ',');
		AM_percent = stoi(line);
		getline(ss3, line, ',');
		AD_percent = stoi(line);

		getline(file, line);
		prob = stoi(line);

		getline(file, line);
		stringstream ss5(line);
		getline(ss5, line, '-');
		E_minPower = stoi(line);
		getline(ss5, line, ',');
		E_maxPower = stoi(line);
		getline(ss5, line, '-');
		E_minHealth = stoi(line);
		getline(ss5, line, ',');
		E_maxHealth = stoi(line);
		getline(ss5, line, '-');
		E_minAttCap = stoi(line);
		getline(ss5, line, ',');
		E_maxAttCap = stoi(line);

		getline(file, line);
		stringstream ss6(line);
		getline(ss6, line, '-');
		A_minPower = stoi(line);
		getline(ss6, line, ',');
		A_maxPower = stoi(line);
		getline(ss6, line, '-');
		A_minHealth = stoi(line);
		getline(ss6, line, ',');
		A_maxHealth = stoi(line);
		getline(ss6, line, '-');
		A_minAttCap = stoi(line);
		getline(ss6, line, ',');
		A_maxAttCap = stoi(line);

		getline(file, line);
		Infection_prob = stoi(line);

		file.close();
	}

	if (n == 5)
	{
		ifstream file("WeakEarth_WeakAliens.txt");
		if (!file.is_open()) {
			cout << "Input File not founded" << endl;
			return;
		}

		string line;

		getline(file, line);
		armyUnitsNo = stoi(line);

		getline(file, line);
		stringstream ss2(line);
		getline(ss2, line, ',');
		ES_percent = stoi(line);
		getline(ss2, line, ',');
		ET_percent = stoi(line);
		getline(ss2, line, ',');
		EG_percent = stoi(line);
		getline(ss2, line, ',');
		EEU_percent = stoi(line);

		getline(file, line);
		stringstream ss3(line);
		getline(ss3, line, ',');
		AS_percent = stoi(line);
		getline(ss3, line, ',');
		AM_percent = stoi(line);
		getline(ss3, line, ',');
		AD_percent = stoi(line);

		getline(file, line);
		prob = stoi(line);

		getline(file, line);
		stringstream ss5(line);
		getline(ss5, line, '-');
		E_minPower = stoi(line);
		getline(ss5, line, ',');
		E_maxPower = stoi(line);
		getline(ss5, line, '-');
		E_minHealth = stoi(line);
		getline(ss5, line, ',');
		E_maxHealth = stoi(line);
		getline(ss5, line, '-');
		E_minAttCap = stoi(line);
		getline(ss5, line, ',');
		E_maxAttCap = stoi(line);

		getline(file, line);
		stringstream ss6(line);
		getline(ss6, line, '-');
		A_minPower = stoi(line);
		getline(ss6, line, ',');
		A_maxPower = stoi(line);
		getline(ss6, line, '-');
		A_minHealth = stoi(line);
		getline(ss6, line, ',');
		A_maxHealth = stoi(line);
		getline(ss6, line, '-');
		A_minAttCap = stoi(line);
		getline(ss6, line, ',');
		A_maxAttCap = stoi(line);

		getline(file, line);
		Infection_prob = stoi(line);

		file.close();
	}

	if (n == 6)
	{
		ifstream file("WeakEarth_ModerateAliens.txt");
		if (!file.is_open()) {
			cout << "Input File not founded" << endl;
			return;
		}

		string line;

		getline(file, line);
		armyUnitsNo = stoi(line);

		getline(file, line);
		stringstream ss2(line);
		getline(ss2, line, ',');
		ES_percent = stoi(line);
		getline(ss2, line, ',');
		ET_percent = stoi(line);
		getline(ss2, line, ',');
		EG_percent = stoi(line);
		getline(ss2, line, ',');
		EEU_percent = stoi(line);

		getline(file, line);
		stringstream ss3(line);
		getline(ss3, line, ',');
		AS_percent = stoi(line);
		getline(ss3, line, ',');
		AM_percent = stoi(line);
		getline(ss3, line, ',');
		AD_percent = stoi(line);

		getline(file, line);
		prob = stoi(line);

		getline(file, line);
		stringstream ss5(line);
		getline(ss5, line, '-');
		E_minPower = stoi(line);
		getline(ss5, line, ',');
		E_maxPower = stoi(line);
		getline(ss5, line, '-');
		E_minHealth = stoi(line);
		getline(ss5, line, ',');
		E_maxHealth = stoi(line);
		getline(ss5, line, '-');
		E_minAttCap = stoi(line);
		getline(ss5, line, ',');
		E_maxAttCap = stoi(line);

		getline(file, line);
		stringstream ss6(line);
		getline(ss6, line, '-');
		A_minPower = stoi(line);
		getline(ss6, line, ',');
		A_maxPower = stoi(line);
		getline(ss6, line, '-');
		A_minHealth = stoi(line);
		getline(ss6, line, ',');
		A_maxHealth = stoi(line);
		getline(ss6, line, '-');
		A_minAttCap = stoi(line);
		getline(ss6, line, ',');
		A_maxAttCap = stoi(line);

		getline(file, line);
		Infection_prob = stoi(line);

		file.close();
	}

	if (n == 7)
	{
		ifstream file("WeakEarth_StrongAliens.txt");
		if (!file.is_open()) {
			cout << "Input File not founded" << endl;
			return;
		}

		string line;

		getline(file, line);
		armyUnitsNo = stoi(line);

		getline(file, line);
		stringstream ss2(line);
		getline(ss2, line, ',');
		ES_percent = stoi(line);
		getline(ss2, line, ',');
		ET_percent = stoi(line);
		getline(ss2, line, ',');
		EG_percent = stoi(line);
		getline(ss2, line, ',');
		EEU_percent = stoi(line);

		getline(file, line);
		stringstream ss3(line);
		getline(ss3, line, ',');
		AS_percent = stoi(line);
		getline(ss3, line, ',');
		AM_percent = stoi(line);
		getline(ss3, line, ',');
		AD_percent = stoi(line);

		getline(file, line);
		prob = stoi(line);

		getline(file, line);
		stringstream ss5(line);
		getline(ss5, line, '-');
		E_minPower = stoi(line);
		getline(ss5, line, ',');
		E_maxPower = stoi(line);
		getline(ss5, line, '-');
		E_minHealth = stoi(line);
		getline(ss5, line, ',');
		E_maxHealth = stoi(line);
		getline(ss5, line, '-');
		E_minAttCap = stoi(line);
		getline(ss5, line, ',');
		E_maxAttCap = stoi(line);

		getline(file, line);
		stringstream ss6(line);
		getline(ss6, line, '-');
		A_minPower = stoi(line);
		getline(ss6, line, ',');
		A_maxPower = stoi(line);
		getline(ss6, line, '-');
		A_minHealth = stoi(line);
		getline(ss6, line, ',');
		A_maxHealth = stoi(line);
		getline(ss6, line, '-');
		A_minAttCap = stoi(line);
		getline(ss6, line, ',');
		A_maxAttCap = stoi(line);

		getline(file, line);
		Infection_prob = stoi(line);

		file.close();
	}


	// set the values form the input file 
	randGenObj.setProb(prob);

	randGenObj.setArmyUnitsNo(armyUnitsNo);

	randGenObj.setES_percent(ES_percent);
	randGenObj.setET_percent(ET_percent);
	randGenObj.setEG_percent(EG_percent);
	randGenObj.setEEU_percent(EEU_percent);
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

	randGenObj.setInfection_prob(Infection_prob);
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
