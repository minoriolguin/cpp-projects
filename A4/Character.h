//: Character.h

/*
Title: Character.h
Description: Character object header file
Date: November 5, 2024
Author: Minori Olguin
Student ID: 3441333
*/

#ifndef CHARACTER_H
#define CHARACTER_H

#include <vector>
#include "Item.h"
using namespace std; // Stream declarations

class Character
{
private:
    string name;
    string description;
    vector<string> dialogues; // Lines the character can say
    vector<string> actions;
    Item character_item;

public:
    Character() : name(""), description("") {}

    Character(const string &name, const string &description,
              const vector<string> &dialogues,
              const vector<string> &actions)
        : name(name), description(description), dialogues(dialogues), actions(actions) {}

    string getName() const { return name; }
    string getDescription() const { return description; }
    const vector<string> &getDialogues() const { return dialogues; }
    const vector<string> &getActions() const { return actions; }
    const Item &getCharacterItem() const { return character_item; }

    // Add an item to the character's inventory
    void addItem(const Item item)
    {
        character_item = item;
    }

    void removeCharacterItem()
    {
        character_item = Item(); // Resets to default constructed item
    }

    void setCharacterItem(const Item &item)
    {
        character_item = item;
    }

    // Check if the character has a specific item by name
    bool hasItem(const string &item_name) const
    {
        return character_item.getName() == item_name;
    }

    // Add a dialogue
    void addDialogue(const string &dialogue)
    {
        dialogues.push_back(dialogue);
    }

    // Add an action
    void addAction(const string &action)
    {
        actions.push_back(action);
    }
};

#endif