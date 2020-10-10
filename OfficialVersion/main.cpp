#include "header.h"

void test()
{
    string test;
    //Currently being used to test the funcitonality of our code so far
    cout << "Testing the save and load functions\n";
    character test1("TEST");
    test1.showStats();
    cout << "\n";
    saveout(test1, "save1.txt");
    character test2 = savein("save1.txt");
    test2.showStats();
    cout << "If the two results appear the same then the process was successful\n";

    cout << "\nPress enter to continue to encounter testing\n";
    //cin.ignore();
    getline(cin, test);

    cout << "Testing the encounter function,\n";
    cout << "Three questions and a statement of monster lvl based on how well you do on the quiz.\n\n";
    //Following code taken from the main of Scott's encounter class
    int monsterlvl = 0;
    Majorencounter me1;
    me1.Printgreeting();
    monsterlvl = monsterlvl + me1.Printriddle();
    monsterlvl = monsterlvl + me1.Printquestion();
    monsterlvl = monsterlvl + me1.Doorgame();
    me1.Monstercombat(monsterlvl);
    //Combat is not yet implemented so it just reads out the lvl of the monster then sends you back.
    cout << "In the back of the room you see a golden letter 'S'" << endl;
}

int main()
{
    char choice;
    cout << "Would you like to run the test or main game loop?\n";
    cout << "T for test and R for main game loop\n";
    cout << "Enter anything else to exit\n";
    cin >> choice;

    if (choice == 't' || choice == 'T')
    {
        test();
    }
    if (choice == 'r' || choice == 'R')
    {
        mainGameLoop();
    }

    return 0;
}
