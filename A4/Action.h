//: Action.h

/*
Title: Action.h
Description: Action object header file
Date: November 5, 2024
Author: Minori Olguin
Student ID: 3441333
*/

#ifndef ACTION_H
#define ACTION_H

#include <iostream> // Stream declarations
#include <string>
#include <map>
#include "Inventory.h"
#include "Location.h"
#include "Character.h"
#include "Item.h"
using namespace std;

class Action
{
private:
    Inventory playerInventory;
    Location *current_location;
    map<string, Location> *all_locations;
    map<string, Character> *all_characters;
    map<string, Item> *all_items;
    vector<string> valid_directions;
    vector<string> valid_yes = {"Yes", "YES", "y", "Y", "Yes ", "YES ", "y ", "Y ", "yes", "yes "};
    int counter = 0;
    bool win = false;
    bool lampIsOn, hatIsOn, location_changed;
    bool door_1_locked = true;
    bool door_2_locked = true;
    bool received_special_message = false;
    map<string, string> door_map = {
        {"door 1", "door_1"},
        {"door 2", "door_2"},
        {"door 3", "door_3"},
        {"door", "door"}};

public:
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

    Location *getCurrentLocation() const { return current_location; }
    bool getLocationChanged() const { return location_changed; }
    bool getLampOn() const { return lampIsOn; }
    bool getWin() const { return win; }
    void playerWins() const { win = true; }

    void setDoor1Lock(bool is_locked)
    {
        door_1_locked = is_locked;
    }

    void setDoor2Lock(bool is_locked)
    {
        door_2_locked = is_locked;
    }

    void setLocationChanged(bool location_changed)
    {
        this->location_changed = location_changed;
    }

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

    void displayHelp() const
    {
        cout << "Help: try going in one of the following directions\n";
        for (auto &exit : current_location->getExitList())
        {
            cout << "- " << exit.first << endl;
        }
    }

    void movePlayer(const string &direction)
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

    bool isDoorLocked(const string &door)
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

    void handleEnterDoorCommand(const vector<string> &command_words)
    {
        string target_door;

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
        if (current_location == &all_locations->find("Return to Above Ground")->second)
        {
            target_door = "door_1";
        }
        else
        {
            target_door = "door";
        }

        if (door_map.find(target_door) != door_map.end())
        {
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

    bool isItem(const string &item_name)
    {
        auto it = all_items->find(item_name);
        return (it != all_items->end());
    }

    Item findItemByName(const string &item_name)
    {
        auto it = all_items->find(item_name);
        if (it != all_items->end())
        {
            return it->second; // Return the item if found
        }
        else
        {
            throw runtime_error("Item not found: " + item_name); // Handle the error
        }
    }

    void takeItem(const Item &item)
    {
        if (current_location->hasItem(item.getName()))
        {
            bool item_taken = playerInventory.addItem(item);
            if (item_taken)
            {
                current_location->removeItem(item.getName());
                cout << "You have taken the " << item.getName() << ".\n";
            }
        }
        else if (playerInventory.hasItem(item.getName()))
        {
            cout << "There is no more " << item.getName() << "s here.\n";
        }
        else
        {
            cout << "There is no " << item.getName() << " here.\n";
        }
    }

    void dropItem(const string &item_name)
    {
        if (playerInventory.hasItem(item_name))
        {
            playerInventory.removeItem(item_name, "drop");
            current_location->addItem(item_name);
        }
        else
        {
            cout << "Unable to find " << item_name << " in your inventory." << endl;
        }
    }

    void eatItem(string item_name)
    {
        playerInventory.removeItem(item_name, "eat");
    }

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

    void useFlamingo(const string &item_name)
    {
        if (playerInventory.hasItem(item_name) || current_location->hasItem(item_name))
        {
            if (current_location->hasItem("hedgehog"))
            {
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

    void wearHat(const string &item_name)
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
                cout << "You put on the hat." << endl;
            }
        }
        else
        {
            cout << "You are not wearing a hat, silly." << endl;
        }
    }

    void takeOffHat(const string &item_name)
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

    void toggleLight()
    {
        lampIsOn = !lampIsOn;
        setDoor2Lock(!lampIsOn);
    }

    Character findCharacterByName(string character_name)
    {
        auto it = all_characters->find(character_name);
        if (it != all_characters->end())
        {
            return it->second; // Return the item if found
        }
        else
        {
            throw runtime_error("Item not found: " + character_name); // Handle the error
        }
    }

    bool isCharacter(string character_name)
    {
        return all_characters->find(character_name) != all_characters->end();
    }

    bool isYes(string input)
    {
        return find(valid_yes.begin(), valid_yes.end(), input) != valid_yes.end();
    }

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

    void doAction(vector<string> action_words)
    {
        if ((current_location->hasItem(action_words[1])) && action_words.size() > 1)
        {
            Item item = findItemByName(action_words[1]);
            if ((action_words[0] == "read" || action_words[0] == "inspect"))
            {
                cout << item.getDescription() << endl;
            }
            else if (action_words[0] == "take" || action_words[0] == "pick")
            {
                takeItem(item);
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
        else if (action_words[0] == "use" || action_words[0] == "wear" || (action_words[0] == "take off"))
        {
            if (action_words[1] == "flamingo")
            {
                useFlamingo(action_words[1]);
            }
            else if (action_words[1] == "hat")
            {
                if (hatIsOn)
                {
                    takeOffHat(action_words[1]);
                }
                else if (!hatIsOn)
                {
                    wearHat(action_words[1]);
                }
            }
            else if (action_words[1] == "gold" && action_words[2] == "key")
            {
                useKey("gold key");
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