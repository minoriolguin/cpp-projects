//: Game.cpp

/*
Title: Game.cpp
Description:
    This program simulates an interactive text-based game,
    "Alice's Adventures in Wonderland." Players take on the role of Alice
    and navigate through different locations in Wonderland, interact with
    characters, pick up items, and solve puzzles to achieve the goal of
    escaping Wonderland.
Author: Minori Olguin
Student ID: 3441333
*/

/*
DOCUMENTATION

Program Purpose:
    This is a C++ implementation that demonstrates object-oriented programming
    concepts, file I/O, and command-based gameplay mechanics.
Date: November 10, 2024


Compile (assuming Cygwin is running): g++ -std=c++11 -o Game Game.cpp
Execution (assuming Cygwin is running): ./Game.exe

Notes: in Cygwin, main must return type int

Classes: Game, Control, Action, Location, Character, Item, Inventory

Variables:
    is_running - bool - Tracks whether the game is active
    location_changed - bool - Tracks if the player's location has changed
    win_message - string - Message displayed when the player wins the game
    starting_location - string - The initial location of the player (Riverbank)
    steps_to_complete - int - Number of steps the player took to complete the game
    locations - map<string, Location> - Stores all game locations
    characters - map<string, Character> - Stores all game characters
    items - map<string, Item> - Stores all game items
    control - Control - Handles input parsing and normalization
    action - Action* - Handles player actions (e.g., moving, interacting)
    current_location - Location* - Pointer to the current location of the player
    inventory - Inventory - Manages the player's collected items
*/

