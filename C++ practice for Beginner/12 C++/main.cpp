#include <iostream>
/*
    Write a C++ program which reads two numbers and display the larger.
*/
using namespace std;

int main()
{
    int x, y;
    cout << "Enter two number" << endl;
    cin>>x>>y;
    if(x>y){
        cout << "The  number is greater \n";
    }else if(x<y){
        cout << "The  number is Less than \n";
    }else {
        cout << "The  number and the second can be Equal";
    }
    return 0;
}
