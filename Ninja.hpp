//
// Created by Jose Romero on 2019-04-30.
//

#ifndef FIGHTINGGAME_NINJA_H
#define FIGHTINGGAME_NINJA_H

#include <iostream>
#include "Character.hpp"

class Ninja : public Character
{
private:
	int lethality;
	std::string weapon;
	int wPower;

public:
	Ninja();
	Ninja(std::string, int);
	int getAttack();
	void print();
	bool isDead(int);
	void updateXP(int);
	void collectWeapon(std::string);
	bool lowHP();
};


#endif //FIGHTINGGAME_NINJA_H
