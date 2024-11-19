//: Assignment2Qestion5.cpp

/*
  Title: Assignment2Qestion5.cpp
  Description: Program contains a Point class to hold x and y values for a point. 
               Point class includes methods show(), add() and subtract() to display 
               the Point x and y values, and add and subtract point coordinates.
               The program also inlcudes the class Shape which contains default functions 
               to calculate area and circumference of the shape, and provide the 
               coordinates (Points) of a rectangle that encloses the shape (a bounding 
               box). These are overloaded by the derived classes and only print a simple 
               message to standard output. The shape class has a display() function, which 
               displays the name of the class and all stored information about the class. 
               The child classes triangle, rectangle and circle have the display(), 
               calculate_circumference(), calculate_area(), and display_bounding_box() 
               functions.
  Date: August 12, 2024
  Author: Minori Olguin
  Student ID: 3441333
*/

/*
 DOCUMENTATION

 Program Purpose: Use classes and inheritance to create several shapes, including triangle, 
		  rectangle and circle. Learn to use error handling in constructors and use 
		  the parent class's functions to reduce repetition in code.
 Compile: g++ -o Assignment2Question5 Assignment2Question5.cpp
 Execution: ./Assignment2Question5

 Notes: in Cygwin, main must return type int

 Classes:
    Point - class to represent a point (x,y) coordinate
    Shape - parent class 
    Circle - child class to shape 
    Rectangle - child class to shape
    Triangle - child class to shape 
    
 Instance Variables:
    shape - instance of the Shape class to test generic display method 
    circle_1 - instance of the Circle class to test circle with negative radius
    circle_2 - instance of the Circle class to test circle
    circle_3 - instance of the Circle class to test circle
    triangle_1 - instance of the Triangle class to test triangle
    triangle_2 - instance of the Triangle class to test non-triangle forming coordinates
    triangle_3 - instance of the Triangle class to test triangle
    rectangle_1 - instance of the Rectangle class to test rectangle 
    rectangle_2 - instance of the Rectangle class to test special case of Square scenario 
    rectangle_3 - instance of the Rectangle class to test non-recangle quadrilateral scenario

 Variables:
    x - int - x-coordinate for point class 
    y - int - y-coordinate for point class 
    amount to change - int - amount that you want to adjust a coordinate by
    other_point - Point - other point to compare to a first point, use to check if coordinates are equivalent
    name - string - represents the name of the shape 
    radius - int - represents the radius of a circle 
    center - Point - represents the center point of a circle 
    top_left - Point - represents the top left corner of the bounding box
    top_right - Point - represents the top right corner of the bounding box
    bot_left - Point - represents the bottom left corner of the bounding box
    bot_right - Point - represents the bottom right corner of the bounding box
    is_triangle - bool - used to keep track of whether the coordinates result in a triangle shape 
    point_1 - Point - used to represent any one of the points on a triangle or rectangle 
    point_2 - Point - used to represent any one of the points on a triangle or rectangle 
    point_3 - Point - used to represent any one of the points on a triangle or rectangle 
    point_4 - Point - used to represent any one of the points on a rectangle
    p1_to_p2 - double - used to represent the distance between point_1 and point_2 in triangle class
    p2_to_p3 - double - used to represent the distance between point_2 and point_3 in triangle class
    p3_to_p1 - double - used to represent the distance between point_3 and point_1 in triangle class
    length - int - used to represent the length (distance between 2 x values) in rectangle class and
                   and in both the area and circumference calculations for rectangle
    width - int - used to represent the width (distance between 2 y values) in rectangle class and
                   and in both the area and circumference calculations for rectangle 
    min_x - int - used to represent the smallest x value in triangle and rectangle
    min_y - int - used to represent the smallest y value in triangle and rectangle
    max_x - int - used to represent the greatest x value in triangle and rectangle
    max_y - int - used to represent the greatest y value in triangle and rectangle
*/

