#include <iostream>
#include <fstream>
#include <stdlib.h>
// Opening Random-access files
using namespace std;

int main()
{


    /*
    ofstream outData;
    outData.open("abc.txt", ios::app | ios::binary);
    if(outData.fail()){
        cerr<<"\nError opening a file";
        exit(1);
    }
    int x;
    cout<<"\nEnter a number: ";
    cin>>x;
    outData.seekp(3);
    outData.write((char*) &x, sizeof(x));
    outData.close();
    cout<<"\nData has been saved";
    */



    int x;
    ifstream inData;
    inData.open("abc.txt", ios::in | ios::binary);
    if(inData.fail()){
        cerr<<"\nError opening a file";
        exit(1);
    }
    while(inData.read((char*) &x, sizeof(x)));
    cout<<x<<endl;
    inData.close();

    return 0;
}
