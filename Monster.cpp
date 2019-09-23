//
// Created by Jose Romero on 2019-04-30.
//

#include "Monster.hpp"

Monster::Monster(std::string t, int l)
{
	type = t;
	double mult;
	if (l < 6)
		mult = 3;
	else if (l < 11)
		mult = 5.5;
	else
		mult = 8;
	maxHP = (int)(mult*(3+l));
	HP = maxHP;
	level = l;
}

int Monster::getAttack()
{
	int attack = level + (3 + std::rand() % level);
	std::cout << type << " has dealt " << attack << " damage!\n";
	return attack;
}

void Monster::print()
{
	std::cout << "LVL " << level << "  MONSTER: " << type << std::endl;
	std::cout << "HP: " << HP << "/" << maxHP << std::endl;
}

void Monster::updateXP(int) {}

bool Monster::isDead(int damage)
{
	HP -= damage;
	return HP <= 0;
}