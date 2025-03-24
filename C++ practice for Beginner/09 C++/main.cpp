#include <iostream>
/*
    Conditional operator (?:)
*/
using namespace std;

int main()
{
    double a = 8.9, b = 7.7, c;
    //c = (a < b) ? a:b;
    cout <<((a < b) ? a:b)<< endl;
    cout <<sizeof(char)<<endl;
    cout <<sizeof(int)<<endl;
    cout <<sizeof(float)<<endl;
    cout <<sizeof(double)<<endl;
    return 0;
}
