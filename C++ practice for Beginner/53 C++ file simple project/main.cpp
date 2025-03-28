#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
using namespace std;

struct account {
    int accNo;
    char name[50];
    int deposit;
    char type;
};

    void write_account();
    void display_all();
    void display_sp(int);
    void moify_account(int);
    void delete_account(int);
    void deposit_withdraw(int, int);
    void intr();

account ac;

int main(){
    system("color 7D");
    char ch;
    int num;
    intr();
    system("cls");

    do{
       cout<<"\n\n\n\tMAIN MENU";
       cout<<"\n\n\t 1. NEW ACCOUNT";
       cout<<"\n\n\t 2. DEPOSIT AMOUNT";
       cout<<"\n\n\t 3. WITHDRAW AMOUNT";
       cout<<"\n\n\t 4. BALANCE ENQUIRY";
       cout<<"\n\n\t 5. ALL ACCOUNT HOLDER LIST";
       cout<<"\n\n\t 6. CLOSE AN ACCOUNT";
       cout<<"\n\n\t 7. MODIFY AN ACCOUNT";
       cout<<"\n\n\t 8. EXIT";
       cout<<"\n\n\t Select your option(1-8)" ;
       cin>>ch;

       switch(ch){
       case '1':
            write_account();
        break;

       case '2':
            cout<<"\n\n\tEnter the account No. : ";
            cin>>num;
            deposit_withdraw(num, 1);
        break;

       case '3':
            cout<<"\n\n\tEnter the account No. : ";
            cin>>num;
            deposit_withdraw(num, 2);
        break;

       case '4':
            cout<<"\n\n\tEnter the account No. : ";
            cin>>num;
            display_sp(num);
        break;

       case '5':
            display_all();
        break;

       case '6':
            cout<<"\n\n\tEnter the account No. :";
            cin>>num;
            delete_account(num);
        break;

       case '7':
            cout<<"\n\n\tEnter the account No. :";
            cin>>num;
            moify_account(num);
        break;

       case '8':
            cout<<"\n\n\tThanks for using bank management system";
        break;

       default:
        cout<<"\a\a\a\a\a\a\a";

       }

       cin.ignore();
       cin.get();
    }while(ch!= '8');

    return 0;
}

//__________Function to write in file __________
void write_account(){
    account ac;
    ofstream outFile;
    outFile.open("accountedl.dat", ios::binary|ios::app);
    cout<<"\nEnter the account No. : ";
    cin>>ac.accNo;
    cout<<"\n\nEnter the Name of the account Holder : ";
    cin.ignore();
    cin.getline(ac.name,50);
    cout<<"\nEnter type of the account (C/S) : ";
    cin>>ac.type;
    ac.type = toupper(ac.type);
    cout<<"\nEnter the initial amount(>=500 for saving and >=1000 for current) : ";
    cin>>ac.deposit;
    cout<<"\n\n\nAccount Created.. \n";
    cout<<"\tPress my key to get Started!!!";
    outFile.write(reinterpret_cast<char *> (&ac), sizeof(account));
    outFile.close();
}

// ________ deposit_withdraw(num, 1) _________
void deposit_withdraw(int n, int option){
    int amt;
    bool found = false;
    account ac;
    fstream File;
    File.open("accountedl.dat", ios::binary|ios::in|ios::out);
    if(!File){
        cout<<"File could not be open !! Press any Key...";
        return;
    }
    while(!File.eof() && found == false){
        File.read(reinterpret_cast<char *> (&ac), sizeof(account));
        if(ac.accNo == n){
            cout<<"\nAccount No. : "<<ac.accNo;
            cout<<"\nAccount Holder Name : ";
            cout<<ac.name;
            cout<<"\nType of Account : "<<ac.type;
            cout<<"\nBalance amount  : "<<ac.deposit<<endl<<endl;

            if(option == 1){
               cout<<"\n\n\tTO DEPOSITE AMOUNT ";
               cout<<"\n\nEnter the amount to be deposited : ";
               cin>>amt;
               ac.deposit+=amt;
            }
            if(option == 2){
               cout<<"\n\n\t To WITHDRAW AMOUNT ";
               cout<<"\n\nEnter the amount to be withdraw ";
               cin>>amt;
               int bal = ac.deposit - amt;
               if(bal < 500 && ac.type == 'S' || (bal < 1000 && ac.type == 'C')){
                cout<<"Insufficiencey balance ";
               }else{
                   ac.deposit -=amt;
               }
            }
            int pos = (-1)*static_cast<int>(sizeof(ac));
            File.seekp(pos, ios::cur);
            File.write(reinterpret_cast<char *> (&ac), sizeof(account));
            cout<<"\n\n\tRecord upDated";
            found=true;
        }
    }
    File.close();
    if(!found == false){
        cout<<"\n\nRecored not found ";
    }
}


