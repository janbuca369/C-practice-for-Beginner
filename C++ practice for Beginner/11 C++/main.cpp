#include <iostream>

/*
    Write a C++ program which height and width of a rectangle and display area of a reactangle.
*/

using namespace std;
#define pi 3.14
int main()
{
    float h, w,r, areaRec, areaCir;
    cout << "Enter height of the rectangle "<<endl;
    cin>>h;
    cout << "Enter width of the rectangle "<<endl;
    cin>>w;
    areaRec = h * w;
    cout << "The Area of the rectangle is: "<<areaRec<<endl;

    cout << "Enter radius of a circle in"<<endl;
    cin>>r;
    areaRec = pi*r*r;
    cout << "The area of the Circles is: "<<areaCir<<endl;
    return 0;
}