/*
 TEST PLAN
 Normal case:
    Does the output match the calculations done manually?
    Do the correct shapes names work with the display method?
    Do the parameters passed to constructors properly apply to the shapes?
    Does the error handling print the correct message and call the correct methods?

 Discussion:
    This program does not accept input from user but when incorrect input is hardcoded, does the 
    program continue to function as expected? The program does function as expected because when 
    the constructors receive parameters that do not create the shape of the class, the shapes handle
    the input. For circle, there's no way to not create a circle because it requires the center point
    and the radius. If a negative radius is entered, the program uses the absolute value of the radius
    and continues as expected. For the rectangle, if the program receives coordinates that do not make
    a rectangle but a different quadrilateral shape, the program acts as if a generic shape was created.
    For triangle, if the program receives 3 coordinates that do not make a triangle, the program acts as
    if a generic shape was created.
*/

#include <iostream> // Stream declarations
#include <set>
using namespace std;

/****************************************************************
 Point
*****************************************************************/
class Point
{
private:
    // declaring variables 
    int x, y;

public:
    Point() // Default constructor
    {
        x = 0;
        y = 0;
    }

    // Overloads default constructor by taking x and y coordinates as parameters
    Point(int x, int y)
    {
        // Checks that both x and y are of type int
        if (typeid(x) != typeid(int) || typeid(y) != typeid(int))
        {
            // Throws a warning if invlaid arguments are received
            throw invalid_argument("Warning: x and y must be integer values.");
        }
        // Sets x and y to arguments received
        this->x = x;
        this->y = y;
    }

    // returns x, required because it's a private variable
    int get_x()
    {
        return x;
    }

    // returns y, required because it's a private variable
    int get_y()
    {
        return y;
    }

    // Prints x and y coordinates
    void show()
    {
        cout << "(" << x << ", " << y << ")" << endl;
    }

    // Adds one point to another
    void add_point(Point point_to_add) 
    {
	add_x(point_to_add.get_x());
	add_y(point_to_add.get_y());
    }

    // Subtracts one point from another
    void subtract_point(Point point_to_subtract)
    {
	subtract_x(point_to_subtract.get_x());
	subtract_y(point_to_subtract.get_y());
    }

    // Adds an amount to x and y 
    void add(int amount_to_change)
    {
        add_x(amount_to_change);
        add_y(amount_to_change);
    }

    // Subtracts an amount from x and from y
    void subtract(int amount_to_change)
    {
        subtract_x(amount_to_change);
        subtract_y(amount_to_change);
    }

    // Subtracts an amount from x and adds that amount to y
    void sub_x_add_y(int amount_to_change)
    {
        subtract_x(amount_to_change);
        add_y(amount_to_change);

    }

    // Adds an amount to x and subtracts that amount from y
    void add_x_sub_y(int amount_to_change)
    {
        add_x(amount_to_change);
        subtract_y(amount_to_change);

    }

    // Adds a value to an x value
    void add_x(int amount_to_change)
    {
        this->x = x + amount_to_change;
    }

    // Adds a value to a y value
    void add_y(int amount_to_change)
    {
        this->y = y + amount_to_change;
    }

    // Subtracts a value from x
    void subtract_x(int amount_to_change)
    {
        this->x = x - amount_to_change;
    }

    // Subtracts a value from y
    void subtract_y(int amount_to_change)
    {
        this->y = y - amount_to_change;
    }

    // Compares one point, to another point and returns a boolean value for if they're the same
    bool compare(Point other_point)
    {
        return (x == other_point.x) && (y == other_point.y);
    }
};

/****************************************************************
 Shape
*****************************************************************/
class Shape
{
public:
    // declaring variables 
    string name;

    Shape() // Default constructor, does not take arguments
    {
        set_name("Shape");
        confirm_creation();
    }

    // sets the name of a shape
    void set_name(string name)
    {
        this->name = name;
    }

    // prints a confirmation message to show the correct creation of the correct shape 
    void confirm_creation()
    {
        cout << "******" << name << " created******" << endl;
    }

    // Prints generic output, not implemented for generic shape, to be overriden by child classes
    virtual double calculate_area()
    {
        cout << "Calculate the area of the shape. Method not implemented for generic shape. ";
        return -1;
    }

    // Prints generic output, not implemented for generic shape, to be overriden by child classes
    virtual double calculate_circumfrence()
    {
        cout << "Calculate the circumference of the shape. Method not implemented for generic shape. ";
        return -1;
    }

