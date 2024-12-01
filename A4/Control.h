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
    map<string, string> direction_map = {
        {"north", "north"},
        {"n", "north"},
        {"up", "north"},
        {"south", "south"},
        {"s", "south"},
        {"down", "south"},
        {"east", "east"},
        {"e", "east"},
        {"right", "east"},
        {"west", "west"},
        {"w", "west"},
        {"left", "west"},
        {"northeast", "northeast"},
        {"ne", "northeast"},
        {"northwest", "northwest"},
        {"nw", "northwest"},
        {"southeast", "southeast"},
        {"se", "southeast"},
        {"southwest", "southwest"},
        {"sw", "southwest"}};
    map<string, string> character_map = {
        {"the mad hatter", "Hatter"},
        {"mad hatter", "Hatter"},
        {"the hatter", "Hatter"},
        {"hatter", "Hatter"},
        {"the white rabbit", "Rabbit"},
        {"white rabbit", "Rabbit"},
        {"the rabbit", "Rabbit"},
        {"rabbit", "Rabbit"},
        {"march hare", "March Hare"},
        {"the march hare", "March Hare"},
        {"the hare", "March Hare"},
        {"hare", "March Hare"},
        {"gryphon", "Gryphon"},
        {"the gryphon", "Gryphon"},
        {"the bird", "Gryphon"},
        {"bird", "Gryphon"},
        {"queen of hearts", "Queen of Hearts"},
        {"red queen", "Queen of Hearts"},
        {"the red queen", "Queen of Hearts"},
        {"queen", "Queen of Hearts"},
        {"the queen", "Queen of Hearts"},
        {"the queen of hearts", "Queen of Hearts"}};
    vector<string> movement_commands = {"north", "south", "east", "west", "northeast", "northwest", "southeast", "southwest"};
    vector<string> action_commands;
    vector<string> exit_commands = {"exit", "quit", "q"};
    vector<string> confirm_commands = {"yes", "y", "q", "quit"};
    vector<string> partial_commands = {"turn", "talk"};

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
    Control() {}

    void setActionCommands(vector<string> commands)
    {
        action_commands = commands;
    }

    string normalizeDirection(const string &input)
    {
        if (direction_map.find(input) != direction_map.end())
        {
            return direction_map[input];
        }
        return "";
    }

    string normalizeCharacterName(const string &input)
    {
        if (character_map.find(input) != character_map.end())
        {
            return character_map[input];
        }
        return "";
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

    bool isPartialCommand(const string &input)
    {
        return find(partial_commands.begin(), partial_commands.end(), input) != partial_commands.end();
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
            if (words[0] == "exit" || words[0] == "q")
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
            if (isMovementCommand(normalizeDirection(word)))
            {
                return {normalizeDirection(word)};
            }
            else if (isActionCommand(word) || isPartialCommand(word))
            {
                if (word == "enter")
                {
                    return words;
                }
                else if (word == "door")
                {
                    words.insert(words.begin(), "enter");
                    return words;
                }
                else if (word == "turn")
                {
                    if (words[1] == "on" || words[2] == "on")
                    {
                        return {"turn on", "lamp"};
                    }
                    else if (words[1] == "off" || words[2] == "off")
                    {
                        return {"turn off", "lamp"};
                    }
                }
                else if (word == "talk")
                {
                    string input;
                    for (int i = 2; i < words.size(); i++)
                    {
                        if (!input.empty())
                        {
                            input += " ";
                        }
                        input += words[i];
                    }
                    return {"talk to", normalizeCharacterName(input)};
                }
                else if (word == "follow" || word == "wear")
                {
                    string input;
                    for (int i = 1; i < words.size(); i++)
                    {
                        if (!input.empty())
                        {
                            input += " ";
                        }
                        input += words[i];
                    }
                    return {"follow", normalizeCharacterName(input)};
                }
                else if (word == "take" && words[1] == "off")
                {
                    string input;
                    for (int i = 2; i < words.size(); i++)
                    {
                        if (!input.empty())
                        {
                            input += " ";
                        }
                        input += words[i];
                    }
                    return {"take off", normalizeCharacterName(input)};
                }
                else
                {
                    return words;
                }
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