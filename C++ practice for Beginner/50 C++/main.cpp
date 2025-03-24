#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;
ofstream fp;
int main()
{
    /*
    fp.open("D:\My Project\C++ practice for Beginner\49 C++", ios::out);
    if(fp.fail()){
        cerr<<"\n Error opening file";
        //getch();
        exit(1);
    }
    fp<<"My team is out of the game"<<endl;
    fp<<"I don't like the tournament"<<endl;
    fp.close();
    */

    char c;
    ofstream outFile2;
    outFile2.open("D:\My Project\C++ practice for Beginner\49 C++\text.txt", ios::out);
    if(outFile2.fail()){
        cerr<<"\n Error opening text.txt";
        exit(1);
    }
    for(int i=1; i<5; i++){
        cout<<"\n Enter a character: ";
        cin>>c;
        outFile2.put(c);
    }
    outFile2.close();

    return 0;
}
