//
// Created by Jose Romero on 2019-04-21.
//

#ifndef FIGHTINGGAME_NOVICE_H
#define FIGHTINGGAME_NOVICE_H

#include <iostream>
#include "Character.hpp"

class Novice : public Character
		{
private:
			int luck;
			int wpower;
			std::string weapon;
public:
			Novice();
			Novice(std::string);
			int getAttack();
			void print();
			bool isDead(int);
			void updateXP(int);
			void collectWeapon(std::string);
		};

#endif //FIGHTINGGAME_NOVICE_H
