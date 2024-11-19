//: Assignment3Question4.cpp

/*
Title: Assignment3Question4.cpp
Description: This program defines a `FloatArrays` class that demonstrates array 
initialization, basic arithmetic operations on arrays, and displays the results 
of computations involving array elements. The main purpose is to help understand 
how to work with arrays, initialize values, perform element-wise operations, and 
display results.
Date: October 4, 2024
Author: Minori Olguin
Student ID: 3441333
*/

/*
DOCUMENTATION

Program Purpose: This program helped me to gain a further understanding of how 
for loops and arrays work in C++.

Compile: g++ -o Assignment3Question4 Assignment3Question4.cpp
Execution: ./Assignment3Question4

Notes: in Cygwin, main must return type int

Classes: FloatArrays

Variables: 
	size - int - Defines the fixed size of the arrays for the for loops as 25.
	loopCounter[25] - float array - Stores integer values from 1 to 25, representing initial values.
	loopCounterSquared[25] - float array - Stores the square of each element in `loopCounter`.
	results[25] - float array - Stores the sum of corresponding elements from `loopCounter` and `loopCounterSquared`.

*/

/*
 TEST PLAN

 Normal case: This program does not take user input so normal input would
 be that it prints in the necessary format as required by assignment guidelines.

 Discussion: This is a really simple program so it doesn't have many limitations.
*/

#include <iostream> // Stream declarations
using namespace std;

/****************************************************************
 Float Arrays
*****************************************************************/
class FloatArrays
{
private:
	static const int size = 25;
	float loopCounter[25];
	float loopCounterSquared[25];
	float results[25];

public:
	// Constructor, initializes the 3 arrays with the necessary  values
	FloatArrays()
	{
		InitializeLoopCounter();
		InitializeLoopCounterSquared();
		InitializeResults();
	}

	// Initializes the loop counter array 
	void InitializeLoopCounter()
	{
		for (int i = 0; i < size; i++)
		{
			loopCounter[i] = i + 1;
		}
	}

	// squares the loop counter squared value
	void InitializeLoopCounterSquared()
	{
		for (int i = 0; i < size; i++)
		{
			loopCounterSquared[i] = loopCounter[i] * loopCounter[i];
		}
	}

	// initializes the results array by adding the two other array vals together
	void InitializeResults()
	{
		for (int i = 0; i < size; i++)
		{
			results[i] = loopCounter[i] + loopCounterSquared[i];
		}
	}

	// Displays the 3 arrays in required format
	void display()
	{
		for (int i = 0; i < size; i++)
		{
			cout << loopCounter[i] << " + " << loopCounterSquared[i]
				 << " = " << results[i] << endl;
		}
	}
};

/****************************************************************
 Main
*****************************************************************/
int main()
{
	FloatArrays demo;
	demo.display();
} ///:~
