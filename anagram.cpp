// function to scramble words
#include<iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include<bits/stdc++.h>
using namespace std;

string questAnswer(int levelChoice);
string  anagram(string originalWord);
/* function that holds possible words for each level and randomly selects the word according to level chosen by user */
string questAnswer(int levelChoice) {
    int num = (rand()+time(0))%2; // need to increase %2 as add words to file
    int pick;
    pick = 2*(levelChoice-1) + num;// need to adjust as add more words
    string word[] = {"now", "cue", "when", "thus", "stout", "stint", "summer", "spring", "prosper", "finding", "kindness", "handsome", "beautiful", "difficult"};
    string randomword;
    randomword = word[pick];
    return randomword;
} 
/* function to randomize letters of the word selected for the quest */
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
}

int main() {
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
    return 0;
}





