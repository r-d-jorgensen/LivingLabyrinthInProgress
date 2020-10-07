// update for the encounter function
// changed  encounter class to a function and changed name to majorEncounter

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;

void friendlyEncounter();
void storeEncounter();
void monsterEncounter(int gameLevel);
int gamblingEncounter();
void luckyEncounter();
void majorEncounter();
int encounterType(int gameLevel, int count);
void printGreeting();
int printRiddle();
int printQuestion();
int doorGame();
void monsterCombat(int level);
string strLower(string n);

int encounterType(int gameLevel, int count)
{
    int num = (rand() + time(0)) % 10;
    if (count % 10 == 0)
        num = 0;
    if ((num == 1) || (num == 2))
        friendlyEncounter();
    else if ((num == 3) || (num == 4))
        storeEncounter();
    else if ((num == 5) || (num == 6))
        monsterEncounter(gameLevel);
    else if ((num == 7) || (num == 8))
    {
        /* creat gold data but may need to call gold from character class 
         * or just return +or - to character  gold */
        int gold;
        gold = gamblingEncounter();
        cout << "Your gambling excursion yielded you " << gold << "gold pieces.";
        cout << " " << endl;
    }
    else if (num == 9)
        luckyEncounter();
    else
    {
        if (count % 10 > 0)
            count = 10 * (count / 10 + 1); // formula needed to employ correct number of majorEncounters
        majorEncounter();
    }
    count++;
    return count;
}
void friendlyEncounter()
{
    cout << "this is a friendly encounter" << endl;
}
void storeEncounter()
{
    cout << "this is a storeEncounter" << endl;
}
void monsterEncounter(int difficulty)
{
    cout << "this is a monsterEncounter with a monster at level " << difficulty;
}
/* gambling encounter, is called by encounterType function
 * gives player an opportunity to make some money, if lucky, then returns
 * an integer representing the los or gain of gold pieces while gambling. */
int gamblingEncounter()
{
    string play;
    int odds;
    int bet;
    int goldPieces = 0;
    int shellChoice;
    int shell;
    cout << "Welcome, you have found us. Would you like to play a game ";
    cout << "of shells? y or n";
    cin >> play;
    cout << endl;
    cin.ignore();
    if ((play == "Y") || (play == "y") || (play == "Yes") ||
        (play == "yes") || (play == "YES"))
    {
        cout << "Great! Here is how we play." << endl;
        cout << "You can choose how many shells to play with and how many gold" << endl;
        cout << "pieces you would like to wager. If you pick the correct shell then you multiply your bet" << endl;
        cout << "by the number of shells used in the game and that is how many " << endl;
        cout << "gold pieces you get back. for example: " << endl;
        cout << "if you use 2 shells and bet 10 gold pieces you get 20 pieces back." << endl;
        cout << "Your original 10 pieces + 10 more." << endl;
        cout << "if you choose 10 shells and wager 10 pieces, you get 100." << endl;
        cout << "Your original 10 + 90 more for winning." << endl;
        cout << "Of course, if you lose, I get your wager." << endl;
        while ((play == "Y") || (play == "y") || (play == "Yes") ||
               (play == "yes") || (play == "YES"))
        {
            /* questions to set up odds for game, we could adjust things 
             * to make odds favorable for the player or for the game. 
             * Currently the odds are set up to be equal. */
            cout << "How many shells do you want to use?";
            cin >> odds;
            cout << endl;
            cin.ignore();
            cout << "What is your bet?";
            cin >> bet;
            cout << endl;
            cin.ignore();
            shell = (rand() + time(0)) % odds;
            cout << "Okay, which shell do you choose? 1-" << odds;
            cin >> shellChoice;
            cout << endl;
            cin.ignore();
            cout << "The winning shell is: " << shell + 1 << endl;
            if (shellChoice == (shell + 1))
            {
                goldPieces = goldPieces + bet * (odds - 1);
                cout << "Nice work! You won " << bet * (odds - 1) << " gold pieces" << endl;
            }
            else
            {
                goldPieces = goldPieces - bet;
                cout << "Sorry, you lost " << bet << "gold pieces." << endl;
            }
            if (goldPieces > 0)
                cout << "You are up " << goldPieces << " gold pieces" << endl;
            else if (goldPieces == 0)
                cout << "You are currently even" << endl;
            else
                cout << "You are down " << -goldPieces << " gold pieces." << endl;
            cout << "Would you like to play again?";
            cin >> play;
            cin.ignore();
        }
    }
    return goldPieces;
}
void luckyEncounter()
{
    cout << "this is a lucky encounter" << endl;
}
void majorEncounter()
{
    int monster = 0;
    printGreeting();
    monster = monster + printRiddle();
    monster = monster + printQuestion();
    monster = monster + doorGame();
    monsterCombat(monster);
    /* after successfully killing monster find an object/letter something */
    cout << "In the back of the room you see a golden letter 'S'" << endl;
}

