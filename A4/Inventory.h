//: Inventory.h

/*
Title: Inventory.h
Description: Item object header file
Date: November 5, 2024
Author: Minori Olguin
Student ID: 3441333
*/

/*
DOCUMENTATION

Program Purpose:
    This class manages the player's inventory within the game. It provides
    functionalities to add, remove, check, and display items in the inventory.
    It also enforces a maximum capacity for the inventory and ensures that
    only valid actions (e.g., "take", "drop", "eat") can be performed on items.

Date: November 10, 2024

Compile (assuming Cygwin is running): g++ -std=c++11 -o Game Game.cpp
Execution (assuming Cygwin is running): ./Game.exe

Notes: In Cygwin, main must return type int

Classes: Inventory

Variables:
    inventory_items - map<string, Item> - Stores the items currently in the inventory
    MAX_SIZE        - const int         - The maximum capacity of the inventory (5 items)
*/

#ifndef INVENTORY_H
#define INVENTORY_H

#include <iostream> // Stream declarations
#include <map>
#include <vector>
#include <algorithm>
#include "Item.h"
using namespace std;

/*****************************************************************************
 * Inventory
 *****************************************************************************/
class Inventory
{
private:
    // private variables
    map<string, Item> inventory_items;
    const int MAX_SIZE = 5;

public:
    // default constructor
    Inventory() {}

    // returns if the inventory is full
    bool isFull()
    {
        if (inventory_items.size() < MAX_SIZE)
        {
            return false;
        }
        else
        {
            return true;
        }
    }

    // add item to inventory
    bool addItem(Item item)
    {
        bool added_to_inventory = false;
        if (!isFull() && item.isItemAction("take"))
        {
            inventory_items[item.getName()] = item;
            added_to_inventory = true;
        }
        else if (isFull() && item.isItemAction("take"))
        {
            cout << "Your inventory is full, please drop an item to take the " << item.getName() << "." << endl;
        }
        else
        {
            cout << "The " << item.getName() << " is not a takeable item." << endl;
        }
        return added_to_inventory;
    }

    // removes item from inventory
    void removeItem(string item_name, string current_action)
    {
        if (current_action == "drop")
        {
            if (hasItem(item_name) && inventory_items[item_name].isItemAction("drop"))
            {
                inventory_items.erase(item_name);
                cout << "The " << item_name << " has been removed from your inventory." << endl;
            }
        }
        else if (current_action == "eat")
        {
            if (hasItem(item_name) && inventory_items[item_name].isItemAction("eat"))
            {
                inventory_items.erase(item_name);
                cout << "You ate the " << item_name << "." << endl;
            }
        }
        else
        {
            cout << item_name << " is not in your inventory and cannot be removed." << endl;
        }
    }

    // checks if inventory has item
    bool hasItem(string item_name)
    {
        return inventory_items.find(item_name) != inventory_items.end();
    }

    // shows inventory contents
    void displayInventory() const
    {
        if (inventory_items.empty())
        {
            cout << "Your inventory is empty." << endl;
        }
        else
        {
            cout << "Inventory:" << endl;
            for (auto pair : inventory_items)
            {
                string name = pair.first;
                cout << "- " << name << endl;
            }
        }
    }
};

#endif