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
	outputFile << "\n\nBattle Statistics for " << armyName << " Army:\n";

	int totalUnits = 0;
	int totalDestroyed = 0;
	int ES_total = 0, ET_total = 0, EG_total = 0;
	int ES_destroyed = 0, ET_destroyed = 0, EG_destroyed = 0;
	double totalDf = 0, totalDd = 0, totalDb = 0;

	// Earth Army Statistics
	ES_total = earthArmy.getEarthSoldiers().getCount();
	ET_total = earthArmy.getTanks().getCount();
	EG_total = earthArmy.getEarthGunneries().getCount();
	totalUnits = ES_total + ET_total + EG_total;

	// Count destroyed units in killedList
	ArmyUnit* ptr;
	killedList.peek(ptr);
	Node<ArmyUnit*>* current = killedList.Getfront();
	while (current != nullptr) {
		ArmyUnit* unit = current->getItem();
		switch (unit->getType()) {
		case ES:
			ES_destroyed++;
			break;
		case ET:
			ET_destroyed++;
			break;
		case EG:
			EG_destroyed++;
			break;
		}

		totalDf += unit->getDf();
		totalDd += unit->getDd();
		totalDb += unit->getDb();

		current = current->getNext();
	}
	totalDestroyed = ES_destroyed + ET_destroyed + EG_destroyed;

	// Output statistics to file
	outputFile << "- Total number of each unit (ES, ET, EG): "
		<< ES_total << ", " << ET_total << ", " << EG_total << endl;


	// ... (Output percentages of destroyed units for each type)

	outputFile << "- Percentage of total destroyed units relative to total units: "
		<< (double)totalDestroyed / totalUnits * 100 << "%" << endl;

	outputFile << "- Average of Df: " << totalDf / totalDestroyed << endl;
	outputFile << "- Average of Dd: " << totalDd / totalDestroyed << endl;
	outputFile << "- Average of Db: " << totalDb / totalDestroyed << endl;
	outputFile << "- Df/Db %: " << (totalDf / totalDb) * 100 << "%" << endl;
	outputFile << "- Dd/Db %: " << (totalDd / totalDb) * 100 << "%" << endl;
}


void Game::writeArmyStatistics(ofstream& outputFile, AlienArmy& alienArmy, string armyName) {
	outputFile << "\n\nBattle Statistics for " << armyName << " Army:\n";

	int totalUnits = 0;
	int totalDestroyed = 0;
	int AS_total = 0, AM_total = 0, AD_total = 0;
	int AS_destroyed = 0, AM_destroyed = 0, AD_destroyed = 0;
	double totalDf = 0, totalDd = 0, totalDb = 0;

	// Alien Army Statistics - similar to Earth Army statistics calculation
	AS_total = alienArmy.getAlienSoldiers().getCount();
	AM_total = alienArmy.getMonstersCount();
	AD_total = alienArmy.getAlienDrones().getCount();
	totalUnits = AS_total + AM_total + AD_total;

	// Count destroyed units in killedList
	Node<ArmyUnit*>* current = killedList.Getfront();
	while (current != nullptr) {
		ArmyUnit* unit = current->getItem();
		switch (unit->getType()) {
		case AS:
			AS_destroyed++;
			break;
		case AM:
			AM_destroyed++;
			break;
		case AD:
			AD_destroyed++;
			break;
		}

		totalDf += unit->getDf();
		totalDd += unit->getDd();
		totalDb += unit->getDb();

		current = current->getNext();
	}
	totalDestroyed = AS_destroyed + AM_destroyed + AD_destroyed;

	// Output statistics to file
	outputFile << "- Total number of each unit (AS, AM, AD): "
		<< AS_total << ", " << AM_total << ", " << AD_total << endl;


	// ... (Output percentages of destroyed units for each type)

	outputFile << "- Percentage of total destroyed units relative to total units: "
		<< (double)totalDestroyed / totalUnits * 100 << "%" << endl;

	outputFile << "- Average of Df: " << totalDf / totalDestroyed << endl;
	outputFile << "- Average of Dd: " << totalDd / totalDestroyed << endl;
	outputFile << "- Average of Db: " << totalDb / totalDestroyed << endl;
	outputFile << "- Df/Db %: " << (totalDf / totalDb) * 100 << "%" << endl;
	outputFile << "- Dd/Db %: " << (totalDd / totalDb) * 100 << "%" << endl;
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
	writeArmyStatistics(outputFile, earthArmy, "Earth");
	writeArmyStatistics(outputFile, alienArmy, "Alien");

	outputFile.close();
	cout << "Output file '" << filename << "' generated successfully." << endl;
}

int Game::getInfectionProb()
{
	return randGenObj.getInfection_prob();
}
