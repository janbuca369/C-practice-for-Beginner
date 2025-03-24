#include <iostream>
#include <fstream>
#include <stdlib.h>
// Types of files
// If an error occurs during opening of a file, C++ does't create a valid file pointer (file object)
using namespace std;

int main()
{
    string x, z;
    char y, a;
    fstream outFile1;
    outFile1.open("abc.txt", ios::app);
    // fail(), bad(), eof(), good()
    if(outFile1.bad()){
        cerr<<"The file is not open!!! \n";
    }
    outFile1<<"Janbuca Teshome \n";
    outFile1.close();
    return 0;
}
