//: Assignment1Qestion4.cpp

/*
  Title: Assignment1Qestion4.cpp
  Description:
  Date: May 27, 2024
  Author: Minori Olguin
  Student ID: 3441333
*/

/*
 DOCUMENTATION

 Program Purpose:

 Compile: g++ -o Assignment1Qestion4 Assignment1Qestion4.cpp
 Execution: ./Assignment1Qestion4

 Notes: in Cygwin, main must return type int

 Classes: CPPHelpMenu

 Variables:
    selection - char - single character as selection for different outputs
        used to choose a menu item
    done - bool - false until the user selects exit, then it will be true,
        used to continue looping untill the user exits the program

*/

/*
  TEST PLAN

  Normal case:
    >C++ Help Menu
    >Select Help on:
    >1. If
    >2. Switch
    >3. For
    >4. While
    >5. Do-while
    >x. Exit

    >Selection: 1

    >if: If is a conditional statement. The expression in parentheses is called the condition, 
    if it is true, the statement in the brackets gets executed. If the condition is not true, 
    nothing happens, or if there is an else block attached, the statement within the else 
    block is executed.

    >C++ Help Menu
    >Select Help on:
    >1. If
    >2. Switch
    >3. For
    >4. While
    >5. Do-while
    >x. Exit

    >Selection: x

    >Thank you. Good bye.

  Bad Data case 1 (Alternative character entered for selection):
    >C++ Help Menu
    >Select Help on:
    >1. If
    >2. Switch
    >3. For
    >4. While
    >5. Do-while
    >x. Exit

    >Selection: s

    >Invalid selection, please try one of the menu options.

    >C++ Help Menu
    >Select Help on:
    >1. If
    >2. Switch
    >3. For
    >4. While
    >5. Do-while
    >x. Exit

    >Selection: x

    >Thank you. Good bye.

Bad Data case 2 (Multiple characters entered for selection):
    >C++ Help Menu
    >Select Help on:
    >1. If
    >2. Switch
    >3. For
    >4. While
    >5. Do-while
    >x. Exit

    >Selection: ss

    >Invalid selection, please try one of the menu options.

    >C++ Help Menu
    >Select Help on:
    >1. If
    >2. Switch
    >3. For
    >4. While
    >5. Do-while
    >x. Exit

    >Selection: (did not prompt)
    >Invalid selection, please try one of the menu options.

    >C++ Help Menu
    >Select Help on:
    >1. If
    >2. Switch
    >3. For
    >4. While
    >5. Do-while
    >x. Exit

    >Selection: x

    >Thank you. Good bye.

Bad Data case 3 (Out of range integer entered for selection):
    >C++ Help Menu
    >Select Help on:
    >1. If
    >2. Switch
    >3. For
    >4. While
    >5. Do-while
    >x. Exit

    >Selection: 8

    >Invalid selection, please try one of the menu options.

    >C++ Help Menu
    >Select Help on:
    >1. If
    >2. Switch
    >3. For
    >4. While
    >5. Do-while
    >x. Exit

    >Selection: x

    >Thank you. Good bye.

Bad Data case 4 (Double entered for selection):
    >C++ Help Menu
    >Select Help on:
    >1. If
    >2. Switch
    >3. For
    >4. While
    >5. Do-while
    >x. Exit

    >Selection: 4.2

    >while: The while statement can be evalutated through a series 
    of short steps that are repeated. First, the program will evaluate 
    the condition in parentheses, yielding true or false. Second, if 
    the condition is false, exit the while statement and continue the 
    execution of the program at the next statement. If the condition is 
    true, execute of the statement between the squiggly-braces, and then 
    go back to the first step. The while loop continues, until the statement 
    in paretheses is evaluated to be false.

    >C++ Help Menu
    >Select Help on:
    >1. If
    >2. Switch
    >3. For
    >4. While
    >5. Do-while
    >x. Exit

    >Selection:
    >Invalid selection, please try one of the menu options.

    >C++ Help Menu
    >Select Help on:
    >1. If
    >2. Switch
    >3. For
    >4. While
    >5. Do-while
    >x. Exit

    >Selection:
    >switch: The switch statement is an alternative to a chained conditional. 
    It uses a variable, which can match several different cases. If the 
    variable matches one of the cases, it will execute that case, if it matches 
    no case, then the default case is executed. The switch statement requires 
    that 'break;' be placed after each case otherwise, the flow of execution 
    would 'fall through' to the next cases. Switch statements work with 
    integers, characters and enumerated types. A default case is not required, 
    but it is good practice.

    >C++ Help Menu
    >Select Help on:
    >1. If
    >2. Switch
    >3. For
    >4. While
    >5. Do-while
    >x. Exit

    >Selection: x

    >Thank you. Good bye.

  Discussion: The selection can take one char as input, it can be an integer or
  a character, if multiple characters are entered it will treat each as a single
  character input and continue the program without prompting for the following
  input for as many characters that have been entered. The program will recognize
  if an invalid input is entered and prompt the user to select one of the options
  from the menu. When I entered a double it took the number before the decimal as
  an integer, the period as an invalid char, then the number after the decimal as
  another integer. The program will not crash with invalid input, but it may go
  through several loops without requesting user input depending on the number of
  characters entered.

*/