//______________  display_sp(num); ___________
void display_sp(int n){

    account ac;
    bool flage = false;
    ifstream inFile;
    inFile.open("accountedl.dat", ios::binary);
    if(!inFile){
        cout<<"File could not be open !! Press any key...";
        return;
    }
    cout<<"\nBALANCE DETAILS \n";
    while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(account))){
        if(ac.accNo == n){
            cout<<"\nAccount No. : "<<ac.accNo;
            cout<<"\nAccount Holder Name : ";
            cout<<ac.name;
            cout<<"\nType of Account : "<<ac.type;
            cout<<"\nBalance amount :"<<ac.deposit;
            flage=true;
            cout<<"\nPress any key to get started !!!";
        }
    }
    inFile.close();
    if(flage == false){
        cout<<"\n\nAccount number don't exist";
        cout<<"\tPress any key to get Started!!!";
    }

}

//********** display_all() *********
void display_all(){
    account ac;
    ifstream inFile;
    inFile.open("accountedl.dat", ios::binary);
    if(!inFile){
        cout<<"File could not be open !! Press any key... ";
        return;
    }
    cout<<"\n\n\tACCOUNT HOLDER LIST \n\n";
    cout<<"===================================================================\n*";
    cout<<"A/c No.                  Name                Type         Balance   \n";
    cout<<"==================================================================== \n*";
    while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(account))){
        cout<<ac.accNo<<setw(10)<< " "<<ac.name<<setw(10)<<" "<<ac.type<<setw(6)<<ac.deposit<<endl;
    }
    inFile.close();
}


void delete_account(int n){
    account ac;
    ifstream inFile;
    ofstream outFile;
    inFile.open("accountedl.dat", ios::binary);
    if(!inFile){
        cout<<"File could not be open !! Press any key...";
        return;
    }
    outFile.open("Tempedl.dat", ios::binary);
    inFile.seekg(0, ios::beg);
    while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(account))){
        if(ac.accNo != n){
            outFile.write(reinterpret_cast<char *> (&ac), sizeof(account));
        }
    }
    inFile.close();
    outFile.close();
    remove("accountedl.dat");
    rename("Tempedl.dat", "accountedl.dat");
    cout<<"\n\n\tRecord Deleted...";
    cout<<"*\nPress any key to get started !!!*";

}

void moify_account(int n){
    bool found = false;
    account ac;
    fstream File;
    File.open("accountedl.dat", ios::binary|ios::in|ios::out);
    if(!File){
        cout<<"File could not be open !! Press any Key...";
        return;
    }

    while(!File.eof() && found == false){
        File.open(reinterpret_cast <char *> (&ac), sizeof(account));
        if(ac.accNo == n){
            cout<<"\nAccount No. : "<<ac.accNo;
            cout<<"\nAccount Holder Name : ";
            cout<<ac.name;
            cout<<"\nType of Account : "<<ac.type;
            cout<<"\nBalance amount : "<<ac.deposit<<endl<<endl;

            cout<<"\n\nEnter the new Details of account\n";
            cout<<"\nAccount No. : "<<ac.accNo;
            cout<<"'nModify Account Holder Name : ";
            cin>>ignore();
            cin>>getline(ac.name,50);
            cout<<"\nModify Type of Account : ";
            cin>>ac.type;
            ac.type = toupper(ac.type);
            cout<<"\nModify Balance amount : ";
            cin>>ac.deposit;
            int pos = (-1)*static_cast<int> (sizeof(account));
            File.seekp(pos,ios::cur);
            File.write(reinterpret_cast<char *> (&ac), sizeof(account));
            cout<<"\n\n\tRecord UpDated";
            found = true;
            cout<<"*\tPress any key to get started!!";
        }
    }
    File.close();
    if(found == false){
        count<<"\n\nRecord Not Found";
    }
}


 void intr(){
    cout<<"**********************************************************\n";
    cout<<"\n->\tThis is from Programmer Janbuca teshome\t\t  \n->";
    cout<<"\tPlease, subscribe if you want to get more project      \n->";
    cout<<"\tWe are always here to help you get more knowledge       \n->";
    cout<<"\tStay tuned with us!!                                     \n\n";
    cout<<"**********************************************************\n";
    cout<<endl;
    cout<<"\tPress any key to get started!!!!";
    cin.get();
 }
