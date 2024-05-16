#pragma once
#include "ArmyUnit.h"
#include "ArrayStack.h" // Might need adjustment based on your implementation
#include "LinkedQueue.h" // Might need adjustment based on your implementation
#include "priQueue.h"     // Might need adjustment based on your implementation

class Game;

class SUArmyUnit :
	public ArmyUnit
{
public:
	static int nextId; // Static variable to keep track of the next available ID

	// Constructors
	SUArmyUnit();
	SUArmyUnit(int health, int power, int cap, Game* pg = nullptr); // Optional Game pointer


	void attack() override; // Pure virtual function for attack (forces derived classes to implement)
};