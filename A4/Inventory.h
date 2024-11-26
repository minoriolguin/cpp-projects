#ifndef INVENTORY_H
#define INVENTORY_H

#include <iostream> // Stream declarations
#include <unordered_map>
#include "Item.h"
using namespace std;

class Inventory
{
private:
    unordered_map<string, Item> inventory_items;
    const int MAX_SIZE = 5;

public:
    Inventory() {}

    void addItem(Item item)
    {
        if (inventory_items.size() < MAX_SIZE && item.isItemAction("take"))
        {
            inventory_items[item.getName()] = item;
            cout << item.getName() << " has been added to your inventory." << endl;
        }
        else
        {
            cout << "Unable to pickup " << item.getName() << ", inventory is full. Please drop an item to take a new item." << endl;
        }
    }

    void removeItem(string item_name)
    {
        if(hasItem(item_name) && inventory_items[item_name].isItemAction("drop")) {
        inventory_items.erase(item_name);
        // cout << item_name << " has been removed from your inventory." << endl; // maybe remove and handle in action
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

    Item findItemByName(string item_name)
    {
        auto it = inventory_items.find(item_name);
        return it->second;
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