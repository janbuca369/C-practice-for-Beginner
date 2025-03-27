#include <iostream>
// Contractor

using namespace std;

class Hello{
public:
    Hello (string name){
        setName (name);
    }

    void setName(string name){
        userName = name;
    }

    string getName(){
        return userName;
    }

    void display(string name){
        cout<<"Welcome, Mr/Mrs "<<getName()<<" from Janbuca \n";
    }
private:
    string userName;

};

int main()
{
    Hello h("Janbuca Teshome");
    Hello h1("Bill Gate!!");
    Hello h2("Professor Haile Gerima!");
    string n, n1, n2;
    cout<<"My first user is "<<h.getName()<<endl;
    cout<<"My Second user is "<<h1.getName()<<endl;
    cout<<"My three user is "<<h2.getName()<<endl;
    cout<<"Enter your name, Please \n";
    getline(cin, n);
    h.setName(n);
    h.display(n);

    cout<<"Enter another name, Please \n";
    getline(cin, n1);
    h1.setName(n1);
    h1.display(n1);

    cout<<"Enter another name, Please \n";
    getline(cin, n2);
    h2.setName(n2);
    h2.display(n2);
    return 0;
}