/*
TEST PLAN
******** Welcome to Alice's Adventures in Wonderland! ********

Instructions: This game expects input in 1-3 word combinations, you can enter north, or n for north, this also applies to, east, south and west. For northeast, you can enter northeast or ne. Capital and lowercaseletters are read as the same thing. Additional commands include, inventory, take, drop, eat, wear, follow, use and talk to. To end the game at any point type 'exit', 'quit' or 'q'. Enter 'help' or 'h' at any point you find yourself stuck in the game for a list of directions. Once the game begins, you will receive a shortdescription on where you are.

Goal: Your goal is to explore Wonderland as Alice to reach the finish line. First enter Wonderland to meet character and find the golden key.The golden key is hidden somewhere in Wonderland and you need it to get back to above ground and win the game. You can earn achievements as you play the game by interacting with characters in Wonderland.

Press enter to start the game.


******** Welcome to Alice's Adventures in Wonderland! ********

You find yourself on a serene riverbank with gentle flowing water and lush greenery. On the ground beside you, there's a book with no pictures lying open on the ground... All around you, you can hear birds chirping and the rustling of leaves. To your east is a large tree casting a long shadow. To you south you see a large field of white coloured flowers.

Current Step: 1

> read book

You've earned the achievement: Read the picture-less book!

A book, with words and no pictures. You read the first line "Chapter 1. Down the Rabbit-Hole Alice was beginning to get very tired of sitting by her sister on the bank, and of having nothing to do: once or twice she had peeped into the book her sister was reading, but it had no pictures or conversations in it, “and what is the use of a book,” thought Alice “without pictures or conversations?”, weird, you think, my name is Alice too, you put the book down.

Current Step: 2

> s

You are now standing in the middle of a vibrant field filled with white and yellow daisies swaying gently in the breeze. The air is filled with the scent of flowers. You think to yourself, how lovely it would be to make a daisy bouquet.

Current Step: 3

> pick daisies

You have taken the daisies.
You've earned the achievement: Made a lovely bouquet of daisies.


Current Step: 4

> ne

You find yourself standing at the base of a tree that towers over you. You take a closer look at the base of the tree, and you see a small partially hidden rabbit hole. Whoosh! You see a White Rabbit quickly hop by... did the Rabbit just say something? You shout "Wait!", the Rabbit continues on its way down the rabbit hole.

Current Step: 5

> down

You fall down, 
into the rabbit hole, 
...
father 
and 
farther 
down, 
wondering 
when 
the 
fall 
will 
stop
... 
...
...
...
...
...
...
...
...
...
...
...
Plop! You gently land on your bottom, you stand up to see where you are.

You find yourself within a small, strange room with many doors. You see 3 doors, the first door is unlabeled, the second door reads, 'Enter', the third door reads, 'Madness ahead'. Behind you, a side table appears out of the blue. On it, a small bottle labeled, "unknown" sits on the top, to its left lies a cake. Beside door 2 there appears to be a lamp.
Hint: type 'enter door ' followed by the door number to enter a door.

Current Step: 6

> door 1

Door 1 is locked, maybe a key would help...

Current Step: 7

> door 2

Door 2 is locked, who knows what could shed a little light on the problem...

Current Step: 8

> turn on lamp

The lamp  is now ON.

Current Step: 9

> turn off lamp

The lamp  is now OFF.

Current Step: 10

> door 3

You made it through the door... 
You find yourself on a winding dirt path with trees arching overhead. Strange mushrooms grow along the edges of the path. Farther down the path to the southeast, you see a shadow, could that be some sort of building?, you wonder...

Current Step: 11

> h

Help: try going in one of the following directions
- door
- southeast

Current Step: 12

> se

You are standing in front of a large house with two chimneys shaped like ears and a rooftop thatched with fur, outside the front of the house, to your south, there was a table set out under a tree. By your feet you see a hat, why is there a hat on the ground? you wonder to yourself.

Current Step: 13

> take hat

You have taken the hat.

Current Step: 14

> wear hat

That character does not exist. :(

Current Step: 15

> s

You go and sit at long table set for tea, a teacup full of tea lies in front of you with a small tart on a flower shaped plate. How unusual you think, there are 3 people...? Squished together sitting at the other end, sitting on mismatched chairs and drinking from different sized cups. The March Hare looks in your direction, while the Hatter completely ignores your arrival, wait... could that be the Rabbit you saw earlier?

Current Step: 16

> talk to hatter

"What day of the month is it?", says the Hatter.

Current Step: 17

> talk to rabbit

“Oh my ears and whiskers", says the Rabbit.

Current Step: 18

> talk to march hare

"I deny it!", says the March Hare.

Current Step: 19

> take teacup

You have taken the teacup.

Current Step: 20

> i

Inventory:
- daisies
- hat
- teacup

Current Step: 21

> take tart

You have taken the tart.
You've earned the achievement: Ate x2!

Current Step: 22

> talk to hatter

 "I dare say you never even spoke to Time!", says the Hatter.

Current Step: 23

> talk to march hare

"Take some more tea.", says the March Hare.

Current Step: 24

> talk to rabbit

“Oh my ears and whiskers", says the Rabbit.

Current Step: 25

> talk to rabbit

"How late it’s getting!”, says the Rabbit.

Current Step: 26

> ne

You can't go that way.

Current Step: 27

> h

Help: try going in one of the following directions
- north

Current Step: 28

> n

You are standing in front of a large house with two chimneys shaped like ears and a rooftop thatched with fur, outside the front of the house, to your south, there was a table set out under a tree. By your feet you see a hat, why is there a hat on the ground? you wonder to yourself.

Current Step: 29

> h

Help: try going in one of the following directions
- northeast
- south

Current Step: 30

> ne

You find yourself on a winding dirt path with trees arching overhead. Strange mushrooms grow along the edges of the path. Farther down the path to the southeast, you see a shadow, could that be some sort of building?, you wonder...

Current Step: 31

> door

You made it through the door... 
You find yourself within a small, strange room with many doors. You see 3 doors, the first door is unlabeled, the second door reads, 'Enter', the third door reads, 'Madness ahead'. Behind you, a side table appears out of the blue. On it, a small bottle labeled, "unknown" sits on the top, to its left lies a cake. Beside door 2 there appears to be a lamp.
Hint: type 'enter door ' followed by the door number to enter a door.

Current Step: 32

> door 2

Door 2 is locked, who knows what could shed a little light on the problem...

Current Step: 33

> turn on lamp

The lamp  is now ON.

Current Step: 34

> door 3

You made it through the door... 
You find yourself on a winding dirt path with trees arching overhead. Strange mushrooms grow along the edges of the path. Farther down the path to the southeast, you see a shadow, could that be some sort of building?, you wonder...

Current Step: 35

> doo

I don't understand that command.

Current Step: 36

> door

You made it through the door... 
You find yourself within a small, strange room with many doors. You see 3 doors, the first door is unlabeled, the second door reads, 'Enter', the third door reads, 'Madness ahead'. Behind you, a side table appears out of the blue. On it, a small bottle labeled, "unknown" sits on the top, to its left lies a cake. Beside door 2 there appears to be a lamp.
Hint: type 'enter door ' followed by the door number to enter a door.

Current Step: 37

> door 2

You made it through the door... 
You find yourself standing at the start of a long narrow path shrouded in shadows, surrounded by tall grass that sways as though alive. The wind howls faintly in the distance. To your south a green lawn, with manicured hedges surrounding. Are those red polka dots? Through the door lies the room full of doors you came through earlier.

Current Step: 38

> s    

You slowly step onto a manicured lawn with hedges shaped like playing cards. Flamingos and hedgehogs are scattered about, seemingly preparing for a game of croquet. You see a Queen of some sort, dressed in Red and White with hearts decorating her loud dress. To your north lies the dark grassy passage, to your west a maze with a small room tucked between the bushes.

Current Step: 39

> take flamingo

You have taken the flamingo.

Current Step: 40

> use flamingo

You've earned the achievement: Played croquet with the Red Queen!

You use the flamingo to play croquet, using the hedgehogs as croquet balls.

Current Step: 41

> w

You crouch down to crawl through an opening in the bushes and you find yourself in a small, dimly lit room. It smells of dust and mystery. A you see a strange bird sitting in the corner. Is that a bird? you think to yourself, hmmm, it might not be upon second look, that must be the Gryphon.

Current Step: 42

> talk to gryphon

"I have a gold key I betcha you'd like to take it.", says the Gryphon.
The Gryphon is offering you the Golden Key, would you like to accept?
y
Your inventory is full, please drop an item to take the gold key.
You've earned the achievement: Found the gold key!

Current Step: 43

> i

Inventory:
- daisies
- flamingo
- hat
- tart
- teacup

Current Step: 44

> drop hat

The hat has been removed from your inventory.

Current Step: 45

> gryphon

I don't understand that command.

Current Step: 46

> talk to gryphon

"You ought to be ashamed of yourself for asking such a simple question", says the Gryphon.

Current Step: 47

> talk to gryphon

"Hold your tongue! You can follow me if you'd like.", says the Gryphon.

Current Step: 48

> talk to gryphon

"No no! The adventures first explanations take such a dreadful time.", says the Gryphon.

Current Step: 49

> talk to gryphon

"I have a gold key I betcha you'd like to take it.", says the Gryphon.
The Gryphon is offering you the Golden Key, would you like to accept?
y
You have taken the gold key.

Current Step: 50

> follow gryphon

You started following Gryphon... This seems to be a short-cut... 
You find yourself in a small room, there doesn’t seem to be much in here. After looking around you find a small tunnel leading upwards. The faint light of the surface glimmers at the end of the passage.

Current Step: 51

> up

You rub your eyes, was it really that dark down there. You crawl up through the small tunnel and breathe the fresh air, feel the warm sunlight and jump for joy! You find yourself back on the riverbank. That wasn't just a dream, was it?

Steps to Complete Game: 51
Congratulations on successfully completing Alice's Adventures in Wonderland!

5 achievements earned:
- Ate x2!
- Found the gold key!
- Made a lovely bouquet of daisies.
- Played croquet with the Red Queen!
- Read the picture-less book!

The end!

Discussion: Program limitations discussed at length in assignment journal.
*/

