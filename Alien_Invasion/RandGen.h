#pragma once
#include <cstdlib>
#include <ctime>
#include "SUArmyunit.h"
#include "EarthArmyUnit.h"
#include "AlienArmyUnit.h"
#include "AlienArmy.h"
#include "EarthArmy.h"
#include "SUArmy.h"
#include <fstream>

class RandGen
{
	int armyUnitsNo;
	int ES_percent, ET_percent, EG_percent, AS_percent, AM_percent, AD_percent, EEU_percent, SU_percent;
    int E_minPower, E_maxPower, E_minHealth, E_maxHealth, E_minAttCap, E_maxAttCap;
    int A_minPower, A_maxPower, A_minHealth, A_maxHealth, A_minAttCap, A_maxAttCap;
    int S_minPower, S_maxPower, S_minHealth, S_maxHealth, S_minAttCap, S_maxAttCap;
	int prob;
    int Infection_prob;
    int threshold;
    int A, B;
   
    Game* pg;
    AlienArmy& alienArmy;
    EarthArmy& earthArmy;
    SUArmy& saviorArmy;

public:
    RandGen(AlienArmy& alien, EarthArmy& earth, SUArmy& saviorArmy);


    // Setters
    void setGame(Game* game);
    void setTimeStep(int time);

    void setArmyUnitsNo(int units);

    void setES_percent(int percent);
    void setET_percent(int percent);
    void setEG_percent(int percent);
    void setEEU_percent(int percent);

    void setAS_percent(int percent);
    void setAM_percent(int percent);
    void setAD_percent(int percent);
    void setSU_percent(int percent);

    void setProb(int probability);

    void setE_minPower(int minRange);
    void setE_maxPower(int maxRange);

    void setE_minHealth(int minHealth);
    void setE_maxHealth(int maxHealth);

    void setE_minAttCap(int minAttCap);
    void setE_maxAttCap(int maxAttCap);

    void setA_minPower(int minRange);
    void setA_maxPower(int maxRange);

    void setA_minHealth(int minHealth);
    void setA_maxHealth(int maxHealth);

    void setA_minAttCap(int minAttCap);
    void setA_maxAttCap(int maxAttCap);

    void setS_minPower(int minRange);
    void setS_maxPower(int maxRange);

    void setS_minHealth(int minHealth);
    void setS_maxHealth(int maxHealth);

    void setS_minAttCap(int minAttCap);
    void setS_maxAttCap(int maxAttCap);

    void setInfection_prob(int Inf_prob);
    void setThreshold(int Threshold);


    // Getters
    Game* getGame() const;
    int getTimeStep() const;

    int getArmyUnitsNo() const;

    int getES_percent() const;
    int getET_percent() const;
    int getEG_percent() const;

    int getAS_percent() const;
    int getAM_percent() const;
    int getAD_percent() const;
    int getSU_percent() const;
    int getEEU_percent() const;

    int getProb() const;

    int getE_minPower() const;
    int getE_maxPower() const;

    int getE_minHealth() const;
    int getE_maxHelth() const;

    int getE_minAttCap() const;
    int getE_maxAttCap() const;

    int getA_minPower() const;
    int getA_maxPower() const;

    int getA_minHealth() const;
    int getA_maxHealth() const;

    int getA_minAttCap() const;
    int getA_maxAttCap() const;

    int getS_minPower() const;
    int getS_maxPower() const;

    int getS_minHealth() const;
    int getS_maxHealth() const;

    int getS_minAttCap() const;
    int getS_maxAttCap() const;

    int getInfection_prob() const;
    int getThreshold() const;

    void generate(int timeStep);
};

