#include <iostream>

using namespace std;

class Hello{
public:
    void setName(string name);
    string getName();
    void disply();

private:
    string userName;
};

void Hello::setName(string name){
    userName = name;
}

string Hello::getName(){
    return userName;
}

void Hello::disply(){
    cout<<"Welcome, Mr/Mrs "<<getName()<<" Good Bay! \n";
}


int main()
{
    Hello h;
    string n;
    cout<<"My first user is "<<h.getName()<<endl;
    cout<<"Enter your name, Please \n";
    getline(cin, n);
    h.setName(n);
    h.disply();
    return 0;
}