#include <iostream> // stream declarations
#include <sstream>
#include <fstream>
#include <map>
#include <vector>
#include <algorithm>
#include "Control.h"
#include "Location.h"
#include "Character.h"
#include "Item.h"
#include "Action.h"
#include "Inventory.h"
using namespace std;

/*****************************************************************************
 * Location 
*****************************************************************************/
class Game
{
private:
    // private variables 
    bool is_running;
    bool location_changed;
    string win_message = "Congratulations on successfully completing Alice's Adventures in Wonderland!";
    string starting_location = "Riverbank";
    int steps_to_complete;
    map<string, Location> locations;
    map<string, Character> characters;
    map<string, Item> items;
    Control control;
    Action *action;
    Location *current_location;
    Inventory inventory;

    // files to load characters, items, actions and locations
    string characters_file = "characters.txt";
    string items_file = "items.txt";
    string actions_file = "actions.txt";
    string locations_file = "locations.txt";

public:
    Game() : is_running(false), control(), steps_to_complete(0) {}
    ~Game() {}

    bool getIsRunning() { return is_running; }
    void setIsRunning(bool running) { is_running = running; }

    void initializeWorld()
    {
        initializeCharacters();
        initializeItems();
        initializeActions();
        initializeLocations();

        action = new Action(&locations, starting_location, &characters, &items, inventory);
    }

