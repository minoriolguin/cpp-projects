//: Assignment3Qestion1.cpp

/*
Title: Assignment3Qestion1.cpp
Description: This program defines a class called `WordCounter` that counts 
the number of words in a given text file. The program prompts the user to 
enter a file name, opens the file if it exists, counts the words within it, 
and displays the word count.
Date: September 23, 2024
Author: Minori Olguin
Student ID: 3441333
*/

/*
DOCUMENTATION

Program Purpose: This program implements a `WordCounter` class that 
helps count the number of words in a specified text file. It prompts the user 
for a file name, attempts to open the file, and if successful, reads through 
the file content to count and display the total number of words.

Compile: g++ -o Assignment3Question1 Assignment3Question1.cpp
Execution: ./Assignment3Question1

Notes: in Cygwin, main must return type int

Classes:
1. `WordCounter`: Handles word counting functionality for a given file.
    - Methods:
      - `getFileName()`: Prompts the user to enter the file name and returns it.
      - `createStream()`: Opens the file and checks if the file stream is good.
      - `countWords()`: Counts the number of words in the file by reading words sequentially.
      - `displayCount()`: Displays the word count result to the console.

Variables:
- file_name - string - Stores the name of the file entered by the user.
- inFile - ifstream - An input file stream object used to read the file content.
- word - string - Temporary variable to hold each word read from the file in `countWords()` method.
- word_count - int - Holds the total word count in the file, calculated by the `countWords()` method.
*/

/*
 TEST PLAN

 Normal case:
    - Enter the name of an existing file with known content.
    - Verify that the program correctly opens the file, counts the words, and displays the accurate word count.

 Bad Data case 1 (non-existent file name):
    - Enter a file name that does not exist.
    - Expected result: Program should output an error message indicating that the file 
						could not be opened.

 Bad Data case 2 (empty file):
    - Enter the name of an empty file.
    - Expected result: Program should display a word count of 0.

 Bad Data case 3 (file with special characters and numbers):
    - Enter a file name containing special characters and numbers mixed with words.
    - Expected result: Program should count only the words, ignoring special characters 
						and numbers if they are not part of a word.

 Discussion: The current limitations for this program is that this program 
 assumes that the user enters a valid file name with an accessible path in 
 the working directory.
*/

#include <iostream>  // Stream declarations
#include <fstream>
using namespace std;

/****************************************************************
 Word Counter
*****************************************************************/
class WordCounter
{
private:
	// declaring variables
	string file_name;
	ifstream inFile;

public:
	// Gets the file name as input from the user
	string getFileName()
	{
		cout << "Enter file name: ";
		cin >> file_name;
		cout << endl;
		return file_name;
	}

	// Method to create a stream, provides descriptive output to terminal
	// to let the user know whether the operation was successful
	void createStream()
	{
		getFileName();
		inFile.open(file_name);
		if (!inFile.good())
		{
			cout << "Not able to open " << file_name << endl;
		}
		else
		{
			cout << file_name << " was successfully opened!" << endl;
		}
	}

	// Count words creates a stream then counts the words and closes the stream
	int countWords()
	{
		createStream();
		string word;
		int word_count = 0;
		cout << "Counting the words in " << file_name << "..." << endl;
		while (inFile >> word)
		{
			word_count++;
		}
		inFile.close();
		return word_count;
	}

	// method that displays the final word count with descriptive text
	void displayCount()
	{
		int word_count = countWords();
		cout << "The final word count for " << file_name << " is "
			 << word_count << " words." << endl;
	}
};

/****************************************************************
 Main
*****************************************************************/
int main()
{
	// Testing the displayCount()
	WordCounter counter;
	counter.displayCount();
} ///:~
