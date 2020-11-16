/* describesLiving Labyrinth, gives instructions if requested by player */
#include<iostream>
#include<string>
#include"textOutput.cpp"
using namespace std;

int program();
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
dialogue("some of the menu choices lead to dead ends at this time.As the");
dialogue("alpha testers of our program, we want you to concentrate on the ");
dialogue("character saving ability of the program, the visual and text- ");
dialogue("based options in the program., as well as the basic encounters");
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
	dialogue("Okay, please enter the level of ");
	dialogue("difficulty you want to play (1 to 7'?");
	int level;
	cin >> level;
	while ((cin.fail()) || !(level >= 1 && level <= 7)) {
		cin.clear();
		cin.ignore();
		dialogue("Please choose 1 to 7");
		cin >> level;
	}
	return level;
}
/*
int main () {
	int level;
	level = program();
	dialogue("you chose level " + to_string(level));
	return 0;
}
*/