    // Prints generic output, not implemented for generic shape, to be overriden by child classes
    virtual void bounding_box()
    {
        cout << "Display the coordinates for the bounding box surrounding the shape. Method not implemented for generic shape."
             << endl;
    }

    // display shows the information about a given shape, can be overriden or overloaded as it is virtual
    virtual void display()
    {
        cout << "\nName: " << name << "\n"
             << "Area: " << calculate_area() << "\n"
             << "Circumference: " << calculate_circumfrence() << "\n"
             << "Bounding box: "; bounding_box(); 
    }
};

/****************************************************************
 Cicle extends Shape
*****************************************************************/
class Circle : public Shape
{
private:
    // Declaring variables
    int radius;
    Point center;

public:
    Circle() // Default constructors
    {
        set_name("Circle");
        confirm_creation();
    }

    // Overloads default constructor, takes a Point and int as parameters
    Circle(Point center, int radius)
    {
        set_name("Circle"); 
        this->center = center; // Sets the value of center

        if (radius >= 0) // Checks if radius is positive, necessary to create a circle
        {
            this->radius = radius;
        }
        else
        {
            cout << "Radius must be a positive number, the absolute value of radius entered will be used." << endl;
            this->radius = abs(radius); // sets the radius to the absolute value of the radius entered
        }
        confirm_creation(); // Calls parent method, confirms the creation of a circle
    }

    // Overrides parent method, calculates and returns the area of a circle
    double calculate_area()
    {
        return M_PI * (radius * radius);
    }

    // Overrides parent method, calculates and returns the circumfrence of a circle
    double calculate_circumfrence()
    {
        return 2 * M_PI * radius;
    }

    // Overrides parent method, creates and displays the coordinates for a bounding box for a circle
    void bounding_box()
    {
        // Sets the corners of the bounding box equal to center
        Point top_left = center;
        Point top_right = center;
        Point bottom_left = center;
        Point bottom_right = center;

        // Adds and subtracts radius from the points as needed
        top_left.sub_x_add_y(radius);
        top_right.add(radius);
        bottom_left.subtract(radius);
        bottom_right.add_x_sub_y(radius);

        // Displays the values 
        cout << "\nTop Left: ";
        top_left.show();
        cout << "Top Right";
        top_right.show();
        cout << "Bottom Left: ";
        bottom_left.show();
        cout << "Bottom Right: ";
        bottom_right.show();
    }

    // Overrides parent method by printing addition information store about the circle class
    void display()
    {
        Shape::display(); // Calls parent method 
        cout << "Center point: "; center.show();
        cout << "Radius: " << radius << "\n"
             << endl;
    }
};

/****************************************************************
 Triangle extends Shape
*****************************************************************/
class Triangle : public Shape
{
public:
    // declaring variables 
    Point point_1;
    Point point_2;
    Point point_3;
    bool is_triangle;

    Triangle() // Default constructor
    {
        set_name("Triangle");
        confirm_creation();
    }

    // Overloads the default constructor by taking 3 Points as parameters
    Triangle(Point point_1, Point point_2, Point point_3)
    {
        // Checks if all 3 points are unique and if not prints an error statement and sets is_triangle to false
        if (point_1.compare(point_2) || point_2.compare(point_3) || point_1.compare(point_3))
        {
            cout << "The points entered do not form a triangle, the three points must be unique to make a triangle." << endl;
            this->is_triangle = false;
        }
        else 
        {
        set_name("Triangle"); 
        confirm_creation(); // Calls parent class method to confirm creation
        this->is_triangle = true; // sets is trinagle to true
        }
        // Sets the values of the 3 corners 
        this->point_1 = point_1;
        this->point_2 = point_2;
        this->point_3 = point_3;
    }

    // Overrides parent method, calculates and returns the area of a triangle
    double calculate_area()
    {
        if (is_triangle) // Checks if is_triangle is set to true, if so, calculates and returns area 
        {
            return 0.5 * abs(point_1.get_x() * (point_2.get_y() - point_3.get_y()) +
                         point_2.get_x() * (point_3.get_y() - point_1.get_y()) +
                         point_3.get_x() * (point_1.get_y() - point_2.get_y()));
        }
        else 
        {
            return Shape::calculate_area(); // Else, calls the parent function
        }
        
    }

