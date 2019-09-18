//
// Created by Jose Romero on 2019-04-21.
//

#ifndef FIGHTINGGAME_KNIGHT_H
#define FIGHTINGGAME_KNIGHT_H

#include <iostream>
#include "Character.h"

class Knight : public Character
		{
private:
			std::string wName;
			int wPower;
			int armor;
public:
			Knight();
			Knight(std::string, int);
			int getAttack();
			void print();
			bool isDead(int);
			void updateXP(int);
			void collectWeapon(std::string);
			bool lowHP();

		};

#endif //FIGHTINGGAME_KNIGHT_H
