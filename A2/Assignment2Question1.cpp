//: Assignment2Qestion1.cpp

/*
  Title: Assignment2Qestion1.cpp
  Description: An animal class with a sound method that has 4 child classes of 
	specific types of animals. Each child class has a sound method that 
	overrides the parent class sound method and prints out the phrase 
	in the assignment requirements. 
  Date: July 29, 2024
  Author: Minori Olguin
  Student ID: 3441333
*/

/*
 DOCUMENTATION

 Program Purpose: Use inheritance and method overriding to create a parent class
	and method that has 4 child classes that override the sound method. Create 
	default constructors for classes. Create a test class to return an animal 
	selected by the user.

 Compile: g++ -o Assignment2Question1 Assignment2Question1.cpp
 Execution: ./Assignment2Question1

 Notes: in Cygwin, main must return type int

 Classes: Animal, Cow, Sheep, Duck, Pig, AnimalTest
    
Instance Variables: 
	cow1 - Cow - first instance of cow
	cow2 - Cow - second instance of cow
	cow3 - Cow - third instance of cow 
	pig1 - Pig - first instance of pig
	pig2 - Pig - second instance of pig
	pig3 - Pig - third instance of pig
	sheep1 - Sheep - first instance of sheep
	sheep2 - Sheep - second instance of sheep
	sheep3 - Sheep - third instance of sheep
	duck1 - Duck - first instance of duck
	duck2 - Duck - second instance of duck
	duck3 - Duck - third instance of duck
	animal - Animal - first instance of animal
	test - AnimalTest - first instance of animal

Variables:
	testAnimal - String - represents the name of the animal type input by user
	animalName - String - represents the name of the animal type input by user transformed to all lower case
	newAnimal - Animal* - represent a pointer to the animal created by the user
*/

/*
 TEST PLAN

 Normal case: 
 	>********* Animal Test *********
	>Enter a type of animal to create it:  cow
	>I am an animal
	>I am a cow
	>cow says 'moo'

 Bad Data case 1 (misspelled animal type)
	>********* Animal Test *********
	>Enter a type of animal to create it:  cowo
	>cowo not recognized, generic animal was created.
	>I am an animal
	>An animal makes a sound based on the animal that it is.

 Bad Data case 2 (integers input instead of string)
	>********* Animal Test *********
	>Enter a type of animal to create it:  234
	>234 not recognized, generic animal was created.
	>I am an animal
	>An animal makes a sound based on the animal that it is.     

 Bad Data case 3 (special characters entered instead of string)
	>********* Animal Test *********
	>Enter a type of animal to create it:  !!!!
	>!!!! not recognized, generic animal was created.
	>I am an animal
	>An animal makes a sound based on the animal that it is.   

 Bad Data case 4 (more than one animal entered)
	>********* Animal Test *********
	>Enter a type of animal to create it:  cow pig
	>I am an animal
	>I am a cow
	>cow says 'moo' 

 Discussion: 
	The program only accepts a single word as input and will only use the first animal entered
	when creating an animal. If the animal name is incorrect or does not match an existing animal
	then a generic type Animal will be created. If special characters or numbers are entered, 
	the program will create a generic Animal. 
*/

#include <iostream> // Stream declarations
#include <iomanip>
using namespace std;


/****************************************************************
 Animal
*****************************************************************/
class Animal 
{
    public:
	Animal() // Default constructor 
	    {
		cout << "I am an animal" << endl;
	    }

        virtual void sound() // Generic animal sound method 
	    {
		cout << "An animal makes a sound based on the animal that it is." << endl;	    
	    }
};

/****************************************************************
 Pig extends Animal 
*****************************************************************/
class Pig: public Animal 
{
    public:
	Pig() // Default constuctor 
	    {
		cout << "I am a pig" << endl;
    	    }

	void sound() // Pig sound method, overrides animal sound method
	    {
		cout << "pig says 'oink'" << endl;
	    }
};

