#include <iostream>

using namespace std;

void explore()
{
    char choice;
    cout << endl
         << "Menu" << endl
         << endl;
    cout << "1: Camp" << endl;
    cout << "2: Move North" << endl;
    cout << "3: Move West" << endl;
    cout << "4: Move East" << endl;
    cout << "5: Move South" << endl;
    cout << "6: Look at Character Sheet" << endl;
    cin >> choice;

    bool choiceNotMade = true;
    while (choiceNotMade)
    {
        switch (choice)
        {
        case '1':
            //Camp call
            break;
        case '2':
            //north movement
            break;
        case '3':
            //west movement
            break;
        case '4':
            //east movement
            break;
        case '5':
            //south movement
            break;
        case '6':
            //char sheet call
            break;
        default:
            cout << "Invalid entry please try again" << endl;
        }
    }
    return;
}