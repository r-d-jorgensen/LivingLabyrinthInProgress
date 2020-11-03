#pragma once
#include"textOutput.cpp"
string strLower(string n);
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
