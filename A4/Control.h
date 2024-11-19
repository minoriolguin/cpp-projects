#ifndef CONTROL_H
#define CONTROL_H

#include <iostream> // Stream declarations
using namespace std;

class Control
{
private:
    string user_input;

public:
    Control () {
        validateInput(getUserInput());
        moveCharacter();
    }

    string getUserInput () 
    {
        cin >> user_input;
        return user_input;
    }

    void validateInput (string user_input) 
    {
        if ()
        {

        }
    }

    void moveCharacter () 
    {
        
    }
};

#endif