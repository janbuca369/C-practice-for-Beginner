#include <iostream>
/*
    Some Loop Practices.
*/

using namespace std;

int main()
{
    // 1. Write a C++ Program to print all natural number from 1 to n. using while loop.
    int n;
    cout<<"Enter a Natural number"<<endl;
    cin>>n;

    int j=1;
    while(j<=n){
        cout<<j<<'\t';
        j++;
    }
    cout<<endl;

    // 2. Write a C++ program to print all natural number reverse from n to 1.
    int c;
    cout<<"Enter a Natural number"<<endl;
    cin>>c;

    int k=c;
    while(k>=1){
        cout<<k<<'\t';
        k--;
    }
    cout<<endl;

    // 3. Write a C++ program to print all alphabets from a to z, using while loop.
    for(char ch='a'; ch<='z'; ch++){
        cout<<ch<<'\t';
    }
    cout<<endl;

    // 4. Write a C++ program to print all even number between 1 to 100, using while loop.
    for(int i=2; i<=100; i=i+2){
        cout<<i<<'\t';
    }
    cout<<endl;
    // 5. write a C++ program to print all odd number between 1 up to 100.
    for(int i=1; i<100; i++){
        if(i%2 != 0){
            cout<<i<<'\t';
        }
    }
    // 6. write a C++ program to find sum of all natural number between 1 up to n.
    // 7. Write a C++ program to find sum of all even numbers between 1 up to n.
    // 8. write a C++ program to find sum of all odd numbers between 1 up to n.

    return 0;
}
