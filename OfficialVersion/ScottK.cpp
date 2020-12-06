#pragma once
#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int tutorial();
void camp();
string strLower(string n);
int riddle();
int question();
void monsterEncounter(int level = 100);
void reward(string type, int amount);
void luckyEncounter();
void trapEncounter();
void gamblingEncounter();
void printGreeting();
int doorGame();
void majorEncounter();
void finalEncounter();
string questAnswer(int levelChoice);
string anagram(string originalWord);
#include "JasonJ.cpp"
#include "DavidJ.cpp"
extern character player;

/*
class FinalPuzzle
{
	public:
		// default constructor
		FinalPuzzle();
		// constructor
		FinalPuzzle(string solution, string puzzle, int curRings, int ringSNeeded);
		void setFinalPuzzle(string finalPuzzle); // Mutator
		string getFinalPuzzle() const;           // Accessor
		void setFinalSolution(string finalSolution); // Mutator
		string getFinalSolution() const;             // Accessor
		void setTotalRingsNeeded(int totalRings);
		int getTotalRingsNeeded() const;
		void setCurrentRings(int totalRings);
		int getCurrentRings() const;

	private:
		string jumbledWord;
		string correctWord;
		int totalRingsNeeded;
		int ringsFound;
}; // end of class definition

// default constructor
FinalPuzzle::FinalPuzzle()
{
	this->jumbledWord = "etts";
	this->correctWord = "test";
	this->totalRingsNeeded = 4;
	this->ringsFound = 0;
}
// constructor
FinalPuzzle::FinalPuzzle(string solution, string puzzle, int curRings, int ringsNeeded)
{
	this->correctWord = solution;
	this->jumbledWord = puzzle;
	this->ringsFound = curRings;
	this->totalRingsNeeded = ringsNeeded;
}
void FinalPuzzle::setFinalPuzzle(string finalPuzzle)
{
	jumbledWord = finalPuzzle;
	return;
}

string FinalPuzzle::getFinalPuzzle() const
{
	return jumbledWord;
}
void FinalPuzzle::setFinalSolution(string finalSolution)
{
	correctWord = finalSolution;
	return;
}

string FinalPuzzle::getFinalSolution() const
{
	return correctWord;
}

void FinalPuzzle::setTotalRingsNeeded(int totalRings)
{
	totalRingsNeeded = totalRings;
	return;
}

int FinalPuzzle::getTotalRingsNeeded() const
{
	return totalRingsNeeded;
}

void FinalPuzzle::setCurrentRings(int currentRings)
{
	ringsFound = currentRings;
	return;
}

int FinalPuzzle::getCurrentRings() const
{
	return ringsFound;
}; // end class definition
*/
/* function to select solution for quest */
string questAnswer(int levelChoice)
{
	int randNum = (rand() + time(0)) % 5; // need to increase %5 as add words to file
	int pick = 0;
	pick = ((levelChoice - 1) * 5) + randNum; // change 5 as add more words,now 5
	string word[] = {"one", "cue", "tee", "mob", "hum",
		"when", "thus", "bash", "belt", "arab",
		"stout", "stint", "cheif", "creek", "power",
		"summer", "spring", "burden", "employ", "gambit",
		"prosper", "finding", "capsize", "epitaph", "finally",
		"kindness", "handsome", "deathbed", "evacuate", "gasoline",
		"beautiful", "difficult", "blacklist", "elaborate", "equipment",
		"astounding", "challenges", "farfetched", "hemisphere", "neutrality",
		"commandment", "computerize", "dormitories", "electrocute", "hexadecimal",
		"bibliographies", "conditioning", "encapsulates", "fortuitously", "minicomputer"};
	string randomword;
	randomword = word[pick];
	return randomword;
}

