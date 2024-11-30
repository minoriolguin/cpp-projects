#ifndef INVENTORY_H
#define INVENTORY_H

#include <iostream> // Stream declarations
#include <map>
#include <vector>
#include <algorithm>
#include "Item.h"
using namespace std;

class Inventory
{
private:
    map<string, Item> inventory_items;
    const int MAX_SIZE = 5;

public:
    Inventory() {}

    bool addItem(Item item)
    {
        bool added_to_inventory = false;
        if (inventory_items.size() < MAX_SIZE && item.isItemAction("take"))
        {
            inventory_items[item.getName()] = item;
            added_to_inventory = true;
        }
        else if (inventory_items.size() >= MAX_SIZE )
        {
            cout << "Your inventory is full, please drop an item to take the " << item.getName() << "."<< endl;
        }
        else 
        {
            cout << "The " << item.getName() << " is not a takeable item." << endl;
        }
        return added_to_inventory;
    }

    void removeItem(string item_name)
    {
        if (hasItem(item_name) && inventory_items[item_name].isItemAction("drop"))
        {
            inventory_items.erase(item_name);
            cout << item_name << " has been removed from your inventory." << endl; // maybe remove and handle in action
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