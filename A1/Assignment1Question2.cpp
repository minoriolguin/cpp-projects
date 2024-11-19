//: Assignment1Qestion2.cpp

/*
  Title: Assignment1Qestion2.cpp
  Description: A C++ program that will accept a number (temperature)
  and a temperature unit designation (i.e., character F or C) from
  the user, and then convert the temperature into the other unit system.
  Date: May 24, 2024
  Author: Minori Olguin
  Student ID: 3441333
*/

/*
 DOCUMENTATION

 Program Purpose:
  Solve a basic programming question. Demonstrate proper format based off
    given input/output visuals. Demonstrate user prompts, keyboard input,
    and simple calculations. Get comfortable with C++.

 Compile: g++ -o Assignment1Qestion2 Assignment1Qestion2.cpp
 Execution: ./Assignment1Qestion2

 Notes: in Cygwin, main must return type int

 Classes: none

 Variables:
  temp - double - floating point number taken as input from user
  new_temp - double - floating point number, converted to user specified temp unit
    temp_unit - string - temperature unit, can be either fahrenheit or celcius whichever
    the inputted unit has been specified as
    new_temp_unit - string - tempurature unit, is either fahrenheit or celcius whichever
    the inputted unit is to be converted to
    unit - char - user inputted character, can be either C or F (capital or  lower), use
    to specify the unit type of the inputted temperature
    done - char - user inputted character, can be N or n, used to exit the program
*/

/*
  TEST PLAN

  Normal case:
    >This program converts Temperatures from Fahrenheit to Celsius and vice versa.
    >Please enter your temperature: 21.5
    >Please enter the units (F/C): f

    >A temperature of 21.5 degrees Fahrenheit is equivalent to -5.83333 degrees Celcius.
    >Do you want another conversion? (Y/N): y

    >Please enter your temperature: -1
    >Please enter the units (F/C): c

    >A temperature of -1 degrees Celcius is equivalent to 30.2 degrees Fahrenheit.
    >Do you want another conversion? (Y/N): n

    >Thank you. Goodbye.

  Bad Data case 1 (more than one character for unit type):
    >This program converts Temperatures from Fahrenheit to Celsius and vice versa.
    >Please enter your temperature: 21.5
    >Please enter the units (F/C): ff

    >A temperature of 21.5 degrees Fahrenheit is equivalent to -5.83333 degrees Celcius.
    >Do you want another conversion? (Y/N): (did not prompt)
    
    >Please enter your temperature: 22
    >Please enter the units (F/C): f

    >A temperature of 22 degrees Fahrenheit is equivalent to -5.55556 degrees Celcius.
    >Do you want another conversion? (Y/N): n

    >Thank you. Goodbye

  Bad Data case 2 (more than one number for temperature):
    >This program converts Temperatures from Fahrenheit to Celsius and vice versa.
    >Please enter your temperature: 21.5 21
    >Please enter the units (F/C): (did not prompt)

    >Invalid input.
    >Please enter the units (F/C): f

    >A temperature of 22 degrees Fahrenheit is equivalent to -5.55556 degrees Celcius.
    >Do you want another conversion? (Y/N): n

    >Thank you. Goodbye

  Bad Data case 3 (other random character (not y/n) for done):
    >This program converts Temperatures from Fahrenheit to Celsius and vice versa.
    >Please enter your temperature: 21.5
    >Please enter the units (F/C): f

    >A temperature of 21.5 degrees Fahrenheit is equivalent to -5.83333 degrees Celcius.
    >Do you want another conversion? (Y/N): s

    >Please enter your temperature: -1
    >Please enter the units (F/C): c

    >A temperature of -1 degrees Celcius is equivalent to 30.2 degrees Fahrenheit.
    >Do you want another conversion? (Y/N): n

    >Thank you. Goodbye.

  Discussion:
    The program only accepts a single number for temperature, it will accept int
    or a double. It will convert int into double if necessary when the conversion
    is preformed. The program cannot read multiple inputs for temperature units or
    for done, if multiple characters are entered, it will use the first input for 
    the first cin, and the second character for the following cin in program without 
    prompting the user for new input. If any other character other than n or N is 
    entered for done, the program will continue.
*/

#include <iostream> // Stream declarations
using namespace std;

int main()
{
  // Declaring variables
  double temp, new_temp;
  char unit;
  string temp_unit;
  string new_temp_unit;
  char done = false;
  bool input_valid = false;

  // Printing program description
  cout << "This program converts Temperatures from Fahrenheit to Celsius and vice versa." << endl;

  // While the user has not selected 'N' or 'n' continue the program, not case sensitive
  while (!(tolower(done) == 'n'))
  {
    // Requesting temperature input from user
    cout << "Please enter your temperature: ";
    cin >> temp;

    // Requesting unit input from user
    input_valid = false;
    while (!input_valid)
    {
      cout << "Please enter the units (F/C): ";
      cin >> unit;
      cout << endl;

      // If the input is valid, exit the loop
      // Setting the variables new_temp_unit and temp_unit based on user input
      // Preforming a calculation to change the input temp into fahrenheit or celcius
      if (tolower(unit) == 'c')
      {
        temp_unit = "Celcius";
        new_temp = (temp * 9 / 5) + 32;
        new_temp_unit = "Fahrenheit";
        input_valid = true;
      }
      else if (tolower(unit) == 'f')
      {
        temp_unit = "Fahrenheit";
        new_temp = ((temp - 32) * 5 / 9);
        new_temp_unit = "Celcius";
        input_valid = true;
      }
      else {
        cout << "Invalid input." << endl;
      }
    }

    // Printing out the results of the inputted temperature converted to fahrenheit or celcius
    cout << "A temperature of " << temp << " degrees " << temp_unit << " is equivalent to " << new_temp << " degrees " << new_temp_unit << "." << endl;

    // Requesting user input to check if they are done with the program
    cout << "Do you want another conversion? (Y/N): ";
    cin >> done;
    cout << endl;
  }

  // Printing thank you and goodbye note
  cout << "Thank you. Goodbye" << endl;
  return 0;
} ///:~
