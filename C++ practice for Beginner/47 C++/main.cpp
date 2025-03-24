#include <iostream>
#include <fstream>
// File Management
using namespace std;

int main()
{
    /*ofstream outFile;
    outFile.open("janbuca.txt");
    outFile<<"Janbuca Selam new";
    outFile.close();
    */

   /* string x;
    ifstream inFile;
    inFile.open("abc.txt");
    inFile>>x;
    cout<<x<<endl;
    inFile.close();
    */


    string x, y, z;
    ifstream inFile;
    inFile.open("janbuca.txt");
    inFile>>x;
    cout<<x<<" ";
    inFile>>y;
    cout<<y<<" ";
    inFile>>z;
    cout<<z<<endl;
    inFile.close();


    return 0;
}
