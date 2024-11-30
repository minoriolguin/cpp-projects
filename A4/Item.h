//: Item.h

/*
Title: Item.h
Description: Item object header file
Date: November 5, 2024
Author: Minori Olguin
Student ID: 3441333
*/

#ifndef ITEM_H
#define ITEM_H

#include <iostream> // Stream declarations
#include <vector>
using namespace std;

class Item
{
private:
    string name;
    vector<string> item_actions;
    string description;

public:
    Item() : name("") {}

    Item(const string &name, const string &description, const vector<string> &actions)
        : name(name), description(description), item_actions(actions) {}

    string getName() const { return name; }
    string getDescription() const { return description; }
    vector<string> getActions() { return item_actions; }
    bool isItemAction(string action) { return find(item_actions.begin(), item_actions.end(), action) != item_actions.end(); }
};
#endif