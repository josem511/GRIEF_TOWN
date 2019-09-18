//
// Created by Jose Romero on 2019-04-30.
//

#ifndef FIGHTINGGAME_DRAGON_H
#define FIGHTINGGAME_DRAGON_H

#include <iostream>
#include "Character.h"

class Dragon : public Character
		{
private:
			int scales;
			int maxScales;
public:
			Dragon();
			Dragon(std::string, int);
			int getAttack();
			void print();
			bool isDead(int);
			void updateXP(int){}
			void heal();
			bool lowHP();
		};

#endif //FIGHTINGGAME_DRAGON_H
