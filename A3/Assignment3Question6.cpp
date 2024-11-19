//: Assignment3Qestion6.cpp

/*
Title: Assignment3Qestion6.cpp
Description: This program defines a `Set` template class that holds unique elements and provides a custom 
iterator for traversing these elements. 
Date: October 27, 2024
Author: Minori Olguin
Student ID: 3441333
*/

/*
DOCUMENTATION

Program Purpose: The main purpose is to learn about templates, sets, and implementing custom iterator classes in C++.

Compile: g++ -o Assignment3Question6 Assignment3Question6.cpp
Execution: ./Assignment3Question6

Notes: in Cygwin, main must return type int

Classes: Set<T>, Iterator

Variables:
    myVector - vector<T> - Stores unique elements within the `Set` class.
    current - typename vector<T>::iterator - Points to the current element in `Set`'s custom iterator.
*/

/*
 TEST PLAN

 Normal case:
    - Insert a series of unique integers (e.g., 1, 2, 3) into the `Set`.
    - Verify that the custom iterator outputs each element in the order they were inserted.

 Bad Data case 1 (duplicate element):
    - Attempt to insert a duplicate element, such as `2` when `2` already exists in the `Set`.
    - Expected result: The `Set` should ignore the duplicate, and it should not be stored.

 Bad Data case 2 (non-integer types):
    - Test `Set` with different data types such as `Set<string>`, `Set<double>`, etc., and insert unique values.
    - Expected result: The `Set` should store only unique values and work as expected regardless of the data type.

 Discussion: This program doesn't take user input and doesn't have many limitations
 as it's directly based off of the C++ class set 
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/****************************************************************
 Set 
*****************************************************************/
template <typename T>
class Set
{
private:
    vector<T> myVector;

public:
    Set() {} // Default constructor

    // Insert method to add unique elements only
    void insert(T val)
    {
        // Check if the value is already present in the vector
        if (find(myVector.begin(), myVector.end(), val) == myVector.end())
        {
            myVector.push_back(val);
        }
    }

    /****************************************************************
     Iterator
    *****************************************************************/
    class Iterator
    {
    private:
        typename vector<T>::iterator current;

    public:
        // Constructor for nested iterator class
        Iterator(typename vector<T>::iterator start) : current(start) {}

        T &operator*()
        {
            return *current;
        }

        Iterator &operator++()
        {
            ++current;
            return *this;
        }

        bool operator!=(const Iterator &other) const { return current != other.current; }
    };

    // Begin and end methods to get iterators
    Iterator begin() { return Iterator(myVector.begin()); }
    Iterator end() { return Iterator(myVector.end()); }
};

/****************************************************************
 main
*****************************************************************/
int main()
{
    Set<int> customSet;
    customSet.insert(1);
    customSet.insert(2);
    customSet.insert(2); // Duplicate value, should not be added 
    customSet.insert(3);

    // Testing custom Set iterator
    cout << "Custom Set elements:\n";
    for (auto it = customSet.begin(); it != customSet.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}///:~
