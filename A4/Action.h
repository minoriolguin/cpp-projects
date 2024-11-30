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
    bool lampIsOn;
    Inventory playerInventory;
    Location *current_location;
    map<string, Location> *all_locations;
    map<string, Character> *all_characters;
    map<string, Item> *all_items;
    vector<string> valid_directions;
    bool location_changed;
    bool door_1_unlocked;
    bool door_2_unlocked;
    bool door_3_unlocked;
    map<string, string> door_map = {
        {"door 1", "door_1"},
        {"door 2", "door_2"},
        {"door 3", "door_3"},
        {"door", "door"}};

public:
    Action(map<string, Location> *locations, const string &start_location_name, map<string, Character> *characters, map<string, Item> *items, Inventory &inventory)
        : lampIsOn(false), all_locations(locations), all_characters(characters), all_items(items), playerInventory(inventory)
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

    Location *getCurrentLocation() { return current_location; }
    bool getLocationChanged() { return location_changed; }

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
        else
        {
            target_door = "door";
        }

        if (door_map.find(target_door) != door_map.end())
        {
            string exit_key = door_map.at(target_door);

            if (current_location->hasExit(exit_key))
            {
                string next_location_name = current_location->getExit(exit_key);

                if (all_locations->find(next_location_name) != all_locations->end())
                {
                    current_location = &(*all_locations)[next_location_name];
                    current_location->displayDescription();
                }
                else
                {
                    cout << "The destination '" << next_location_name << "' does not exist.\n";
                }
            }
            else
            {
                cout << "There is no exit for '" << target_door << "' in this location.\n";
            }
        }
        else
        {
            cout << "The door '" << target_door << "' does not exist.\n";
        }
    }

    bool isItem(string item_name)
    {
        auto it = all_items->find(item_name);
        return (it != all_items->end());
    }

    Item findItemByName(string item_name)
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

    void takeItem(Item item)
    {
        if (current_location->hasItem(item.getName()))
        {
            current_location->removeItem(item.getName());
            bool item_taken = playerInventory.addItem(item);
            if (item_taken)
            {
                cout << "You have taken the " << item.getName() << ".\n";
            }
        }
        else
        {
            cout << "There is no " << item.getName() << " here.\n";
        }
    }

    void dropItem(string item_name)
    {
        if (playerInventory.hasItem(item_name))
        {
            playerInventory.removeItem(item_name);
            current_location->addItem(item_name);
        }
        else
        {
            cout << "Unable to find " << item_name << " in your inventory." << endl;
        }
    }

    void toggleLight()
    {
        lampIsOn = !lampIsOn;
    }

    void doAction(vector<string> action_words)
    {
        if (current_location->hasItem(action_words[1]) && action_words.size() > 1)
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
        }
        else if (action_words[0] == "drop")
        {
            dropItem(action_words[1]);
        }
        else if (action_words[0] == "inventory" || action_words[0] == "i")
        {
            playerInventory.displayInventory();
        }
        else if (action_words[0] == "toggle")
        {
            toggleLight();
            cout << "The lamp " << (lampIsOn ? " is now ON." : " is now OFF.") << endl;
        }
        else if (action_words.size() == 1)
        {
            cout << "You need to enter an item after " << action_words[0] << " to " << action_words[0] << " it." << endl;
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