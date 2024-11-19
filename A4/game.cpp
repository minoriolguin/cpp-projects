//: Assignment4.cpp

/*
Title: Assignment4.cpp
Description:
Date: November 10, 2024
Author: Minori Olguin
Student ID: 3441333
*/

/*
DOCUMENTATION

Program Purpose:

Compile: g++ -o Assignment4 Assignment4.cpp
Execution: ./Assignment4

Notes: in Cygwin, main must return type int

Classes:

Variables:

*/

/*
TEST PLAN

Normal case:


Bad Data case 1 ():
    -

Bad Data case 2 ():
    -

Discussion:
*/
#include <iostream>
#include <iomanip>
#include <sstream>
#include <map>
#include "Action.h"
#include "Character.h"
#include "Control.h"
#include "Inventory.h"
#include "Item.h"
#include "Location.h"
using namespace std;

class Game
{
private:
    bool isRunning;
    int score;
    Character madHatter, redQueen, cheshireCat, rabbit, caterpillar;
    Location aboveRabbitHole, inRabbitHole;


public:
    Game () 
    {
        isRunning = true;
        score = 0;
    }

    bool getIsRunning() 
    {
        return isRunning;
    }

    void setIsRunning()
    {
        this->isRunning = !(this->isRunning);
    }

    int getScore () 
    {
        return score;
    }

    void setScore (int newScore) 
    {
        this->score = newScore;
    }

    void addToScore (int amountToAdd) 
    {
        this->score = this->score + amountToAdd;
    }

    void subtractFromScore (int amountToSubtract) 
    {
        this->score = this->score - amountToSubtract;
    }

    void displayScore () 
    {
        cout << "Current score: " << getScore() << endl;
    }

    void endGame() 
    {
        if (getIsRunning()) 
        {
            setIsRunning();
            cout << "Final score: " << getScore() << endl;
            cout << "The end!" << endl;
        }
    }
};

int main ()
{
    Game wonderland;
    while (wonderland.getIsRunning())
    {


    }

    return 0;
};