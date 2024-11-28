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
    vector<string> actions;

public:
    Item() : name("") {}

    Item(const string &name, const string &description, const vector<string> &actions)
        : name(name), description(description), actions(actions) {}

    // Currently all items can be added to inventory, but for scalability, if there's one that cannot
    void addToInventoryItem()
    {
        item_actions.push_back("take");
        item_actions.push_back("drop");
    }

    void addItemAction(string action) { item_actions.push_back(action); }
    string getName() { return name; }
    vector<string> getItemActions() { return item_actions; } // this function may be unnecessary review code and double check ** REMOVE ME BEFORE SUBMITTING UNLESS NECESSARY
    bool isItemAction(string action) { return find(item_actions.begin(), item_actions.end(), action) != item_actions.end(); }
};

#endif