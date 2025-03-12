#include <iostream>
/*
    Do while Loop
    do{
        process;
    }while(condition);
*/

using namespace std;

int main()
{
    //Write a C++ program and display number 1 up to 5.
    int i=1;
    do{
        cout<<i<<'\t';
        i++;
    }while(i<5);

    //Display a C++ program and display number 18 up to 2.
    int k=20;
    do{
        cout<<k<<'\n';
        k=k-2;
    }while(k>0);
    return 0;
}