    void initializeCharacters()
    {
        ifstream file(characters_file);
        if (!file.is_open())
        {
            cerr << "Error: Could not open " << characters_file << endl;
            return;
        }

        string line;
        while (getline(file, line))
        {
            if (line.empty() || line[0] == '#')
            {
                continue;
            }

            stringstream ss(line);
            string name, description, dialogues, actions, item;
            getline(ss, name, '|');
            getline(ss, description, '|');
            getline(ss, dialogues, '|');
            getline(ss, actions, '|');
            getline(ss, item, '|');

            vector<string> dialogueList;
            vector<string> actionList;

            stringstream dialogueStream(dialogues);
            stringstream actionStream(actions);
            string token;

            while (getline(dialogueStream, token, ','))
                dialogueList.push_back(token);

            while (getline(actionStream, token, ','))
                actionList.push_back(token);

            Character character(name, description, dialogueList, actionList);
            characters[name] = character;
            if (!item.empty())
            {
                character.addItem(items[item]);
            }
        }
        file.close();
    }

    void initializeItems()
    {
        ifstream file(items_file);
        if (!file.is_open())
        {
            cerr << "Error: Could not open " << items_file << endl;
            return;
        }

        string line;
        while (getline(file, line))
        {
            if (line.empty() || line[0] == '#')
            {
                continue;
            }

            stringstream ss(line);
            string name, description, actions, achievement;
            getline(ss, name, '|');
            getline(ss, description, '|');
            getline(ss, actions, '|');
            getline(ss, achievement, '|');

            vector<string> actionList;
            stringstream actionStream(actions);
            string token;

            while (getline(actionStream, token, ','))
                actionList.push_back(token);

            Item item(name, description, achievement, actionList);
            items[name] = item;
        }
        file.close();
    }

    void initializeActions()
    {
        ifstream file(actions_file);
        if (!file.is_open())
        {
            cerr << "Error: Could not open " << actions_file << endl;
            return;
        }

        vector<string> parsed_actions;
        string line;
        while (getline(file, line))
        {
            if (line.empty() || line[0] == '#')
            {
                continue;
            }

            stringstream ss(line);
            string action_name, description, targets;
            getline(ss, action_name, '|');
            getline(ss, description, '|');
            getline(ss, targets, '|');

            parsed_actions.push_back(action_name);
            vector<string> targetList;
            stringstream targetStream(targets);
            string token;

            while (getline(targetStream, token, ','))
                targetList.push_back(token);
        }
        file.close();
        control.setActionCommands(parsed_actions);
    }

    void initializeLocations()
    {
        ifstream file(locations_file);
        if (!file.is_open())
        {
            cerr << "Error: Could not open " << locations_file << endl;
            return;
        }

        string line;
        while (getline(file, line))
        {
            if (line.empty() || line[0] == '#')
            {
                continue;
            }

            stringstream ss(line);
            string name, description, exits, conditions, characters_str, items_str;

            getline(ss, name, '|');
            getline(ss, description, '|');
            getline(ss, exits, '|');
            getline(ss, conditions, '|');
            getline(ss, characters_str, '|');
            getline(ss, items_str, '|');

            size_t pos;
            while ((pos = description.find("\\n")) != string::npos)
            {
                description.replace(pos, 2, "\n");
            }

            map<string, string> exitMap;
            vector<string> directions;
            stringstream exitStream(exits);
            string exitToken;
            while (getline(exitStream, exitToken, ','))
            {
                size_t delim = exitToken.find('=');
                if (delim != string::npos)
                {
                    string direction = exitToken.substr(0, delim);
                    string destination = exitToken.substr(delim + 1);
                    exitMap[direction] = destination;
                    directions.push_back(direction);
                }
            }

            map<string, string> conditionMap;
            if (!conditions.empty())
            {
                stringstream conditionStream(conditions);
                string conditionToken;
                while (getline(conditionStream, conditionToken, ','))
                {
                    size_t delim = conditionToken.find('=');
                    if (delim != string::npos)
                    {
                        string key = conditionToken.substr(0, delim);
                        string value = conditionToken.substr(delim + 1);
                        conditionMap[key] = value;
                    }
                }
            }

            vector<string> character_list;
            stringstream charStream(characters_str);
            string char_name;
            while (getline(charStream, char_name, ','))
            {
                if (!char_name.empty())
                    character_list.push_back(char_name);
            }

            vector<string> item_list;
            stringstream itemStream(items_str);
            string item_name;
            while (getline(itemStream, item_name, ','))
            {
                if (!item_name.empty())
                    item_list.push_back(item_name);
            }

            Location location(name, description, exitMap, conditionMap);

            for (const string &item_name : item_list)
            {
                location.addItem(item_name);
            }
            for (const string &character_name : character_list)
            {
                location.addCharacter(character_name);
            }
            locations[name] = location;
        }
        file.close();
    }

