//
// Created by Jose Romero on 2019-04-23.
//

#include "Knight.h"

Knight::Knight() : Character("knight", 120, 0, 10, 120)
{
	armor = 1;
	wName = "none";
	wPower = 0;
}

Knight::Knight(std::string n, int lvl) : Character(n, 120, 0, 10, 120)
{
	armor = 1;
	wName = "none";
	wPower = 0;
	for (int i = 0; i < lvl; i++)
	{
		level++;
		NLP += 7;
		maxHP += 19;
		armor += 1;
	}
	HP = maxHP;
}

int Knight::getAttack()
{
	int attack = 10 + std::rand() % 10 + wPower;
	std::cout << name << " has dealt " << attack << " damage!\n";
	return attack;
}

void Knight::print()
{
	std::cout << "LVL " << level << "  Knight: " << name << "\t";
	std::cout << "HP: " << HP << "/" << maxHP << std::endl;
	std::cout << "XP: " << XP << "/" << NLP << std::endl;
	std::cout << "ARMOR: " << armor << std::endl;
	if (wName != "none") {
		std::cout << "WEAPON NAME: " << wName << std::endl;
		std::cout << "WEAPON POWER: " << wPower << std::endl;
	}
}

bool Knight::isDead(int damage)
{
	if (damage > armor)
	{
		HP -= (damage - armor);
		return HP <= 0;
	}
}

void Knight::updateXP(int monsterLevel)
{
	XP += monsterLevel;
	if (XP >= NLP)
	{
		level++;
		XP -= NLP;
		NLP += 5;
		maxHP += 19;
		HP += 19;
		armor += 1;
	}
}

void Knight::collectWeapon(std::string nameOfWeapon)
{
	wName = nameOfWeapon;
	wPower += 20;
}

bool Knight::lowHP()
{
	return ((double)HP/maxHP) <= (20.0/100);
}
