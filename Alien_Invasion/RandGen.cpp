#include "RandGen.h"

// Constructor

// memo was here



RandGen::RandGen(AlienArmy& alien, EarthArmy& earth) : alienArmy(alien), earthArmy(earth)
{
    armyUnitsNo = 0;
    ES_percent = 0;
    ET_percent = 0;
    EG_percent = 0;
    AS_percent = 0;
    AM_percent = 0;
    AD_percent = 0;
    prob = 0.0;
}



void RandGen::setGame(Game* game)
{
    pg = game;
}

void RandGen::setTimeStep(int time)
{
    timeStep = time;
}



// Setters
void RandGen::setArmyUnitsNo(int units) {
    armyUnitsNo = units;
}

void RandGen::setES_percent(int percent) {
    ES_percent = percent;
}

void RandGen::setET_percent(int percent) {
    ET_percent = percent;
}

void RandGen::setEG_percent(int percent) {
    EG_percent = percent;
}

void RandGen::setAS_percent(int percent) {
    AS_percent = percent;
}

void RandGen::setAM_percent(int percent) {
    AM_percent = percent;
}

void RandGen::setAD_percent(int percent) {
    AD_percent = percent;
}

void RandGen::setProb(int probability) {
    prob = probability;
}

void RandGen::setE_minPower(int minRange)
{
    E_minPower = minRange;
}

void RandGen::setE_maxPower(int maxRange)
{
    E_maxPower = maxRange;
}

void RandGen::setE_minHealth(int minHealth)
{
    E_minHealth = minHealth;
}

void RandGen::setE_maxHealth(int maxHealth)
{
    E_maxHealth = maxHealth;
}

void RandGen::setE_minAttCap(int minAttCap)
{
    E_minAttCap = minAttCap;
}

void RandGen::setE_maxAttCap(int maxAttCap)
{
    E_maxAttCap = maxAttCap;
}

void RandGen::setA_minPower(int minRange)
{
    A_minPower = minRange;
}

void RandGen::setA_maxPower(int maxRange)
{
    A_maxPower = maxRange;
}

void RandGen::setA_minHealth(int minHealth)
{
    A_minHealth = minHealth;
}

void RandGen::setA_maxHealth(int maxHealth)
{
    A_maxHealth = maxHealth;
}

void RandGen::setA_minAttCap(int minAttCap)
{
    A_minAttCap = minAttCap;
}

void RandGen::setA_maxAttCap(int maxAttCap)
{
    A_maxAttCap = maxAttCap;
}



Game* RandGen::getGame() const
{
    return pg;
}

int RandGen::getTimeStep() const
{
    return timeStep;
}

// Getters
int RandGen::getArmyUnitsNo() const {
    return armyUnitsNo;
}

int RandGen::getES_percent() const {
    return ES_percent;
}

int RandGen::getET_percent() const {
    return ET_percent;
}

int RandGen::getEG_percent() const {
    return EG_percent;
}

int RandGen::getAS_percent() const {
    return AS_percent;
}

int RandGen::getAM_percent() const {
    return AM_percent;
}

int RandGen::getAD_percent() const {
    return AD_percent;
}

int RandGen::getProb() const {
    return prob;
}

int RandGen::getE_minPower() const
{
    return E_minPower;
}

int RandGen::getE_maxPower() const
{
    return E_maxPower;
}

int RandGen::getE_minHealth() const
{
    return E_minHealth;
}

int RandGen::getE_maxHelth() const
{
    return E_maxHealth;
}

int RandGen::getE_minAttCap() const
{
    return E_minAttCap;
}

int RandGen::getE_maxAttCap() const
{
    return E_maxAttCap;
}

int RandGen::getA_minPower() const
{
    return A_minPower;
}

int RandGen::getA_maxPower() const
{
    return A_maxPower;
}

int RandGen::getA_minHealth() const
{
    return A_minHealth;
}

int RandGen::getA_maxHealth() const
{
    return A_maxHealth;
}

int RandGen::getA_minAttCap() const
{
    return A_minAttCap;
}

int RandGen::getA_maxAttCap() const
{
    return A_maxAttCap;
}

