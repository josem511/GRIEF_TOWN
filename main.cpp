#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <vector>
#include <ctype.h>      /* toupper */
#include "Character.hpp"
#include "Novice.hpp"
#include "Ninja.hpp"
#include "Knight.hpp"
#include "Wizard.hpp"
#include "Monster.hpp"
#include "Dragon.hpp"

using namespace std;

int gold = 10;
bool ready = false;
bool finishedGame = false;

Character* intro();
int inTownMenu();
void home(vector<Character*>&);
void shop(vector<Character*>&);
int forest();
void jungle(vector<Character*>&, Character*, bool&);
void cave(vector<Character*>&, Character* , bool&);
void desert(vector<Character*>&, Character* , bool&);
void fightMonster(vector<Character*>&, Monster, int);
void fightJungleBoss(vector<Character*>&, Character*, bool&);
void fightCaveBoss(vector<Character*>&, Character*, bool&);
void fightDesertBoss(vector<Character*>&, Character*, bool&);
void fightFinalBoss(vector<Character*>&, Character*);




int main() {
	srand (time(NULL)); //set up seed for random functions

	vector<Character*> party;
	party.push_back(intro());
	int action;
	string dummyVar;

	Character* ninjaPtr = new Ninja("BANDIT", 4);
	bool ninjaDefeated = false;
	Character* knightPtr = new Knight("BANDIT", 9);
	bool knightDefeated = false;
	Character* wizardPtr = new Wizard("BANDIT", 14);
	bool wizardDefeated = false;
	Character* dragPtr = new Dragon("Nicole's Pet", 25);


	action = inTownMenu();

	while (action != 5 && !finishedGame) {
		if (action == 1) {
			home(party);
		} else if (action == 2) {
			int exploringChoice;
			exploringChoice = forest();
			while (exploringChoice != 4 && !finishedGame) {
				if (exploringChoice == 1)
					jungle(party, ninjaPtr, ninjaDefeated);
				else if (exploringChoice == 2)
					cave(party, knightPtr, knightDefeated);
				else if (exploringChoice == 3)
					desert(party, wizardPtr, wizardDefeated);
				else if (exploringChoice == 666)
					fightFinalBoss(party, dragPtr);

					cout << "Please enter a number between 1-4!\n";
				if (!finishedGame) exploringChoice = forest();
			}
		} else if (action == 3)
			shop(party);
		else if (action == 4)
		{
			if (gold >= 10) {
				cout << "You got a 10 g drink and left\n";
				gold -=10;
			} else
				cout << "You dont even have enough money to get a drink;\n";
		}

		if (ninjaDefeated && knightDefeated && wizardDefeated && !ready)
		{
			cout << "\n\n\n\n\n\n\n\n" << party[1]->getName() << ": We need to tell you something!\n"
									   << party[2]->getName() << ": The reason why there have been so many monsters around the area ...\n"
									   << party[3]->getName() << ": Even the reason why we have been terrorizing the city ...\n"
									   << "Ruben: It is because of that man! ヾ( ･`⌓´･)ﾉﾞ\n"
									   << party[1]->getName() << ": Her name is Nicole II and she wants to take over the city.\n"
									   << party[2]->getName() << ": We need to do something. \n"
									   << party[3]->getName() << ": I believe that if we work together, we can beat her up!\n";
			cout << "\n\n\nWhat do you think? [Y/N]";
			cin >> dummyVar;
			cout << "Ruben: (•́⌄•́๑)૭✧ Whatever. I know you can defeat her. Go to the Dark Territory, turn left and you'll see her house\n";
			ready = true;
		}

		if (!finishedGame)
			action = inTownMenu();
	}

	cout << "\nThank you for playing!\n";
	return 0;
}


