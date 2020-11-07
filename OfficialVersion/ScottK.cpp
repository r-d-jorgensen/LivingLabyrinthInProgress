//#pragma once
#include<iostream>
#include"textOutput.cpp"
#include<string>
#include<fstream>
using namespace std;
string strLower(string n);
int riddle();
int question();
void monsterEncounter(int level);
void luckyEncounter();
void trapEncounter();
void gamblingEncounter();
void printGreeting();
int doorGame();
/* function takes in a string and converts all letters to lower case so
 * when comparing player's guess to the answer, the case doesn't matter */ 
string strLower(string n) {
	for (size_t i=0;i<n.size();i++){
		n[i] = tolower(n[i]);
	}
	return n;
}
/* function randomly chooses among 5 different greetings for variety 
 * in major Encounters */ 
void printgreeting()
{
	string greeting[5] = {
		"Hello, here is a riddle for you.",
			"It is good to see you. I have a riddle for you.",
			"I have been waiting for you. Here is a mind bender for you.",
			"If you answer this question correctly, I will help you pick the best door.",
			"There you are! Answer this."};
			int randNum = (rand() + time(0)) % 5;
			dialogue(greeting[randNum], 2, "Greeter");
}
/* random chance to help determine the level of the monster to battle 
 * a wrong selection increases the difficulty by 2 levels  */
