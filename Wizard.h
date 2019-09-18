//
// Created by Jose Romero on 2019-04-23.
//

#ifndef FIGHTINGGAME_WIZARD_H
#define FIGHTINGGAME_WIZARD_H

#include <iostream>
#include "Character.h"

class Wizard : public Character
		{
private:
			std::string mName;
			int mPower;
public:
			Wizard();
			Wizard(std::string, int);
			int getAttack();
			void print();
			bool isDead(int);
			void updateXP(int);
			void collectWeapon(std::string);
			bool lowHP();
		};

#endif //FIGHTINGGAME_WIZARD_H
