//: Control.h

/*
Title: Control.h
Description: Controller object header file
Date: November 5, 2024
Author: Minori Olguin
Student ID: 3441333
*/

#ifndef CONTROL_H
#define CONTROL_H

#include <iostream> // Stream declarations
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

class Control
{
private:
    vector<string> north = {"north", "n", "up"};
    vector<string> south = {"south", "s", "down"};
    vector<string> east = {"east", "e", "right"};
    vector<string> west = {"west", "w", "left"};
    vector<string> northwest = {"northwest", "nw"};
    vector<string> northeast = {"northeast", "ne"};
    vector<string> southeast = {"southeast", "se"};
    vector<string> southwest = {"southwest", "sw"};
    vector<string> movement_commands;
    vector<string> action_commands;
    vector<string> exit_commands = {"exit", "quit", "q"};
    vector<string> confirm_commands = {"yes", "y"};

    void createMovementVector()
    {
        movement_commands.insert(movement_commands.end(), north.begin(), north.end());
        movement_commands.insert(movement_commands.end(), south.begin(), south.end());
        movement_commands.insert(movement_commands.end(), east.begin(), east.end());
        movement_commands.insert(movement_commands.end(), west.begin(), west.end());
        movement_commands.insert(movement_commands.end(), northwest.begin(), northwest.end());
        movement_commands.insert(movement_commands.end(), northeast.begin(), northeast.end());
        movement_commands.insert(movement_commands.end(), southeast.begin(), southeast.end());
        movement_commands.insert(movement_commands.end(), southwest.begin(), southwest.end());
    }

    string trimWhitespace(string input)
    {
        int start = 0;
        while (start < input.size() && isspace(input[start]))
            start++;

        int end = input.size() - 1;
        while (end >= 0 && isspace(input[end]))
            end--;

        if (start > end)
            return {};

        string trimmed_input = input.substr(start, end - start + 1);

        return trimmed_input;
    }

    string convertToLower(string input)
    {
        transform(input.begin(), input.end(), input.begin(),
                  [](unsigned char c)
                  { return tolower(c); });
        return input;
    }

    vector<string> splitIntoWords(const string &input)
    {
        istringstream stream(input);
        vector<string> words;
        string word;
        while (stream >> word)
        {
            words.push_back(word);
        }
        return words;
    }

    vector<string> validateInput(string input)
    {
        return splitIntoWords(convertToLower(trimWhitespace(input)));
    }

public:
    Control()
    {
        createMovementVector();
    }

    void setActionCommands(vector<string> commands) 
    {
        action_commands = commands;
    }

    bool isExitCommand(const string &input)
    {
        return find(exit_commands.begin(), exit_commands.end(), input) != exit_commands.end();
    }

    bool isMovementCommand(const string &input)
    {
        return find(movement_commands.begin(), movement_commands.end(), input) != movement_commands.end();
    }

    bool isActionCommand(const string &input)
    {
        return find(action_commands.begin(), action_commands.end(), input) != action_commands.end();
    }

    bool isConfirmCommand(const string &input)
    {
        return find(confirm_commands.begin(), confirm_commands.end(), input) != confirm_commands.end();
    }

    vector<string> validateAndParseInput(const string &input)
    {
        vector<string> words = validateInput(input);

        if (words.empty())
        {
            cout << "Please enter a command.\n";
            return {};
        }

        if (isExitCommand(words[0]))
        {
            if (words[0] == "exit")
            {
                return {"exit"};
            }
            else 
            {
                return {"quit"};
            }
        }

        for (string word : words)
        {
            if (isMovementCommand(word) || isActionCommand(word))
            {
                return words;
            }
        }

        return {"invalid"};
    }

    bool confirmQuitGame(string input)
    {
        vector<string> words = validateInput(input);
        return isConfirmCommand(words[0]);
    }
};

#endif