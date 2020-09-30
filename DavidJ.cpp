#include <iostream>

using namespace std;

class npc {
    
};

class livingLibary {
    public:
        int libraryChoices();
};

class livingLibary {
    int libraryChoices() {
        char choice;
        cout << endl << "Living Libary Menu" << endl << endl;
        cout << "1: Talk to book NPC" << endl;
        cout << "2: go to perk store" << endl;
        cout << "3: talk to guide NPC (settings)" << endl;
        cout << "4: open char sheet" << endl;
        cout << "5: Exit the game" << endl;
        cin >> choice;
        
        bool choiceNotMade = true;
        while (choiceNotMade) {
        switch (choice) {
            case '1':
                 return 1; //book realm function call
            case '2':
                 return 1; //perk store function call
            case '3':
                 return 1; //setting function call
            case '4':
                 return 1; //char sheet function call
            case '5':
                return 0;//exit game function call
            default:
                cout << "Invalid entry please try again" << endl;
            }
        }
    }
};

int main() {
    int location = 1;
    bool mainGameLoop = true;
    while(mainGameLoop) {
        if (location == 0) {
            cout << "Thank You For Playing" << endl;
            return 0;
        } else if (location == 1) {
            livingLibary library;
            location = library.libraryChoices();
        }
    }
}
