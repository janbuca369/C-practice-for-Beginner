#include <iostream>

using namespace std;

int main()
{
    // A palindrome is a sequence of characters that reads the same backward or forward like 12321, 5555, 45554, 11611
    // Write a program which accepts a string and dispaly the number of characters contained in the string. E.g if the string "Wel come".
    // Write a program which that reads a string and display the number of vowels in the string and their number of occurrences.

    string line = "Short line for testing";
    string s1;
    s1 = "Hi guys";
    cout<<"s1 is: "<<s1<<endl;
    string s2 (s1);
    cout<<"s2 is: "<<s2<<endl;
    string s3(line);
    cout<<"s3 is: "<<s3<<endl;
    string s4 (line, 10);
    cout<<"s4 is: "<<s4<<endl;
    //copy word 'line' from s3

    return 0;
}