/****************************************************************
 Sheep extends Animal 
*****************************************************************/
class Sheep: public Animal 
{
    public: 
	Sheep() // Default constructor 
	    {
		cout << "I am a sheep" << endl;
	    }

	void sound() // Sheep sound method, overrides animal sound method
	    {
		cout << "sheep says 'baah'" << endl;
	    }
};

/****************************************************************
 Duck extends animal 
*****************************************************************/
class Duck: public Animal 
{
    public: 
	Duck() // Default constructor
	    {
		cout << "I am a duck" << endl;
	    }

	void sound() // Duck sound method, overrides animal sound method 
	    {
		cout << "duck says 'quack'" << endl;
	    }
};

/****************************************************************
 Cow extends Animal 
*****************************************************************/
class Cow: public Animal
{
    public:
	Cow() // Default constructor 
	    {
		cout << "I am a cow" << endl;
	    }

        void sound() // Cow sound method, overrides animal sound method 
            {
                cout << "cow says 'moo'" << endl;
            }
};

/****************************************************************
 AnimalTest
*****************************************************************/
class AnimalTest 
{
    public:
	// selectAnimal prompts user for animal type string input, it returns that string
	string selectAnimal() 
	    {
		string testAnimal;
		cout << "\n\n********* Animal Test *********\n\n" 
		     << "Enter a type of animal to create it: " 
		     << endl;
		cin >> testAnimal;
		cout << endl;
		return testAnimal;
   	    } 

	// Creates an animal takes a string parameter of user input that is the name of the animal
	//  Transforms the name to all lowercase and then compares the name to all the animal names
	// The default is to create an animal if there is no matching animal name, this method returns
	// an Animal pointer
	Animal* createAnimal(string testAnimal) 
	    {   
		string animalName = testAnimal;
		transform(animalName.begin(), animalName.end(), animalName.begin(), ::tolower); 
		if(animalName == "pig")
		{
		    return new Pig();
		}
		else if (animalName == "sheep")
		{
		    return new Sheep();
		}
                else if (animalName == "duck")
                {
		    return new Duck();
                }
                else if (animalName == "cow")
                {
		    return new Cow();
                }
		else if (animalName == "animal")
                {
				return new Animal(); 
                }
		else 
		{
	        cout << animalName << " not recognized, generic animal was created." << endl;
		    return new Animal();   
		}
	    } 

		// Sound method overrides the Animal sound method, calls the sound method of animal
		// that the pointer is pointing at
		void sound(Animal* newAnimal)
		{
			newAnimal->sound();
		}

};

/****************************************************************
 main
*****************************************************************/
int main () 
{
    // Creating first instance of parent and child classes
    Animal animal1;
    Pig pig1;
    Sheep sheep1;
    Duck duck1;
    Cow cow1;  

    // Creating second instance of all child classes
    Pig pig2;
    Sheep sheep2;
    Duck duck2;
    Cow cow2;

    // Creating third instance of all child classes
    Pig pig3;
    Sheep sheep3;
    Duck duck3;
    Cow cow3;

    // Calling sound method for each animal that was created 
    animal1.sound();
    pig1.sound();
    sheep1.sound();
    duck1.sound();
    cow1.sound();

    // Calling sound method for all second instances of child classes 
	pig2.sound();
    sheep2.sound();
    duck2.sound();
    cow2.sound();

    // Calling sound method for all third instances of child classes
    pig3.sound();
    sheep3.sound();
    duck3.sound();
    cow3.sound();

    // AnimalTest
	// Create an instance of test
    AnimalTest test;

	// Create a new animal from user input, select animal gets input from user, create animal 
	// creates the animal based on the string returned from user input, as a Animal pointer
    Animal* newAnimal = test.createAnimal(test.selectAnimal());
	// Call sound method to call the sound method for the newAnimal the user created
	test.sound(newAnimal);

    delete newAnimal; // Free the memory that was used with the 'new' statement in createAnimal 
} ///:~
