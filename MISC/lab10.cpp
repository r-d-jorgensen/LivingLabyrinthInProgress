//
//optimized by:
//date:
//
//
//Lab-10 framework
//This program spell checks the words in a text file.
//
//Original author: Gordon Griesel
//
//Assignment:
//Optimize this program for running time.
//Your time will be compared to other students in the class.
//
//Test like this:
//   $ time ./lab10 article
//
//A large part of this code was removed when refactoring
//comments will describe the new way the code functions.
//
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <fstream>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

//do not modify
const char dictname[] = "/usr/share/dict/cracklib-small";

//Removed the enum declaring upper and lower
//as it is no longer needed.

//Declared dictionary vector globally so it
//doesnt need to be passed to functions.
vector<string> v;

//Functions prototypes were changed as needed,
//such as no longer passing ifstream objects.
int spell_check(char *text);
int search_for_word(char *xword);
void convert_to_lower(char *str);
void convert_to_lower(string str);

int main(int argc, char *argv[])
{
    //Dictionary is now only opened once,
    //saving time from opening it repeatedly
    ifstream din(dictname);
    if (din.fail()) {
        printf("Dictionary file failed to open!\n\n");
        exit(1);
    }
    //Saves the entire dictionary to a vector so accessing it is much faster,
    //as well as enabling non-linear searches
    while(!din.eof())
    {
        string temp;
        din >> temp;
        convert_to_lower(temp);
        v.push_back(temp);
    }
    din.close();    

    //Next line sorts the vector, takes time but allows binary search,
    //if the dictionary is sorted, this can be commented out to make
    //the code *much* faster i.e. lowering from 0.1 seconds to 0.02 seconds
    sort(v.begin(),v.end()); 
    
    //Original code, nothing has been changed in the rest of main()
    //unless there were spelling errors that needed to be fixed.
    if (argc < 2) {
        printf("\nUsage: %s <file name>\n\n", argv[0]);
        return 0;
    }

    char fname[256];
    strcpy(fname, argv[1]);
    printf("\n");
    printf("Lab-10 program optimization.\n");
    printf("spell-check this file: **%s**\n", fname);
    ifstream fin(fname);
    if (fin.fail()) {
        printf("ERROR: opening **%s** for input\n", fname);
        return 0;
    }
    int nMisspelled = 0;
    char word[256];
    fin >> word;
    while (!fin.eof()) {
        nMisspelled += spell_check(word);
        fin >> word;
    }
    fin.close();
    printf("\nTotal misspelled words: %i\n", nMisspelled);
    printf("Program complete.\n\n");
    return 0;
}

int spell_check(char *xword)
{
    int found = search_for_word(xword);
    if (found != 1) {
        printf("  Misspelled: %s\n", xword);
        return 1;
    }
        return 0;
}

//convert_to_a_case changed to convert_to_lower
//as it was unnecessary for the function
//and saves time by not passing an extra variable.
void convert_to_lower(char *str)
{
    int slen = strlen(str);
    for (int i=0; i<slen; i++) {
        str[i] = (char)tolower(str[i]);
    }
}

//Overloaded function in order to save a
//very small amount of time from converting
//string to char array then back to string.
void convert_to_lower(string str)
{
    int slen = str.length();
    for (int i=0; i < slen; i++) {
        str[i] = (char)tolower(str[i]);
    }
}

//Removed the multiple while loops and 
//instead all is handled in one line in a loop
//using remove instead of iterating through every
//word letter by letter.
void check_last_character(char *str)
{
    char chars[] = ",.:;";
    for (unsigned int i = 0; i < strlen(chars); ++i) {
        *remove(str,str+strlen(str),chars[i])=0;
    }
}

//search_for_word was massively overhauled,
//the search is no longer a linear search through
//an ifstream object, but now uses binary search
//on the vector created in main.
//This results in the search being much faster.
int search_for_word(char *word)
{
    //returns: 0 = word not found.
    //         1 = word found.
    //
    check_last_character(word);
    convert_to_lower(word);
    if (binary_search(v.begin(), v.end(), word)) 
        return 1;
    return 0;
}
