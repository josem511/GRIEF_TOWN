//
// Created by Jose Romero on 2019-04-23.
//

#include "Character.h"

Character::Character()
{
	name = "none";
	level = 1;
	HP = 0;
	XP = 0;
	NLP = 10;
	maxHP = 0;
}

Character::Character(std::string n, int hp, int xp, int nextLevelPoints, int m)
{
	name = n;
	level = 1;
	HP = hp;
	XP = xp;
	NLP = nextLevelPoints;
	maxHP = m;
}

void Character::heal()
{
	HP = maxHP;
}

void Character::changeName(std::string newName)
{
	name = newName;
}