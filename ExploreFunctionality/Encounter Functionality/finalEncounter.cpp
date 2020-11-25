void finalEncounter() {
	string jumble = "ctost";// ###jumble = thePuzzle->getFinalPuzzle();
	string answer = "scott"; // ### answer = thePuzzle->getFinalSolution();
	dialogue("You hear a voice from the shadows.");
	dialogue("You have done very well to get this far");
	dialogue("Here is a drink to help you before yur final battle.");
	string drink;
	dialogue("Type 'Yes' if you want to take a drink from  the potion.");
	cin >> drink;
	cin.ignore();
	if ((drink == "Yes") || (drink =="yes") || (drink == "Y") || (drink == "y")) {
		dialogue("Doesn't that feel better?");
		/*### player.HP = maxHP; */
		dialogue("The potion has regenerated your health to maxHP");
	}
	dialogue("The door slams shut behind you!");
	dialogue("Ha Ha Ha Ha. You are trapped. The only way out is to put");
	dialogue("rings in the correct order before the dragon smells you");
	dialogue("Here is the order you found the rings " + jumble);
	dialogue("What word do they spell? ");
	string guess;
	cin >> guess;
	guess = strLower(guess);
	if (answer == guess) {
		dialogue("Great Job, you win!");
		dialogue("You find 2000 gold pieces");
		//###player.gold += 2000;
	}
	else {
		monsterEncounter(13);
	}
	return;
}