/* function to jumble letters in word */
string anagram(string originalWord)
{
	string jumbledWord;
	unsigned choice;
	unsigned temp;
	int count = 0;
	for (size_t i = 0; i < originalWord.size(); i++)
	{
		count++;
		choice = (rand() + time(0)) % (originalWord.size() - i);
		jumbledWord[originalWord.size() - i - 1] = originalWord[choice];
		temp = choice;
		originalWord[temp] = originalWord[originalWord.size() - i - 1];
		originalWord[originalWord.size() - i - 1] = originalWord[choice];
	}
	string jumble = "";
	int k;
	for (k = 0; k < count; k++)
	{
		jumble = jumble + jumbledWord[k];
	}
	return jumble;
}
/* describesLiving Labyrinth, gives instructions if requested by player */
int tutorial()
{
	dialogue("Welcome to the Living Labyrinth");
	dialogue("Thank you for willingly participating in  the alpha ");
	dialogue("testing of our first iteration of the,'Living Labyrinth,' ");
	dialogue("adventure game. if you would like more background or ");
	dialogue("instructions, please press '1', otherwise, press '2' to");
	dialogue("	start playing ");
	int choice = 0;
	cin >> choice;
	while ((cin.fail()) || !(choice >= 1 && choice <= 2))
	{
		cin.clear();
		cin.ignore();
		dialogue("Please choose either 1 or 2");
		cin >> choice;
	}
	if (choice == 1)
	{
		dialogue("The Living Labyrinth is primarily a menu driven,");
		dialogue("single player, fantasy RPG. One exciting innovation");
		dialogue("we have implemented is the option for users to choose a game that");
		dialogue("includes a lot of graphics that are visually appealing to most");
		dialogue("players but there is an additional option that is text based,");
		dialogue("which is more user friendly for the blind and visually impaired. ");
		dialogue("This iteration will only have bare, which is text only, and sparse,");
		dialogue("which has a few visuals and places text in various spots on screen");
		dialogue("You will be asked your preference after this explanation");
		dialogue("Another exciting aspect of the game is that you do not have to");
		dialogue("finish it in one sitting. You can stop the game and your character");
		dialogue("will be saved.");
		dialogue("When you return to your game you will start at the last  check");
		dialogue("point you passed. You will find yourself  in the library after");
		dialogue("the last letter clue that you procured. You will keep your items,");
		dialogue("gold, and experience.");
		dialogue("At the end of reading this explanation, you will be asked to enter");
		dialogue("the level you would like to play. This level represents the");
		dialogue("length of the anagram that you will have to solve to finish");
		dialogue("the quest. Level 1 is a 3 letter anagram while level 7 is a 9 ");
		dialogue("letter anagram. As you travel throughout the land you will run ");
		dialogue("into traps, monsters, lucky finds and opportunities to gamble your");
		dialogue("money away. the main goal is to find the 'Riddle Masters' that are");
		dialogue("gatekeepers of the rings with monograms on them. You will be given");
		dialogue("a riddle, a question, and choice of 3 dorrs to go through. How ");
		dialogue("well you do on these 3 tasks will determine the difficulty level ");
		dialogue("of the monster you will have to kill in order to find a ring ");
		dialogue("with a letter engraved in it. If you answer both questions");
		dialogue("correctly and choose the right door, then you will find the ring ");
		dialogue("without having to fight anything. Once you find a ring, you will go");
		dialogue("back to the library and continue on your journey to find the next ");
		dialogue("ring. When you find all of the rings with letters engraved in them");
		dialogue("then you will have to fight a Boss and solve the anagram to win");
		dialogue("that round. ");
		dialogue("This is the first iteration of our, 'Living Labyrinth,' game. You");
		dialogue(" will notice that we only have one Book Realm at this time and that");
		dialogue("some of the menu choices currently lead to dead ends. As the");
		dialogue("alpha testers of our program, we want you to concentrate on the ");
		dialogue("character saving ability of the game, the bare");
		dialogue("vs. 				sparse visual options, and the ");
		dialogue("various encounters");
		dialogue("Thank you in advance for helping us find any bugs that we may have");
		dialogue("overlooked, so we can fix them while implementing additional");
		dialogue("functionality in our next iteration. ");
		dialogue("After choosing your difficulty level, your ");
		dialogue("character's name, and the text type you want.");
		dialogue("you will be in the library. ");
		dialogue("In the library, you can choose among:");
		dialogue("Talk to NPC, Perk store, Character sheet, and Settings");
		dialogue("If you want to change from graphical to text-based, go to settings");
		dialogue("and make the change. After that, you may want to look at your ");
		dialogue("character sheet or check out the perk store.");
		dialogue("In order to start your adventure, select 'Talk to NPC' ");
		dialogue("then select 'go to book realm'");
		dialogue("In the book realm you can go to the armory or the general store.");
		dialogue("these are currently underdeveloped and will be ");
		dialogue("available in the next iteration.");
		dialogue("In order to start the encounters, choose 'Explore and then choose");
		dialogue("to move in any direction and the encounters will begin. You can");
		dialogue("also choose to camp to restore some health. Of course,");
		dialogue("you could get ambushed!");
		dialogue("Good Luck!");
	}
	string charName;
	dialogue("Okay, please enter the name of your character.");
	cin >> charName;
	dialogue("Your character's name is " + charName);
	player.name = charName;
	/*###*/
	int graphics;
	dialogue("Choose your graphics level. '0' for bare, '1' for sparse, full N/A");
	cin >> graphics;
	while ((cin.fail()) || !(graphics >= 0 && graphics <= 1))
	{
		cin.clear();
		cin.ignore();
		dialogue("Please choose 0 or 1");
		cin >> graphics;
	}
	dialogue("graphics level  is " + to_string(graphics));
	player.textType = graphics;
	dialogue("Now, please enter the level of ");
	dialogue("difficulty you want to play (1 to 10'?");
	int level;
	cin >> level;
	while ((cin.fail()) || !(level >= 1 && level <= 10))
	{
		cin.clear();
		cin.ignore();
		dialogue("Please choose 1 to 10");
		cin >> level;
	}
	/* Comment from Jason to Scott
	Difficulty is presented to player as 1 (easy) to 10 (hard)
	so not to be confusing, but is used in calculations as the
	reverse to multiply player values */
	player.difficulty = (11 - level);
	string questKey;
	string jumble;
	questKey = questAnswer(level);
	jumble = anagram(questKey);
while (jumble == questKey)
{
	jumble = anagram(questKey);
}
	/* constructor filled with parameters */
	player.thePuzzle = FinalPuzzle(questKey, jumble, 0, level + 2);
	/* get functions will be removed, just for testing */
	dialogue("current rings: " + to_string(player.thePuzzle.getCurrentRings()));
	dialogue("Rings Needed: " + to_string(player.thePuzzle.getTotalRingsNeeded()));
	dialogue("Solution: " + player.thePuzzle.getFinalSolution());
	dialogue("jumbled word: " + player.thePuzzle.getFinalPuzzle());
	return 0;
}

