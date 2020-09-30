// function to scramble words
#include<iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;

string questanswer(int levelchoice);
string  anagram(string originalword);
/* function that holds possible words for each level and randomly selects the word according to level chosen by user */
string questanswer(int levelchoice) {
    int num = (rand()+time(0))%2; // need to increase %2 as add words to file
    int index;
    index = 2*(levelchoice-1) + num;// need to adjust as add more words
    string word[] = {"now", "cue", "when", "thus", "stout", "stint", "summer", "spring", "prosper", "finding", "kindness", "handsome", "beautiful", "difficult"};
    string randomword;
    randomword = word[index];
    return randomword;
} 
/* function to randomize letters of the word selected for the quest */
string anagram(string originalword) { 
    string jumbledword;
    unsigned index; 
    unsigned temp;
    for (size_t i=0;i<originalword.size();i++) {
        index = (rand()+time(0))%(originalword.size()-i); 
        /* gets random character from original word and places 
         * in the last character of the jumbled word then reduces the last index by 1 for next loop */
        jumbledword[originalword.size()-i-1] = originalword[index];
        temp = index;
        originalword[temp]= originalword[originalword.size()-i-1];
        originalword[originalword.size()-i-1] = originalword[index];
    }
    for (unsigned k = 0;k<originalword.size();k++)
        cout << jumbledword[k];
    return jumbledword;
}

int main() {
    int level;
    string questkey;
    string jumble;
    cout << "What level would you like to play?";
    cin >> level;
    cout << endl;
    /* prints the answer for the quest */
    questkey = questanswer(level);
    cout << questkey << endl;
    /* attempting to print and jumbled from the anagram function but it 
     * isn't working. it works inside the anagram function. Do you guys have anay idea why or how to fix? */
    jumble = anagram(questkey);
    cout << jumble << endl;
    for (size_t i=0;i<jumble.size();i++) 
        cout << jumble[i];
    cout << endl;


    //int i;
    //for (i=0;i<level+2;i++)
    //cout << jumble[i];

    return 0;
}





