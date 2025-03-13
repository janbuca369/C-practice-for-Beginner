#include <iostream>
// Every C++ Program should have main function.
// Every C++ program starts in main function and ends in main function


/*
  Write a C++ program a function named check that has three parameter
  The first parameter should accept an integer number,
  The second argument a floating-point number & the third parameter a double-precision number,
  The body of the function should just display the sum of values of data passed to the the function when it is called.
*/

using namespace std;

void check(int x, float y, double z);
void display(); // function declaration
void showResult();
float mul();
double area(double w, double h);


int main()
{
    int x=7;
    float y=5.5;
    double z =3.3;
    check(x, y,z);
    display(); // function call
    showResult();
    float p = mul();
    cout<<"The Multiplication of two number is: "<<p<<endl;
    double width, height;
    cout<<"Enter width \n";
    cin>>width;
    cout<<"Enter height \n";
    cin>>height;
    double a = area(width, height);
    cout<<"The Area  is :"<<a<<endl;

    return 0;
}

void display(){ // function definition
    cout<<"Hi Janbo"<<endl;
}

void showResult(){
    int x, y, sum;
    cout<<"Enter two number: \n";
    cin>>x>>y;
    sum = x+y;
    cout<<"The Sum is: "<<sum<<endl;
}

float mul(){
    float x, y, pro;
    cout<<"Enter two floating point numbers: \n";
    cin>>x>>y;
    pro = x*y;
    return pro; // I have successfully fished, or send

}

double area(double w, double h){
    double a;
    a = w*h;
    return a;
}


void check(int x, float y, double z){
    double sum = x+y+z;
    cout<<"Three parameter: "<<sum<<endl;
}
