#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
using namespace std;
int question()
{
    ifstream questionFile;
    questionFile.open("InfoFiles/Questions/questions.txt");
    string randomQuestion;
    string guess;
    string answer;
    int monsterlevel; //int returned by function to determine monster difficulty
    int num = ((rand() + time(0)) % 5);
    num = 2*num;
    for (int i=0;i<num+1;i++) 
        getline(questionFile, randomQuestion);
    cout << randomQuestion << endl;
    getline(questionFile, answer);
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
    } else {
        cout << "Sorry, that is incorrect but go ahead through that door and talk to my friend." << endl;
        monsterlevel = 1;
    }
    cout << endl;
    questionFile.close();
    return monsterlevel;
} // end question function
