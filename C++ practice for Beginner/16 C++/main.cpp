#include <iostream>

/*
    While Loop
    while(Condition){
        process;
    }
*/

using namespace std;

int main()
{
    //Write a C++ program display number starting from 15 and adding 5. up to 60.
    int j=15;
    while(j<=60){
        cout<<j<<" ";
        j=j+5;
    }

    //Write a C++ Program display 55, 53, 51, 49, 47.
    int n=55;
    while(n>=47){
        cout<<n<<endl;
        n=n-2;
    }
    return 0;
}
