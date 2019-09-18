//
// Created by Jose Romero on 2019-04-23.
//

#include "Novice.h"

Novice::Novice() : Character("novice", 80, 0, 10, 80)
{
//	std::srand (time(NULL));
	luck = std::rand() % 2;
	std::cout << "luck : " << luck << std::endl;
}

Novice::Novice(std::string n) : Character(n, 80, 0, 10, 80)
{
//	std::srand (time(NULL));
	luck = std::rand() % 2;
}

int Novice::getAttack()
{
//	std::srand (time(NULL));
	int attack = 1 + std::rand() % 10 + luck + wpower;
	std::cout << name << " has dealt " << attack << " damage!\n";
	return attack;
}

void Novice::print()
{
	std::cout << "LVL " << level << "  NOVICE: " << name << "\t";
	std::cout << "HP: " << HP << "/" << maxHP << std::endl;
	std::cout << "XP: " << XP << "/" << NLP << std::endl;
	std::cout << "LUCK: " << luck;
	if (wpower > 0) std::cout << " + " << wpower;
	std::cout << std::endl;
}

bool Novice::isDead(int damage)
{
	HP -= damage;
	return HP <= 0;
}

void Novice::updateXP(int monsterLevel)
{
	XP += monsterLevel;
	if (XP >= NLP)
	{
		level++;
		XP -= NLP;
		NLP += 5;
		maxHP += 10;
		HP += 10;
		luck += 3 + std::rand() % 3;
	}
}

void Novice::collectWeapon(std::string n)
{
	weapon = n;
	wpower += 15;
}