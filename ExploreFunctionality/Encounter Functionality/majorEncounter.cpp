void majorEncounter()
{
	/*
	   int rings = thePuzzle->getCurrentRings(); 
	   int ringsNeeded = thePuzzle->getTotalRingsNeeded();
	// while is just for testing
	//	while (rings < ring0sNeeded) {
	thePuzzle->setCurrentRings(rings);
	*/
	int monster = 0;
	printGreeting();
	monster += riddle();
	monster += question();
	monster += doorGame();
	monsterEncounter(monster);
	//after successfully killing monster find a ring with a letter engraved
	/*
	   string clue  = thePuzzle->getFinalPuzzle();
	// get clue and type cast to string 
	char engraved = clue[rings];
	string letter; 
	letter += engraved; 
	dialogue("In the back of the room you see a ring.");
	dialogue("It is engraved with the letter " + letter);
	rings++;
	if (rings >= ringsNeeded) {
	dialogue("time to have the final battle, here are the clues. Can you unscramble them?" << endl;
	dialogue("jumbled word: " + thePuzzle->getFinalPuzzle());
	monsterEncounter(10);
	}
	}       
	*/
	finalEncounter();
	return;
}
