//: Assignment4.cpp

/*
Title: Assignment4.cpp
Description:
Date: November 10, 2024
Author: Minori Olguin
Student ID: 3441333
*/

/*
DOCUMENTATION

Program Purpose:

Compile: g++ -o Assignment4 Assignment4.cpp
Execution: ./Assignment4

Notes: in Cygwin, main must return type int

Classes:

Variables:

*/

/*
TEST PLAN

Normal case:


Bad Data case 1 ():
    -

Bad Data case 2 ():
    -

Discussion:
*/

#include <iostream>
#include <sstream>
#include <fstream>
#include <map>
#include <vector>
#include <algorithm>
#include "Control.h"
#include "Location.h"
#include "Character.h"
#include "Item.h"
using namespace std;

class Game
{
private:
    bool is_running;
    bool location_changed;
    map<string, Location> locations;
    map<string, Character> characters;
    Control control;
    Location *current_location;

    // files to load characters, items, actions and locations
    string characters_file = "characters.txt";
    string items_file = "items.txt";
    string actions_file = "actions.txt";
    string locations_file = "locations.txt";

public:
    Game() : is_running(false), control() {}
    ~Game() {}

    bool getIsRunning() { return is_running; }
    void setIsRunning(bool running) { is_running = running; }

    void initializeWorld()
    {
        initializeCharacters();
        initializeItems();
        initializeActions();
        initializeLocations();

        if (locations.find("Riverbank") != locations.end())
        {
            setCurrentLocation(&locations["Riverbank"]);
        }
        else
        {
            cerr << "Error: Starting location 'Riverbank' not found." << endl;
            exit(EXIT_FAILURE);
        }
    }

    void initializeCharacters()
    {
        ifstream file(characters_file);
        if (!file.is_open())
        {
            cerr << "Error: Could not open " << characters_file << endl;
            return;
        }

        string line;
        while (getline(file, line))
        {
            stringstream ss(line);
            string name, description, dialogues, actions, item;
            getline(ss, name, '|');
            getline(ss, description, '|');
            getline(ss, dialogues, '|');
            getline(ss, actions, '|');
            getline(ss, item, '|');

            vector<string> dialogueList;
            vector<string> actionList;

            stringstream dialogueStream(dialogues);
            stringstream actionStream(actions);
            string token;

            while (getline(dialogueStream, token, ','))
                dialogueList.push_back(token);

            while (getline(actionStream, token, ','))
                actionList.push_back(token);

            Character character(name, description, dialogueList, actionList, item);
            characters[name] = character;
        }
        file.close();
    }

    void initializeItems()
    {
        ifstream file(items_file);
        if (!file.is_open())
        {
            cerr << "Error: Could not open " << items_file << endl;
            return;
        }

        string line;
        while (getline(file, line))
        {
            stringstream ss(line);
            string name, description, actions;
            getline(ss, name, '|');
            getline(ss, description, '|');
            getline(ss, actions, '|');

            vector<string> actionList;
            stringstream actionStream(actions);
            string token;

            while (getline(actionStream, token, ','))
                actionList.push_back(token);

            Item item(name, description, actionList);
        }
        file.close();
    }

    void initializeActions()
    {
        ifstream file(actions_file);
        if (!file.is_open())
        {
            cerr << "Error: Could not open " << actions_file << endl;
            return;
        }

        vector<string> parsed_actions;
        string line;
        while (getline(file, line))
        {
            stringstream iss(line);
            string action_name, description, targets;
            getline(iss, action_name, '|');
            getline(iss, description, '|');
            getline(iss, targets, '|');

            parsed_actions.push_back(action_name);
            vector<string> targetList;
            stringstream targetStream(targets);
            string token;

            while (getline(targetStream, token, ','))
                targetList.push_back(token);
        }
        file.close();
        control.setActionCommands(parsed_actions);
    }

