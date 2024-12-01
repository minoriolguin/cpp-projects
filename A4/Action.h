//: Action.h

/*
Title: Action.h
Description: Action object header file
Date: November 5, 2024
Author: Minori Olguin
Student ID: 3441333
*/

/*
DOCUMENTATION

Program Purpose:
    This program is responsible for handling player actions and
    interactions within the game world. It manages player movement,
    item interactions, door states, and communication with characters.
    This class serves as the intermediary between the player and the
    various game elements such as locations, items, and characters.

Date: November 10, 2024

Compile (assuming Cygwin is running): g++ -std=c++11 -o Game Game.cpp
Execution (assuming Cygwin is running): ./Game.exe

Notes: in Cygwin, main must return type int

Classes: Action

Variables:
    playerInventory - Inventory - Manages the player's inventory
    current_location - Location* - Pointer to the player's current location
    all_locations - map<string, Location>*  - Pointer to a map of all game locations
    all_characters - map<string, Character>* - Pointer to a map of all game characters
    all_items - map<string, Item>* - Pointer to a map of all game items
    valid_directions - vector<string> - Vector of valid movement directions
    valid_yes - vector<string> - Vector of variations for confirming "yes"
    counter - int - Tracks the number of character dialogues
    win - bool - Tracks whether the player has won the game
    lampIsOn - bool - Tracks the lamp's state (on/off)
    hatIsOn - bool - Tracks whether the player is wearing the hat
    location_changed - bool - Tracks whether the player's location has changed
    door_1_locked - bool - Tracks whether Door 1 is locked
    door_2_locked - bool - Tracks whether Door 2 is locked
    received_special_message - bool - Tracks whether a special message was received
    door_map - map<string, string> - Maps door names to their corresponding identifiers
*/

#ifndef ACTION_H
#define ACTION_H

#include <iostream> // Stream declarations
#include <string>
#include <map>
#include <set>
#include "Inventory.h"
#include "Location.h"
#include "Character.h"
#include "Item.h"
using namespace std;

/*****************************************************************************
 * Action
 *****************************************************************************/
class Action
{
private:
    // private variables descriptive in nature
    Inventory playerInventory;
    Location *current_location;

    // location, character, items and door maps
    map<string, Location> *all_locations;
    map<string, Character> *all_characters;
    map<string, Item> *all_items;
    map<string, string> door_map = {
        {"door 1", "door_1"},
        {"door 2", "door_2"},
        {"door 3", "door_3"},
        {"door", "door"}};

    // validation vectors
    vector<string> valid_directions;
    vector<string> valid_yes = {"Yes", "YES", "y", "Y", "Yes ", "YES ", "y ", "Y ", "yes", "yes "};
    // set of strings representing achievements that can be earned
    set<string> achievements;
    // counters and bools
    int counter = 0;
    bool win = false;
    bool lampIsOn, hatIsOn, location_changed;
    bool door_1_locked = true;
    bool door_2_locked = true;
    bool received_special_message = false;

public:
    // Constructor for action
    Action(map<string, Location> *locations, const string &start_location_name, map<string, Character> *characters, map<string, Item> *items, Inventory &inventory)
        : lampIsOn(false), hatIsOn(false), all_locations(locations), all_characters(characters), all_items(items), playerInventory(inventory)
    {
        if (all_locations->find(start_location_name) != all_locations->end())
        {
            current_location = &(*all_locations)[start_location_name];
        }
        else
        {
            cerr << "Error: Starting location '" << start_location_name << "' not found." << endl;
            exit(EXIT_FAILURE);
        }
    }

    // single line getters
    Location *getCurrentLocation() const { return current_location; }
    bool getLocationChanged() const { return location_changed; }
    bool getLampOn() const { return lampIsOn; }
    bool getWin() const { return win; }

    // set player wins
    void playerWins() { win = true; }

    // setters for door locks
    void setDoor1Lock(bool is_locked)
    {
        door_1_locked = is_locked;
    }

    void setDoor2Lock(bool is_locked)
    {
        door_2_locked = is_locked;
    }

    // setter for location changed
    void setLocationChanged(bool location_changed)
    {
        this->location_changed = location_changed;
    }

    // method for auto transitions, when a player is transitioned without entering a command
    void autoTransitionTo(const string &next_location_name)
    {
        if (all_locations->find(next_location_name) != all_locations->end())
        {
            current_location = &(*all_locations)[next_location_name];
            current_location->displayDescription();
            setLocationChanged(true);
        }
        else
        {
            cout << "Error: The location '" << next_location_name << "' does not exist!" << endl;
            setLocationChanged(false);
        }
    }

