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
#include "Action.h"
#include "Inventory.h"
using namespace std;

class Game
{
private:
    bool is_running;
    bool location_changed;
    string starting_location = "Riverbank";
    map<string, Location> locations;
    map<string, Character> characters;
    map<string, Item> items;
    Control control;
    Action *action;
    Location *current_location;
    Inventory inventory;

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

        action = new Action(&locations, starting_location, &characters, &items, inventory);
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
            if (line.empty() || line[0] == '#')
            {
                continue;
            }

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

            Character character(name, description, dialogueList, actionList);
            characters[name] = character;
            if (!item.empty())
            {
                character.addItem(items[item]);
            }
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
            if (line.empty() || line[0] == '#')
            {
                continue;
            }

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
            items[name] = item;
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
            if (line.empty() || line[0] == '#')
            {
                continue;
            }

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
            if (line.empty() || line[0] == '#')
            {
                continue;
            }

            stringstream ss(line);
            string name, description, exits, conditions, characters_str, items_str;

            getline(ss, name, '|');
            getline(ss, description, '|');
            getline(ss, exits, '|');
            getline(ss, conditions, '|');
            getline(ss, characters_str, '|');
            getline(ss, items_str, '|');

            size_t pos;
            while ((pos = description.find("\\n")) != string::npos)
            {
                description.replace(pos, 2, "\n");
            }

            map<string, string> exitMap;
            vector<string> directions;
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
                    directions.push_back(direction);
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

            vector<string> character_list;
            stringstream charStream(characters_str);
            string char_name;
            while (getline(charStream, char_name, ','))
            {
                if (!char_name.empty())
                    character_list.push_back(char_name);
            }

            vector<string> item_list;
            stringstream itemStream(items_str);
            string item_name;
            while (getline(itemStream, item_name, ','))
            {
                if (!item_name.empty())
                    item_list.push_back(item_name);
            }

            Location location(name, description, exitMap, conditionMap);


            for (const string &item_name : item_list)
            {
                location.addItem(item_name);
            }
            for (const string &character_name : character_list)
            {
                location.addCharacter(character_name);
            }
            locations[name] = location;
        }
        file.close();
    }

    void displayInstructions()
    {
        string enter;
        cout
            << "******** Welcome to Alice's Adventures in Wonderland! ********\n"
            << "\nInstructions: This game expects input in 1-2 word combinations, you can enter "
            << "north, or n for north, this also applies to, east, south and west. "
            << "For northeast, you can enter northeast or ne. Capital and lowercase"
            << "letters are read as the same thing. Additional commands include, inventory, "
            << "take, drop, drink, eat, and talk to. To end the game at any point "
            << "type 'exit', 'quit' or 'q'. Once the game begins, you will receive a short"
            << "description on where you are.\n\nGoal: explore Wonderland as Alice to reach the finish line."
            << " First enter Wonderland to meet character and find the golden key."
            << "The golden key is hidden somewhere in Wonderland and you need it to get back to above "
            << "ground and win the game. You can earn achievements as you play the "
            << "game by interacting with characters in Wonderland.\n\nPress enter to start the game.\n";
        getline(cin, enter);
        cout << "\n******** Welcome to Alice's Adventures in Wonderland! ********\n"
             << endl;
    }

    void play()
    {
        // Game set-up
        initializeWorld();
        setIsRunning(true);
        displayInstructions();

        action->getCurrentLocation()->displayDescription();

        // Game loop for state: playing
        do
        {
            string input;
            cout << "> ";
            getline(cin, input);

            vector<string> action_words = control.validateAndParseInput(input);

            if (action_words.empty())
            {
                continue;
            }
            if (action_words[0] == "invalid")
            {
                cout << "I don't understand that command." << endl;
                continue;
            }

            if (action_words[0] == "exit" || action_words[0] == "quit")
            {
                endGame(action_words[0]);
                continue;
            }

            if (control.isMovementCommand(action_words[0]))
            {
                action->movePlayer(action_words[0]);
            }
            else if (action_words[0] == "enter")
            {
                action->handleEnterDoorCommand(action_words);
            }
            else
            {
                action->doAction(action_words);
            }
        } while (getIsRunning());
    }

    void endGame(string quit_word)
    {
        // if the quit word is exit or q, then double check that the user wants to exit the game rather than an area within the game
        if (getIsRunning() && quit_word == "exit")
        {
            cout << "You are about to quit the game. Enter 'yes', 'q', 'y' or 'quit' to "
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