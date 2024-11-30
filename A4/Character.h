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

#include <vector> // Stream declarations
#include "Item.h"
using namespace std;

class Character
{
private:
    // Private variables
    string name;
    string description;
    vector<string> dialogues;
    vector<string> actions;
    Item character_item;
    string special_message = "\"I have a gold key I betcha you'd like to take it.\"";

public:
    Character() : name(""), description("") {}

    Character(const string &name, const string &description,
              const vector<string> &dialogues,
              const vector<string> &actions)
        : name(name), description(description), dialogues(dialogues), actions(actions) {}

    string getName() { return name; }
    string getDescription() { return description; }
    vector<string> getDialogues() { return dialogues; }
    vector<string> getActions() { return actions; }
    Item getCharacterItem() { return character_item; }
    bool isGryphon() { return getName() == "Gryphon"; }

    bool talkToPlayer(int counter)
    {
        if (counter < dialogues.size())
        {
            cout << dialogues[counter] << ", says the " << getName() << "." << endl;
            if (dialogues[counter] == special_message)
            {
                return true;
            }
        }
        else 
        {
            counter = dialogues.size() - 1;
            cout << dialogues[counter] << ", says the " << getName() << "." << endl;
        }
        return false;
    }

    void addItem(Item item)
    {
        character_item = item;
    }

    void removeCharacterItem()
    {
        character_item = Item();
    }

    void setCharacterItem(Item item)
    {
        character_item = item;
    }

    bool hasAction(string action)
    {
        return find(actions.begin(), actions.end(), action) != actions.end();
    }

    bool hasItem(string item_name)
    {
        return character_item.getName() == item_name;
    }

    void addDialogue(string dialogue)
    {
        dialogues.push_back(dialogue);
    }

    void addAction(string action)
    {
        actions.push_back(action);
    }
};

#endif