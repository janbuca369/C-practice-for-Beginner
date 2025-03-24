#include <iostream>
#include <fstream>
// File Management
using namespace std;

int main()
{
    /*
    ofstream outFile;
    //outFile.open("janbuca2.txt", ios::out); //ios::out is overwrite
    outFile.open("janbuca2.txt", ios::app); // it text can be append
    outFile<<"Kefele Selam new by Mimo \n";
    outFile.close();
    */



    string x, z;
    char y, a;
    ifstream inFile1, inFile2, inFile3, inFile4, inFile5;
    inFile1.open("Mimo1.txt");
    inFile2.open("Mimo2.txt");
    inFile3.open("Mimo3.txt");
    inFile4.open("Mimo4.txt");
    inFile5.open("Mimo5.txt");

    inFile1>>y;
    cout<<"The read character is: "<<y<<endl;
    inFile2>>x;
    cout<<"The read word is: "<<x<<endl;
    getline(inFile3, z);
    cout<<"The read line is: "<<z<<endl;
    inFile4.get(a);
    cout<<"The read character is: "<<a<<endl;
    inFile1.close();
    inFile2.close();
    inFile3.close();
    inFile4.close();
    inFile5.close();







    return 0;
}