    // Overrides parent method, calculates and returns the circumfrence of a triangle
    double calculate_circumfrence()
    {
        if (is_triangle) 
        {
        double p1_to_p2 = sqrt(pow((point_2.get_x() - point_1.get_x()), 2) + pow((point_2.get_y() - point_1.get_y()), 2));
        double p2_to_p3 = sqrt(pow((point_3.get_x() - point_2.get_x()), 2) + pow((point_3.get_y() - point_2.get_y()), 2));
        double p3_to_p1 = sqrt(pow((point_1.get_x() - point_3.get_x()), 2) + pow((point_1.get_y() - point_3.get_y()), 2));

        return p1_to_p2 + p2_to_p3 + p3_to_p1;
        }
        else
        {
            return Shape::calculate_circumfrence();
        }
    }

    // Overrides parent method, creates and displays the coordinates for a bounding box for a triangle
    void bounding_box()
    {
        if (is_triangle) // Checks if it's a triangle and then finds min and max x and y values 
        {                // to create a bounding box  
            int min_x = min(point_1.get_x(), min(point_2.get_x(), point_3.get_x()));
            int max_x = max(point_1.get_x(), max(point_2.get_x(), point_3.get_x()));
            int min_y = min(point_1.get_y(), min(point_2.get_y(), point_3.get_y()));
            int max_y = max(point_1.get_y(), max(point_2.get_y(), point_3.get_y()));

            // Displays the bounding box coordinates 
            cout << "\nTop Left: ";
            Point(min_x, max_y).show();
            cout << "Top Right: ";
            Point(max_x, max_y).show();
            cout << "Bottom Left: ";
            Point(min_x, min_y).show();
            cout << "Bottom Right: ";
            Point(max_x, min_y).show();
        }
        else
        {
            Shape::bounding_box(); // Calls parent method, if it's not a valid triangle
        }
    }

    // Overrides parent method by printing addition information store about the triangle class
    void display()
    {
        Shape::display(); // Calls parent method for display then prints additional stored information for triangle
        cout << "Point 1: ";
        point_1.show();
        cout << "Point 2: ";
        point_2.show();
        cout << "Point 3: ";
        point_3.show();
        cout << endl;
    }
};

/****************************************************************
 Rectangle extends Shape
*****************************************************************/
class Rectangle : public Shape
{
public:
    // Declaring variables
    Point point_1;
    Point point_2;
    Point point_3;
    Point point_4;
    int length;
    int width;
    int min_x;
    int min_y;
    int max_x;
    int max_y;

    Rectangle() // Default constructor
    {
        set_name("Rectangle");
        confirm_creation(); // From parent class, prints a confirmation message if the shape was created
    }

    // Rectangle construct overloads default constructor and takes 4 Points as parameters
    Rectangle(Point point_1, Point point_2, Point point_3, Point point_4)
    { 
        // Sets all the corner points of the shape
        this->point_1 = point_1;
        this->point_2 = point_2;
        this->point_3 = point_3;
        this->point_4 = point_4;

        if (!is_rectangle()) // checks if the coordinates form a rectangle, prints a message if they do not
        {
            cout << "The points entered do not form a rectangle." << endl;
        }
        else 
        {
            set_name("Rectangle"); // Sets the shape name to rectangle 
            confirm_creation(); // From parent class, prints a confirmation message if the shape was created
            if (is_square()) // if is rectangle returns true then it checks for is_square, if it returns true
            {                // the shape name is set to square and a confirmation message is printed
                set_name("Square");
                cout << "Special case of rectangle discovered.\n******Square******" << endl;
            }
        }
    }