//int main()
//{
//	Wizard w1;
//	Novice n1("jose");
//	Knight k1("ires", 13);
//	n1.getAttack();
//	k1.getAttack();
//	w1.getAttack();
//	n1.print();
//	n1.isDead(15);
//	n1.updateXP(15);
//	n1.print();
//	k1.print();
//	k1.isDead(15);
//	k1.updateXP(15);
//	k1.print();
//	k1.getAttack();
//	w1.print();
//	w1.isDead(15);
//	w1.updateXP(15);
//	w1.print();
//}

Character* intro()
{
	string name;
	string dummyVar;
	cout << "Welcome to Grieftown, ヽ( ´ー`)ノ\n\n"
	        "You must be the new novice from the capital, my name is Ruben and I am the "
	        "Mayor here. \nWhat was your name again? ";
	getline(cin, name);
	cout << "\n"
	        "Well, I am glad you came, " << name << ". As you may already know, Griefland is a small \n"
	                                                "town out in the country full of bandits and monsters. However, we were not \n"
	                                                "always like this. We used to be called Joyland, but everything changed when \n"
	                                                "she came! ヾ( ･`⌓´･)ﾉﾞ\n"
	                                                "\n"
	                                                "Well, don’t worry about it. Just try to fight the monsters in the forest, and collect the gold, \nso you "
	                                                "can go back home. That’s what you came here for, after all.\n\n"
												 "Do you have any questions?[Y/N] ";
	cin >> dummyVar;
	cout << "Well, I am sure you'll be fine\n\n";
	return new Novice(name);
}

int inTownMenu()
{
	int ans;
	cout << "\t-----GRIEFTOWN-----\n"
	        "\n"
	        "1. Home\t\t\t\t\t\t(gold = " << gold << " g)\n"
	        "2. DARK TERRITORY\n"
	        "3. Shop\n"
		    "4. Bar \n"
		    "5. Quit.\n\n"
		 "What would you like to do?(enter number): ";
	cin >> ans;
	return ans;
}

void home(vector<Character*> &people)
{
	int ans;
	cout << "\nRuben: This is your house for now, it's not much but there is a:\n"
		 "1. Bed (to restore HP)\n"
		 "2. Door (to go back to town)\n"
        "what did you want to do?(enter number): ";
	cin >> ans;
	while (ans != 3) {
		if (ans == 1) {
			for (Character *p : people)
				p->heal();
			cout << "You are all healed now\n\n";
			for (Character *p : people)
				p->print();
			cout << endl;
			break;
		}
		else if(ans == 2)
			break;
		cout << "please choose 1 or 2.";
		cin >> ans;
	}
	cout << "Come back when you are feeling tired!\n";
}

