#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
#include "strLower.cpp"
using namespace std;
int riddle()
{
    ifstream riddleFile;
    riddleFile.open("InfoFiles/Riddles/riddles.txt");
    string randomRiddle;
    string guess;
    string answer;
    int monsterlevel; //int returned by function to determine monster difficulty
    int num = ((rand() + time(0)) % 63);
    num = 2*num;
    for (int i=0;i<num+1;i++) 
        getline(riddleFile, randomRiddle);
    cout << randomRiddle << endl;
    getline(riddleFile, answer);
    answer = strLower(answer);
    answer.erase(answer.find_last_not_of("\n\r") + 1);
    getline(cin, guess);
    guess.erase(guess.find_last_not_of("\n\r") + 1);
    /* function call to convert all letters to lowercase, so simple capitalization doesn't cause a wrong answer */
    guess = strLower(guess);
    cout << endl;
    /* if wrong then get more difficult monster otherwise no monster or easier monster */
    if (guess.compare(answer) == 0) {
        cout << "Good job. Go through that door andd meet my friend." << endl;
        monsterlevel = 0;
    }	else	{
        cout << "Sorry, that is incorrect but go ahead through that door and talk to my friend." << endl;
        monsterlevel = 1;
    }
    cout << endl;
    riddleFile.close();
    return monsterlevel;
} // end riddle function
