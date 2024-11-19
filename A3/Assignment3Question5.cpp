//: Assignment3Qestion5.cpp

/*
Title: Assignment3Qestion5.cpp
Description: A program to manage a collection of books on a bookshelf. 
The program allows adding books to a shelf, displaying book information, 
and sorting the books by title and publication year.
Date: October 12, 2024
Author: Minori Olguin
Student ID: 3441333
*/

/*
DOCUMENTATION

Program Purpose: Implement a program using a cpp header doc, 
and learn how to use vector.

Compile: g++ -o Assignment3Question5 Assignment3Question5.cpp
Execution: ./Assignment3Question5

Notes: in Cygwin, main must return type int

Classes: Bookshelf

Variables:
    - books - vector of books
*/

/*
 TEST PLAN

 Normal case:
Add multiple books with different titles and publication years.
Display the books to verify they are stored correctly.
Sort the books and ensure they are ordered alphabetically by title. 
If titles are the same, verify that the books are sorted by publication year.

 Discussion: Current limitations include that if books have exactly the same information, 
 it will input both books. Unsure of how the compare function would work in this situation.
 Potential future enhancements include allowing sorting by additional attributes, such as 
 author name or genre. Other limitations include that the book class currently has default

*/

#include <iostream>  // Stream declarations
#include <vector>
#include "book.h"
using namespace std;

/****************************************************************
 Bookshelf
*****************************************************************/
class Bookshelf
{
private:
    vector<Book> books;

public:
    Bookshelf() {} // default constructor

    void addBook(Book book)
    {
        books.push_back(book);
    }

    void displayBooks()
    {
        for (int i = 0; i < books.size() - 1; i++)
        {
            books[i].printBookInformation();
        }
    }

    static bool compareBooks(Book &book, Book &bookToCompare)
    {
        if (book.getTitle() == bookToCompare.getTitle())
        {
            return book.getPublicationYear() < bookToCompare.getPublicationYear();
        }
        return book.getTitle() < bookToCompare.getTitle();
    }

    void sortBooks()
    {
        sort(books.begin(), books.end(), compareBooks);
        cout << "Books successfully sorted!\n"
             << endl;
    }
};

/****************************************************************
 main
*****************************************************************/
int main()
{
    cout << "Displaying several test book creations.\n"
         << endl;
    // create several book objects and display their attributes
    Book prideAndPrejudice("Pride and Prejudice", 9780140434262, "Jane Austen", 8, "Modern Library", 2000);
    prideAndPrejudice.printBookInformation();

    Book animalFarm("Animal Farm", 9780451526342, "George Orwell", 4, "Signet Classics", 1996);
    animalFarm.printBookInformation();

    Book lifeOfPi("Life of Pi", 9780770430078, "Yann Martel", 1, "Seal Books", 2006);
    lifeOfPi.printBookInformation();

    Book toKillAMockingBird("To Kill a Mockingbird", 9782253115847, "Harper Lee", 10, "Harper Perennial Modern Classics", 1960);
    toKillAMockingBird.printBookInformation();

    // Creating bookshelf instance
    Bookshelf bookshelf;

    // Adding 12 books to the bookshelf
    cout << "Adding 12 books to the bookshelf.\n"
         << endl;
    bookshelf.addBook(prideAndPrejudice);
    bookshelf.addBook(animalFarm);
    bookshelf.addBook(lifeOfPi);
    bookshelf.addBook(toKillAMockingBird);
    bookshelf.addBook(Book("Fahrenheit 451", 9780743247221, "Ray Bradbury", 12, "Ballantine Books", 1953));
    bookshelf.addBook(Book("Twilight", 9780316015844, "Stephenie Meyer", 3, "Little, Brown and Company", 2006));
    bookshelf.addBook(Book("New Moon", 316160199, "Stephenie Meyer", 2, "Little, Brown and Company", 2006));
    bookshelf.addBook(Book("Eclipse", 9780316160209, "Stephenie Meyer", 1, "Little, Brown and Company", 2007));
    bookshelf.addBook(Book("BreakingDawn", 31606792, "Stephenie Meyer", 1, "Little, Brown and Company", 2008));
    bookshelf.addBook(Book("The Hunger Games", 9780439023481, "Suzanne Collins", 1, "Scholastic Press", 2008));
    bookshelf.addBook(Book("Catching Fire", 9780545227247, "Suzanne Collins", 1, "Scholastic Press", 2009));
    bookshelf.addBook(Book("Mockingjay", 9780439023511, "Suzanne Collins", 1, "Scholastic Press", 2010));

    // Showing the books in the order they were added
    cout << "Displaying the books before sorting.\n"
         << endl;
    bookshelf.displayBooks();

    // Sorting the books by title, then year
    cout << "Sorting the books.\n"
         << endl;
    bookshelf.sortBooks();

    // Showing the books sorted by title & year
    cout << "Displaying the books after sorting.\n"
         << endl;
    bookshelf.displayBooks();
} ///:~