/* camp function is called when player wants to rest. there is a 10% chance 
 * that a monster will ambush the player, so no rest is attained. Otherwise, if
 *  allowed to rest, then player increases hit points by a constant factor 
 *  based on constitution and a random number*/
void camp()
{
	int randEnc = ((rand() + time(0)) % 10);
	if (randEnc == 1)
	{
		dialogue("You hear a noise that wakes you from your slumber");
		dialogue("You prepare for some kind of attack.");
		monsterEncounter(); //call monsterEncounter function
	}
	else
	{
		//int maxHP = 40;      ###
		int maxHP = player.maxHP;
		//int currentHP = 30;  ###
		int currentHP = player.HP;
		int diff = maxHP - currentHP;
		//int constitution = 7; ###
		int constitution = player.stat[0];
		int randNum = ((rand() + time(0)) % (maxHP / 2));
		int conAdjustment = constitution * (maxHP / 20); // incorporates player con to heal
		int hpFactor = conAdjustment + randNum;
		currentHP = currentHP + ((diff * hpFactor) / maxHP);
		dialogue("You feel rested. You gained ");
		dialogue(to_string((diff * hpFactor) / maxHP) + "HP");
		dialogue("You have " + to_string(currentHP) + "HP");
		if (currentHP > maxHP)
		{
			currentHP = maxHP;
		}
		//###
		player.HP = currentHP;
	}
	return;
}
/* function takes in a string and converts all letters to lower case so
 * when comparing player's guess to the answer, the case doesn't matter */