void shop(vector<Character*>& heroes)
{
	int ans;
	string buy = "N";
	cout << "\t-----SHOP----- \t\t(gold = " << gold << " g)\n"
	        "\n"
	        "1. 4-Leaf Clover           (view)\n"
	        "2. Shurikens               (view)\n"
	        "3. Long Sword              (view)\n"
	        "4. Magic Staff             (view)\n"
	        "5. GRIEFTOWN\n\n"
	        "What would you like to do?(enter number): ";
	cin >> ans;
	while (ans != 5)
	{
		if (ans == 1){
			cout << "4-Leaf Clover: \n"
		            "\n\tThis item grants the Novice an additional \e[1m 15 luck points.\e[0m"
		            "\n\n \t\t\t cost: 1000 g\n"
			        "Would you like to purchase?[Y/N]";
			cin >> buy;
			if (toupper(buy[0]) == 'Y')
			{
				if (gold >= 1000)
				{
					gold -= 1000;
					heroes[0]->collectWeapon("4-Leaf Clover");
					cout << "CONGRATS ON YOUR PURCHASE\n";
					heroes[0]->print();
					buy = "N";
				}
				else {
					cout << "Please come back when you have enough gold to buy it.\nYou just need "<< (1000 - gold) <<" g more\n";
					buy = "N";
				}
			}
		}
		else if (ans == 2){
			cout << "Shurikens: \n"
			        "\n\tThis item grants the Ninja an additional \e[1m 20 lethality points.\e[0m"
			        "\n\n \t\t\t cost: 1500 g\n"
			        "Would you like to purchase?[Y/N]";
			cin >> buy;
			if (toupper(buy[0]) == 'Y')
			{
				if (gold >= 1500)
				{
					gold -= 1500;
					heroes[1]->collectWeapon("Shurikens");
					cout << "CONGRATS ON YOUR PURCHASE\n";
					heroes[1]->print();
					buy = "N";
				}
				else {
					cout << "Please come back when you have enough gold to buy it.\nYou just need "<< (1500 - gold) <<" g more\n";
					buy = "N";
				}
			}
		}
		else if (ans == 3){
			cout << "Long Sword: \n"
			        "\n\tThis item grants the Knight an additional \e[1m 20 Weapon Power.\e[0m"
			        "\n\n \t\t\t cost: 2000 g\n"
			        "Would you like to purchase?[Y/N]";
			cin >> buy;
			if (toupper(buy[0]) == 'Y')
			{
				if (gold >= 2000)
				{
					gold -= 2000;
					heroes[2]->collectWeapon("Long Sword");
					cout << "CONGRATS ON YOUR PURCHASE\n";
					heroes[2]->print();
					buy = "N";
				}
				else {
					cout << "Please come back when you have enough gold to buy it.\nYou just need " << (2000 - gold)
					     << " g more\n";
					buy = "N";
				}
			}
		} else if (ans == 4){
			cout << "Magic Staff: \n"
			        "\n\tThis item grants the Wizard an additional \e[1m 25 Magic Power.\e[0m"
			        "\n\n \t\t\t cost: 2500 g\n"
			        "Would you like to purchase?[Y/N]";
			cin >> buy;
			if (toupper(buy[0]) == 'Y')
			{
				if (gold >= 2500)
				{
					gold -= 2500;
					heroes[3]->collectWeapon("Magic Staff");
					cout << "CONGRATS ON YOUR PURCHASE\n";
					heroes[3]->print();
					buy = "N";
				}
				else {
					cout << "Please come back when you have enough gold to buy it.\nYou just need "<< (2500 - gold) <<" g more\n";
					buy = "N";
				}
			}
		}
		cout << "\t-----SHOP----- \t\t(gold = " << gold << " g)\n"
		                                                   "\n"
		                                                   "1. 4-Leaf Clover           (view)\n"
		                                                   "2. Shurikens               (view)\n"
		                                                   "3. Long Sword              (view)\n"
		                                                   "4. Magic Staff             (view)\n"
		                                                   "5. GRIEFTOWN\n\n"
		                                                   "What would you like to do?(enter number): ";
		cin >> ans;
	}
}

int forest()
{
	int ans;
	cout << "\t-----DARK TERRITORY-----\n"
	        "\n"
	        "1. Explore Jungle   (level 1-5)\n"
	        "2. Explore Cave     (level 6-10)\n"
	        "3. Explore Dessert  (level 11-15)\n"
	        "4. GRIEFTOWN\n";
	if (ready) cout << "666. NICOLE'S MASSION IN THE HILL      (CAREFUL! ONCE YOU ENTER, YOU CANNOT LEAVE)\n";
	cout<<  "\nWhat would you like to do?(enter number): ";
	cin >> ans;
	return ans;
}

void jungle(vector<Character*> &people, Character* enPtr, bool &d)
{
	int ans;
	string enemies[5] = {"Bat", "Slime", "Spider", "Fox", "Jungle Tortoise"};
	int minL = 1;

	cout << "\n\t-----JUNGLE-----\n"
	        "\n"
	        "1. Fight Monster\n";
	if(!d) cout <<  "2. Fight Boss\n";
	cout << "3. Go Back\n\n"
	        "What would you like to do?(enter number): ";
	cin >> ans;

	while (ans != 3)
	{
		if (ans == 1)
		{
			int numberForEnemy = rand() % 5;
			int level = minL + rand() % 5;
			fightMonster(people, Monster(enemies[numberForEnemy], level), level);
		}
		else if (ans == 2 && !d)
			fightJungleBoss(people, enPtr, d);
		cout << "\n\t-----JUNGLE-----\n"
		        "\n"
		        "1. Fight Monster\n";
		if(!d) cout <<  "2. Fight Boss\n";
		cout << "3. Go Back\n\n"
		        "What would you like to do?(enter number): ";
		cin >> ans;
	}


}

