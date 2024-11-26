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

public:
    Item() : name("") {}
    
    Item(string name) 
    { 
        this->name = name;  // remove this from constructor to add items that cannot be added to inventory to the game
    }

    // Currently all items can be added to inventory, but for scalability, if there's one that cannot
    void addToInventoryItem() 
    { 
        item_actions.push_back("take"); 
        item_actions.push_back("drop"); 
    }

    void addItemAction(string action) { item_actions.push_back(action); }
    string getName() { return name; }
    vector<string> getItemActions() { return item_actions; } // this function may be unnecessary review code and double check ** REMOVE ME BEFORE SUBMITTING UNLESS NECESSARY
    bool isItemAction(string action) { return find(item_actions.begin(), item_actions.end(), action)!= item_actions.end(); }
};

#endif