    // displays a help menu that lists exits available to the player
    void displayHelp() const
    {
        cout << "Help: try going in one of the following directions\n";
        for (auto &exit : current_location->getExitList())
        {
            cout << "- " << exit.first << endl;
        }
    }

    // moves the player based on the command they enter
    void movePlayer(string direction)
    {
        if (current_location->hasExit(direction))
        {
            string next_location_name = current_location->getExit(direction);

            if (next_location_name == "Rabbit Hole")
            {
                current_location = &(*all_locations)[next_location_name];
                current_location->displayDescription();

                autoTransitionTo("Room Full of Doors");
                return;
            }

            // special case of winning the game
            if (current_location->getName() == "Return to Above Ground" && next_location_name == "Riverbank")
            {
                if (playerInventory.hasItem("gold key"))
                {
                    playerWins();
                    cout << "\n\nYou rub your eyes, was it really that dark down there. "
                         << "You crawl up through the small tunnel and breathe the fresh air, "
                         << "feel the warm sunlight and jump for joy! You find yourself back on "
                         << "the riverbank. That wasn't just a dream, was it?\n"
                         << endl;
                    return;
                }
            }

            // if the location exists
            if (all_locations->find(next_location_name) != all_locations->end())
            {
                current_location = &(*all_locations)[next_location_name];
                current_location->displayDescription();
                setLocationChanged(true);
            }
            else
            {
                cout << "The destination '" << next_location_name << "' does not exist!" << endl;
                setLocationChanged(false);
            }
        }
        else
        {
            cout << "You can't go that way." << endl;
        }
    }

    // checks if the door is locked returns bool
    bool isDoorLocked(string door)
    {
        if (door == "door_1")
        {
            if (door_1_locked)
            {
                cout << "Door 1 is locked, maybe a key would help..." << endl;
            }
            else
            {
                cout << "You made it through the door... " << endl;
            }
            return door_1_locked;
        }
        else if (door == "door_2")
        {
            if (door_2_locked)
            {
                cout << "Door 2 is locked, who knows what could shed a little light on the problem..." << endl;
            }
            else
            {
                cout << "You made it through the door... " << endl;
            }
            return door_2_locked;
        }
        else
        {
            cout << "You made it through the door... " << endl;
            return false;
        }
    }

    // handles when the character moves through a door
    void handleEnterDoorCommand(vector<string> command_words)
    {
        string target_door;

        // checks if the character is in special location where they need 3 commands
        if (current_location == &all_locations->find("Room Full of Doors")->second)
        {
            if (command_words.size() < 3)
            {
                cout << "Enter what? Please specify a door.\n";
                return;
            }

            target_door = command_words[1];
            for (int i = 2; i < command_words.size(); ++i)
            {
                target_door += " " + command_words[i];
            }
        }

        // sets the door to door_1 to make sure it's not locked
        else if (current_location == &all_locations->find("Return to Above Ground")->second)
        {
            target_door = "door_1";
        }

        // otherwise set to door to handle player entering unlabeled door
        else
        {
            target_door = "door";
        }

        // if the door a valid door exit
        if (door_map.find(target_door) != door_map.end())
        {
            // if the door isn't locked
            string exit_key = door_map.at(target_door);
            if (!isDoorLocked(exit_key))
            {
                movePlayer(exit_key);
            }
        }
        else
        {
            cout << "The door '" << target_door << "' does not exist.\n";
        }
    }

    // Checks if a string is an item
    bool isItem(string item_name)
    {
        auto it = all_items->find(item_name);
        return (it != all_items->end());
    }

    // finds the item by it's name, if the item is found, returns the item
    Item findItemByName(string item_name)
    {
        auto it = all_items->find(item_name);
        if (it != all_items->end())
        {
            return it->second;
        }
        else
        {
            throw runtime_error("Item not found: " + item_name);
        }
    }

    // handles when the player enters 'take' item
    void takeItem(Item item)
    {
        // checks if the item is in the current location
        if (current_location->hasItem(item.getName()))
        {
            // tries to put item in play inventory
            bool item_taken = playerInventory.addItem(item);
            // if successful
            if (item_taken)
            {
                // removes item from current location
                current_location->removeItem(item.getName());
                cout << "You have taken the " << item.getName() << ".\n";
            }
        }
        // if the player already took the item
        else if (playerInventory.hasItem(item.getName()))
        {
            cout << "There is no more " << item.getName() << "s here.\n";
        }
        // if the item isn't in this location
        else
        {
            cout << "There is no " << item.getName() << " here.\n";
        }
    }

    // removes item from players inventory if player enters 'drop'
    void dropItem(string item_name)
    {
        if (playerInventory.hasItem(item_name))
        {
            // removes the item from player inventory if it is there and adds to current location
            playerInventory.removeItem(item_name, "drop");
            current_location->addItem(item_name);
        }
        else
        {
            // if the item is not in the players inventory and they try to drop
            cout << "Unable to find " << item_name << " in your inventory." << endl;
        }
    }

