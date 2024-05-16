#include "Game.h"

Game::Game(): randGenObj(alienArmy, earthArmy)
{
	GameOn = true;
	SilentMode = false;
}

void Game::go()
{
	randGenObj.setGame(this);
	ReadFormInputFile();
	cout << "Enter 1 for NormalMode " << endl << "Enter 2 for SilentMode" << endl;;
	int x=0;
	while (x != 1 && x != 2) {
		cin >> x;
		if (x == 1)SilentMode = false;
		else if (x == 2) {
			SilentMode = true;
			cout << "SilentMode" << endl<<"Simualation Started...."<<endl;
		}
		else
		{
			cout << "Please enter correct number" << endl;
		}


	}
	
	
	timeStep = 0;

	while(GameOn)
	{
		
		randGenObj.generate(timeStep);

		earthArmy.Attack();
		alienArmy.Attack();
		earthArmy.infectionSpread();

		//Printing Part
		if (!SilentMode) {
			cout << "Current timestep: " << timeStep << endl;
			earthArmy.Print();
			alienArmy.Print();
			cout << "================= Killed list ================" << endl;
			cout << killedList.getCount() << " units [";
			killedList.print();
			cout << "]\n";
			cout << "Infection Percentage : " << this->getEarthArmy()->getNumOfInfectedSoldiers() << endl;
			cout << "Press any char to continoue and E for Exit" << endl;
			char x;
			cin >> x;
			cout << "\n\n\n";
			if (x == 'e' || x == 'E')GameOn = false;
		}
		else {
			if (timeStep == 1000) {
				GameOn = false;
			}
		}
	

		
		
		// at end of each iteration
		timeStep++;


	}
	cout << "Simulation Ended" << endl;
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
	int threshold;

	//Choose Input file difficulty
	int n = 0;
	cout << "Choose difficulty level  \n1- ModerateEarth ModerateAliens \n2- StrongEarth WeakAliens" <<
		"\n3- StrongEarth ModerateAliens \n4- StrongEarth StrongAliens \n5- WeakEarth WeakAliens " <<
		"\n6- WeakEarth ModerateAliens \n7- WeakEarth StrongAliens " << endl;
	cin >> n;
	while (n <= 0 || n > 7)
	{ 
		cout << "----->Enter a valid number<----- \n";
		cout << "Choose difficulty level  \n1- ModerateEarth ModerateAliens \n2- StrongEarth WeakAliens" <<
			"\n3- StrongEarth ModerateAliens \n4- StrongEarth StrongAliens \n5- WeakEarth WeakAliens "<<
			"\n6- WeakEarth ModerateAliens \n7- WeakEarth StrongAliens " << endl;
	cin >> n;
	}
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
		getline(file, line);
		threshold = stoi(line);
		
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
		getline(file, line);
		threshold = stoi(line);

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
		getline(file, line);
		threshold = stoi(line);

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
		getline(file, line);
		threshold = stoi(line);

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
		getline(file, line);
		threshold = stoi(line);

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
		getline(file, line);
		threshold = stoi(line);

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
		getline(file, line);
		threshold = stoi(line);

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
	randGenObj.setThreshold(threshold);
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
	unit->setHealth(0);
	unit->setTd(timeStep);
	killedList.enqueue(unit);
}

int Game::getTimeStep()
{
	return timeStep;
}

bool Game::GetSilentMode()
{
	return SilentMode;
}

EarthArmy* Game::getEarthArmy()
{
	return &earthArmy;
}

AlienArmy* Game::getAlienArmy()
{
	return &alienArmy;
}


void Game::writeArmyStatistics(ofstream& outputFile, EarthArmy& earthArmy, string armyName) {
	
}


