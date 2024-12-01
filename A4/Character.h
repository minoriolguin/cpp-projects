//: Character.h

/*
Title: Character.h
Description: Character object header file
Date: November 5, 2024
Author: Minori Olguin
Student ID: 3441333
*/

/*
DOCUMENTATION

Program Purpose:
    This class represents the non-playable characters (NPCs) in the game 
    world. Characters can interact with the player through dialogues, actions, 
    and items. They play a key role in the game play, such as providing hints or 
    essential items needed to progress.

Date: November 10, 2024

Compile (assuming Cygwin is running): g++ -std=c++11 -o Game Game.cpp
Execution (assuming Cygwin is running): ./Game.exe

Notes: in Cygwin, main must return type int

Classes: Character

Variables:
    name - string - The name of the character
    description - string - A description of the character
    dialogues - vector<string> - List of dialogues the character can say
    actions - vector<string> - List of actions the character can perform
    character_item - Item - An item associated with the character
    special_message - string - A special dialogue message from the character
*/

#ifndef CHARACTER_H
#define CHARACTER_H

#include <vector> // Stream declarations
#include "Item.h"
using namespace std;

/*****************************************************************************
 * Character 
*****************************************************************************/
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
    // Default constructor 
    Character() : name(""), description("") {}

    // Parameterized constructor
    Character(const string &name, const string &description,
              const vector<string> &dialogues,
              const vector<string> &actions)
        : name(name), description(description), dialogues(dialogues), actions(actions) {}

    // Getters for character attributes
    string getName() { return name; }
    string getDescription() { return description; }
    vector<string> getDialogues() { return dialogues; }
    vector<string> getActions() { return actions; }
    Item getCharacterItem() { return character_item; }
    // returns bool for special character is gryphon
    bool isGryphon() { return getName() == "Gryphon"; }

    // talk to player command, returns bool and takes counter as input 
    bool talkToPlayer(int counter)
    {
        // checks the counter if it's a valid dialogue
        if (counter < dialogues.size())
        {
            // outputs the dialogue and checks if it should output a special message
            cout << dialogues[counter] << ", says the " << getName() << "." << endl;
            if (dialogues[counter] == special_message)
            {
                return true;
            }
        }
        else 
        {
            // if dialogue counter is not a valid size, make it a valid size
            counter = dialogues.size() - 1;
            // output the statement
            cout << dialogues[counter] << ", says the " << getName() << "." << endl;
        }
        // return false if special condition wasn't met
        return false;
    }

    // add item to character 
    void addItem(Item item)
    {
        character_item = item;
    }

    // remove the item from the character
    void removeCharacterItem()
    {
        character_item = Item();
    }

    // set an item as belonging to a character
    void setCharacterItem(Item item)
    {
        character_item = item;
    }

    // check if an action is valid for a character
    bool hasAction(string action)
    {
        return find(actions.begin(), actions.end(), action) != actions.end();
    }

    // checks if the character has a certain item
    bool hasItem(string item_name)
    {
        return character_item.getName() == item_name;
    }

    // Add a dialogue to a characters dialogue vector
    void addDialogue(string dialogue)
    {
        dialogues.push_back(dialogue);
    }

    // Add an action to a character action vector
    void addAction(string action)
    {
        actions.push_back(action);
    }
};

#endif