void cave(vector<Character*> &people, Character* enPtr, bool &d)
{
	string enemies[5] = {"Big Bat", "Big Slime", "Wolf", "large Spider", "Goblin"};
	int ans;
	int minL = 6;

	cout << "\n\t-----CAVE-----\n"
	        "\n"
	        "1. Fight Monster\n";
	if(!d) cout <<  "2. Fight Boss\n";
	cout << "3. Go Back\n\n"
	        "What would you like to do?(enter number): ";
	cin >> ans;

	while (ans != 3) {
		if (ans == 1) {
			int numberForEnemy = rand() % 5;
			int level = minL + rand() % 5;
			fightMonster(people, Monster(enemies[numberForEnemy], level), level);
		}
		else if (ans == 2 && !d)
			fightCaveBoss(people, enPtr, d);
		cout << "\n\t-----CAVE-----\n"
		        "\n"
		        "1. Fight Monster\n";
		if(!d) cout <<  "2. Fight Boss\n";
		cout << "3. Go Back\n\n"
		        "What would you like to do?(enter number): ";
		cin >> ans;
	}
}

void desert(vector<Character*> &people, Character* enPtr, bool &d) {
	string enemies[5] = {"Mummy", "Paladin", "Ghoul", "Werewolf", "Golem"};
	int ans;
	int minL = 11;

	cout << "\n\t-----DESERT-----\n"
	        "\n"
	        "1. Fight Monster\n";
	if (!d) cout << "2. Fight Boss\n";
	cout << "3. Go Back\n\n"
	        "What would you like to do?(enter number): ";
	cin >> ans;

	while (ans != 3) {
		if (ans == 1) {
			int numberForEnemy = rand() % 5;
			int level = minL + rand() % 5;
			fightMonster(people, Monster(enemies[numberForEnemy], level), level);
		}
		else if (ans == 2 && !d)
			fightDesertBoss(people, enPtr, d);
		cout << "\n\t-----DESERT-----\n"
		        "\n"
		        "1. Fight Monster\n";
		if (!d) cout << "2. Fight Boss\n";
		cout << "3. Go Back\n\n"
		        "What would you like to do?(enter number): ";
		cin >> ans;
	}
}

void fightMonster(vector<Character*>& heroes, Monster m, int l)
{
	int ans;
	string keepGoing = "y";
	bool meDead = false;
	bool enDead = false;
	cout << "\nHEROES:\n";
	for (Character *p : heroes)
		p->print();
	cout << "\nENEMY:\n";
	m.print();

	cout << "\n1. Fight \n"
	        "2. Escape  \n"
	        "What would you like to do?(enter number): ";
	cin >> ans;

	if (ans == 1)
	{
		while(!meDead && !enDead && toupper(keepGoing[0]) == 'Y')
		{
			for (Character *p : heroes)
				enDead = m.isDead(p->getAttack()); //exits
			if (!enDead)
				meDead = heroes[0]->isDead(m.getAttack());

			if (!meDead && !enDead)
			{
				cout << "\nHEROES:\n";
				for (Character *p : heroes)
					p->print();
				cout << "\nMONSTER:\n";
				m.print();
				cout << "would you like to continue? [Y/N]";
				cin >> keepGoing;
			}
		}
		if (enDead)
		{
			for (Character *p : heroes)
				p->updateXP(2*l);
			cout << "\n YOU HAVE DEFEATED THE ENEMY! \n"
		   "You have earned " << 20*l << " g\n";
			gold += 20*l;
		}
		else if (meDead)
			cout << "c༽✖﹏✖༼ᓄ\nYou have been defeated! Go home and rest!\n";
	}
	else if (ans == 2)
		cout << "\nYou have escaped!\n";
}

