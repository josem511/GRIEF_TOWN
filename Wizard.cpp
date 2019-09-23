//
// Created by Jose Romero on 2019-04-23.
//

#include "Wizard.hpp"

Wizard::Wizard() : Character("wizard", 100, 0, 10, 100)
{
	mName = "None";
	mPower = 0;
}

Wizard::Wizard(std::string n, int lvl) : Character(n, 100, 0, 10, 100)
{
	mName = "None";
	mPower = 0;
	for (int i = 0; i < lvl; i++)
	{
		level++;
		NLP += 6;
		maxHP += 8;
		HP += 8;
		mPower += 3;
	}
}

int Wizard::getAttack()
{
	int attack = 5 + std::rand() % 10 + mPower;
	std::cout << name << " has dealt " << attack << " damage!\n";
	return attack;
}

void Wizard::print()
{
	std::cout << "LVL " << level << "  Wizard: " << name << "\t";
	std::cout << "HP: " << HP << "/" << maxHP << std::endl;
	std::cout << "XP: " << XP << "/" << NLP << std::endl;
	std::cout << "MAGIC POWER: " << mPower;
	if (mName != "None") std::cout << " + " << mPower << "\nMAGIC WEAPON: " << mName;
	std::cout << std::endl;
}

bool Wizard::isDead(int damage)
{
	HP -= damage;
	return HP <= 0;
}

void Wizard::updateXP(int monsterLevel)
{
	XP += monsterLevel;
	if (XP >= NLP)
	{
		level++;
		XP -= NLP;
		NLP += 5;
		maxHP += 8;
		HP += 8;
		mPower += 3;
	}
}

void Wizard::collectWeapon(std::string nameOfWeapon)
{
	mName = nameOfWeapon;
	mPower += 25;
}

bool Wizard::lowHP()
{
	return ((double)HP/maxHP) <= (20.0/100);
}

