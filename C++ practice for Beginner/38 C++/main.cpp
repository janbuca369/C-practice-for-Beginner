#include <iostream>
// Pointers Operator Example
using namespace std;

int main()
{
    /*
    int *p1, v1;
    v1=0;
    p1=&v1; // v1 and *p1 now refer to the same variable
    *p1 = 35;
    cout<<v1<<endl;
    cout<<*p1<<endl;
    cout<<&v1<<endl;
    cout<<p1<<endl;
    */





    /*
    int val1 = 9, val2 = 25;
    int *myPointer;
    myPointer = &val1;
    *myPointer = 99;
    myPointer = &val2;
    *myPointer = 50;
    cout<<" Value-1 == "<<val1<<"\n Value-2 == "<<val2<<endl;
    */

    int va1 = 10, va2 = 29;
    int *p1, *p2;

    p1 = &va1;     // p1 = address pointer to va1
    p2 = &va2;     // p2 = address pointer to va2

    *p1 = 100;
    *p2 = *p1;     // Value pointed by p2 = Value pointed to p1

    p1 = p2;
    *p1 = 20;

    cout<<" The Value 1 = "<<va1<<"\n The value 2 = "<<va2<<endl;


    return 0;
}
