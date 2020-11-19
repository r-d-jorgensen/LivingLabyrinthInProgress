/* camp function is called when player wants to rest. there is a 10% chance 
 * that a monster will ambush the player, so no rest is attained. Otherwise, if
 *  allowed to rest, then player increases hit points by a constant factor 
 *  based on constitution and a random number*/ 
#pragma once
#include <iostream>
#include"textOutput.cpp"
using namespace std;

void camp();
void camp()
{
	int randEnc = ((rand() + time(0)) % 10);
	if (randEnc == 1){
		dialogue("You hear a noise that wakes you from your slumber");
		dialogue("You prepare for some kind of attack.");
		//	monsterEncounter(); call monsterEncounter function
	} else {
		int maxHP = 40; // call player.maxHp;
		int currentHP = 30; //call player.hp;
		int diff = maxHP - currentHP;
		int constitution = 7; // call player.con
		int randNum = ((rand() + time(0)) % (maxHP/2));
		int conAdjustment = constitution * (maxHP/20); // incorporates player con to heal 
		int hpFactor = conAdjustment + randNum;
		currentHP = currentHP + ((diff * hpFactor) / maxHP);

		dialogue("You feel rested. You gained ");
		dialogue(to_string((diff * hpFactor) / maxHP) + "HP");
		dialogue("You have " + to_string(currentHP) + "HP");
		// player.setHP(currentHP);
	}
	return;
}

/*
   int main() {
   for (int i = 0; i<20;i++)
   camp();
   return 0;
   }
   */
