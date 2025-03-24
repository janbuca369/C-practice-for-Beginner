#include <iostream>
//String Representation and Manipulation

using namespace std;

int main()
{
    /*
    //Declaration of a string
    char s[10];

    //Initialization of Strings
    char s1[] = "Example";
    // it also
    //char s1[] = {"E", "x", "a", "m", "p", "l", "e"};
    */

    /*
    // Accessing Each characters of the String
    cout<<s1[0]<<endl;
    for(int i=0; i<=6; i++){
        cout<<s1[i]<<" ";
    }

    cout<<endl<<s1;
    */

    /*
    const int max=80;
    char str[max];

    cout<<"\n Enter a String: \n";
    cin.get(str, max); //max avoid buffer overflow
    cout<<"\n Your Entered: "<<str;
    */

    /*
    //Reading String from the Keybord
    char name[25], fatherName[25];
    cout<<"Enter name: \n";
    cin>>name<<endl;
    cout<<"Enter your father name: \n";
    cin>>fatherName<<endl;
    cout<<"The name entered was is: "<<name<<" "<<fatherName<<endl;
    */




    //Reading Multiple lines
    const int max=50;
    char str[max];
    cout<<"\nEnter a String: \n";
    cin.get(str, max, '0');  // terminates with $
    cout<<"\n Your Enter is: \n"<<str;







    return 0;
}