void printGreeting()
{
    string greeting[5] = {
        "Hello, here is a riddle for you.",
        "It is good to see you. I have a riddle for you.",
        "I have been waiting for you. Here is a mind bender for you.",
        "If you answer this question correctly, I will help you pick the best door.",
        "There you are! Answer this."};
    int num = (rand() + time(0)) % 5;
    cout << greeting[num] << endl
         << endl;
}
/* function returns 0 if answer correct and 1 if answer is wrong making the monster more difficult */

int printRiddle()
{
    string riddle[70][2] = {
        {"Mr. and Mrs. Mustard have six daughters and each daughter has one brother. How many people are in the Mustard family?", "9"},
        {"I am something people love or hate. I change peoples appearances and thoughts. If a person takes care of them self I will go up even higher. To some people I will fool them. To others I am a mystery. Some people might want to try and hide me but I will show. No matter how hard people try I will Never go down. What am I?", "age"},
        {"Only one color, but not one size, Stuck at the bottom, yet easily flies. Present in sun, but not in rain, Doing no harm, and feeling no pain. What is it?", "shadow"},
        {"Who is that with a neck and no head, two arms and no hands?  What is it?", "shirt"},
        {"If eleven plus two equals one, what does nine plus five equal?", "2"},
        {"It cannot be seen, cannot be felt, cannot be heard, and cannot be smelt. It lies behind stars and under hills, And empty holes it fills. It comes first and follows after, Ends life, and kills laughter. What is it?", "dark"},
        {"What English word retains the same pronunciation, even after you take away four of its five letters?", "queue"},
        {"What is it that given one, you'll have either two or none? a(n)", "choice"},
        {"Three playing cards in a row. Can you name them with these clues? There is a two to the right of a king. A diamond will be found to the left of a spade. An ace is to the left of a heart. A heart is to the left of a spade. Now, identify all three cards. (type 6 characters for your answer, 4 of hearts is 4h)", "adkh2s"},
        {"The more you take, the more you leave behind. What am I?", "footsteps"},
        {"What 8 letter word can have a letter taken away and it still makes a word. Take another letter away and it still makes a word. Keep on doing that until you have one letter left. What is the word?", "starting"},
        {"What has a head, a tail, is brown, and has no legs?", "penny"},
        {"What comes once in a minute, twice in a moment, but never in a thousand years?", "m"},
        {"What has many keys, but cannot even open a single door?", "piano"},
        {"Re-arrange the letters, O O U S W T D N E J R, to spell just one word. What is it?", "justoneword"},
        {"Poor people have it. Rich people need it. If you eat it you die. what is it?", "nothing"},
        {"What belongs to you, but other people use it more than you?(two words)", "your name"},
        {"What has six faces, but does not wear makeup, has twenty-one eyes, but cannot see? What is it?(a/an)", "die"},
        {"How do you make the number 7 an even number without addition, subtraction, multiplication, or division?", "drop the s"},
        {"I am a word of six; my first three letters refer to an automobile; my last three letters refer to a household animal; my first four letters is a fish; my whole is found in your room. What am I?", "carpet"},

        {"A pregnant lady named her children: Dominique, Regis, Michelle, Fawn, Sophie and Lara. What will she name her next child? Jessica, Katie, Abby or Tilly?", "Tilly"},
        {"I'm not clothes but I cover your body; the more I'm used, the thinner I grow. What am I?", "soap"},
        {"A time when they are green, a time when they are brown, but both of these times, cause me to frown. But just in between, for a very short while, They are perfect and yellow and cause me to smile!", "bananas"},
        {"Sometimes I am born in silence, Other times, no. I am unseen, But I make my presence known. In time, I fade without a trace. I harm no one, but I am unpopular with all. What am I?a(n)", "fart"},
        {"There are 2 ducks in front of 2 other ducks. There are 2 ducks behind 2 other ducks. There are 2 ducks beside 2 other ducks. How many ducks are there?(type the number i.e. 25)", "4"},
        {"I am strong enough to smash ships, but I fear the Sun. What am I?", "ice"},
        {"If there are four sheep, two dogs and one herds-men, how many feet are there?(type the number i.e. 25)", "2"},
        {"What can you hold in your right hand, but not in your left?", "your left hand"},

        {"I always follow you around, everywhere you go at night. I look very bright to people, but I can make the sun dark. I can be in many different forms and shapes. What am I?", "moon"},
        {"A cloud was my mother, the wind is my father, my son is the cool stream, and my daughter is the fruit of the land. A rainbow is my bed, the earth my final resting place, and I'm the torment of man. Who Am I?", "rain"},
        {"There is a clothing store in Bartlesville. The owner has devised his own method of pricing items. A vest costs $20, socks cost $25, a tie costs $15 and a blouse costs $30. Using the method, how much would a pair of underwear cost?", "$45"},
        {"If 5 cats catch 5 mice in 5 minutes, how long will it take one cat to catch a mouse?(hint between 1-100)", "5"},
        {"I am the beginning of sorrow, and the end of sickness. You cannot express happiness without me, yet I am in the midst of crosses. I am always in risk, yet never in danger. You may find me in the sun, but I am never out of darkness. What am I?", "the letter s"},
        {"A farmer in California owns a beautiful pear tree. He supplies the fruit to a nearby grocery store. The store owner has called the farmer to see how much fruit is available for him to purchase. The farmer knows that the main trunk has 24 branches. Each branch has exactly 12 boughs and each bough has exactly 6 twigs. Since each twig bears one piece of fruit, how many plums will the farmer be able to deliver?(use digits)", "0"},
        {"What day would yesterday be if Thursday was four days before the day after tomorrow?", "friday"},
        {"What relation would your father's sister's sister-in-law be to you?(your...)", "mother"},
        {"If the day before yesterday is the 23rd, then what is the day after tomorrow?(give number i.e. 13 not 13th)", "27"},
        {"I can be long, or I can be short. I can be grown, and I can be bought. I can be painted, or left bare. I can be round, or square. What am I?(a(n)", "fingernail"},
        {"I'm the part of the bird that's not in the sky. I can swim in the ocean and yet remain dry. What am I?a(n)", "shadow"},
        {"If your uncle's sister is not your aunt, what relation is she to you?(your...)", "mother"},
        {"What common English verb becomes its own past tense by rearranging its letters?", "eat"},
        {"If you have two coins which total 35 cents and one of the coins is not a dime, what are the two coins?", "a quarter and a dime"},
        {"Which word is the odd one out: Seventy, Brawl, Clover, Proper, Carrot, Swing, Change, Travel, Sacred, Stone?", "carrot"},
        {"I am a path situated between high natural masses. Remove my first letter and you have a path situated between man-made masses.(a/n)", "valley"},
        {"Tommorrow Is Neither Wednesday Nor Thursday. Yesterday Was Not Friday Or Saturday. Today Is Not Thursday Nor Monday Nor Sunday. What Day Is Today?", "friday"},
        {"I am the ruler of shovels, I have a double. I am as thin as a knife, I have a wife. What am I?", "the king of spades"},
        {"I don't have eyes, but once I did see. Once I had thoughts, but now I'm white and empty. What am I?a(n)", "skull"},
        {"What has to be broken before it can be used?a(n)", "egg"},
        {"How many bricks does it take to complete a brick building?(give answer indigit form ie 1234", "1"},
        {"If you put roast in a roaster, what do you put in toaster?", "bread"},
        {"We hurt without moving. We poison without touching. We bear the truth and the lies. We are not to be judged by our size. What are we?", "words"},
        {"What can be stolen, mistaken, or altered, yet never leaves you your entire life?", "identity"},
        {"What is red and blue, and purple and green? No one can reach it, not even the queen?a(n)", "rainbow"},
        {"On Christmas eve, when Santa leaves his workshop on the north pole, what direction does he travel?", "south"},
        {"If a wheel has 64 spokes, how many spaces are there between the spokes?", "64"},
        {"I look at you, you look at me, I raise my right, you raise your left. What am I?", "reflection"},
        {"Two men are in a desert. They both have packs on. One of the guys is dead. The guy who is alive has his pack open, the guy who is dead has his pack closed. What is in the pack?a(n)", "parachute"},
        {"Who can shave three times a day and still grow a beard?a(n)", "barber"},
        {"What can you find in the center of gravity?", "v"}};
    string guess;
    int monsterLevel; //int returned by function to determine monster difficulty
    int num = ((rand() + time(0)) % 70);
    cout << riddle[num][0] << endl;
    cin >> guess;
    guess = strLower(guess);
    cout << endl;
    /* if wrong then get more difficult monster otherwise no monster or easier monster */
    if (guess == riddle[num][1])
    {
        cout << "Good job. You have just made your life a little easier. Go through that door andd meet my friend." << endl;
        monsterLevel = 0;
    }
    else
    {
        cout << "Sorry, that is incorrect but go ahead through that door and talk to my friend." << endl;
        monsterLevel = 1;
    }
    cout << endl;
    return monsterLevel;
} // end printRiddle function

