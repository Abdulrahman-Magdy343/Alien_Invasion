#include "ArmyUnit.h"
#include "Game.h"
#include <string>




ArmyUnit::ArmyUnit(int ID, int health, int power, int cap, UnitType type, int timeStamp, Game* pg) 
    : ID(ID), health(health), initialHealth(health), power(power), capacity(cap), type(type), joinTime(timeStamp), Pgame(pg) {}

ArmyUnit::ArmyUnit()
{
}

// Setters
void ArmyUnit::setID(int id) {
    ID = id;
}

void ArmyUnit::setType(UnitType unitType) {
    type = unitType;
}

void ArmyUnit::setJoinTime(int timePoint) {
    joinTime = timePoint;
}

void ArmyUnit::setHealth(int unitHealth) {
    health = unitHealth;
}

void ArmyUnit::setPower(int unitPower) {
    power = unitPower;
}

void ArmyUnit::setCapacity(int unitCapacity) {
    capacity = unitCapacity;
}

void ArmyUnit::setPgame(Game* pg) {
    Pgame = pg;
}
void ArmyUnit::setTa(int ta) {
    if (!hasBeenAttacked)
    {
        Ta = ta;
        setDf(Ta - joinTime);
        hasBeenAttacked = true;
    }
}

void ArmyUnit::setTd(int td) {
    Td = td;
    setDd(Td - Ta);
    setDb(Td - joinTime);
}

void ArmyUnit::setDf(int df) {
    Df = df;
}

void ArmyUnit::setDd(int dd) {
    Dd = dd;
}

void ArmyUnit::setDb(int db) {
    Db = db;
}

// Getters


string ArmyUnit::getID() const  {
   
        return to_string(ID);
    
}


UnitType ArmyUnit::getType() const {
    return type;
}

int ArmyUnit::getJoinTime() const
{
    return joinTime;

}


int ArmyUnit::getHealth() const {
    return health;
}

int ArmyUnit::getInitialHealth() const
{
    return initialHealth;
}

int ArmyUnit::getPower() const {
    return power;
}

int ArmyUnit::getCapacity() const {
    return capacity;
}

Game* ArmyUnit::getPgame() const {
    return Pgame;
}

bool ArmyUnit::gethasbeenattacked()
{
    return hasBeenAttacked;
}

int ArmyUnit::getTa() const {
    return Ta;
}

int ArmyUnit::getTd() const {
    return Td;
}

int ArmyUnit::getDf() const {
    return Df;
}

int ArmyUnit::getDd() const {
    return Dd;
}

int ArmyUnit::getDb() const {
    return Db;
}

void ArmyUnit::setHasBeenAttacked(bool attacked)
{
    hasBeenAttacked = attacked;
}


