//
// Created by Jose Romero on 2019-04-30.
//

#include "Ninja.hpp"

Ninja::Ninja() : Character("ninja", 85, 0, 10, 85)
{
	lethality = 1;
	weapon = "none";
}

Ninja::Ninja(std::string name, int lvl)  : Character(name, 85, 0, 10, 85)
{
	lethality = 1;
	weapon = "none";
	for (int i = 0; i < lvl; i++)
	{
		level++;
		NLP += 7;
		maxHP += 15;
		HP += 15;
		lethality += 2;
	}
}

int Ninja::getAttack()
{
	int attack = 7 + std::rand() % 10 + lethality + wPower;
	std::cout << name << " has dealt " << attack << " damage!\n";
	return attack;
}

void Ninja::print()
{
	std::cout << "LVL " << level << "  Ninja: " << name << "\t" ;
	std::cout << "HP: " << HP << "/" << maxHP << std::endl;
	std::cout << "XP: " << XP << "/" << NLP << std::endl;
	std::cout << "LETHALITY: " << lethality;
	if (weapon != "none") std::cout << " + " << wPower <<"\nWEAPON NAME: " << weapon;
	std::cout << std::endl;
}

bool Ninja::isDead(int damage)
{
	HP -= damage;
	return HP <= 0;
}

void Ninja::updateXP(int monsterLevel)
{
	XP += monsterLevel;
	if (XP >= NLP)
	{
		level++;
		XP -= NLP;
		NLP += 5;
		maxHP += 15;
		HP += 15;
		lethality += 2;
	}
}

void Ninja::collectWeapon(std::string nameOfWeapon)
{
	weapon = nameOfWeapon;
	wPower = 15;
}

bool Ninja::lowHP()
{
	return ((double)HP/maxHP) <= (20.0/100);
}

