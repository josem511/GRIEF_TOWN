//
// Created by Jose Romero on 2019-04-25.
//

#ifndef FIGHTINGGAME_MONSTER_H
#define FIGHTINGGAME_MONSTER_H

#include "Character.hpp"
#include <iostream>
#include <string>

class Monster : public Character
		{
private:
	std::string type;
public:
	Monster(std::string, int);
	int getAttack();
	void print();
	bool isDead(int);
	void updateXP(int);
		};


#endif //FIGHTINGGAME_MONSTER_H
