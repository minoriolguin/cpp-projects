#ifndef LOCATION_H
#define LOCATION_H

#include <iostream> // Stream declarations
using namespace std;

class Location
{
private:
    string name;
    string description;

public:
    Location (string name, string description) 
    {
        
    }

    string getLocation () 
    {
        return name;
    }

    string getDescription () 
    {
        return description;
    }

    void displayLocation ()
    {
        cout << getLocation() 
             << getDescription()
             << endl;
    }

    
};

#endif