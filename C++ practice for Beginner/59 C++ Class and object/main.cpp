#include <iostream>
// Class and Object
using namespace std;

class Hello{
public:
    void display(){
        cout<<"Hello Ali, Your are the Greatest man in boxing \n";
    }

    void display1(string name){
        cout<<"Welcome, Mr/Mrs "<<name<<" Good Bay!! \n";
    }
};

int main()
{
    Hello h;
    string n;
    h.display();
    cout<<"Enter your name, Please \n";
    getline(cin,n);
    h.display1(n);
    return 0;
}
