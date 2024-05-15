#pragma once
using namespace std;

class Game;

enum UnitType
{
	ES, // Earth Solider
	ET, // Earth Tank
	EG, // Earth Gunnery
	HU, // Heal Unit
	AS, // Alien Solider
	AM, // Alien Monster
	AD // Alien Drone
};
class ArmyUnit
{
protected:
	int ID;
	UnitType type;
	int joinTime;
	int health;
	int initialHealth;
	int power;
	int capacity;
	Game* Pgame;

	// Output file parameters

	int Ta; //First Attack time
	int Td; //destruction time
	int Df; //First Attack delay
	int Dd; //Destruction delay
	int Db; //Battle time

	bool hasBeenAttacked = false;
public:
	ArmyUnit(int ID, int health, int power, int cap, UnitType type, int timeStamp, Game* pg);
	ArmyUnit();
	// Setters
	void setID(int id);
	void setType(UnitType unitType);
	void setJoinTime(int timePoint);
	void setHealth(int unitHealth);
	void setPower(int unitPower);
	void setCapacity(int unitCapacity);
	void setPgame(Game* pg);

	void setTa(int ta);
	void setTd(int td);
	void setDf(int df);
	void setDd(int dd);
	void setDb(int db);

	// Getters
	int getID() const;
	UnitType getType() const;
	int getJoinTime() const;
	int getHealth() const;
	int getInitialHealth() const;
	int getPower() const;
	int getCapacity() const;
	Game* getPgame() const;
	bool gethasbeenattacked();
	bool isAlive() const { 
		return health > 0;
	}

	int getTa() const;
	int getTd() const;
	int getDf() const;
	int getDd() const;
	int getDb() const;
	void setHasBeenAttacked(bool attacked);



	// Functionalities
	virtual void attack() = 0;
};

