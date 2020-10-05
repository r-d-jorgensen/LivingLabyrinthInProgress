// function to scramble words
#include<iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <bits/stdc++.h> 
using namespace std;

string questanswer(int levelchoice);
string  anagram(string originalword);
string questanswer(int levelchoice) {
	int num = (rand()+time(0))%2; // need to increase %2 as add words to file
int pick;
pick = 2*(levelchoice-1) + num;// need to adjust as add more words
string word[] = {"now", "cue", "when", "thus", "stout", "stint", "summer", "spring", "prosper", "finding", "kindness", "handsome", "beautiful", "difficult"};
string randomword;
randomword = word[pick];
return randomword;
} 
string anagram(string originalword) { 
string jumbledword;
unsigned choice; 
unsigned temp;
int count=0;
for (size_t i=0;i<originalword.size();i++) {
count++;
	choice = (rand()+time(0))%(originalword.size()-i); 
jumbledword[originalword.size()-i-1] = originalword[choice];

temp = choice;
originalword[temp]= originalword[originalword.size()-i-1];
//jumbledword = jumbledword + jumbledword[originalword.size()-i-1];
originalword[originalword.size()-i-1] = originalword[choice];

}
//cout << jumbledword << endl;
//for (unsigned k = 0;k<originalword.size();k++)
//cout << jumbledword[k];
string jumble = "";
int k;
for (k=0;k<count;k++){
jumble = jumble +jumbledword[k];
}
return jumble;
}

int main() {
int level;
string questkey;
cout << "What level would you like to play?";
cin >> level;
cout << endl;
string jumble;

//for (unsigned k = 0;k<originalword.size();k++)
//cout << jumbledword[k];

//cout << questanswer(level) << endl;
questkey = questanswer(level);
cout << questkey << endl;
jumble = anagram(questkey);
cout << jumble << endl;
//for (int  i=0;i<level+2;i++) 
//cout << jumble[i];
//cout << endl;
/*for (size_t k = 0;k<jumble.size();k++)
cout << jumble[k];
*/

//int i;
//for (i=0;i<level+2;i++)
//cout << jumble[i];
 
return 0;
}