    // Checks and returns if the coordinates form a rectangle 
    bool is_rectangle()
    {
        // Makes a set of all the x values 
        set<int> x_values;
        x_values.insert(point_1.get_x());
        x_values.insert(point_2.get_x());
        x_values.insert(point_3.get_x());
        x_values.insert(point_4.get_x());

        // Makes a set of all the y values
        set<int> y_values;
        y_values.insert(point_1.get_y());
        y_values.insert(point_2.get_y());
        y_values.insert(point_3.get_y());
        y_values.insert(point_4.get_y());

        this->min_x = *x_values.begin(); // Sets min_x equal to the first x value in the set
        this->max_x = *x_values.rbegin(); // Sets max_x equal to the last x value in the set
        this->length = max_x - min_x; // Sets length equal to larger x value minus smaller x value

        this->min_y = *y_values.begin(); // Sets min_y equal to the first y value in the set
        this->max_y = *y_values.rbegin(); // Sets max_y equal to the last y value in the set
        this->width = max_y - min_y; // Sets width equal to larger y value minus smaller y value

        // If there is not exactly 2 distinct x values or not exactly 2 distinct y values return false
        if (x_values.size() != 2 || y_values.size() != 2)
        {
            return false;
        }
        else
	{
            return true; // returns true if there are exactly 2 distinct x values and 2 distinct y values 
        }
    }

    // Checks and returns if the rectangle is a square shape
    bool is_square()
    {
        return length == width;
    }

    // Overrides parent method, calculates and returns the area of a rectangle
    double calculate_area()
    {
        if (is_rectangle()) // Checks if the shape is a rectangle, calculates and returns area if so
        {
            return length * width;
        }
        else
        {
            return Shape::calculate_area(); // Calls parent method for shape if not a rectangle
        }
    }

    // Overrides parent method, calculates and returns the circumfrence of a rectangle
    double calculate_circumfrence()
    {
        if (is_rectangle()) // If the shape is a rectangle, preform and return the calculation
        {
        return (2 * length) + (2 * width);
        }
        else
        {
            return Shape::calculate_circumfrence(); // Calls parent method for shape if not a rectangle
        }
    }

    // Overrides parent method, creates and displays the coordinates for a bounding box for a rectangle
    void bounding_box()
    {
        if (is_rectangle()) // Checks if the shape is a valid method if so, creates and displays a bounding box
       {
            cout << "\nTop Left: ";
            Point(min_x, max_y).show();
            cout << "Top Right: ";
            Point(max_x, max_y).show();
            cout << "Bottom Left: ";
            Point(min_x, min_y).show();
            cout << "Bottom Right: ";
            Point(max_x, min_y).show();
       }
       else 
       {
        Shape::bounding_box(); // Calls the parent method for bounding_box()
       }
    }

    // Overrides parent method by printing addition information store about the rectangle class
    void display()
    {
        Shape::display(); // Calls the parent method display
        if (is_rectangle()) // Checks if the shape is a rectangle and displays information accordingly
        {
            cout << "Length: " << length << "\n"
                 << "Width: " << width << endl;
        }
        cout << "Point 1: "; point_1.show();
        cout << "Point 2: "; point_2.show();
        cout << "Point 3: "; point_3.show();
        cout << "Point 4: "; point_4.show();
        cout << endl;
    }
};

/****************************************************************
 main
*****************************************************************/
int main()
{
    // Testing the shape display
    Shape shape;
    shape.display();

    // Radius variable created for program readability, testing a negative value 
    int radius = -2;
    // Creating circle
    Circle circle_1(Point(5, 5), radius);
    circle_1.display();

    // Creating triangle
    Triangle triangle_1(Point(3, 5), Point(5, 3), Point(1, 3));
    triangle_1.display();

    // Creating rectangle
    Rectangle rectangle_1(Point(3, 5), Point(8, 5), Point(3, 3), Point(8, 3));
    rectangle_1.display();

    // Changing the radius
    radius = 6;
    // Creating circle
    Circle circle_2(Point(2, 2), radius);
    circle_2.display();

    // Creating an invalid triangle
    Triangle triangle_2(Point(24, 5), Point(24, 5), Point(1, 3));
    triangle_2.display();

    // Creating square
    Rectangle rectangle_2(Point(10, 15), Point(15, 10), Point(10, 10), Point(15, 15));
    rectangle_2.display();

    // Changing the radius    
    radius = 12;
    // Creating circle
    Circle circle_3(Point(45, 1), radius);
    circle_3.display();

    // Creating triangle
    Triangle triangle_3(Point(0, 0), Point(-2, 3), Point(1, 3));
    triangle_3.display();

    // Creating non-rectangle 4 sided shape
    Rectangle rectangle_3(Point(12, 5), Point(32, 6), Point(4, 3), Point(8, 7));
    rectangle_3.display();

} ///:~
