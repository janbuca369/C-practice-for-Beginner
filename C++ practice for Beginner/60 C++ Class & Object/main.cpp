#include <iostream>

using namespace std;

class Hello{
public:
    void setName(string name){
        userName = name;
    }

    string getName(){
        return userName;
    }

    void display(){
        cout<<"Welcome, Mr/Mrs "<<getName()<<" Good bay again! \n";
    }

private:
    string userName;
};

int main()
{
    Hello h;
    string n;
    cout<<"My first user is "<<h.getName()<<endl;
    cout<<"Enter your name, Please \n";
    getline(cin, n);
    h.setName(n);
    h.display();
    return 0;
}