string strLower(string n)
{
	for (size_t i = 0; i < n.size(); i++)
	{
		n[i] = tolower(n[i]);
	}
	return n;
}
/* function randomly chooses among 5 different greetings for variety 
 * in major Encounters */
void printGreeting()
{
	string greeting[5] = {
		"Hello, here is a riddle for you.",
		"It is good to see you. I have a riddle for you.",
		"I have been waiting for you. Here is a mind bender for you.",
		"If you answer this question correctly, I will help you pick the best door.",
		"There you are! Answer this."};
	int randNum = (rand() + time(0)) % 5;
	dialogue(greeting[randNum], 2, "Greeter");
	//dialogue("Press 'enter' to continue", 2, "Greeter");;
	string enter;
	getline(cin, enter);
}

/* random chance to help determine the level of the monster to battle 
 * a wrong selection increases the difficulty by 2 levels  */
int doorGame()
{
	string door[3] = {"left", "middle", "right"};
	string guess;
	int monsterlevel = 0;
	int randNum = (rand() + time(0)) % 3;
	dialogue("Choose a door: Left, Middle, or Right", 2, "Door Master");
	cin >> guess;
	/* call to convert to lower case for comparison */
	guess = strLower(guess);
	if (guess == door[randNum])
	{
		monsterlevel = 0;
	}
	else
	{
		monsterlevel = 2;
	}
	dialogue("Good Luck", 2, "Door Master");
	return monsterlevel;
}
/* function is called by majorEncounter. It randomly selects a riddle from 
 * riddle.txt file, the player guesses the answer. An incorrect answer return
 * a 1 increasing the monster difficulty by 1 at end of major encounter */
int riddle()
{
	ifstream riddleFile;
	riddleFile.open("./txtFiles/riddles.txt");
	string randomRiddle;
	string guess;
	string answer;
	int monsterlevel; //int returned by function to determine monster difficulty
	int num = ((rand() + time(0)) % 63);
	num = 2 * num;
	for (int i = 0; i < num + 1; i++)
		getline(riddleFile, randomRiddle);
	dialogue((randomRiddle) + " ", 2, "Riddle Master");
	getline(riddleFile, answer);
	answer = strLower(answer);
	answer.erase(answer.find_last_not_of("\n\r") + 1);
	getline(cin, guess);
	guess.erase(guess.find_last_not_of("\n\r") + 1);
	/* function call to convert all letters to lowercase, so simple capitalization doesn't cause a wrong answer */
	guess = strLower(guess);
	/* if wrong then get more difficult monster otherwise no monster or easier monster */
	if (guess.compare(answer) == 0)
	{
		dialogue("Good job. Go through that door andd meet the Question Master", 2, "Riddle Master");
		monsterlevel = 0;
	}
	else
	{
		dialogue("Sorry, that is incorrect but go ahead through that door");
		dialogue("Talk to the Question Master.", 2, "Riddle Master");
		monsterlevel = 1;
	}
	riddleFile.close();
	return monsterlevel;
} // end riddle function
int question()
{
	ifstream questionFile;
	questionFile.open("./txtFiles/questions.txt");
	string randomQuestion;
	string guess;
	string answer;
	int monsterlevel; //int returned by function to determine monster difficulty
	int randNum = ((rand() + time(0)) % 47);
	randNum = 2 * randNum;
	for (int i = 0; i < randNum + 1; i++)
		getline(questionFile, randomQuestion);
	dialogue((randomQuestion) + " ", 2, "Question Master");
	getline(questionFile, answer);
	answer = strLower(answer);
	answer.erase(answer.find_last_not_of("\n\r") + 1);
	getline(cin, guess);
	guess.erase(guess.find_last_not_of("\n\r") + 1);
	/* function call to convert all letters to lowercase, so simple capitalization doesn't cause a wrong answer */
	guess = strLower(guess);
	/* if wrong then get more difficult monster otherwise no monster or easier monster */
	if (guess.compare(answer) == 0)
	{
		dialogue("Good job. Go through that door andd meet the Door Master", 2, "Question Master");
		monsterlevel = 0;
	}
	else
	{
		dialogue("Sorry, that is incorrect.");
		dialogue("Go through that door and talk to the Door Master", 2, "Question Master");
		monsterlevel = 1;
	}
	questionFile.close();
	return monsterlevel;
} // end question function

