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
using namespace std;

class Action
{
private:
    Inventory *playerInventory; // inventory pointer
    Location *current_location;
    map<string, Location> *all_locations;
    vector<string> valid_directions;
    bool location_changed;

public:
    Action(map<string, Location> *locations, const string &start_location_name)
        : all_locations(locations)
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

    void doAction(vector<string> action_words)
    {
    }
    // void takeItem(string item_name, Location current_location)
    // {
    //     if (current_location.hasItem(item_name))
    //     {
    //         Item item = current_location.getItem(item_name);
    //         current_location.removeItem(item_name);
    //         playerInventory->addItem(item);
    //         cout << "You have taken the " << item_name << ".\n";
    //     }
    //     else
    //     {
    //         cout << "There is no " << item_name << " here.\n";
    //     }
    // }

    // void dropItem(string item_name) {}
};

#endif