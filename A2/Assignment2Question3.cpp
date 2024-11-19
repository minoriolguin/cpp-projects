//: Assignment2Qestion3.cpp

/*
  Title: Assignment2Qestion3.cpp
  Description: Program creates instances of elevator, you can move up or down one floor or 
               enter a specific floor to go to as a destination.
  Date: August 7, 2024
  Author: Minori Olguin
  Student ID: 3441333
*/

/*
 DOCUMENTATION

 Program Purpose: Use different instances of elevator to move up, down and to specific floors.
                  Learn to implement basic error handling and use setters and getters to 
                  access private attributes.

 Compile: g++ -o Assignment2Question3 Assignment2Question3.cpp
 Execution: ./Assignment2Question3

 Notes: in Cygwin, main must return type int

 Classes: Elevator
    
Instance Variables: 
    eastonCentreElevator - Elevator - elevator in easton centre 
    northernCentreElevator - Elevator - elevator in northern centre
    westernCentreElevator - Elevator - elevator in western centre
    southernCentreElevator - Elevator - elevator in southern centre
    centralCentreElevator - Elevator - elevator in central centre

Variables:
    numOfFloors - int - number of floors available to an elevator
    currentFloor - int - current floor that the elevator is at
    destinationFloor - int - destination floor that the elevator is heading to
    title - string - name of the elevator 
*/

/*
 TEST PLAN

 Normal case: 
    Does the elevator move to the floor specified?
    Does the elevator move up when moveUp() called?
    Does the elevator move down when moveDown() called?
    Does the elevator finalize function move elevator to floor 1 before elevator is destoryed?

 Discussion:
    I don't think this program has any limitations because it doesn't take any input
    from the user so it funcitions by printing out statements that indicate what is 
    happening in the program.
*/

#include <iostream> // Stream declarations
using namespace std;

/****************************************************************
 Elevator
*****************************************************************/
class Elevator 
{
    private:
        // Elevator attributes
        int numOfFloors;
        int currentFloor;
        string title;

        // Sets the number of floors for the elevator 
        void setFloors(int numOfFloors)
        {
            this->numOfFloors = numOfFloors;
        }

        // Sets the current floor 
        void setCurrentFloor(int currentFloor)
        {
            this->currentFloor = currentFloor;
        }

        // Returns the current floor
        int getCurrentFloor()
        {
            return currentFloor;
        }

        // Returns the number of floors
        int getNumOfFloors()
        {
            return numOfFloors;
        }

    public:
    // Default constructor, initiallizes with 5 floors, prints a statement to confirm elevator was created
    Elevator()
    {
        setFloors(5);
        setCurrentFloor(1); 
        cout << "\nNew elevator created with " << getNumOfFloors() << " floors." << endl;  
    }

    // Overloaded constructor that sets num of floors based on parameter, prints a statement to confirm elevator was created
    Elevator(int numOfFloors) 
    {
        setFloors(numOfFloors);
        setCurrentFloor(1);
        cout << "\nNew elevator created with " << getNumOfFloors() << " floors." << endl;  

    }

    // Destructor 
    ~Elevator() 
    {
        finalize();
    }

    // Sets title for elevator
    void setTitle(string title) 
    {
        this->title = title;
        displayCurrentFloor();
    }

    // Returns the title for elevator 
    string getTitle()
    {
        return title;
    }

    // displays the current floor number
    void displayCurrentFloor()
    {
        cout << getTitle() << " is currently at floor " << getCurrentFloor() << ".\n" << endl;
    }

    // Sets floor to 1 and prints a statement to confirm the elevator moved to first floor
    void finalize() 
    {
        if (getCurrentFloor() != 1)
        {
            setCurrentFloor(1);
            cout << getTitle() << " ending: elevator returned to the first floor." << endl;
        }
        else 
        {
        cout << getTitle() << " ending: elevator is already at the first floor." << endl;
        }
    }