void Game::writeArmyStatistics(ofstream& outputFile, EarthArmy& earthArmy, AlienArmy& alienArmy, string armyName1, string armyName2) {
	outputFile << "\n\nBattle Statistics for " << armyName1 << " Army:\n";

	int totalUnitsE = 0;
	int totalDestroyedE = 0;
	int ES_totalE = 0, ET_totalE = 0, EG_totalE = 0;
	int ES_destroyedE = 0, ET_destroyedE = 0, EG_destroyedE = 0;
	double totalDfE = 0, totalDdE = 0, totalDbE = 0;
	int totalUnitsA = 0;
	int totalDestroyedA = 0;
	int AS_totalA = 0, AM_totalA = 0, AD_totalA = 0;
	int AS_destroyedA = 0, AM_destroyedA = 0, AD_destroyedA = 0;
	double totalDfA = 0, totalDdA = 0, totalDbA = 0;

	// Earth Army Statistics
	ES_totalE = earthArmy.getEarthSoldiers().getCount();
	ET_totalE = earthArmy.getTanks().getCount();
	EG_totalE = earthArmy.getEarthGunneries().getCount();
	totalUnitsE = ES_totalE + ET_totalE + EG_totalE;

	// Alien Army Statistics - similar to Earth Army statistics calculation
	AS_totalA = alienArmy.getAlienSoldiers().getCount();
	AM_totalA = alienArmy.getMonstersCount();
	AD_totalA = alienArmy.getAlienDrones().getCount();
	totalUnitsA = AS_totalA + AM_totalA + AD_totalA;
	// Count destroyed units in killedList
	ArmyUnit* unit;


	while (killedList.dequeue(unit)) {
		cout << unit->getType()<< endl;
		switch (unit->getType()) {
		case AS:
			AS_destroyedA++;
			totalDfA += unit->getDf();
			totalDdA += unit->getDd();
			totalDbA += unit->getDb();
			break;
		case AM:
			AM_destroyedA++;
			totalDfA += unit->getDf();
			totalDdA += unit->getDd();
			totalDbA += unit->getDb();
			break;
		case AD:
			AD_destroyedA++;
			totalDfA += unit->getDf();
			totalDdA += unit->getDd();
			totalDbA += unit->getDb();
			break;

		case ES:
			ES_destroyedE++;
			totalDfE += unit->getDf();
			totalDdE += unit->getDd();
			totalDbE += unit->getDb();
			break;
		case ET:
			ET_destroyedE++;
			totalDfE += unit->getDf();
			totalDdE += unit->getDd();
			totalDbE += unit->getDb();
			break;
		case EG:
			EG_destroyedE++;
			totalDfE += unit->getDf();
			totalDdE += unit->getDd();
			totalDbE += unit->getDb();
			break;
		}

		
		


	}
	totalDestroyedA = AS_destroyedA + AM_destroyedA+ AD_destroyedA;
	totalDestroyedE = ES_destroyedE + ET_destroyedE + EG_destroyedE;

	// Output statistics to file
	outputFile << "- Total number of each unit (ES, ET, EG): "
		<< ES_totalE << ", " << ET_totalE << ", " << EG_totalE << endl;


	// ... (Output percentages of destroyed units for each type)

	outputFile << "- Percentage of total destroyed units relative to total units: "
		<< (double)totalDestroyedE / totalUnitsE * 100 << "%" << endl;

	outputFile << "- Average of Df: " << totalDfE / totalDestroyedE << endl;
	outputFile << "- Average of Dd: " << totalDdE / totalDestroyedE << endl;
	outputFile << "- Average of Db: " << totalDbE / totalDestroyedE << endl;
	outputFile << "- Df/Db %: " << (totalDfE / totalDbE) * 100 << "%" << endl;
	outputFile << "- Dd/Db %: " << (totalDdE / totalDbE) * 100 << "%" << endl;
	outputFile << "\n\nBattle Statistics for " << armyName2 << " Army:\n";



	// Output statistics to file
	outputFile << "- Total number of each unit (AS, AM, AD): "
		<< AS_totalA << ", " << AM_totalA << ", " << AD_totalA << endl;


	// ... (Output percentages of destroyed units for each type)

	outputFile << "- Percentage of total destroyed units relative to total units: "
		<< (double)totalDestroyedA / totalUnitsA * 100 << "%" << endl;

	outputFile << "- Average of Df: " << totalDfA / totalDestroyedA << endl;
	outputFile << "- Average of Dd: " << totalDdA / totalDestroyedA << endl;
	outputFile << "- Average of Db: " << totalDbA / totalDestroyedA << endl;
	outputFile << "- Df/Db %: " << (totalDfA / totalDbA) * 100 << "%" << endl;
	outputFile << "- Dd/Db %: " << (totalDdA/ totalDbA) * 100 << "%" << endl;
}
void Game::generateOutputFile(string filename) {
	ofstream outputFile(filename);

	if (!outputFile.is_open()) {
		cout << "Error: Unable to open output file!" << endl;
		return;
	}

	// Sort the killed list by destruction time (Td)
	killedList.Sort();

	outputFile << "Td\tID\tTj\tDf\tDd\tDb\n";
	Node<ArmyUnit*>* current = killedList.Getfront();

	while (current != nullptr) {
		ArmyUnit* unit = current->getItem();
		outputFile << unit->getTd() << "\t" << unit->getID() << "\t"
			<< unit->getJoinTime() << "\t" << unit->getDf() << "\t"
			<< unit->getDd() << "\t" << unit->getDb() << endl;
		current = current->getNext();
	}

	// Calculate and write statistics for both armies
	writeArmyStatistics(outputFile, earthArmy, alienArmy,  "Earth", "Alien");
	

	outputFile.close();
	cout << "Output file '" << filename << "' generated successfully." << endl;
}

int Game::getInfectionProb()
{
	return randGenObj.getInfection_prob();
}