/* another function to determine difficulty level of monster */
int printQuestion()
{
    string question[5][2] = {
        {"How many bits in a byte?", "8"},
        {"Who is president of the United States of America? (last Name)", "trump"},
        {"How many bits in a kilobyte?", "8192"},
        {"What is the capital of Canada?", "ottawa"},
        {"How long does it take for the sun's light to get to Earth?(nearest minute)", "8"}};
    string guess;
    int monsterLevel; //int returned by function to determine monster difficulty
    int num = ((rand() + time(0)) % 5);
    cout << question[num][0] << endl;
    cin >> guess;
    guess = strLower(guess);
    cout << endl;
    /* if wrong then get more difficult monster otherwise no monster or easier monster */
    if (guess == question[num][1])
    {
        cout << "Good job. You have just made your life a little easier. Go through that door and meet my friend for a game of chance." << endl;
        monsterLevel = 0;
    }
    else
    {
        cout << "Sorry, that is incorrect but it is time to try your luck at a game of chance. Go through that door." << endl;
        monsterLevel = 1;
    }
    cout << endl;
    return monsterLevel;
} // end printQuestion function
/* random chance for which monster to battle */
int doorGame()
{
    string door[3] = {"left", "middle", "right"};
    string guess;
    int monsterLevel = 0;
    int num = (rand() + time(0)) % 3;
    cout << "Choose a door: Left, Middle, or Right" << endl;
    cin >> guess;
    guess = strLower(guess);
    cout << endl;
    if (guess == door[num])
    {
        monsterLevel = 0;
    }
    else
    {
        monsterLevel = 2;
    }
    cout << "Good Luck" << endl
         << endl;
    return monsterLevel;
}
void monsterCombat(int level)
{
    cout << "There is a combat with  a monster at level " << level << endl;
    return;
}

string strLower(string n)
{
    for (size_t i = 0; i < n.size(); i++)
    {
        n[i] = tolower(n[i]);
    }
    return n;
}

int main()
{
    int level;
    int maxEncounters;
    int encounterCount = 1;
    cout << "What level do you want to play?";
    cin >> level;
    /* calculate number of major encounter to collect letters for anagram solution letters is level +2*/
    maxEncounters = (level + 2) * 10;
    while (encounterCount <= maxEncounters)
    {
        encounterCount = encounterType(level, encounterCount);
        //cout << encounterCount << endl;
    }
    return 0;
}
