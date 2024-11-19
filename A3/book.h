#ifndef BOOK_H
#define BOOK_H

#include <iostream> // Stream declarations
using namespace std;

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
    Book()
    { // Default constructor
        string title = "No Title Found";
        long ISBN = 0;
        string author = "No Author Found";
        string edition = "No Edition Found";
        string publisher = "No Publisher Found";
        int publicationYear = 0;
    }

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
    void setEdition(int numEdition)
    {
        if (numEdition > 0)
        {
            int remainder = numEdition % 10;
            switch (remainder)
            {
            case 1:
                if (numEdition == 11)
                {
                    edition = to_string(numEdition) + "th";
                    break;
                }
                edition = to_string(numEdition) + "st";
                break;
            case 2:
                if (numEdition == 12)
                {
                    edition = to_string(numEdition) + "th";
                    break;
                }
                edition = to_string(numEdition) + "nd";
                break;
            case 3:
                if (numEdition == 13)
                {
                    edition = to_string(numEdition) + "th";
                    break;
                }
                edition = to_string(numEdition) + "rd";
                break;
            default:
                edition = to_string(numEdition) + "th";
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

#endif