    // handles if player enters 'eat' item
    void eatItem(string item_name)
    {
        addAchievement(findItemByName(item_name).getAchievement());
        playerInventory.removeItem(item_name, "eat");
    }

    // handles if the player tries to use a key
    void useKey(string item_name)
    {
        if (playerInventory.hasItem(item_name))
        {
            if (current_location->getName() == "Room Full of Doors")
            {
                cout << "You use the gold key to unlock the door and put it back into your pocket." << endl;
                setDoor1Lock(false);
            }
            else
            {
                cout << "You can't use the gold key here." << endl;
            }
        }
        else
        {
            cout << "You don't have a gold key in your inventory." << endl;
        }
    }

    // handles if the player tries to use the flamingo
    void useFlamingo(string item_name)
    {
        if (playerInventory.hasItem(item_name))
        {
            if (current_location->hasItem("hedgehog"))
            {
                addAchievement(findItemByName(item_name).getAchievement());
                cout << "You use the flamingo to play croquet, using the hedgehogs as croquet balls." << endl;
            }
            else
            {
                cout << "You can't use the " << item_name << " with out a hedgehog ball." << endl;
            }
        }
        else
        {
            cout << "You don't have a " << item_name << " in your inventory." << endl;
        }
    }

    // handles if player enters 'wear' item
    void wearHat(string item_name)
    {
        if (playerInventory.hasItem(item_name) && findItemByName(item_name).isWearable())
        {
            if (hatIsOn)
            {
                cout << "You are already wearing the hat." << endl;
            }
            else
            {
                playerInventory.removeItem(item_name, "drop");
                addAchievement(findItemByName(item_name).getAchievement());
                cout << "You put on the hat." << endl;
            }
        }
        else
        {
            cout << "You are not wearing a hat, silly." << endl;
        }
    }

    // handles if player enters 'take off' item
    void takeOffHat(string item_name)
    {
        if (hatIsOn && !playerInventory.isFull())
        {
            playerInventory.addItem(findItemByName(item_name));
            cout << "You take off the hat and put it in your inventory." << endl;
        }
        else if (hatIsOn && playerInventory.isFull())
        {
            cout << "Your inventory is full, please remove an item to take off the hat and place it in your inventory." << endl;
        }
        else if (!hatIsOn)
        {
            cout << "You are not wearing a hat, silly." << endl;
        }
    }

    // toggles the light, unlocks the door 2 if light is on
    void toggleLight()
    {
        lampIsOn = !lampIsOn;
        setDoor2Lock(!lampIsOn);
    }

    // finds the character by it's name, if the character is found, returns the character
    Character findCharacterByName(string character_name)
    {
        auto it = all_characters->find(character_name);
        if (it != all_characters->end())
        {
            return it->second;
        }
        else
        {
            throw runtime_error("Item not found: " + character_name);
        }
    }

    // checks if the string entered is a valid character
    bool isCharacter(string character_name)
    {
        return all_characters->find(character_name) != all_characters->end();
    }

    // checks if yes is a valid yes
    bool isYes(string input)
    {
        return find(valid_yes.begin(), valid_yes.end(), input) != valid_yes.end();
    }

    // handles talk to character action
    void talkToCharacter(string character_name)
    {
        if (isCharacter(character_name))
        {
            Character character = findCharacterByName(character_name);
            if (current_location->hasCharacter(character_name))
            {
                received_special_message = character.talkToPlayer(counter);
                if (counter > 2)
                {
                    counter = 0;
                }
                else
                {
                    counter++;
                }
                if (received_special_message)
                {
                    string input;
                    cout << "The Gryphon is offering you the Golden Key, would you like to accept?" << endl;
                    getline(cin, input);
                    if (isYes(input))
                    {
                        takeItem(findItemByName("gold key"));
                        addAchievement(findItemByName("gold key").getAchievement());
                        character.removeCharacterItem();
                    }
                    else
                    {
                        cout << "Never mind, move along!" << endl;
                    }
                }
            }
            else
            {
                cout << "The " << character_name << " is not in the " << current_location->getName() << "." << endl;
            }
        }
        else
        {
            cout << "That character does not exist. :(" << endl;
        }
    }

