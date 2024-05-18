#pragma once
#include "ArmyUnit.h"
#include "ArrayStack.h" // Might need adjustment based on your implementation
#include "LinkedQueue.h" // Might need adjustment based on your implementation
#include "priQueue.h"     // Might need adjustment based on your implementation

class Game;

class EarthArmyUnit :
	public ArmyUnit
{
public:
	static int nextId; // Static variable to keep track of the next available ID

	// Constructors
	EarthArmyUnit();
	EarthArmyUnit(int health, int power, int cap, int timeStamp, UnitType type, Game* pg = nullptr); // Optional Game pointer

	virtual void attack() = 0; // Pure virtual function for attack (forces derived classes to implement)
};

class EarthSoldier : public EarthArmyUnit {
	int UMLjoinTime;
	bool isInfected;
	bool isImmune;
public:
	// Constructors
	EarthSoldier();
	EarthSoldier(int health, int power, int cap, int timeStamp, Game* pg = nullptr); // Optional Game pointer
	void setUMLjoinTime(int Tj);
	int getUMLjoinTime();
	void beInfected();
	void attack() override; // Override pure virtual function
	string getID();
	bool getIsInfected();
};

class EarthTank : public EarthArmyUnit {
	int UMLjoinTime;
public:
	// Constructors
	EarthTank();
	EarthTank(int health, int power, int cap, int timeStamp, Game* pg = nullptr); // Optional Game pointer
	void setUMLjoinTime(int Tj);
	int getUMLjoinTime();
	void attack() override; // Override pure virtual function
};

class EarthGunnery : public EarthArmyUnit {
public:
	// Constructors
	EarthGunnery();
	EarthGunnery(int health, int power, int cap, int timeStamp, Game* pg = nullptr); // Optional Game pointer

	void attack() override; // Override pure virtual function
};

class HealUnit :public EarthArmyUnit {
public:
	HealUnit();
	HealUnit(int health, int power, int cap, int timeStamp, Game* pg = nullptr);
	bool shouldBeDestroyed = false;
	void attack() override;
};