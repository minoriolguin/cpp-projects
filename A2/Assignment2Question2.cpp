//: Assignment2Qestion2.cpp

/*
  Title: Assignment2Qestion2.cpp
  Description: Define a class called Book. The Book class stores attributes,
    including the title, ISBN number, author, edition, publisher, and year
    of publication. These attributes are  private and can be accessed with
    public get/set methods in this class to access these attributes.

  Date: August 7, 2024
  Author: Minori Olguin
  Student ID: 3441333
*/

/*
 DOCUMENTATION

 Program Purpose:
    Use getters and setters to return and set private attributes.

 Compile: g++ -o Assignment2Question2 Assignment2Question2.cpp
 Execution: ./Assignment2Question2

 Notes: in Cygwin, main must return type int

 Classes: Book

 Book Attributes:
    title - string - represents the book's title
    ISBN - long - represents the book's ISBN
    author - string - represents the author of the book
    edition - string - represents book edition
    publisher - string - represents the book publisher
    publicationYear - int - represents the book's year of publication

 Variables:
    newTitle - string - represents the book's title used in setter method as a parameter
    newISBN - long - represents the book's ISBN used in setter method as a parameter
    newAuthor - string - represents the author of the book used in setter method as a parameter
    newEdition - int - represents book edition used in setter method as a parameter
    newPublisher - string - represents the book publisher used in setter method as a parameter
    newPublicationYear - int - represents the book's year of publication used in setter method as a parameter

*/

/*
 TEST PLAN
 Normal case: 
    Do the setters set the correct information for the book?
    Do the getters return the correct information for the book?

 Discussion:
    This program does not take user input and all values are hardcoded. All of the 
    numbers must be positive.
*/

#include <iostream> // Stream declarations
using namespace std;

/****************************************************************
 Book
*****************************************************************/
class Book
{
private:
    // Book attributes
    string title;
    long ISBN;
    string author;
    string edition;
    string publisher;
    int publicationYear;

public:
    // Default constructor 
    Book()
    {
        string title = "No Title Found";
        long ISBN = 0;
        string author = "No Author Found";
        string edition = "No Edition Found";
        string publisher = "No Publisher Found";
        int publicationYear = 0;
    }

    // Second constructor that takes the attributes as parameters and uses
    // setter methods to create the book with the attributes entered
    Book(string title, long ISBN, string author, int edition, string publisher, int publicationYear)
    {
        setTitle(title);
        setISBN(ISBN);
        setAuthor(author);
        setEdition(edition);
        setPublisher(publisher);
        setPublicationYear(publicationYear);
    }

    // returns the title
    string getTitle()
    {
        return title;
    }

    // returns the ISBN
    long getISBN()
    {
        return ISBN;
    }

    // returns the author
    string getAuthor()
    {
        return author;
    }

    // returns the edition
    string getEdition()
    {
        return edition;
    }

    // returns the publisher 
    string getPublisher()
    {
        return publisher;
    }

    // returns the publication year
    int getPublicationYear()
    {
        return publicationYear;
    }

    // sets the title
    void setTitle(string newTitle)
    {
        title = newTitle;
    }

    // sets the ISBN
    void setISBN(long newISBN)
    {
        if (newISBN > 0)
        {
            ISBN = newISBN;
        }
        else 
        {
            cout << "Invalid ISBN entered, ISBN not set." << endl;
        }
    }

    // sets the author
    void setAuthor(string newAuthor)
    {
        author = newAuthor;
    }

    // sets the edition and adds the appropriate post-fix 
    void setEdition(int newEdition)
    {
        if (newEdition > 0)
        {
            newEdition = newEdition % 10;
            switch (newEdition)
            {
            case 1:
                edition = to_string(newEdition) + "st";
                break;
            case 2:
                edition = to_string(newEdition) + "nd";
                break;
            case 3:
                edition = to_string(newEdition) + "rd";
                break;
            default:
                edition = to_string(newEdition) + "th";
                break;
            }
        }
        else
        {
            cout << "Invalid input, edition not set." << endl;
        }
    }

    // sets the publisher
    void setPublisher(string newPublisher)
    {
        publisher = newPublisher;
    }

    // sets the publication year if it is greater than 0
    void setPublicationYear(int newPublicationYear)
    {
        if (newPublicationYear > 0) 
        {
        publicationYear = newPublicationYear;
        }
        else 
        {
            cout << "Invalid publication year entered, publication year not set." << endl;
        }
    }

    // prints the attributes for a book using getter methods
    void printBookInformation()
    {
        cout << "Title: " << getTitle() << "\n"
             << "ISBN: " << getISBN() << "\n"
             << "Author: " << getAuthor() << "\n"
             << "Edition: " << getEdition() << "\n"
             << "Publisher: " << getPublisher() << "\n"
             << "Publication Year: " << getPublicationYear() << "\n"
             << endl;
    }
};

/****************************************************************
 main
*****************************************************************/
int main()
{
    // Creating book The Hunger Games, settting all attributes
    // Then printing all attributes to console
    Book theHungerGames;
    theHungerGames.setTitle("The Hunger Games");
    theHungerGames.setISBN(9780439023481);
    theHungerGames.setAuthor("Suzanne Collins");
    theHungerGames.setEdition(1);
    theHungerGames.setPublicationYear(2008);
    theHungerGames.setPublisher("Scholastic Press");
    theHungerGames.printBookInformation();

    // Creating book Pride and Prejudice, settting all attributes
    // Then printing all attributes to console
    Book prideAndPrejudice;
    prideAndPrejudice.setTitle("Pride and Prejudice");
    prideAndPrejudice.setISBN(9780140434262);
    prideAndPrejudice.setAuthor("Jane Austen");
    prideAndPrejudice.setEdition(2);
    prideAndPrejudice.setPublicationYear(2000);
    prideAndPrejudice.setPublisher("Modern Library");
    prideAndPrejudice.printBookInformation();

    // Creating book Twilight, settting all attributes
    // Then printing all attributes to console
    Book twilight;
    twilight.setTitle("Twilight");
    twilight.setISBN(9780316015844);
    twilight.setAuthor("Stephenie Meyer");
    twilight.setEdition(3);
    twilight.setPublicationYear(2006);
    twilight.setPublisher("Little, Brown and Company");
    twilight.printBookInformation();

    // Creating book Animal Farm, settting all attributes using the 
    // setter methods through a constructor for a cleaner look
    // Then printing all attributes to console using getters
    // I was unsure of the requirements so I used the getters
    // in main to get print the information to consolve in
    // this example, even though the method above is much cleaner
    Book animalFarm("Animal Farm", 9780451526342, "George Orwell", 4, "Signet Classics", 1996);
    cout << "Title: " << animalFarm.getTitle() << "\n"
         << "ISBN: " << animalFarm.getISBN() << "\n"
         << "Author: " << animalFarm.getAuthor() << "\n"
         << "Edition: " << animalFarm.getEdition() << "\n"
         << "Publisher: " << animalFarm.getPublisher() << "\n"
         << "Publication Year: " << animalFarm.getPublicationYear() << "\n"
         << endl;

} ///:~
