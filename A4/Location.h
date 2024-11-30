//: Location.h

/*
Title: Location.h
Description: Location object header file
Date: November 5, 2024
Author: Minori Olguin
Student ID: 3441333
*/

#ifndef LOCATION_H
#define LOCATION_H

#include <iostream> // Stream declarations
#include <map>
#include <string>
#include <vector>
#include "Character.h"
#include "Item.h"
using namespace std;

class Location
{
private:
    string name;
    string description;
    map<string, string> exits;
    map<string, string> conditions;
    vector<string> items_in_location;
    vector<string> characters_in_location;

public:
    Location() : name(""), description("") {}

    Location(const string &name, const string &description,
             const map<string, string> &exits = {},
             const map<string, string> &conditions = {})
        : name(name), description(description), exits(exits), conditions(conditions) {}

    void displayDescription() const
    {
        cout << description << endl;
    }

    vector<string> getValidDirections() const
    {
        vector<string> directions;
        for (const auto &exit : exits)
        {
            directions.push_back(exit.first);
        }
        return directions;
    }

    string getName()
    {
        return name;
    }

    map<string, string> getConditions() { return conditions; }
    map<string, string> getExitList() { return exits; }
    const vector<string> getCharacters() { return characters_in_location; }
    const vector<string> getItems() { return items_in_location; }

    string getItem(const string &item_name)
    {
        for (string item : items_in_location)
        {
            if (item == item_name)
            {
                return item_name;
            }
        }
        throw invalid_argument("Item '" + item_name + "' not found in this location.");
    }

    string getExit(const string &direction)
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

    bool hasItem(const string &item_name) const
    {
        return find(items_in_location.begin(), items_in_location.end(), item_name) != items_in_location.end();
    }

    bool hasCharacter(const string &character_name) const
    {
        return find(characters_in_location.begin(), characters_in_location.end(), character_name) != characters_in_location.end();
    }

    bool hasExit(const string &direction)
    {
        return exits.find(direction) != exits.end();
    }

    void addCharacter(const string &character_name)
    {
        characters_in_location.push_back(character_name);
    }

    void removeCharacter(const string &character_name)
    {
        characters_in_location.erase(remove(characters_in_location.begin(), characters_in_location.end(), character_name), characters_in_location.end());
    }

    void addItem(const string &item_name)
    {
        items_in_location.push_back(item_name);
    }

    void removeItem(const string &item_name)
    {
        items_in_location.erase(remove(items_in_location.begin(), items_in_location.end(), item_name), items_in_location.end());
    }
};

#endif