    // handles follow character action
    void followCharacter(string direction, string character_name)
    {
        if (isCharacter(character_name))
        {
            Character character = findCharacterByName(character_name);
            if (current_location->hasCharacter(character_name) && character.hasAction(direction))
            {
                cout << "You started following " << character_name << "... This seems to be a short-cut... " << endl;

                movePlayer(direction);
            }
            else if (!current_location->hasCharacter(character_name))
            {
                cout << "The " << character_name << " is not in the " << current_location->getName() << "." << endl;
            }
            else
            {
                cout << "You can't follow the " << character_name << "." << endl;
            }
        }
        else
        {
            cout << "That character does not exist. :(" << endl;
        }
    }

    // add the achievement to the achievement set if it doesn't already have it
    void addAchievement(const string &achievement)
    {
        if (achievement.empty())
        {
            return;
        }

        if (achievements.find(achievement) == achievements.end())
        {
            achievements.insert(achievement);
            cout << "You've earned the achievement: " << achievement << "\n"
                 << endl;
        }
    }

    // output the achievements that the player earned
    void displayAchievements()
    {
        int achievementsCount = achievements.size();
        cout << endl;

        if (achievementsCount == 0)
        {
            cout << "You did not earn any achivements." << endl;
        }
        else if (achievementsCount == 1)
        {
            cout << "1 achievement earned:" << endl;
            cout << "- " << *achievements.begin() << endl;
        }
        else
        {
            cout << achievementsCount << " achievements earned:" << endl;
            for (const string &achievement : achievements)
            {
                cout << "- " << achievement << endl;
            }
        }

        cout << endl;
    }

    // Takes input as vector<string> matches the action words to an above method and calls it
    void doAction(vector<string> action_words)
    {
        if ((current_location->hasItem(action_words[1])) && action_words.size() > 1)
        {
            Item item = findItemByName(action_words[1]);
            if ((action_words[0] == "read" || action_words[0] == "inspect"))
            {
                addAchievement(item.getAchievement());
                cout << item.getDescription() << endl;
            }
            else if (action_words[0] == "take" || action_words[0] == "pick")
            {
                takeItem(item);
                if (action_words[1] != "hat" && action_words[1] != "flamingo")
                {
                    addAchievement(item.getAchievement());
                }
            }
            else if ((action_words[0] == "turn on" || action_words[0] == "turn off") && current_location->hasItem("lamp"))
            {
                if (lampIsOn && action_words[0] == "turn on")
                {
                    cout << "The lamp is already on!" << endl;
                }
                else if (!lampIsOn && action_words[0] == "turn off")
                {
                    cout << "The lamp is already off!" << endl;
                }
                else
                {
                    toggleLight();
                    cout << "The lamp " << (lampIsOn ? " is now ON." : " is now OFF.") << endl;
                }
            }
        }
        else if (action_words[0] == "inventory" || action_words[0] == "i")
        {
            playerInventory.displayInventory();
        }
        else if (action_words[0] == "help" || action_words[0] == "h")
        {
            displayHelp();
        }
        else if (action_words.size() == 1)
        {
            cout << "You need to enter an item after " << action_words[0] << " to " << action_words[0] << " it." << endl;
        }
        else if (action_words[0] == "use" || action_words[0] == "wear" || action_words[0] == "take off")
        {
            if (action_words.size() > 1)
            {
                if (action_words[1] == "flamingo")
                {
                    useFlamingo(action_words[1]);
                }
                else if (action_words[1] == "hat")
                {
                    if (action_words[0] == "wear")
                    {
                        if (!hatIsOn)
                        {
                            wearHat(action_words[1]);
                        }
                    }
                    else if (action_words[0] == "take off")
                    {
                        if (hatIsOn)
                        {
                            takeOffHat(action_words[1]);
                        }
                    }
                    else if (action_words[0] == "use")
                    {
                        if (hatIsOn)
                        {
                            takeOffHat(action_words[1]);
                        }
                        else
                        {
                            wearHat(action_words[1]);
                        }
                    }
                }
                else if (action_words.size() > 2 && action_words[1] == "gold" && action_words[2] == "key")
                {
                    useKey("gold key");
                }
            }
        }
        else if (action_words[0] == "eat")
        {
            if (findItemByName(action_words[1]).isEdible())
            {
                eatItem(action_words[1]);
            }
            else
            {
                cout << "You can't eat " << action_words[1] << "!" << endl;
            }
        }
        else if (action_words[0] == "talk to")
        {
            talkToCharacter(action_words[1]);
        }
        else if (action_words[0] == "drop")
        {
            dropItem(action_words[1]);
        }

        else if (action_words[0] == "follow")
        {
            followCharacter(action_words[0], action_words[1]);
        }
        else if (!current_location->hasItem(action_words[1]) && action_words.size() == 2)
        {
            cout << "There is no " << action_words[1] << " in " << current_location->getName() << "." << endl;
        }
        else
        {
            cout << "Cannot " << action_words[0] << " in " << current_location->getName() << endl;
        }
    }
};

#endif