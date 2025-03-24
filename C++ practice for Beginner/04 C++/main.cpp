#include <iostream>
/*
    Operators
        - is a symbol that makes the machine to take an action.
        - C++ provides several categories of operators, including the following.
            - Assignment operator (=).
            - Arithmetic operator (+, -, *, /, %).
            - Relation Operator (==, !=, >, < <=, >=).
            - Logical operator (!, &&, ||).
            - Increment/decrement operator (--, ++).
            - Compound assignment operators (+=, -=, *=, /=)
            - Conditional operator (?:)
            - Comma operator
            - The size operator
            - Explicit type casting operators etc.
*/

using namespace std;

int main()
{
    int a = 11, b = 7, sum, sub, pro, div, rem;
    sum = a + b;
    sub = a - b;
    pro = a * b;
    div = a / b;
    rem = a % b;

    cout << "The Value of a is 11 and b is 7"<< endl;
    cout << "The Addition of a and b is: "<<sum<< endl;
    cout << "The Subtraction of a and b is: "<<sub<< endl;
    cout << "The Multiplcation of a and b is: "<<pro<< endl;
    cout << "The Divsion of a and b is: "<<div<< endl;
    cout << "The Reminder of a and b is: "<<rem<< endl;
    return 0;
}