    void displayInstructions()
    {
        string enter;
        cout
            << "******** Welcome to Alice's Adventures in Wonderland! ********\n"
            << "\nInstructions: This game expects input in 1-3 word combinations, you can enter "
            << "north, or n for north, this also applies to, east, south and west. "
            << "For northeast, you can enter northeast or ne. Capital and lowercase"
            << "letters are read as the same thing. Additional commands include, inventory, "
            << "take, drop, eat, wear, follow, use and talk to. To end the game at any point "
            << "type 'exit', 'quit' or 'q'. Enter 'help' or 'h' at any point you find yourself "
            << "stuck in the game for a list of directions. Once the game begins, you will receive a short"
            << "description on where you are.\n\nGoal: Your goal is to explore Wonderland as Alice to reach the finish line. "
            << "First enter Wonderland to meet character and find the golden key."
            << "The golden key is hidden somewhere in Wonderland and you need it to get back to above "
            << "ground and win the game. You can earn achievements as you play the "
            << "game by interacting with characters in Wonderland.\n\nPress enter to start the game.\n";
        getline(cin, enter);
        cout << "\n******** Welcome to Alice's Adventures in Wonderland! ********\n"
             << endl;
    }

    void play()
    {
        // Game set-up
        initializeWorld();
        setIsRunning(true);
        displayInstructions();

        action->getCurrentLocation()->displayDescription();

        // Game loop for state: playing
        do
        {
            steps_to_complete++;
            cout << "\nCurrent Step: " << steps_to_complete << "\n"
                 << endl;

            string input;
            cout << "> ";
            getline(cin, input);

            vector<string> action_words = control.validateAndParseInput(input);
            cout << endl;
            if (action_words.empty())
            {
                continue;
            }
            if (action_words[0] == "invalid")
            {
                cout << "I don't understand that command." << endl;
                continue;
            }

            if (action_words[0] == "exit" || action_words[0] == "quit")
            {
                endGame(action_words[0]);
                continue;
            }

            if (control.isMovementCommand(action_words[0]))
            {
                action->movePlayer(action_words[0]);
            }
            else if (action_words[0] == "enter")
            {
                action->handleEnterDoorCommand(action_words);
            }
            else
            {
                action->doAction(action_words);
            }
            if (action->getWin())
            {
                cout << "Steps to Complete Game: " << steps_to_complete << endl;
                cout << win_message << "\n"
                     << endl;
                endGame("quit");
            }
        } while (getIsRunning());
    }

    // Handles if the player ends the game or if the player wins the game
    void endGame(string quit_word)
    {
        // if the quit word is exit or q, then double check that the user wants to exit the game rather than an area within the game
        // easy to accidentally press q when going for w and also maybe confusing to have exit when there's exits in the game
        if (getIsRunning() && quit_word == "exit")
        {
            cout << "You are about to quit the game. Enter 'yes', 'q', 'y' or 'quit' to "
                 << "confirm or anything else to continue playing.\n> ";
            string input;
            getline(cin, input);

            if (control.confirmQuitGame(input))
            {
                setIsRunning(false);
                action->displayAchievements();
                cout << "The end!" << endl;
            }
            else
            {
                cout << "... resuming game play ..." << endl;
            }
        }
        else
        {
            setIsRunning(false);
            action->displayAchievements();
            cout << "The end!" << endl;
        }
    }
};

/*****************************************************************************
 * Main 
*****************************************************************************/
int main()
{
    Game wonderland;
    wonderland.play();
    return 0;
};