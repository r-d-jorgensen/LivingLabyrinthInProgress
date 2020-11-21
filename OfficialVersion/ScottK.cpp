#pragma once
#include <cstdlib>
#include <ctime>
#include <bits/stdc++.h> 
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
int program();
void camp();
string strLower(string n);
int riddle();
int question();
void monsterEncounter(int level);
void luckyEncounter();
void trapEncounter();
void gamblingEncounter();
void printGreeting();
int doorGame();
void majorEncounter();
#include"DavidJ.cpp"

string questAnswer(int levelChoice);
string  anagram(string originalWord);
class FinalPuzzle 
{
    public:
           // default constructor
           FinalPuzzle(); 
           // constructor
           FinalPuzzle(string solution, string puzzle, int curRings, int ringSNeeded); 
           void setFinalPuzzle(string finalPuzzle); // Mutator    
           string getFinalPuzzle() const;        // Accessor
           void printFinalPuzzle() const;
               void setFinalSolution(string finalSolution); // Mutator    
           string getFinalSolution() const;        // Accessor
           void printFinalSolution() const;
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
FinalPuzzle::FinalPuzzle() {
    this->jumbledWord = "none";
        this->correctWord = "none";
        this->totalRingsNeeded = 0;
        this->ringsFound = 0;
}
// constructor
FinalPuzzle::FinalPuzzle(string solution, string puzzle, int curRings, int ringsNeeded) { 
    this->correctWord = solution;
        this->jumbledWord = puzzle;
        this->ringsFound = curRings;
        this->totalRingsNeeded = ringsNeeded;
}
void FinalPuzzle::setFinalPuzzle(string finalPuzzle) { 
    jumbledWord = finalPuzzle;
        return;
}

string FinalPuzzle::getFinalPuzzle() const { 
    return jumbledWord;
}

void FinalPuzzle::printFinalPuzzle() const {
    cout << "The letters you need to re-arrange are " << jumbledWord << endl;
        return;
}

void FinalPuzzle::setFinalSolution(string finalSolution) { 
    correctWord = finalSolution;
        return;
}

string FinalPuzzle::getFinalSolution() const {
    return correctWord;
}

void FinalPuzzle::printFinalSolution() const {
    cout << "The answer is: " << correctWord << endl;
        return;
}

void FinalPuzzle::setTotalRingsNeeded(int totalRings) {
    totalRingsNeeded = totalRings;
        return;
}

int FinalPuzzle::getTotalRingsNeeded() const {
    return totalRingsNeeded;
}

void FinalPuzzle::setCurrentRings(int currentRings) {
    ringsFound = currentRings;
        return;
}

int FinalPuzzle::getCurrentRings() const {
    return ringsFound;
}; // end class definition

/* function to select solution for quest */
string questAnswer(int levelChoice) 
{
    int randNum = (rand()+time(0))%2; // need to increase %2 as add words to file
    int pick;
        pick = 2*(levelChoice-1) + randNum;// need to adjust as add more words
    string word[] = {"now", "cue", "when", "thus", "stout", "stint", "summer", "spring", "prosper", "finding", "kindness", "handsome", "beautiful", "difficult"};
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
        int count=0;
        for (size_t i=0;i<originalWord.size();i++) {
            count++;
                choice = (rand()+time(0))%(originalWord.size()-i); 
                jumbledWord[originalWord.size()-i-1] = originalWord[choice];
                temp = choice;
                originalWord[temp]= originalWord[originalWord.size()-i-1];
                originalWord[originalWord.size()-i-1] = originalWord[choice];
        }
    string jumble = "";
        int k;
        for (k=0;k<count;k++){
            jumble = jumble +jumbledWord[k];
        }
    return jumble;
}
/* describesLiving Labyrinth, gives instructions if requested by player */
int program() 
{
    dialogue("Welcome to the Living Labyrinth");
    dialogue("You have been selected because of your superior knowledge and ");
    dialogue("intellect in the  computer software field to take part in the");
    dialogue("alpha testing of the Living Labyrinth. Thank you for your");
    dialogue("willingness to participate in this endeavor.");
    dialogue("if you would like more background or instructions, please press '1'");
    dialogue("Otherwise,press '2' to start playing ");
    int choice = 0;
    cin >> choice;
    while ((cin.fail()) || !(choice >= 1 && choice <= 2)) {
        cin.clear();
        cin.ignore();
        dialogue("Please choose either 1 or 2");
        cin >> choice;
    }
    if (choice == 1) {
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
        dialogue("character saving ability of the program, the bare");
        dialogue("vs. 				sparse visual options, and the ");
        dialogue("various encounters");
        dialogue("Thank you in advance for helping us find any bugs that we may have");
        dialogue("overlooked, so we can fix them while implementing additional");
        dialogue("functionality in our next iteration. ");
        dialogue("After choosing your anagram level, you will be in the library.");
        dialogue("In the library, you can choose among:");
        dialogue("Talk to NPC, Perk store, Character sheet, and Settings"); 
        dialogue("If you want to change from graphical to text-based, go to settings");
        dialogue("and make the change. After that, you may want to look at your ");
        dialogue("character sheet or check out the perk store.");
        dialogue("In order to start your adventure, select 'Talk to NPC' ");
        dialogue("then select 'go to book realm'");
        dialogue("In the book realm you can go to the armory or the general store.");
        dialogue("In order to start the encounters, choose 'Explore and then choose");
        dialogue("to move in any direction and the encounters will begin. You can");
        dialogue("also choose to camp to restore some health. Of course,");
        dialogue("you could get ambushed!");
        dialogue("Good Luck!");
    }
    string charName;
    dialogue("Okay, please enter the name of your character.");
    cin >> charName;
    dialogue("Your character's name is " + charName); // player.name = charName
    int graphics;
    dialogue("Choose your graphics level. '0' for bare, '1' for sparse, full N/A");
    cin >> graphics;
    while ((cin.fail()) || !(graphics >= 0 && graphics <= 1)) {
        cin.clear();
        cin.ignore();
        dialogue("Please choose 0 or 1");
        cin >> graphics;
    }
    dialogue("graphics level  is " + to_string(graphics)); // player.textTYpe = graphics;
    dialogue("Now, please enter the level of ");
    dialogue("difficulty you want to play (1 to 7'?");
    int level;
    cin >> level;
    while ((cin.fail()) || !(level >= 1 && level <= 7)) {
        cin.clear();
        cin.ignore();
        dialogue("Please choose 1 to 7");
        cin >> level;
    }
    string questKey;
    string jumble;
    questKey = questAnswer(level);
    jumble = anagram(questKey);
/* constructor filled with parameters */
    static FinalPuzzle *puzzle1= new FinalPuzzle(questKey, jumble, 0, level + 2);
/* get functions will be removed, just for testing */
    dialogue("current rings: " + to_string(puzzle1->getCurrentRings()));
    dialogue("Rings Needed: " + to_string(puzzle1->getTotalRingsNeeded()));
    dialogue("Solution: " + puzzle1->getFinalSolution());
    dialogue("jumbled word: " + puzzle1->getFinalPuzzle());
    return 0;
}

/* camp function is called when player wants to rest. there is a 10% chance 
 * that a monster will ambush the player, so no rest is attained. Otherwise, if
 *  allowed to rest, then player increases hit points by a constant factor 
 *  based on constitution and a random number*/ 
void camp()
{
    int randEnc = ((rand() + time(0)) % 10);
    if (randEnc == 1){
        dialogue("You hear a noise that wakes you from your slumber");
        dialogue("You prepare for some kind of attack.");
        monsterEncounter(100); //call monsterEncounter function
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
        riddleFile.open("./txtFiles/riddles.txt");
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
        questionFile.open("./txtFiles/questions.txt");
        string randomQuestion;
        string guess;
        string answer;
        int monsterlevel; //int returned by function to determine monster difficulty
    int randNum = ((rand() + time(0)) % 47);
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

/* function receives an int which indicates level of the monster if received 
 * from majorEncounter. A 100  indicates that monsterEncounter was called 
 * from Explore. function adjusts monster using randomization and chaar's lvl */ 
void monsterEncounter(int level)
{ 
    int monsterLevel = 0;
    if (level == 100) {
        int randNum = ((rand() + time(0)) % 100);
        if (randNum < 100)
            monsterLevel = 1;
        if (randNum <94)
            monsterLevel = 0;
        if (randNum < 87)
            monsterLevel = -1;
        if (randNum < 75)
            monsterLevel = -2;
        if (randNum < 50)
            monsterLevel = -3;
    } else {
        int randNum = ((rand() + time(0)) % 3);
        monsterLevel = level + randNum -1;
    }
    int charLevel = 1; // call char.lvl();
    monsterLevel += charLevel;
    //	 monster = new monster(monsterLevel);
    //monsterCombat();
    cout << "Monster sent to combat is level " << monsterLevel << endl;
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
        trapFile.open("./txtFiles/traps.txt");
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
    /*
       int rings = 0; 
       dialogue("current rings: " + to_string(puzzle1->getCurrentRings()));
       rings++;
       puzzle1->setCurrentRings(rings);
       int ringsNeeded = puzzle1->getTotalRingsNeeded();
       dialogue("Rings Needed: " + to_string(puzzle1.getTotalRingsNeeded()));
       dialogue("Solution: " + puzzle1.getFinalSolution());
       dialogue("jumbled word: " + puzzle1.getFinalPuzzle());
       */
    int monster = 0;
        printgreeting();
        monster += riddle();
        monster += question();
        monster += doorgame();
        monsterEncounter(monster);
        //after successfully killing monster find a ring with a letter engraved
        /*
           string clue  = puzzle1->getFinalPuzzle();
           char letter = clue[rings];
           dialogue("jumbled word: " + puzzle1->getFinalPuzzle());
           */
        dialogue("In the back of the room you see a ring.");
    /*
       dialogue("It is engraved with the letter " + letter);
       if (rings >= ringsNeeded) {
       cout << "time to have the final battle" << endl;
       }
       */
    return;
}
