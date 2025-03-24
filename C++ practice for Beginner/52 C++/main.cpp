#include <iostream>
#include <fstream>
// Get() and put() stream pointers
// tellg() and tellp()
// seekg() and seekp()
using namespace std;

int main()
{
    long begin, end;
    ifstream myfile("example.txt");
    begin = myfile.tellg();
    myfile.seekg(0, ios::end);
    end = myfile.tellg();

    cout<<"Size is: "<<(end-begin)<<"bytes. \n";
    myfile.seekg(-4, ios::end);
    end = myfile.tellg();
    cout<<endl;
    myfile.close();
    return 0;
}