int doorgame()
{
	string door[3] = {"left", "middle", "right"};
	string guess;
	int monsterlevel = 0;
	int randNum = (rand() + time(0)) % 3;
	dialogue("Choose a door: Left, Middle, or Right", 2, "Door Master");
	cin >> guess;
/* call to convert to lower case for comparison */
	guess = strLower(guess);
	if (guess == door[randNum]) {
		monsterlevel = 0;
	} else{
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
    riddleFile.open("riddles.txt");
    string randomRiddle;
    string guess;
    string answer;
    int monsterlevel; //int returned by function to determine monster difficulty
    int num = ((rand() + time(0)) % 63);
    num = 2*num;
    for (int i=0;i<num+1;i++) 
        getline(riddleFile, randomRiddle);
    dialogue((randomRiddle) + " ",2 , "Riddle Master");
    getline(riddleFile, answer);
    answer = strLower(answer);
    answer.erase(answer.find_last_not_of("\n\r") + 1);
    getline(cin, guess);
    guess.erase(guess.find_last_not_of("\n\r") + 1);
    /* function call to convert all letters to lowercase, so simple capitalization doesn't cause a wrong answer */
    guess = strLower(guess);
    /* if wrong then get more difficult monster otherwise no monster or easier monster */
    if (guess.compare(answer) == 0) {
        dialogue("Good job. Go through that door andd meet the Question Master", 2, "Riddle Master");
        monsterlevel = 0;
    }	else	{
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
	questionFile.open("questions.txt");
	string randomQuestion;
	string guess;
	string answer;
	int monsterlevel; //int returned by function to determine monster difficulty
	int randNum = ((rand() + time(0)) % 5);
	randNum = 2*randNum;
	for (int i=0;i<randNum+1;i++) 
		getline(questionFile, randomQuestion);
	dialogue((randomQuestion) + " ",2, "Question Master");
	getline(questionFile, answer);
	answer = strLower(answer);
	answer.erase(answer.find_last_not_of("\n\r") + 1);
	getline(cin, guess);
	guess.erase(guess.find_last_not_of("\n\r") + 1);
	/* function call to convert all letters to lowercase, so simple capitalization doesn't cause a wrong answer */
	guess = strLower(guess);
	/* if wrong then get more difficult monster otherwise no monster or easier monster */
	if (guess.compare(answer) == 0) {
		dialogue("Good job. Go through that door andd meet the Door Master", 2, "Question Master");
		monsterlevel = 0;
	} else {
		dialogue("Sorry, that is incorrect.");
				dialogue("Go through that door and talk to the Door Master", 2,"Question Master");
				monsterlevel = 1;
				}
				questionFile.close();
				return monsterlevel;
				} // end question function
/* monster function selects monster */
void monsterEncounter(int level)
{ cout << "there is a monster at level " << level << endl;
	/* I think that maybe we use this function to find a monster from the  monster.txt file,
	 * create the armor class, hp and everything and then pass those attributes on  to
	 * the monstercombat function with all of the parameters passes to it. not sure */
	// call to monsterCombat function?
}
/* lucky encounter  function selects a random lucky find
 * gold, weapon, armor, or artifact */
void luckyEncounter()
{int gold = 100; // pull gold from character stats or items etc  
	int luck = 15; // pulled from stats
	int goldFound = 0;
	/* first random generator is gold vs weapon vs armor */
	int randNum = ((rand() + time(0)) % 10);
	if (randNum < 7 ) {
		int randGold = ((rand() + time(0)) % 50);
		randGold = randGold + luck/3;
		/* incorporates luck to determine how much gold found */
		if (randGold < 57)
			goldFound = 100;
		if (randGold < 54)
			goldFound =50;
		if (randGold < 52)
			goldFound = 40;
		if (randGold< 48)
			goldFound = 25;
		if (randGold <41)
			goldFound = 20;
		if (randGold< 31)
			goldFound = 15;
		if (randGold <20)
			goldFound = 10;
		if (randGold <10)
			goldFound = 5;
		gold = gold + goldFound;
		dialogue("You see something glimmer in the sunlight");
		dialogue("You see " + to_string(goldFound) + " gold pieces!");
		// add gold to character's items.
	}
	else if ((randNum == 7) || (randNum == 8)) {
		int damage = 0;
		int randWeapon = ((rand() + time(0)) % 5);
		string weapon[5] = {
			"dagger", "short sword", "long sword", "two handed sword", "mace"
		};
		/* randomized increased damage per hit */ 
		int randDamage = ((rand() + time(0)) % 50);
		randDamage += luck/3;
		/* incorporates luck to determine increased damage  */
		if (randDamage < 57)
			damage = 5;
		if (randDamage < 52)
			damage =4;
		if (randDamage < 45)
			damage =3;
		if (randDamage <35 )
			damage =2;
		if (randDamage < 22)
			damage =1;
		dialogue("You see a " + weapon[randWeapon]);
		dialogue("it increases your damage by " + to_string(damage)); 
	} 
	else {
		int armorClassIncreased = 0;
		/* randomized increased armor class */ 
		int randArmorClass = ((rand() + time(0)) % 50);
		randArmorClass += luck/3;
		/* incorporates luck to determine increased damage  */
		if (randArmorClass < 57)
			armorClassIncreased = 5;
		if (randArmorClass < 52)
			armorClassIncreased =4;
		if (randArmorClass < 45)
			armorClassIncreased  =3;
		if (randArmorClass <35 )
			armorClassIncreased =2;
		if (randArmorClass < 22)
			armorClassIncreased =1;
		dialogue("You see plate armor");
		dialogue("it increases your armor class by " + to_string(armorClassIncreased)); 
		// pass to character items
	}
}
/* trap encounter  function selects a random trap which may cause harm */
void trapEncounter()
{
	int luck = 10; // pulled from stats
	int agility = 9; // from stats
	int dexterity = 8; // from stats
	int hpLost = 0;
	ifstream trapFile;
		trapFile.open("traps.txt");
		string randomTrap;
		int randNum = 0;
	randNum = ((rand() + time(0)) % 5);
		randNum = 3*randNum;// calculation to move to each different trap
	for (int i=0;i<randNum+1;i++) 
		getline(trapFile, randomTrap);
			dialogue((randomTrap));
	/* pause for result of trap */
	dialogue("Press 'enter' to continue. " );
	string enter;
	getline(cin, enter);
	/* move to next line in trap.txt file */
	getline(trapFile, randomTrap);
		/* print this line if player is able to avoid trap and move 1 more line if not
		   in order to display the correct message */
		int randGetHurt = ((rand() + time(0)) % 100);
	randGetHurt += agility + dexterity + luck;
	if (randGetHurt >65)
		dialogue((randomTrap));
	else {
		getline(trapFile, randomTrap);
			dialogue((randomTrap));
		/* damage is 2 10 sided dice */
		int randHPLost1 = ((rand() + time(0)) % 10);
		int randHPLost2 = ((rand() + time(0)) % 10);
		hpLost = randHPLost1 + randHPLost2;	
		dialogue("You lost " + to_string(hpLost) + " hit points");
	}
	trapFile.close();
		// send hp lost to character hp
} // end trap function

/* gambling encounter, is called by Explore function
 * gives player an opportunity to make some money, if lucky, then places new 
 * gold amount back to character's item*/
void gamblingEncounter()
{
	string play;
	int odds = 0;
	int bet = 0;
	int goldPieces = 0;
	int shellChoice = 0;
	int shell = 0;
	int goldCarried = 100; // call from items or stats etc
	dialogue("Welcome, you have found us. Would you like to play a game of shells? y or n", 2, "Dealer");
	cin >> play;
	cout << endl;
	cin.ignore();
	if ((play == "Y") || (play == "y") || (play == "Yes") ||
			(play == "yes") || (play == "YES")) {
		/* dialogue function formats the output and telss who/what is talking */
		dialogue("Great! Here is how you play. You pick the number of shells and how much money you want to bet.", 2, "Dealer");
		dialogue("The more shells you want to use, the more money you win with a correct selection", 2, "Dealer");
		dialogue("Of course, if you lose, I get your wager.", 2, "Dealer");
		/* loop to continue gambling as long as player wants */
		while ((play == "Y") || (play == "y") || (play == "Yes") ||
				(play == "yes") || (play == "YES")) {
			/* shells determin odds, thus, payback upon winning */
			dialogue("How many shells do you want to use? 2-10", 2, "Dealer");
			cin >> odds;
			/* loop taken if a letter is typed or shells not between 2 and 10 */
			while ((cin.fail()) || (!((odds > 1) && (odds < 11)))) {
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
			while ((cin.fail()) || (!((bet > 0) && (bet <= goldCarried)))) {
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
			while ((cin.fail()) || (!((shellChoice > 0) && (shellChoice <=  odds)))) {
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
				goldPieces = goldPieces + bet * (odds - 1);
				dialogue("Good job! you won " + to_string(bet*(odds-1))+ " gold pieces ", 2, "Dealer");
				goldCarried = goldCarried + bet*(odds-1);
				dialogue("Your current balance is " + to_string(goldPieces) + " gold pieces");
			}			else {
				goldPieces = goldPieces - bet;
				dialogue("Sorry, you lost " + to_string(bet) + "gold pieces.", 2, "Dealer");
				dialogue("Your current balance is " +to_string(goldPieces) + " gold Pieces");
				goldCarried = goldCarried - bet;
			}
			dialogue("Would you like to play again? ", 2, "Dealer");
			cin >> play;
			cin.ignore();
		}
		dialogue("Your total gold after playing is " + to_string(goldCarried)); // send to character gold
	}
}

/* Scott Kurtz
 *majorEncounter Function. Incorporates a greeting, a riddle, a trivia
 * question, a random door game. The success of these games determines 
 * the difficulty level of the monster to face at the end. Ends with a letter
 * clue for the final solution to the game */

void majorEncounter() 
{
	int monster = 0;
		printgreeting();
		monster += riddle();
		monster += question();
		monster += doorgame();
		monsterEncounter(monster);
		//after successfully killing monster find an object/letter something
		dialogue("In the back of the room you see a golden letter 'S'");
}
/*
int main()
{
luckyEncounter();
gamblingEncounter();
trapEncounter();
monsterEncounter(3);
majorEncounter();
return 0;
}
*/