void fightJungleBoss(vector<Character*>& heroes, Character* ninja, bool &d)
{
	int ans;
	string keepGoing = "Y";
	string forg;
	bool forgiven = false;
	bool meDead = false;
	bool enDead = false;
	cout << "\nヽ(｀⌒´メ)ノ\nHMMMMMMMM so you are the new Novice trying save the town, there's nothing you can do kid.\n\n";
	for (Character *p : heroes)
		p->print();
	cout << "\nENEMY:\n";
	ninja->print();

	cout << "\n1. Fight \n"
	        "2. Escape  \n"
	        "What would you like to do?(enter number): ";
	cin >> ans;
	if (ans == 1)
	{
		while(!meDead && !enDead && (toupper(keepGoing[0])  == 'Y') && !forgiven)
		{
			for (Character *p : heroes)
				enDead = ninja->isDead(p->getAttack()); //exits
			if (!enDead)
				meDead = heroes[0]->isDead(ninja->getAttack());
			if (!meDead)
			{
				cout << "\nHEROES:\n";
				for (Character *p : heroes)
					p->print();
				cout << "\nENEMY:\n";
				ninja->print();
				if (ninja->lowHP()){
					cout << "┗|｀O´|┛ \nIT HAS BEEN A WHILE SINCE I HAD SUCH A GOOD MATCH.\nYOU ARE GETTING THE BEST OF ME!\n\n";
					cout << "would you like to forgive her? [Y/N]";
					cin >> forg;
					if (toupper(forg[0]) == 'Y')
					{
						cout << "(╭ರ_•́)\nWhy are you doing this? I cannot let you do that my boss will kill me\n"
			                    "That means I have to join your party!ヾ(@^▽^@)ノ\n But i dont have a name ε٩( ºωº )۶з\n\n";
						string tmpName;
						cout << "So what do you want me to be called? ";
						cin >> tmpName;
						ninja->changeName(tmpName);
						cout << "i love it ٩(♡ε♡ )۶\n";
						forgiven = true;
						d = true;
						heroes.push_back(ninja);
						break;
					}
				}
				else {
					cout << "Would you like to continue? [Y/N]";
					cin >> keepGoing;
				}
			}
		}
		if (enDead && !forgiven)
		{
			for (Character *p : heroes)
				p->updateXP(30);
			cout << "\n YOU HAVE DEFEATED THE ENEMY! \n";
			cout << "\n\n NOW THE ZOMBIE NINJA IS IN YOUR TEAM";
			ninja->changeName("ZOMBIE NINJA");
			forgiven = true;
			d = true;
			heroes.push_back(ninja);

		}
		else if (meDead && !forgiven)
			cout << "c༽✖﹏✖༼ᓄ\nYou have been defeated! Go home and rest!\n";
	}
	else if (ans == 2)
		cout << "\nYou have escaped!\n";
	ninja->heal();
}

