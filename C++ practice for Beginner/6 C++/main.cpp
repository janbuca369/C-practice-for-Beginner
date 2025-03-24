#include <iostream>
/*
    Logical operator (!, &&, ||).
*/
using namespace std;

int main()
{
    int a = 10, b = 11;
    cout << ((a != 10) || (5 == 5) )<< endl;
    cout << ((a != 10) && (5 == 5) )<< endl;
    cout << (!(a != 10) || (5 == 5) )<< endl;
    return 0;
}
