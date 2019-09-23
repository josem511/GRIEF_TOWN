//
// Created by Jose Romero on 2019-04-21.
//

#ifndef FIGHTINGGAME_CHARACTER_H
#define FIGHTINGGAME_CHARACTER_H

#include <string>

class Character
		{
protected:
			std::string name;
			int level;
			int HP;
			int XP; // everyone starts at 0
			int NLP;
			int maxHP; // same as starting HP
public:
			Character();
			Character(std::string, int, int, int, int);
			virtual int getAttack() = 0;
			virtual void print() = 0;
			virtual bool isDead(int) = 0;
			virtual void updateXP(int) = 0;
			virtual void heal();
			void changeName(std::string);
			virtual bool lowHP(){return false;}
			virtual void collectWeapon(std::string) {}
			std::string getName() { return name;}
		};

#endif //FIGHTINGGAME_CHARACTER_H