//void RandGen::setEarthPowerLimits(int upLimit, int lowLimit) {
//    EarthPowerUplimit = upLimit;
//    EarthPowerLowLimit = lowLimit;
//}
//
//void RandGen::setEarthHealthLimits(int upLimit, int lowLimit) {
//    EarthHealthUplimit = upLimit;
//    EarthHealthLowLimit = lowLimit;
//}
//
//void RandGen::setEarthAttCapLimits(int upLimit, int lowLimit) {
//    EarthAttCapUplimit = upLimit;
//    EarthAttCapLowLimit = lowLimit;
//}
//
//// Setters for Alien entity limits
//void RandGen::setAlienPowerLimits(int upLimit, int lowLimit) {
//    AlienPowerUplimit = upLimit;
//    AlienPowerLowLimit = lowLimit;
//}
//
//void RandGen::setAlienHealthLimits(int upLimit, int lowLimit) {
//    AlienHealthUplimit = upLimit;
//    AlienHealthLowLimit = lowLimit;
//}
//
//void RandGen::setAlienAttCapLimits(int upLimit, int lowLimit) {
//    AlienAttCapUplimit = upLimit;
//    AlienAttCapLowLimit = lowLimit;
//}
//
//// Getters for Earth entity limits
//int RandGen::getEarthPowerUpLimit() const {
//    return EarthPowerUplimit;
//}
//
//int RandGen::getEarthPowerLowLimit() const {
//    return EarthPowerLowLimit;
//}
//
//int RandGen::getEarthHealthUpLimit() const {
//    return EarthHealthUplimit;
//}
//
//int RandGen::getEarthHealthLowLimit() const {
//    return EarthHealthLowLimit;
//}
//
//int RandGen::getEarthAttCapUpLimit() const {
//    return EarthAttCapUplimit;
//}
//
//int RandGen::getEarthAttCapLowLimit() const {
//    return EarthAttCapLowLimit;
//}
//
//// Getters for Alien entity limits
//int RandGen::getAlienPowerUpLimit() const {
//    return AlienPowerUplimit;
//}
//
//int RandGen::getAlienPowerLowLimit() const {
//    return AlienPowerLowLimit;
//}
//
//int RandGen::getAlienHealthUpLimit() const {
//    return AlienHealthUplimit;
//}
//
//int RandGen::getAlienHealthLowLimit() const {
//    return AlienHealthLowLimit;
//}
//
//int RandGen::getAlienAttCapUpLimit() const {
//    return AlienAttCapUplimit;
//}
//
//int RandGen::getAlienAttCapLowLimit() const {
//    return AlienAttCapLowLimit;
//}

void RandGen::generate()
{
    srand(time(0));
    A = (1 + rand() % 100);
    if (A < prob || timeStep == 0) {
        for (int i = 0; i < armyUnitsNo; i++) //loop to generate units of earth army
        {
            B = (1 + rand() % 100);

            int power, health, attCapacity; // random generation of pow, health, and attCap of each unit
            power = E_minPower + rand() % (E_maxPower - E_minPower);
            health = E_minHealth + rand() % (E_maxHealth - E_minHealth);
            attCapacity = E_minAttCap + rand() % (E_maxAttCap - E_minAttCap);

            if (B <= ES_percent)
            {
                EarthSoldier* newUnit = new EarthSoldier(health, power, attCapacity, timeStep, pg);
                earthArmy.addUnit(newUnit);
            }
            else if (B <= ES_percent + ET_percent)
            {
                EarthTank* newUnit = new EarthTank(health, power, attCapacity, timeStep, pg);
                earthArmy.addUnit(newUnit);
            }
            else if (B <= ES_percent + ET_percent + EG_percent)
            {
                EarthGunnery* newUnit = new EarthGunnery(health, power, attCapacity, timeStep, pg);
                earthArmy.addUnit(newUnit);
            }
            else
            {
                HealUnit* newUnit = new HealUnit(health, power, attCapacity, timeStep, pg);
                earthArmy.addUnit(newUnit);
            }

        }

        for (int i = 0; i < armyUnitsNo; i++) //loop to generate units of alien army
        {
            B = (1 + rand() % 100);

            int power, health, attCapacity;
            power = A_minPower + rand() % (A_maxPower - A_minPower);
            health = A_minHealth + rand() % (A_maxHealth - A_minHealth);
            attCapacity = A_minAttCap + rand() % (A_maxAttCap - A_minAttCap);

            if (B <= AS_percent)
            {
                AlienSoldier* newUnit = new AlienSoldier(health, power, attCapacity, timeStep, pg);
                alienArmy.addUnit(newUnit);
            }
            else if (B <= AS_percent + AM_percent)
            {
                AlienMonster* newUnit = new AlienMonster(health, power, attCapacity, timeStep, pg);
                alienArmy.addUnit(newUnit);
            }
            else
            {
                AlienDrone* newUnit = new AlienDrone(health, power, attCapacity, timeStep, pg);
                alienArmy.addUnit(newUnit);
            }

        }

    }
    else
        return;
}