/* function receives an int which indicates level of the monster if received 
 * from majorEncounter. A 100  indicates that monsterEncounter was called 
 * from Explore. function adjusts monster using randomization and chaar's lvl */

/* lucky encounter  function selects a random lucky find
 * gold, weapon, armor, or artifact */

void monsterEncounter(int level)
{
	int monsterLevel = 0;
	//	int charLevel = 1;  ###
	int charLevel = player.lvl;
	string rewardType; // sent to reward function with bounty to generate reward
	int bounty = 0;
	/* receiving 100 as level means a random monster in the wilderness, less 
	 * difficult and less reward once killed */
	if (level == 100)
	{
		int randNum = ((rand() + time(0)) % 100);
		if (randNum > 93)
			monsterLevel = 1;
		else if (randNum > 86)
			monsterLevel = 0;
		else if (randNum > 74)
			monsterLevel = -1;
		else if (randNum > 49)
			monsterLevel = -2;
		else
			monsterLevel = -3;
		bounty = monsterLevel + 5 + charLevel;
		rewardType = "wild";
	}
	else
	{
		int randNum = ((rand() + time(0)) % 3);
		monsterLevel = level + randNum - 1;
		monsterLevel += charLevel;
		bounty = charLevel;
		rewardType = "clue";
	}
	//###
	monster theMonster(monsterLevel);
	//###
	combat(theMonster);
	cout << "Monster sent to combat is level " << monsterLevel << endl; //###
	reward(rewardType, bounty);
	return;
}
/* reward function generates the reward depending on the type of monster
 * killed and where the monstr was met i.e. in wild or in major encounter */
void reward(string type, int amount)
{
	int gold = 0;
	if (type == "wild")
	{
		for (int i = 0; i < amount; i++)
		{
			int randNum = ((rand() + time(0)) % 5);
			gold += randNum;
		}
	}
	else if (type == "clue")
	{
		gold = amount * 100;
		for (int i = 0; i < amount; i++)
		{
			int randNum = ((rand() + time(0)) % 50);
			gold += randNum;
		}
	}
	else
	{
		gold = 2;
	}
	dialogue("You found " + to_string(gold) + "gold pieces after killing the enemy");
	// ###
	player.gold = gold;
	return;
}

void luckyEncounter()
{
	//	int gold = 100; //###
	int gold = player.gold;
	//	int luck = 15;  ### i
	int luck = player.stat[5];
	int goldFound = 0;
	/* first random generator is gold vs weapon vs armor
	   int randNum = ((rand() + time(0)) % 10);
	   if (randNum < 7)
	   {*/
	int randGold = ((rand() + time(0)) % 50);
	randGold = randGold + luck / 3;
	/* incorporates luck to determine how much gold found */
	if (randGold > 54)
		goldFound = 100;
	else if (randGold > 51)
		goldFound = 50;
	else if (randGold > 47)
		goldFound = 40;
	else if (randGold > 40)
		goldFound = 25;
	else if (randGold > 30)
		goldFound = 20;
	else if (randGold > 19)
		goldFound = 15;
	else if (randGold > 9)
		goldFound = 10;
	else
		goldFound = 5;
	dialogue("You see something glimmer in the sunlight");
	dialogue("You see " + to_string(goldFound) + " gold pieces!");
	gold += goldFound;
	//###
	player.gold = gold; // add gold to character's items.
}
/*
   else if ((randNum == 7) || (randNum == 8))
   {*/
/*### Commented out old code, next set of pounds is new code
  int randWeapon = ((rand() + time(0)) % 5);
  string weapon[5] = {
  "dagger", "short sword", "long sword", "two handed sword", "mace"};
  dialogue("You see a " + weapon.name); */
/* ### item weapon("2");
   dialogue("You see a " + weapon.name);
   player.addItem(weapon);  */
