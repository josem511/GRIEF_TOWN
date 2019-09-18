//
// Created by Jose Romero on 2019-05-01.
//

#include "Dragon.h"

Dragon::Dragon() : Character("Dragon", 180, 0, 15, 180)
{
	maxScales = 25;
	scales = maxScales;
}

Dragon::Dragon(std::string n , int lvl) : Character(n, 180, 0, 15, 180)
{
	maxScales = 25;
	scales = maxScales;
	for (int i = 1; i < lvl; i++)
	{
		maxScales += 10;
		level ++;
		maxHP += 30;
	}
	scales = maxScales;
	HP = maxHP;
}

int Dragon::getAttack()
{
	int attack = level + (std::rand() % 2*level);
	std::cout << name << " has dealt " << attack << " damage!\n";
	return attack;
}

void Dragon::print()
{
	std::cout << "LVL " << level << "  DRAGON: " << name << std::endl;
	std::cout << "HP: " << HP << "/" << maxHP << std::endl;
	std::cout << "SCALES: " << scales << " / " << maxScales << std::endl;
}

bool Dragon::isDead(int damage)
{
	if (scales > 0) {
		scales -= (damage / 2);
		if (scales < 0)
			scales = 0;
	} else
		HP -= damage;
	return HP <= 0;
}

void Dragon::heal() //will actually grow scales instead
{
	int newScales = level + (std::rand() % 2*level);
	std::cout << name << " has grown " << newScales << " new scales!\n";
	scales += newScales;
	if (scales > maxScales)
		scales = maxScales;
}

bool Dragon::lowHP()
{
	return ((double)HP/maxHP) <= (10.0/100);
}