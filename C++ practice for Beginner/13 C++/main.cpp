#include <iostream>
/*
    Write a C++ program which reads a number and check if the number even or odd.
*/
using namespace std;

int main()
{
    int a;
    cout << "Enter any natural  number" << endl;
    cin>>a;
    if(a%2 == 0){
        cout << "The number is Even\n";
    }else{
        cout << "The number is Odd \n";
    }
    return 0;
}
