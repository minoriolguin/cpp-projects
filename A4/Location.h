//: Location.h

/*
Title: Location.h
Description: Location object header file
Date: November 5, 2024
Author: Minori Olguin
Student ID: 3441333
*/

/*
DOCUMENTATION

Program Purpose:
    This class represents a location in the game world. Locations have a name, 
    description, exits, conditions, items, and characters. This class provides 
    methods to manage and retrieve location details, such as available exits, 
    items, and characters. It is a fundamental component for handling player 
    movement and interactions within the game.

Date: November 10, 2024

Compile (assuming Cygwin is running): g++ -std=c++11 -o Game Game.cpp
Execution (assuming Cygwin is running): ./Game.exe

Notes: In Cygwin, main must return type int

Classes: Location

Variables:
    name - string - The name of the location
    description - string - The description of the location
    exits - map<string, string> - Maps directions to destination locations
    conditions - map<string, string> - Maps conditions for exits or events
    items_in_location - vector<string> - List of item names present in the location
    characters_in_location - vector<string> - List of character names present in the location
*/

#ifndef LOCATION_H
#define LOCATION_H

#include <iostream> // Stream declarations
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include "Character.h"
#include "Item.h"
using namespace std;

/*****************************************************************************
 * Location 
*****************************************************************************/
class Location
{
private:
    // Private variables 
    string name, description;
    map<string, string> exits, conditions;
    vector<string> items_in_location, characters_in_location;

public:
    // Default constructor
    Location() : name(""), description("") {}

    // Constructor 
    Location(const string &name, const string &description,
             const map<string, string> &exits = {},
             const map<string, string> &conditions = {})
        : name(name), description(description), exits(exits), conditions(conditions) {}

    // Displays the location description
    void displayDescription() { cout << description << endl; }
    // Getters: single liners that simply return a value
    const string &getName() const { return name; }
    const map<string, string> &getConditions() const { return conditions; }
    const map<string, string> &getExitList() const { return exits; }
    const vector<string> &getCharacters() const { return characters_in_location; }
    const vector<string> &getItems() const { return items_in_location; }

    // Getters that iterate through a vector or map
    vector<string> getValidDirections() 
    {
        vector<string> directions;
        for (auto &exit : exits)
        {
            directions.push_back(exit.first);
        }
        return directions;
    }

    const string &getItem(const string &item_name) const
    {
        for (const string &item : items_in_location)
        {
            if (item == item_name)
            {
                return item;
            }
        }
        throw invalid_argument("Item '" + item_name + "' not found in this location.");
    }

    const string &getExit(const string &direction) const
    {
        if (hasExit(direction))
        {
            return exits.at(direction);
        }
        else
        {
            throw invalid_argument("Invalid direction: " + direction);
        }
    }

    // Functions that check if a string is valid within a map or vector and then return boolean value
    bool hasItem(const string &item_name) const
    {
        return find(items_in_location.begin(), items_in_location.end(), item_name) != items_in_location.end();
    }

    bool hasCharacter(const string &character_name) const
    {
        return find(characters_in_location.begin(), characters_in_location.end(), character_name) != characters_in_location.end();
    }

    bool hasExit(const string &direction) const
    {
        return exits.find(direction) != exits.end();
    }

    // Adds character and item to their vectors
    void addCharacter(const string &character_name)
    {
        characters_in_location.push_back(character_name);
    }

    void addItem(const string &item_name)
    {
        items_in_location.push_back(item_name);
    }

    // removes character or item from their vector
    void removeCharacter(const string &character_name)
    {
        characters_in_location.erase(remove(characters_in_location.begin(), characters_in_location.end(), character_name), characters_in_location.end());
    }

    void removeItem(const string &item_name)
    {
        items_in_location.erase(remove(items_in_location.begin(), items_in_location.end(), item_name), items_in_location.end());
    }
};

#endif