/*	}
	else
	{
### Commented out old code, next set of pounds is new code
int randArmor = ((rand() + time(0)) % 5);
string armor[5] = {
"plate mail", "chain mail", "leather mail", " helmet", "shield"};
dialogue("You see a " + armor[randArmor]); */
/* ### item armor("1");
   dialogue("You see a " + armor.name);
   player.addItem(weapon); 
   }
   }*/
/* trap encounter  function selects a random trap which may cause harm */
void trapEncounter()
{
	//	int luck = 10;     //###
	int luck = player.stat[5];
	//	int agility = 9;   //###
	int agility = player.stat[4];
	//	int dexterity = 8; //###
	int dexterity = player.stat[2];
	//	int hitPoints = 100;  ###
	int hitPoints = player.HP;
	int HPLost = 0;
	ifstream trapFile;
	trapFile.open("./txtFiles/traps.txt");
	string randomTrap;
	int randNum = 0;
	randNum = ((rand() + time(0)) % 5);
	randNum = 3 * randNum; // calculation to move to each different trap
	for (int i = 0; i < randNum + 1; i++)
		getline(trapFile, randomTrap);
	dialogue((randomTrap));
	/* pause for result of trap */
	dialogue("Press 'enter' to continue. ");
	string enter;
	getline(cin, enter);
	/* move to next line in trap.txt file */
	getline(trapFile, randomTrap);
	/* print this line if player is able to avoid trap and move 1 more line if not
	   in order to display the correct message */
	int randGetHurt = ((rand() + time(0)) % 100);
	randGetHurt += agility + dexterity + luck;
	if (randGetHurt > 65)
		dialogue((randomTrap));
	else
	{
		getline(trapFile, randomTrap);
		dialogue((randomTrap));
		/* damage is 1 to 30% of current HP*/
		int randPercent = ((rand() + time(0)) % 30);
		HPLost = hitPoints * randPercent / 100;
		hitPoints = hitPoints - HPLost;
		//###
		player.HP = hitPoints;
		dialogue("You lost " + to_string(HPLost) + " hit points");
	}
	trapFile.close();
	return;
} // end trap function
/* gambling encounter, is called by Explore function
 * gives player an opportunity to make some money, if lucky, then places new 
 * gold amount back to character's item*/