#include <iostream> // Stream declarations
using namespace std;

/****************************************************************
 CPPHelpMenu
*****************************************************************/
class CPPHelpMenu
{

public:
    // Method for printing the menu
    static void display()
    {
        cout << "C++ Help Menu" << endl;
        cout << "Select Help on:" << endl;
        cout << "1. If" << endl;
        cout << "2. Switch" << endl;
        cout << "3. For" << endl;
        cout << "4. While" << endl;
        cout << "5. Do-while" << endl;
        cout << "x. Exit\n"
             << endl;
    }

    // Method for getting user selection
    static char getSelection()
    {
        char selection;
        cout << "Selection: ";
        cin >> selection;
        cout << endl;
        return selection;
    }

    // Method for printing the definition based on the user selection
    static bool printSelection(char selection)
    {
        bool done = false;
        switch (selection)
        {
        case '1':
            cout << "if: If is a conditional statement. The expression in" 
                 << "parentheses is called the condition, if it is true, the "
                 << "statement in the brackets gets executed. If the condition "
                 << "is not true, nothing happens, or if there is an else block " 
                 << "attached, the statement within the else block is executed.\n"
                 << endl;
            break;
        case '2':
            cout << "switch: The switch statement is an alternative to a chained "
                 << "conditional. It uses a variable, which can match several different "
                 << "cases. If the variable matches one of the cases, it will execute that "
                 << "case, if it matches no case, then the default case is executed. "
                 << "The switch statement requires that 'break;' be placed after each case"
                 << "otherwise, the flow of execution would 'fall through' to the next cases. "
                 << "Switch statements work with integers, characters and enumerated types. "
                 << "A default case is not required, but it is good practice.\n"
                 << endl;
            break;
        case '3':
            cout << "for: The for loop is a convenient way to write a loop with a counter "
                 << "It initializes a variable, has a condition/test, and has an incrementor "
                 << "For loops can be replicated using while loops, but they are more "
                 << "concise because it puts all the loop related statements in parentheses "
                 << "beside the for declaration. It runs the same way that other loops run "
                 << "as it will continue to loop until the condition returns false.\n"
                 << endl;
            break;
        case '4':
            cout << "while: The while statement can be evalutated through a series " 
                 << "of short steps that are repeated. First, the program will evaluate "
                 << "the condition in parentheses, yielding true or false. Second, if "
                 << " the condition is false, exit the while statement and continue the "
                 << "execution of the program at the next statement. If the condition is "
                 << "true, execute of the statement between the squiggly-braces, and then "
                 << "go back to the first step. The while loop continues, until the statement "
                 << "in paretheses is evaluated to be false.\n"
                 << endl;
            break;
        case '5':
            cout << "do-while: The do-while statement is similar to the while statement and "
                 << "can also be evalutated through a series of short steps that are repeated. "
                 << "The main difference between a while loop and a do-while loop, is the order "
                 << "in which the steps are executed and how many times at minimum the steps are "
                 << "executed. First, the program will execute the statement between the squiggly-"
                 << "braces. Second, the program will evaluate the condition in parentheses, "
                 << "yielding true or false. If the condition is false, exit the do-while statement "
                 << "and continue the execution of the program at the next statement. If the "
                 << "condition is true, return to the top of the do-while statement and repeat the statement "
                 << "between the squiggly-braces. The do-while loop continues, until the statement in "
                 << "paretheses is evaluated to be false. The statement inside the do-while braces is executed "
                 << "at a minimum of once, while the while loop statement does not have to be executed once.\n"
                 << endl;
            break;
        case 'x':
        case 'X':
            cout << "Thank you. Good bye.\n"
                 << endl;
            done = true;
            break;
        default:
            cout << "Invalid selection, please try one of the menu options.\n"
                 << endl;
        }
        return done;
    }
};

/****************************************************************
 main
*****************************************************************/
int main()
{
    // declaring variables
    CPPHelpMenu helpMenu;
    bool done = false;

    // prompting user for input and displaying selection based on input
    // continuing while user has not entered 'x' to indicate they are done
    while (!done)
    {
        helpMenu.display();
        done = helpMenu.printSelection(helpMenu.getSelection());
    }
    return 0;
} ///:~