void fightCaveBoss(vector<Character*>& heroes, Character* knight, bool &d)
{
	int ans;
	string keepGoing = "Y";
	string forg;
	bool forgiven = false;
	bool meDead = false;
	bool enDead = false;
	cout << "\n(๑•̀ㅂ•́)و\nHello . . . It looks like you are looking for trouble. \n"
		 "I guess I will just have to kick your ass since that ninja hasn't.\n\n";
	for (Character *p : heroes)
		p->print();
	cout << "\nENEMY:\n";
	knight->print();

	cout << "\n1. Fight \n"
	        "2. Escape  \n"
	        "What would you like to do?(enter number): ";
	cin >> ans;
	if (ans == 1)
	{
		while(!meDead && !enDead && (toupper(keepGoing[0])  == 'Y') && !forgiven)
		{
			for (Character *p : heroes)
				enDead = knight->isDead(p->getAttack()); //exits
			if (!enDead)
				meDead = heroes[0]->isDead(knight->getAttack());
			if (!meDead)
			{
				cout << "\nHEROES:\n";
				for (Character *p : heroes)
					p->print();
				cout << "\nENEMY:\n";
				knight->print();
				if (knight->lowHP()){
					cout << "(ꐦ°᷄д°᷅) \nHOW CAN THIS BE POSSIBLE. YOU ARE JUST A NOVICE.\n"
			                "YOU SHOULD NOT BE ABLE TO EVEN MAKE ME TICKLE\n\n";
					cout << "would you like to forgive him? [Y/N]";
					cin >> forg;
					if (toupper(forg[0]) == 'Y')
					{
						cout << "༼ つ ͠° ͟ ͟ʖ ͡° ༽つ\nDONT GET COCKY KID. \n<(｀^´)>\nTHIS ONLY HAPPENNED BC I DONT HAVE MY WEAPON\n"
						        "That means I have to join your party and give me a name!\n\n";
						string tmpName;
						cout << "So what do you want me to be called? ";
						cin >> tmpName;
						knight->changeName(tmpName);
						forgiven = true;
						d = true;
						heroes.push_back(knight);
						break;
					}
				}
				else {
					cout << "Would you like to continue? [Y/N]";
					cin >> keepGoing;
				}
			}
		}
		if (enDead && !forgiven)
		{
			for (Character *p : heroes)
				p->updateXP(30);
			cout << "\n YOU HAVE DEFEATED THE ENEMY! \n";
			cout << "\n\n NOW THE ZOMBIE NINJA IS IN YOUR TEAM";
			knight->changeName("ZOMBIE KNIGHT");
			heroes.push_back(knight);
			d = true;
		}
		else if (meDead && !forgiven)
			cout << "c༽✖﹏✖༼ᓄ\nYou have been defeated! Go home and rest!\n";
	}
	else if (ans == 2)
	{
		cout << "\nYou have escaped!\n";
	}
	knight->heal();
}

void fightDesertBoss(vector<Character*>& heroes, Character* wizard, bool &d)
{
	int ans;
	string keepGoing = "Y";
	string forg;
	bool forgiven = false;
	bool meDead = false;
	bool enDead = false;
	cout << "\n｡;+*(★`∪´☆)*+;｡\nWho has come to see my performance?\n"
	        "Today's show: kill the audience\n\n";
	for (Character *p : heroes)
		p->print();
	cout << "\nENEMY:\n";
	wizard->print();

	cout << "\n1. Fight \n"
	        "2. Escape  \n"
	        "What would you like to do?(enter number): ";
	cin >> ans;
	if (ans == 1)
	{
		while(!meDead && !enDead && (toupper(keepGoing[0])  == 'Y') && !forgiven)
		{
			for (Character *p : heroes)
				enDead = wizard->isDead(p->getAttack()); //exits
			if (!enDead)
				meDead = heroes[0]->isDead(wizard->getAttack());
			if (!meDead)
			{
				cout << "\nHEROES:\n";
				for (Character *p : heroes)
					p->print();
				cout << "\nENEMY:\n";
				wizard->print();
				if (wizard->lowHP()){
					cout << "(ฅ⁍̴̀◊⁍̴́)و ̑̑ \nDAMN. HOW COULD THIS BE?\n"
					        "YOU SHOULD HAVE ALL BEEN DEAD FROM MY SECOND ATTACK!\n\n";
					cout << "would you like to forgive her? [Y/N]";
					cin >> forg;
					if (toupper(forg[0]) == 'Y')
					{
						cout << "୧( ˵ ° ~ ° ˵ )୨ ̑̑\nALRIGHT ALRIGHT. \n\nI DONT LIKE MY BOSS. \nI'LL JUST JOIN YOU TILL I GET A WEAPON SO I CAN KILL YOU.\n"
						        "FOR NOW ... give me a name! ♡〜٩( ˃́▿˂̀ )۶〜♡\n\n";
						string tmpName;
						cout << "So what do you want me to be called? ";
						cin >> tmpName;
						wizard->changeName(tmpName);
						forgiven = true;
						d = true;
						heroes.push_back(wizard);
						break;
					}
				}
				else {
					cout << "Would you like to continue? [Y/N]";
					cin >> keepGoing;
				}
			}
		}
		if (enDead && !forgiven)
		{
			for (Character *p : heroes)
				p->updateXP(30);
			cout << "\n YOU HAVE DEFEATED THE ENEMY! \n";
			cout << "\n\n NOW THE ZOMBIE WIZARD IS IN YOUR TEAM";
			wizard->changeName("ZOMBIE WIZARD");
			d = true;
			heroes.push_back(wizard);
		}
		else if (meDead && !forgiven)
			cout << "c༽✖﹏✖༼ᓄ\nYou have been defeated! Go home and rest!\n";
	}
	else if (ans == 2)
	{
		cout << "\nYou have escaped!\n";
	}
	wizard->heal();
}

