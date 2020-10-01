// function to scramble words
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include<bits/stdc++.h>
using namespace std;

<<<<<<< HEAD
string questAnswer(int levelChoice);
string  anagram(string originalWord);
/* function that holds possible words for each level and randomly selects the word according to level chosen by user */
string questAnswer(int levelChoice) {
    int num = (rand()+time(0))%2; // need to increase %2 as add words to file
    int pick;
    pick = 2*(levelChoice-1) + num;// need to adjust as add more words
=======
string questanswer(int levelchoice);
string anagram(string originalword);
/* function that holds possible words for each level and randomly selects the word according to level chosen by user */
string questanswer(int levelchoice)
{
    int num = (rand() + time(0)) % 2; // need to increase %2 as add words to file
    int index;
    index = 2 * (levelchoice - 1) + num; // need to adjust as add more words
>>>>>>> cc8f5b870d452a5d06891488904b5d482fed515d
    string word[] = {"now", "cue", "when", "thus", "stout", "stint", "summer", "spring", "prosper", "finding", "kindness", "handsome", "beautiful", "difficult"};
    string randomword;
    randomword = word[pick];
    return randomword;
}
/* function to randomize letters of the word selected for the quest */
<<<<<<< HEAD
string anagram(string originalWord) { 
    string jumbledWord;
    unsigned pick; 
    unsigned temp;
    string jumbled = "";
    int count=0;
    int k;
    for (size_t i=0;i<originalWord.size();i++) {
        count++; // count for use with concat function with jumbled string;
        pick = (rand()+time(0))%(originalWord.size()-i); 
        /* gets random character from original word and places 
         * in the last character of the jumbled word then reduces the last pick by 1 for next loop */
        jumbledWord[originalWord.size()-i-1] = originalWord[pick];
        temp = pick;
        originalWord[temp]= originalWord[originalWord.size()-i-1];
        originalWord[originalWord.size()-i-1] = originalWord[pick];
    }
    for (k = 0;k<count;k++)
        jumbled = jumbled + jumbledWord[k];
    return jumbled;
=======
string anagram(string originalword)
{
    string jumbledword;
    unsigned index;
    unsigned temp;
    for (size_t i = 0; i < originalword.size(); i++)
    {
        index = (rand() + time(0)) % (originalword.size() - i);
        /* gets random character from original word and places 
         * in the last character of the jumbled word then reduces the last index by 1 for next loop */
        jumbledword[originalword.size() - i - 1] = originalword[index];
        temp = index;
        originalword[temp] = originalword[originalword.size() - i - 1];
        originalword[originalword.size() - i - 1] = originalword[index];
    }
    for (unsigned k = 0; k < originalword.size(); k++)
        cout << jumbledword[k];
    return jumbledword;
>>>>>>> cc8f5b870d452a5d06891488904b5d482fed515d
}

int main()
{
    int level;
    string questKey;
    string jumble;
    cout << "What level would you like to play?";
    cin >> level;
    cout << endl;
    /* prints the answer for the quest */
    questKey = questAnswer(level);
    cout << questKey << endl;
    jumble = anagram(questKey);
    cout << jumble << endl;
<<<<<<< HEAD
=======
    for (size_t i = 0; i < jumble.size(); i++)
        cout << jumble[i];
    cout << endl;

    //int i;
    //for (i=0;i<level+2;i++)
    //cout << jumble[i];

>>>>>>> cc8f5b870d452a5d06891488904b5d482fed515d
    return 0;
}