    void initializeLocations()
    {
        ifstream file(locations_file);
        if (!file.is_open())
        {
            cerr << "Error: Could not open " << locations_file << endl;
            return;
        }

        string line;
        while (getline(file, line))
        {
            stringstream ss(line);
            string name, description, exits, conditions;
            getline(ss, name, '|');
            getline(ss, description, '|');
            getline(ss, exits, '|');
            getline(ss, conditions, '|');

            map<string, string> exitMap;
            stringstream exitStream(exits);
            string exitToken;

            while (getline(exitStream, exitToken, ','))
            {
                size_t delim = exitToken.find('=');
                if (delim != string::npos)
                {
                    string direction = exitToken.substr(0, delim);
                    string destination = exitToken.substr(delim + 1);
                    exitMap[direction] = destination;
                }
            }

            map<string, string> conditionMap;
            if (!conditions.empty())
            {
                stringstream conditionStream(conditions);
                string conditionToken;
                while (getline(conditionStream, conditionToken, ','))
                {
                    size_t delim = conditionToken.find('=');
                    if (delim != string::npos)
                    {
                        string key = conditionToken.substr(0, delim);
                        string value = conditionToken.substr(delim + 1);
                        conditionMap[key] = value;
                    }
                }
            }
            Location location(name, description, exitMap, conditionMap);
            locations[name] = location;
        }
        file.close();
    }

    void displayInstructions()
    {
        string enter;
        cout
            << "******** Welcome to Alice's Adventures in Wonderland! ********\n"
            << "This game expects input in 1-2 word combinations, you can enter\n"
            << "north, or n for north, this also applies to, east, south and west.\n"
            << "For northeast, you can enter northeast or ne. Capital and lowercase\n"
            << "letters are read as the same thing. Additional commands include, inventory,\n"
            << "take, drop, drink, eat, and talk to. To end the game at any point\n"
            << "type 'exit', 'quit' or 'q'. If at any time you need help with which\n"
            << "actions are available to you, enter 'help' for a list of actions.\n"
            << "Once the game begins, you will receive a short description on where\n"
            << "you are. Your goal is to reach the finish line, which is finding your\n"
            << "way out of Wonderland after retrieving a golden key. The golden key is\n"
            << "hidden in Wonderland. You can start the game by pressing enter to continue.\n"
            << endl;
        getline(cin, enter);
    }

    void processActions(vector<string> actionWords)
    {
    }

    bool getLocationChanged() { return location_changed; }
    Location *getCurrentLocation() { return current_location; }

    void setCurrentLocation(Location *location)
    {
        if (current_location != location)
        {
            current_location = location;
            setLocationChanged(true);
        }
        else
        {
            setLocationChanged(false);
        }
    }

    void setLocationChanged(bool changed_location)
    {
        location_changed = changed_location;
    }

    void play()
    {
        // Game set-up
        initializeWorld();
        setIsRunning(true);
        displayInstructions();

        setLocationChanged(true);

        // Game loop for state: playing
        do
        {
            if (getLocationChanged())
            {
                current_location->displayCurrentLocationDescription();
            }
            // put location description if location changed
            string input;
            cout << "> ";
            getline(cin, input);

            vector<string> actionWords = control.validateAndParseInput(input);

            if (actionWords.empty())
                continue;
            if (actionWords[0] == "invalid")
            {
                cout << "I don't understand that command." << endl;
                continue;
            }

            if (actionWords[0] == "exit" || actionWords[0] == "quit")
            {
                endGame(actionWords[0]);
                continue;
            }

            processActions(actionWords);

        } while (getIsRunning());
    }

    void endGame(string quit_word)
    {
        if (getIsRunning() && quit_word == "exit")
        {
            cout << "You are about to quit the game. Enter 'yes' or 'quit' to "
                 << "confirm or anything else to continue playing.\n> ";
            string input;
            getline(cin, input);

            if (control.confirmQuitGame(input))
            {
                setIsRunning(false);
                cout << "The end!" << endl;
            }
            else
            {
                cout << "... resuming game play ..." << endl;
            }
        }
        else
        {
            setIsRunning(false);
            cout << "The end!" << endl;
        }
    }
};

int main()
{
    Game wonderland;
    wonderland.play();
    return 0;
};