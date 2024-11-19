//: Assignment3Qestion3.cpp

/*
Title: Assignment3Qestion3.cpp
Description: This program defines a `TextFileReader` class that reads lines 
from a specified text file, stores them in an array, and displays the file 
content either with or without line numbers. A `TextFileReaderDemo` class 
is used to demonstrate the functionality by prompting the user for a file 
name and displaying the file contents.
Date: September 30, 2024
Author: Minori Olguin
Student ID: 3441333
*/

/*
DOCUMENTATION

Program Purpose: This program helped me to better understand file I/O, getline() and 
string concatenation in for loops.

Compile: g++ -o Assignment3Question3 Assignment3Question3.cpp
Execution: ./Assignment3Question3

Notes: in Cygwin, main must return type int

Classes: TextFileReader, TextFileReaderDemo

Variables:
	file_name - string - Stores the name of the file entered by the user
	in_file - ifstream - an input file stream object user for reading the file
	stringArray[100] - string array): Stores up to 100 lines from the file, with each element holding a line.
	index - int - Used in `fillArray()` to track the position in `stringArray`.
	line - string - Holds each line read from the file in `fillArray()` method.
	stringBuffer - string - Used in `contents()` to concatenate and display the contents of `stringArray`.
*/

/*
TEST PLAN

 Normal case:
    - Enter a valid file name with multiple lines of content.
    - Verify that `contents()` displays the file contents without line numbers.
    - Verify that `display()` shows each line with corresponding line numbers.

 Bad Data case 1 (non-existent file name):
    - Enter a file name that does not exist.
    - Expected result: Program should output an error message indicating that the file could not be opened.

 Bad Data case 2 (file with more than 100 lines):
    - Enter a file name with over 100 lines of content.
    - Expected result: Only the first 100 lines should be stored and displayed, while the rest are ignored.

 Bad Data case 3 (empty file):
    - Enter the name of an empty file.
    - Expected result: Both `contents()` and `display()` should show no output, as there are no lines to display.

 Discussion: The main limitation for this program is that it can only handle a file of size 
 100 lines or less. If more, then the array will not be able to handle the size. 
*/

#include <iostream> // Stream declarations
#include <fstream>
#include <string>
using namespace std;

/****************************************************************
 Text File Reader
*****************************************************************/
class TextFileReader
{
private:
	string file_name;
	ifstream in_file;
	string stringArray[100];

public:
	TextFileReader() {} // Default contstructor

	TextFileReader(string file_name)
	{
		this->file_name = file_name;
		createStream(file_name);
		fillArray();
	}

	void createStream(string file_name)
	{
		in_file.open(file_name);
		if (!in_file.good())
		{
			cout << "Not able to open " << file_name << endl;
			exit(1);
		}
		else
		{
			cout << file_name << " was successfully opened!" << endl;
		}
	}

	void fillArray()
	{
		int index = 0;
		string line;
		while (getline(in_file, line) && index < 100)
		{
			stringArray[index] = line;
			index++;
		}
	}

	void contents()
	{
		string stringBuffer;
		for (int index = 0; index < 100; index++)
		{
			if (!stringArray[index].empty())
			{
				stringBuffer = stringBuffer + stringArray[index] + "\n";
			}
		}
		cout << stringBuffer << endl;
	}

	void display()
	{
		for (int index = 0; index < 100; index++)
		{
			if (!stringArray[index].empty())
			{
				cout << "line " << index + 1 << ": "
					 << stringArray[index] << endl;
			}
		}
	}
};

/****************************************************************
 Text File Reader Demo
*****************************************************************/
class TextFileReaderDemo
{
private:
	string file_name;

public:
	TextFileReaderDemo()
	{
		TextFileReader reader(getFileName());
		cout << "Demo for reader contents.\n"
			 << endl;
		reader.contents();
		cout << "Demo for display with line numbers.\n"
			 << endl;
		reader.display();
	}

	string getFileName()
	{
		cout << "Enter file name: ";
		cin >> file_name;
		return file_name;
	}
};

/****************************************************************
 Main
*****************************************************************/
int main()
{
	TextFileReaderDemo demo;
	return 0;
} ///:~