void fightFinalBoss(vector<Character*>& heroes, Character* dragon)
{
	string ans;
	string keepGoing = "Y";
	string forg;
	bool meDead = false;
	bool enDead = false;
	int counter = 0;
	int focus = 0;

	cout << "┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼███\n"
	        "┼┼┼┼┼┼┼┼┼┼┼┼┼███████\n"
	        "┼┼┼┼┼┼┼┼┼┼██████████████\n"
	        "┼┼┼┼┼┼┼████████████████████\n"
	        "┼┼┼┼██████████████████████████\n"
	        "┼████████████████████████████████\n"
	        "██████████████████████████████████\n"
	        "┼████████████████████████████████\n"
	        "┼█░░░░██░░░░██████████░░░░██░░░░█\n"
	        "┼█░░░░██░░░░██████████░░░░██░░░░█\n"
	        "┼█░░░░██░░░░██████████░░░░██░░░░█\n"
	        "┼████████████████████████████████\n"
	        "┼█░░░░██░░░░██████████░░░░██░░░░█\n"
	        "┼█░░░░██░░░░██████████░░░░██░░░░█\n"
	        "┼█░░░░██░░░░██████████░░░░██░░░░█\n"
	        "┼████████████████████████████████\n"
	        "┼████████████████████████████████\n"
	        "┼████████████████████████████████\n"
	        "┼█░░░░██░░░░██████████░░░░██░░░░█\n"
	        "┼█░░░░██░░░░█▒▒▒▒▒▒▒▒█░░░░██░░░░█\n"
	        "┼█░░░░██░░░░█▒▒▒▒▒▒▒▒█░░░░██░░░░█\n"
	        "┼████████████▒▒▒░░▒▒▒████████████\n"
	        "┼█░░░░██░░░░█▒▒▒▒▒▒▒▒█░░░░██░░░░█\n"
	        "┼█░░░░██░░░░█▒▒▒▒▒▒▒▒█░░░░██░░░░█\n"
	        "┼█░░░░██░░░░█▒▒▒▒▒▒▒▒█░░░░██░░░░█\n"
	        "┼████████████▒▒▒▒▒▒▒▒████████████\n"
	        "┼████████████▒▒▒▒▒▒▒▒████████████\n"
	        "┼████████████▓▓▓▓▓▓▓▓████████████\n"
	        "████████████▓▓▓▓▓▓▓▓▓▓████████████\n"
	        "███████████▓▓▓▓▓▓▓▓▓▓▓▓███████████"
		    "\nPress 1 and Enter to continue . . .  ";
	cin >> ans;
	cout << "\n\nWell, that a nice house! Let's go see who is this man!\n"
		 "1. Go knock on door.\n"
         "2. Come back later.\n"
		 "What would you like to do? ";
	cin >> ans;
	while (ans != "2" && !finishedGame) {
		if (ans == "1") {
			cout << "\n(҂⌣̀_⌣́)\nNicole II: It looks like someone has come to visit.\n"
			        "Nicole II: Perhaps they dare to challange me.\n";
			cout << "\n|ʘ‿ʘ)╯\nRuben: Well you guys. Good luck! But I have to go do something important to do. \n";
			cout << "\n╰༼=ಠਊಠ=༽╯\nNicole II: Where do you think you are going? \n"
			        "----------Giant Dragon is summoned!----------\n";
			dragon->print();
			cout << "Are you sure you would like to continue? [Y/N] ";
			cin >> keepGoing;
			if (toupper(keepGoing[0]) == 'Y')
				cout << "Nicole II: I can't say I admire your stupidity, but okay. Time to fight!\n(⌐▨_▨)\n";
			else
				cout << "(⌐▨_▨)\nNicole II: Good try, but there is no going back now.\n";

			while (!meDead && !enDead && !finishedGame) {
				for (Character *p : heroes)
					enDead = dragon->isDead(p->getAttack()); //exits
				if (!enDead) {
					meDead = heroes[focus]->isDead(dragon->getAttack());
					counter++;
					if (counter % 3 == 0)
						dragon->heal();
				}
				cout << "\nHEROES:\n";
				for (Character *p : heroes)
					p->print();
				cout << "\nENEMY:\n";
				dragon->print();
				if (!meDead) {
					if (dragon->lowHP() && !enDead) {
						cout << "(▼皿▼ﾒ)ﾉ\nDragon is almost dead!";
						cout << "would you like to forgive her? [Y/N]";
						cin >> forg;
						if (toupper(forg[0]) == 'Y')
						{
							/* Forgiving  */
							cout << "Щ(◣д◢)Щ\nNICOLE II: I dont need forgiveness.\n";
						}
						else
						{
							/* escaping */
							cout << "へ（>_<へ)\nNICOLE II: What a cruel world.\n";
						}
					} else {
						cout << "Would you like to continue? [Y/N]";
						cin >> keepGoing;
						if (toupper(keepGoing[0]) == 'Y')
						{} else
							cout << "\n(⌐▨_▨)\nNicole II: Did you forget? you cannot escape!\n";
						cout << "Who would you like the dragon to focus?\n(WHOEVER YOU CHOOSE, WILL GET HIT BY THE DRAGON NEXT, AND NO ONE CAN DIE!)\n"
						        "1. Novice\n"
						        "2. Ninja\n"
						        "3. Knight\n"
						        "4. Wizard\n"
						        "Choice (1, 2, 3, or 4): ";
						cin >> focus;
						while (focus < 1 || focus > 4) {
							cout << "Please Choose 1, 2, 3, or 4 : ";
							cin >> focus;
						}
						focus--;
					}
				}
				if (enDead && !finishedGame)
				{
					for (Character *p : heroes)
						p->updateXP(30);
					cout << "\n o(〃＾▽＾〃)o\nYOU HAVE DEFEATED THE ENEMY! \n";
					cout << "\n\nRuben: Thank you so much now our town is called JOYTOWN again!!!\n";
					finishedGame = true;
				}
				else if (meDead && !finishedGame)
				{
					cout << "c༽✖﹏✖༼ᓄ\nYou have been defeated! Go home and rest!\n";
					cout << "PLEASE TRY AGAIN!";
					finishedGame = true;
				}
			}
		} else {
			cout << "\nEnter '1' or '2'\nWell, that a nice house! Let's go see who is this man!\n"
			        "1. Go knock on door.\n"
			        "2. Come back later.\n"
			        "What would you like to do? ";
			cin >> ans;
		}
	}
}
