#include <iostream>
// Identifiers, Variables, Data type & Constants
/*
    Identifiers
        - is a name given to any program element.
        - Only letters, digits and underlined characters are valid.
        - Should always begin with a letter or an underscore.
        - Key words should not be used as names for identifiers.

    Variables
        - is a reserved place in memory to store information in.
        - All variables have three important properties: Data type, name and value.
        - We can declare multiple variables at the same time.

    Data type
        - It is name given to a set of values which have common property.
        - ex. integer, float, char, boolean and so on.

    Constants
        - is any expression that has a fixed values.
        - In C++ two types of constant: literal and symbolic constants.
        - In C++ two ways to declare a symbolic constant: #define and the const.
*/

using namespace std;
#define a 9.8
int main(){


    float x = 15, y = 15, sum, area;
    const float z = 8.2;
    sum = x + z;
    area = a * x;


    cout << "The Addition of 15 and 15 is: "<<sum<< endl;
    cout << "The area is: "<<area<< endl;
    unsigned int num = -255; // it means don't accept negative value.
    cout <<num;
    return 0;
}

/*
    Fundamental DataType
    Type         Bytes      Ranges
    short        2          -32,768 to 32,767
    int          4          -2B to 2B
    long         4          same
    long long    8
    float        4
    double       8
    long double  8
    bool         1          true / false
    char         1

    Statically-Type       Dynamically-Type
    - C++                  - Python
    - C#                   - JavaScript
    - Java                 - Ruby


    Number System
    System                      Digits          Example
    Decimal (Base 10)           0-9             255
    Binary (Base 2)             0, 1            1111111
    Hexadecimal (Base 16)       0 - 9, A - F    FF

    RGB = Red Green Blue
          FF   00   00

*/
