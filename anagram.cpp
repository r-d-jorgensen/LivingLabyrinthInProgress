// function to scramble words
#include<iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <bits/stdc++.h> 
using namespace std;

string questAnswer(int levelChoice);
string  anagram(string originalWord);
/* function to randomly select the solution for the entire quest based on level
 *that was chosen by player. Level 1 has a 3 letter word, level  2 has a 
 4 letter word etc until level 7 has a 9 letter word. */
string questAnswer(int levelChoice) {
	int num = (rand()+time(0))%2; // need to increase %2 as add words to file
int pick;
pick = 2*(levelChoice-1) + num;// need to adjust as add more words
string word[] = {"now", "cue", "when", "thus", "stout", "stint",
    "summer", "spring", "prosper", "finding", "kindness", "handsome", "beautiful", "difficult"};
string randomWord;
randomWord = word[pick];
return randomWord;
} 
/* This function takes in the word randomly selected by the 
 * questKey function and jumbles it for the ultimate question */

string anagram(string originalWord) { 
string jumbledWord;
unsigned choice; 
unsigned temp;
int count=0;
for (size_t i=0;i<originalWord.size();i++) {
count++;
	choice = (rand()+time(0))%(originalWord.size()-i); 
/* takes random letter from above function and places it at the end of
 * the wordand decrements the placement as i is incremented */
    jumbledWord[originalWord.size()-i-1] = originalWord[choice];
temp = choice;
originalWord[temp]= originalWord[originalWord.size()-i-1];
originalWord[originalWord.size()-i-1] = originalWord[choice];
}
string jumble = "";
int k;
/* loop to concatinate all of the letters to produce anagram */
for (k=0;k<count;k++){
jumble = jumble +jumbledWord[k];
}
return jumble;
}

int main() {
int level;
string questKey;
cout << "What level would you like to play?";
cin >> level;
cout << endl;
string jumble;
/* call to get answer for  quest (word) */
questKey = questAnswer(level);
    /* printing answer just for checking if working */
cout << questKey << endl;
jumble = anagram(questKey);
cout << jumble << endl;
return 0;
}