    // moves the elevator down one floor if it is not at the bottom floor
    void moveDown()
    {
        if (getCurrentFloor() > 1)
        {
            setCurrentFloor(--currentFloor);
            cout << getTitle() << " moved down. Current floor: " << getCurrentFloor() << "\n" <<endl;
        }
        else 
	{
            cout << getTitle() << " is already at the bottom floor" 
                 << " and is not able to move down a floor. \nCurrent floor: "
                 << getCurrentFloor() << "\n" << endl;
        }
    }

    // moves the elevator up one floor if it is not at the top floor 
    void moveUp()
    {
        if (getCurrentFloor() < getNumOfFloors())
        {
            setCurrentFloor(++currentFloor);
            cout << getTitle() << " moved up. \nCurrent floor: "
                 << getCurrentFloor() << "\n" << endl;
        }
        else 
	{
            cout << getTitle() << " is already at the top floor"
                 << " and is not able to move up a floor.\n" 
                 << endl;
        }
    }

    // moves the elevator to the floor entered as a parameter if it exists
    void moveToFloor(int destinationFloor) 
    {
        if (destinationFloor == currentFloor) 
        {
            cout << getTitle() << " is already on floor" 
                 << destinationFloor << ".\n" << endl;
        }
        else if (destinationFloor >= 1 && destinationFloor <= numOfFloors)
        {
            setCurrentFloor(destinationFloor);
            cout << getTitle() << " moved to floor " 
                 << getCurrentFloor() << ".\n" << endl;
        }
        else 
	{
            cout << destinationFloor << " is not a valid floor, "
                 << getTitle() << " has floors 1 to " 
                 << getNumOfFloors() << ".\n" << endl;
        }
    }
};

/****************************************************************
 main
*****************************************************************/
int main () 
{
    // Scenario 1: Elevator in Easton Centre
    cout << "\n\nScenario 1: Easton Centre Elevator" << endl;
    Elevator eastonCentreElevator;
    eastonCentreElevator.setTitle("Eastern Centre Elevator");
    eastonCentreElevator.moveDown();
    eastonCentreElevator.moveUp();
    eastonCentreElevator.moveToFloor(12);
    eastonCentreElevator.moveDown();

    // Scenario 2: Elevator in Northern Centre
    cout << "\n\nScenario 2: Northern Centre Elevator" << endl;
    Elevator northernCentreElevator(10);
    northernCentreElevator.setTitle("Northern Centre Elevator");
    northernCentreElevator.moveUp();
    northernCentreElevator.moveToFloor(9);
    northernCentreElevator.moveUp();
    northernCentreElevator.moveUp();
    northernCentreElevator.moveDown();

    // Scenario 3
    cout << "\n\nScenario 3: Western Centre Elevator" << endl;
    Elevator westernCentreElevator(2);
    westernCentreElevator.setTitle("Western Centre Elevator");
    westernCentreElevator.moveToFloor(7);
    westernCentreElevator.displayCurrentFloor();
    westernCentreElevator.moveToFloor(1);
    westernCentreElevator.moveUp();

    // Scenario 4 
    cout << "\n\nScenario 4: Southern Centre Elevator" << endl;
    Elevator southernCenterElevator(4);
    southernCenterElevator.setTitle("Southern Centre Elevator");
    southernCenterElevator.moveToFloor(4);
    southernCenterElevator.moveToFloor(1);
    southernCenterElevator.moveDown();

    // Scenario 5 
    cout << "\n\nScenario 5: Central Centre Elevator" << endl;
    Elevator centralCentreElevator;
    centralCentreElevator.setTitle("Central Centre Elevator");
    centralCentreElevator.moveToFloor(5);
    centralCentreElevator.moveUp();
    centralCentreElevator.displayCurrentFloor();
    centralCentreElevator.moveDown();
    centralCentreElevator.moveDown();
    
} ///:~
