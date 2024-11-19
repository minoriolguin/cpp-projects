//: Assignment1Qestion3.cpp

/*
  Title: Assignment1Qestion3.cpp
  Description: This C++ program will create a table of temperature conversions, 
    starting from −40 degrees (both Fahrenheit and Celsius), and running at 5 
    degree intervals for 100 entries in each column.
  Date: May 24, 2024
  Author: Minori Olguin
  Student ID: 3441333
*/

/*
 DOCUMENTATION

 Program Purpose: Use a single cout statement per line to create a table.
    Learn about cout and how to format numeric input in c++. Complete a simple
    calculation. Use static methods.

 Compile: g++ -o Assignment1Qestion3 Assignment1Qestion3.cpp
 Execution: ./Assignment1Qestion3.exe

 Notes: in Cygwin, main must return type int

 Classes: TempConverter

 Variables:
    fahrenheit_temp - double - temperature in fahrenheit
    celcius_temp - double - temperature in celcius
    temp - double - temperature, can be in either fahrenheit or celcius
*/

/*
  TEST PLAN

  Normal case:
    Does the output from my program match the output provided below?
*/

#include <iostream> // Stream declarations
#include <iomanip>
using namespace std;

/****************************************************************
 TempConverter
*****************************************************************/
class TempConverter
{
public:
    // Method takes a fahrenheit temp as input and returns that temp in celcius
    static double fahrenheitToCelcius(double fahrenheit_temp)
    {
        return (fahrenheit_temp - 32) * 5 / 9;
    }

    // Method takes a celcius temp as input and returns that temp in fahrenheit
    static double celciusToFahrenheit(double celcius_temp)
    {
        return (celcius_temp * 9 / 5) + 32;
    }
};

/****************************************************************
 main
*****************************************************************/
int main()
{
    // declaring variables
    TempConverter converter;
    double temp = -40.000;

    // printing out header
    cout << right << setw(18) << "Temperature" << "    |" << right << setw(17) << "Temperature" << endl;
    cout << right << setw(17) << "(degrees)" << "     |" << right << setw(16) << "(degrees)" << endl;
    cout << setw(8) << "F" << setw(9) << "C"
         << setw(6) << "|" << setw(8) << "C" << setw(10) << "F" << endl;

    // printing out the temperature and it converted to fahrenheit and it converted to celcius
    while (temp <= 455.00)
    {
        // display output with columns of 10 and 3 digits after the decimal of precision for temperatures
        cout << fixed << setw(10) << setprecision(3) << temp
             << setw(10) << converter.fahrenheitToCelcius(temp) << "  |"
             << setw(10) << temp << setw(10) << converter.celciusToFahrenheit(temp) << endl;

        // incrementing temperature by 5
        temp += 5.000;
    }
    return 0;
} ///:~
