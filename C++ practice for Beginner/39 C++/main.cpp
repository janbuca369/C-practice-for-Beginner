#include <iostream>
// Arithmetic of Pointers
/*
    Only addition and subtraction operations are allowed to be conducted.
*/
using namespace std;

int main()
{
    /*char *myChar;
    short *myShort;
    int *myLong;
    long *x;
    double *y;

    cout<<myChar<<endl;
    cout<<myShort<<endl;
    cout<< myLong<<endl;
    cout<<x<<endl;
    cout<<y<<endl;

    myChar++;
    myShort++;
    myLong++;
    x++;
    y++;
    cout<<endl<<endl<<endl;
    cout<<myChar<<endl;
    cout<<myShort<<endl;
    cout<< myLong<<endl;
    cout<<x<<endl;
    cout<<y<<endl;
    */


    /*
    int x, *p1, *p2, *p3;
    p1=&x;
    p2=p1--;
    p2=--p1;

    cout<<p1<<endl<<p2<<endl<<p3<<endl<<x<<endl;
    */

    float x = 9, *p;
    p=&x;
    cout<<p<<endl;
    p=p-3;
    cout<<p<<endl;


    return 0;
}