void gamblingEncounter()
{
	if (player.gold < 1)
	{
		dialogue("this is a casino, You have no money. You must leave!");
		return;
	}
	string play;
	int odds = 0;
	int bet = 0;
	int goldPieces = 0;
	int shellChoice = 0;
	int shell = 0;
	//	int goldCarried = 100; //###
	int goldCarried = player.gold;
	dialogue("Welcome, you have found us. Would you like to play a game of shells? y or n", 2, "Dealer");
	cin >> play;
	cin.ignore();
	if ((play == "Y") || (play == "y") || (play == "Yes") ||
		(play == "yes") || (play == "YES"))
	{
		/* dialogue function formats the output and telss who/what is talking */
		dialogue("Great! Here is how you play. You pick the number of shells and how much money you want to bet.", 2, "Dealer");
		dialogue("The more shells you want to use, the more money you win with a correct selection", 2, "Dealer");
		dialogue("Of course, if you lose, I get your wager.", 2, "Dealer");
		/* loop to continue gambling as long as player wants */
		while ((play == "Y") || (play == "y") || (play == "Yes") ||
			   (play == "yes") || (play == "YES"))
		{
			/* shells determin odds, thus, payback upon winning */
			dialogue("How many shells do you want to use? 2-10", 2, "Dealer");
			cin >> odds;
			/* loop taken if a letter is typed or shells not between 2 and 10 */
			while ((cin.fail()) || (!((odds > 1) && (odds < 11))))
			{
				cin.clear();
				//	std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
				cin.ignore();
				dialogue("bad entry, try again. ", 2, "Dealer");
				cin >> odds;
			}
			dialogue("What is your bet?", 2, "Dealer");
			cin.ignore();
			cin >> bet;
			/* loop to catch letters or bets > than gold character hass */
			while ((cin.fail()) || (!((bet > 0) && (bet <= goldCarried))))
			{
				cin.clear();
				//	std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
				cin.ignore();
				dialogue("Your response is invalid. You cannot bet more than you have.", 2, "Dealer");
				cin >> bet;
			}
			cin.ignore();
			shell = (rand() + time(0)) % odds;
			/* need to convert int odds to string to print with dialogue*/
			dialogue("Okay, which shell do you choose 1 to " + to_string(odds), 2, "Dealer");
			cin >> shellChoice;
			/* checking for validity of user's shell choice */
			while ((cin.fail()) || (!((shellChoice > 0) && (shellChoice <= odds))))
			{
				cin.clear();
				//	std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
				cin.ignore();
				dialogue("bad entry, try again. ", 2, "Dealer");
				cin >> shellChoice;
			}
			cin.ignore();
			dialogue("The winning shell is: " + to_string(shell + 1), 2, "Dealer");
			if (shellChoice == (shell + 1))
			{
				goldPieces = goldPieces + bet * (odds);
				dialogue("Good job! you won " + to_string(bet * (odds)) + " gold pieces ", 2, "Dealer");
				goldCarried = goldCarried + bet * (odds);
				dialogue("Your current balance is " + to_string(goldPieces) + " gold pieces");
			}
			else
			{
				goldPieces = goldPieces - bet;
				dialogue("Sorry, you lost " + to_string(bet) + "gold pieces.", 2, "Dealer");
				dialogue("Your current balance is " + to_string(goldPieces) + " gold Pieces");
				goldCarried = goldCarried - bet;
			}
			dialogue("Would you like to play again? ", 2, "Dealer");
			cin >> play;
			cin.ignore();
		}
		dialogue("Your total gold after playing is " + to_string(goldCarried));
		//###
		player.gold = goldCarried;
	}
}

/* Scott Kurtz
 *majorEncounter Function. Incorporates a greeting, a riddle, a trivia
 * question, a random door game. The success of these games determines 
 * the difficulty level of the monster to face at the end. Ends with a letter
 * clue for the final solution to the game */

void majorEncounter()
{
	int rings = player.thePuzzle.getCurrentRings();
	int ringsNeeded = player.thePuzzle.getTotalRingsNeeded();
	int monster = 0;
	printGreeting();
	monster += riddle();
	monster += question();
	monster += doorGame();
	monsterEncounter(monster);
	//after successfully killing monster find a ring with a letter engraved
	string clue = player.thePuzzle.getFinalPuzzle();
	// get clue and type cast to string
	char engraved = clue[rings];
	string letter;
	letter += engraved;
	dialogue("In the back of the room you see a ring.");
	dialogue("It is engraved with the letter " + letter);
	rings++;
	if (rings >= ringsNeeded)
	{
		finalEncounter();
	}
	return;
}

void finalEncounter()
{
	string jumble = player.thePuzzle.getFinalPuzzle();
	string answer = player.thePuzzle.getFinalSolution();
	dialogue("You hear a voice from the shadows.");
	dialogue("You have done very well to get this far");
	dialogue("Here is a drink to help you before yur final battle.");
	string drink;
	dialogue("Type 'Yes' if you want to take a drink from  the potion.");
	cin >> drink;
	cin.ignore();
	if ((drink == "Yes") || (drink == "yes") || (drink == "Y") || (drink == "y"))
	{
		dialogue("Doesn't that feel better?");
		player.HP = player.maxHP;
		dialogue("The potion has regenerated your health to maxHP");
	}
	dialogue("The door slams shut behind you!");
	dialogue("Ha Ha Ha Ha. You are trapped. The only way out is to put");
	dialogue("the rings in the correct order before the dragon smells you");
	dialogue("Here is the order you found the rings " + jumble);
	dialogue("What word do they spell? ");
	string guess;
	cin >> guess;
	guess = strLower(guess);
	if (answer == guess)
	{
		dialogue("Great Job, you win!");
		dialogue("You find 2000 gold pieces");
		player.gold += 2000;
	}
	else
	{
		monsterEncounter(13);
	}
	return;
}
