//: Assignment1Qestion5.cpp

/*
  Title: Assignment1Qestion5.cpp
  Description: A C++ program that uses two nested for loops and the modulus operator 
    (%) to detect and print all prime numbers from 1 to 10,000. Prime numbers are 
    integral numbers that are only evenly divisible by themselves and one (1). 
    Display all the prime numbers found.
  Date: May 27, 2024
  Author: Minori Olguin
  Student ID: 3441333
*/

/*
 DOCUMENTATION

 Program Purpose: Use nested for loops and the modulo operator to preform
    simple calculations and display output to the screen.

 Compile: g++ -o Assignment1Qestion5 Assignment1Qestion5.cpp
 Execution: ./Assignment1Qestion5

 Notes: in Cygwin, main must return type int

 Classes: none
    
 Variables:
    column_counter - int - keeps count of the columns and starts a new line
        after every group of 10 numbers have been printed to the screen
    prime - bool - keeps track of whether a number is prime or not, used to 
        decide whether to print the number or not
    dividend - int - the dividend is the number that is being divided by all
        the other numbers, it is incremented by 1 each for loop
    divisor - int - the divisor is the number we are trying to divide the dividend
        by, with each loop it's incremented by 1 and resets to 2 when the dividen 
        increments by 1
*/

/*
  TEST PLAN

  Normal case: 
    Does the output from my program have the correct number of prime numbers printing?
    If a number is selected at random, is it a prime number?
*/

#include <iostream> // Stream declarations
#include <iomanip>
using namespace std;

int main()
{
    int column_counter = 0;

    // Outter for loop, begins at 2 is incremented by 1
    for (int dividend = 2; dividend <= 10000; dividend++)
    {
        bool prime = true;
        // inner for loop, begins at 2 since all numbers are divisible by 1, 
        // increments by 1, and tests the dividend against each divisor between 2 and 10,000
        for (int divisor = 2; divisor <= 10000; divisor++)
        {
            // if the dividend is not the divisor and if the modulo results in 0 change prime to false
            if ((dividend != divisor) && (dividend % divisor == 0))
            {
                prime = false;
		break;
            }
        }

        // displays the dividend as output if the dividend is a prime number 
        if (prime)
        {
            // display output 
            cout << setw(10) << dividend;
            column_counter++;

            // check which column is being printed, every 10 columns begin a new line
            if (column_counter % 10 == 0)
            {
                cout << endl;
            }
        }
    }
    cout << endl;
    return 0;
} ///:~
