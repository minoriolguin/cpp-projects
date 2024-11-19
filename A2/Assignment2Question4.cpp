//: Assignment2Qestion4.cpp

/*
  Title: Assignment2Qestion4.cpp
  Description: This program has a parent class of Rodent, with 4 child classes, mouse, gerbil,
  hamster, and guinea pig. This program does not take user input and each rodent can preform the
  same actions with all the other child classes, however, if the rodent preforms the action
  differently, then different output will appear to screen.
  Date: August 8, 2024
  Author: Minori Olguin
  Student ID: 3441333
*/

/*
 DOCUMENTATION

 Program Purpose: To use inheritance to have different child classes that override a parent class function.

 Compile: g++ -o Assignment2Question4 Assignment2Question4.cpp
 Execution: ./Assignment2Question4

 Notes: in Cygwin, main must return type int

 Classes:
    Rodent - Parent class 
    Mouse - Child class to rodent 
    Gerbil - Child class to rodent 
    Hamster - Child class to rodent 
    Guinea Pig - Child class to rodent

Instance Variables:
    rodent - instance of Rodent
    mouse - instance of Mouse
    gerbil - instance of Gerbil
    hamster - instance of Hamster
    guineaPig - instance of GuineaPig

Variables: none
*/

/*
 TEST PLAN

 Normal case:
    Does the correct output print from the parent class method or the child class method when called?
    Do functions that override parent class methods work properly?
    Do each of the print statement correlate to which method was called?
    Are all instances of each class correctly created when called?

 Discussion:
    There was no part of this program that accepted user input so there was not much error 
    handling involved. As well as there was a lack of calculations or numbers and the main 
    thing was ensure that the cout statements aligned with both the methods called and the 
    class they belonged to.
*/

#include <iostream> // Stream declarations
using namespace std;

/****************************************************************
 Rodent
*****************************************************************/
class Rodent
{
public:
    Rodent() // Default constructor
    {
    }

    // rodent gnawing, keeps their teeth from getting too long
    void gnaw()
    {
        cout << "rodent gnawing" << endl;
    }

    // rodent drinking
    void drink()
    {
        cout << "rodent drinking" << endl;
    }

        // rodent scurrying, represents how rodents move from place to place
        void scurry()
    {
        cout << "rodent scurrying" << endl;
    }

    // rodent grooming itself
    void groom()
    {
        cout << "rodent grooming" << endl;
    }

    // rodent burrow, common behaviour for rodents to dig tunnels for themselves
    void burrow()
    {
        cout << "rodent burrowing" << endl;
    }

    // rodent eating, rodents eat different foods
    virtual void eat()
    {
        cout << "rodent eating" << endl;
    }

    // rodent sleeping, rodents need varying levels of sleep per day
    virtual void sleep()
    {
        cout << "rodent sleeping" << endl;
    }
};

/****************************************************************
 Mouse extends Rodent
*****************************************************************/
class Mouse : public Rodent
{
public:
    // Overrides parent class method
    //Mice eating seeds, mice typically eat seeds
    void eat() 
    {
        cout << "Mouse eating seeds" << endl;
    }
    // Overrides parent class method
    // Mice can sleep for up to 12 hours a day
    void sleep() 
    {
        cout << "Mouse is sleeping for 12 hours." << endl;
    }
};

/****************************************************************
 Gerbil extends Rodent
*****************************************************************/
class Gerbil : public Rodent
{
public:
    // Overrides parent class method
    // Gerbil eating insects, normal food for gerbils to eat
    void eat() 
    {
        cout << "Gerbil eating insects" << endl;
    }
    // Overrides parent class method
    // Gerbil sleeping, gerbils sleep for up to 12 hours a day
    void sleep() 
    {
        cout << "Gerbil is sleeping for 12 hours." << endl;
    }
};

/****************************************************************
 Hamster extends Rodent
*****************************************************************/
class Hamster : public Rodent
{
public:
    // Overrides parent class method
    // Hamster eating hay, normal food for hamsters to eat
    void eat() 
    {
        cout << "Hamster eating hay" << endl;
    }
    // Overrides parent class method
    // Hamsters sleep for about 14 hours a day
    void sleep() 
    {
            cout << "Hamster is sleeping for 14 hours." << endl;
    }
};

/****************************************************************
 GuineaPig extends Rodent
*****************************************************************/
class GuineaPig : public Rodent
{
public:
    // Overrides parent class method
    // Guniea pig eating grass, grass is commonly eaten by guniea pigs
    void eat() 
    {
        cout << "Guinea pig eating grass" << endl;
    }
    // Overrides parent class method
    // Guniea pig sleeping, guniea pigs sleep for about 6 hours a day
    void sleep() 
    {
        cout << "Guniea pig is sleeping for 6 hours." << endl;
    }
};

/****************************************************************
 main
*****************************************************************/
int main()
{
    // Creating instances of each object
    cout << "Creating instance variables\n\n..." << endl;
    Rodent rodent;
    Mouse mouse;
    Gerbil gerbil;
    Hamster hamster;
    GuineaPig guineaPig;

    // Rodent sceario
    cout << "\nRodent (generic) Scenario\n" << endl;
    rodent.drink();
    rodent.eat();
    rodent.sleep();
    rodent.burrow();
    rodent.scurry();
    rodent.groom();
    rodent.drink();
    rodent.eat();
    rodent.sleep();
    rodent.scurry();
    rodent.drink();
    rodent.eat();
    rodent.gnaw();
    rodent.sleep();  

    // Mouse scenario
    cout << "\n\nMouse Scenario\n" << endl;
    mouse.drink();
    mouse.eat();
    mouse.sleep();
    mouse.burrow();
    mouse.scurry();
    mouse.groom();
    mouse.drink();
    mouse.eat();
    mouse.sleep();
    mouse.scurry();
    mouse.drink();
    mouse.eat();
    mouse.gnaw();
    mouse.sleep();

    // Gerbil scenario
    cout << "\n\nGerbil Scenario\n" << endl;
    gerbil.drink();
    gerbil.eat();
    gerbil.sleep();
    gerbil.burrow();
    gerbil.scurry();
    gerbil.groom();
    gerbil.drink();
    gerbil.eat();
    gerbil.sleep();
    gerbil.scurry();
    gerbil.drink();
    gerbil.eat();
    gerbil.gnaw();
    gerbil.sleep();

    // hamster scenario
    cout << "\n\nHamster Scenario\n" << endl;
    hamster.drink();
    hamster.eat();
    hamster.sleep();
    hamster.burrow();
    hamster.scurry();
    hamster.groom();
    hamster.drink();
    hamster.eat();
    hamster.sleep();
    hamster.scurry();
    hamster.drink();
    hamster.eat();
    hamster.gnaw();
    hamster.sleep();

    // Guinea pig scenario
    cout << "\n\nGuinea Pig Scenario\n" << endl;
    guineaPig.drink();
    guineaPig.eat();
    guineaPig.sleep();
    guineaPig.burrow();
    guineaPig.scurry();
    guineaPig.groom();
    guineaPig.drink();
    guineaPig.eat();
    guineaPig.sleep();
    guineaPig.scurry();
    guineaPig.drink();
    guineaPig.eat();
    guineaPig.gnaw();
    guineaPig.sleep();

} ///:~
