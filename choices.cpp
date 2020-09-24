#include <iostream>

using namespace std;

class livingLibary
{
public:
    int libraryChoices()
    {
        char choice;
        cout << "menu" << endl;
        cin >> choice;

        bool choiceNotMade = true;
        while (choiceNotMade)
        {
            switch (choice)
            {
            case '1':
                cout << "option 1" << endl;
                return 1; //book realm function call
            case '2':
                cout << "option 2" << endl;
                return 1; //perk store function call
            case '3':
                cout << "option 3" << endl;
                return 1; //setting function call
            case '4':
                cout << "option 4" << endl;
                return 1; //char sheet function call
            case '5':
                cout << "option 5" << endl;
                return 0; //exit game function call
            default:
                cout << "re-enter" << endl;
            }
        }
    }
};

int main()
{
    int location = 1;
    bool mainGameLoop = true;
    while (mainGameLoop)
    {
        if (location == 0)
        {
            break;
        }
        else if (location == 1)
        {
            livingLibary library;
            location = library.libraryChoices();
        }
    }

    return 0;
}
