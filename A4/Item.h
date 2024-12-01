//: Item.h

/*
Title: Item.h
Description: Item object header file
Date: November 5, 2024
Author: Minori Olguin
Student ID: 3441333
*/

/*
DOCUMENTATION

Program Purpose:
    This class represents an item in the game. Items have a name, description,
    and a set of valid actions, and achievements that the player can perform 
    and earn on/with them. This class provides methods to retrieve item details 
    and check if specific actions (e.g., "eat", "wear", "take") are allowed for the item.

Date: November 10, 2024

Compile (assuming Cygwin is running): g++ -std=c++11 -o Game Game.cpp
Execution (assuming Cygwin is running): ./Game.exe

Notes: In Cygwin, main must return type int

Classes: Item

Variables:
    name - string - The name of the item
    description - string - The description of the item
    item_actions - vector<string> - List of valid actions that can be performed on the item
    achievement - string - Achievement message
*/

#ifndef ITEM_H
#define ITEM_H

#include <iostream> // Stream declarations
#include <vector>
using namespace std;

/*****************************************************************************
 * Item 
*****************************************************************************/
class Item
{
private:
    // private variables
    string name, description, achievement;
    vector<string> item_actions;

public:
    // default constructor
    Item() : name("") {}

    // Parameterized constructor
    Item(const string &name, const string &description, const string &achievement, const vector<string> &actions)
        : name(name), description(description), achievement(achievement), item_actions(actions) {}

    // getters 
    string getName() const { return name; }
    string getDescription() const { return description; }
    string getAchievement() const { return achievement; }
    vector<string> getActions() { return item_actions; }

    // checkers, checks if item has certain action, if its edible or wearable
    bool isItemAction(string action) { return find(item_actions.begin(), item_actions.end(), action) != item_actions.end(); }
    bool isEdible() const { return find(item_actions.begin(), item_actions.end(), "eat") != item_actions.end(); }
    bool isWearable() const { return find(item_actions.begin(), item_actions.end(), "wear") != item_actions.end(); }
};
#endif