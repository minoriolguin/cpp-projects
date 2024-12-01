//: Inventory.h

/*
Title: Inventory.h
Description: Item object header file
Date: November 5, 2024
Author: Minori Olguin
Student ID: 3441333
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
    map<string, Item> inventory_items;
    const int MAX_SIZE = 5;

public:
    Inventory() {}

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
        else if (current_action == "eat") {
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

    bool hasItem(string item_name)
    {
        return inventory_items.find(item_name) != inventory_items.end();
    }

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