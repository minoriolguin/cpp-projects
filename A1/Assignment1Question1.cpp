//: Assignment1Qestion1.cpp

/*
  Title: Assignment1Qestion1.cpp
  Description: A C++ program that will generate a multiplication table.
  Begins with the 1× table, followed by 2×, then 3×, and so on, until a
  table from 1× to 12× has been generated.
  Date: May 23, 2024
  Author: Minori Olguin
  Student ID: 3441333
*/

/*
 DOCUMENTATION

 Program Purpose:
    Make use of nested loops to create a table. Get comfortable with C++.

 Compile: g++ -o Assignment1Qestion1 Assignment1Qestion1.cpp
 Execution: ./Assignment1Qestion1

 Notes: in Cygwin, main must return type int

 Classes: none

 Variables:
    column - int - index for counting to 12 and multiplying by row
    row - int - index for counting to 12 and multiplying by column
    product - int - result from multiplying column * row
*/

/*
  TEST PLAN

  Normal case:
    Does the output from my program match the output provided in this assignment?
*/

#include <iostream> // Stream declarations
using namespace std;

int main()
{
    // Declaring variables
    int product;
    int column = 1;
    int row = 1;

    cout << "      |   ";

    // printing the first row (header row) before beginning to multiply
    while (column <= 12)
    {
        cout << column << " |  ";
        if (column < 9)
        {
            cout << " ";
        }
        column++;
    }
    cout << endl;
    column = 1;

    // // beginning the while loop to print the first column and table contents
    while (column <= 12)
    {
        // checking if i <= 9 (single digit int) to see how many spaces to insert
        if (column <= 9)
        {
            cout << " ";
        }

        // print the first column (side header column)
        cout << "   " << column;
        row = 1;

        // while loop for printing the table insides
        while (row <= 12)
        {
            product = row * column;

            // using if statement to check for single digits for spacing
            if (product <= 9)
            {
                cout << " |   ";
            }

            // using else if statement to check for double digits for spacing
            else if (product <= 99)
            {
                cout << " |  ";
            }

            // using else for triple digits for spacing
            else
            {
                cout << " | ";
            }

            // printing the first int in the row by the column number (the product)
            cout << product;

            // incrementing j by 1
            row++;
        }
        cout << " |" << endl;

        // incrementing i by 1
        column++;
    }
    return 0;
} ///:~
