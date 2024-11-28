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
using namespace std;

class Location
{
private:
    string name;
    string description;
    map<string, string> exits;
    map<string, string> conditions;

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

    bool hasExit(const string &direction)
    {
        return exits.find(direction) != exits.end();
    }
};

#endif