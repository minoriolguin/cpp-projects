//: Assignment3Qestion2.cpp

/*
Title: Assignment3Qestion2.cpp
Description: This program defines a `ReadByLine` class that allows the 
user to read a text file line by line. The program prompts the user to 
enter a file name, opens the file if it exists, and then reads and 
displays each line of the file. The user must press enter to proceed 
to the next line.
Date: September 24, 2024
Author: Minori Olguin
Student ID: 3441333
*/

/*
DOCUMENTATION

Program Purpose: This program helped me to learn how to use getline() and 
understand more about file I/O.

Compile: g++ -o Assignment3Question2 Assignment3Question2.cpp
Execution: ./Assignment3Question2

Notes: in Cygwin, main must return type int

Classes: ReadByLine

Variables:
 - file_name - string - Stores the name of the file entered by the user.
 - inFile - ifstream - An input file stream used to read from the file.
 - enter - string - Temporarily holds input to wait for the user to press enter.
 - line - string - Holds each line read from the file for display.
*/

/*
TEST PLAN 

 Normal case:
    - Enter the name of an existing file with several lines of content.
    - Verify that the program correctly opens the file, displays each line one by one, and waits for the user to press enter before proceeding to the next line.

 Bad Data case 1 (non-existent file name):
    - Enter a file name that does not exist.
    - Expected result: Program should output an error message indicating that the file could not be opened and exit gracefully.

 Bad Data case 2 (empty file):
    - Enter the name of an empty file.
    - Expected result: Program should indicate the file was successfully opened but display nothing (no lines to read).

 Discussion: The main limitation for this program is the same as for problem 1
 the program assumes that the user has entered a valid path to a file that is in 
 the same working directory or has a valid path to another directory.
*/

#include <iostream>  // Stream declarations
#include <fstream>
using namespace std;

/****************************************************************
 Read by line
*****************************************************************/
class ReadByLine
{
private:
	string file_name;
	ifstream inFile;

public:
	string getFileName()
	{
		cout << "Enter a file name: ";
		cin >> file_name;
		return file_name;
	}

	void createStream()
	{
		getFileName();
		inFile.open(file_name);
		if (!inFile.good())
		{
			cout << "Not able to open " << file_name << endl;
			exit(1);
		}
		else
		{
			cout << file_name << " was successfully opened!" << endl;
		}
	}

	void readFile()
	{
		createStream();
		string enter;
		string line;

		cout << "Beginning to read " << file_name << " file will be read line by line. "
			 << "Press enter to continue to the next line.\n"
			 << endl;
		getline(cin, enter);
		while (getline(inFile, line))
		{
			cout << line;
			getline(cin, enter);
		}
		cout << "Done reading, end of file!" << endl;
		inFile.close();
	}
};

/****************************************************************
 Main
*****************************************************************/
int main()
{
	ReadByLine reader;
	reader.readFile();
} ///:~
