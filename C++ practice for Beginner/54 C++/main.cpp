#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

struct account {
    int accNo;
    char name[50];
    int deposit;
    char type;
    string address;
    string phone;
    time_t creationDate;
};

void write_account();
void display_all();
void display_sp(int);
void modify_account(int);
void delete_account(int);
void deposit_withdraw(int, int);
void intro();
void account_statement(int);
void search_by_name(const string&);
void calculate_interest();

account ac;

int main() {
    system("color 7D");
    char ch;
    int num;
    string name;
    intro();
    system("cls");

    do {
        cout << "\n\n\n\tMAIN MENU";
        cout << "\n\n\t1. NEW ACCOUNT";
        cout << "\n\n\t2. DEPOSIT AMOUNT";
        cout << "\n\n\t3. WITHDRAW AMOUNT";
        cout << "\n\n\t4. BALANCE ENQUIRY";
        cout << "\n\n\t5. ALL ACCOUNT HOLDER LIST";
        cout << "\n\n\t6. CLOSE AN ACCOUNT";
        cout << "\n\n\t7. MODIFY AN ACCOUNT";
        cout << "\n\n\t8. ACCOUNT STATEMENT";
        cout << "\n\n\t9. SEARCH BY NAME";
        cout << "\n\n\t10. CALCULATE INTEREST";
        cout << "\n\n\t11. EXIT";
        cout << "\n\n\tSelect your option (1-11): ";
        cin >> ch;

        switch(ch) {
            case '1':
                write_account();
                break;
            case '2':
                cout << "\n\n\tEnter the account No. : ";
                cin >> num;
                deposit_withdraw(num, 1);
                break;
            case '3':
                cout << "\n\n\tEnter the account No. : ";
                cin >> num;
                deposit_withdraw(num, 2);
                break;
            case '4':
                cout << "\n\n\tEnter the account No. : ";
                cin >> num;
                display_sp(num);
                break;
            case '5':
                display_all();
                break;
            case '6':
                cout << "\n\n\tEnter the account No. : ";
                cin >> num;
                delete_account(num);
                break;
            case '7':
                cout << "\n\n\tEnter the account No. : ";
                cin >> num;
                modify_account(num);
                break;
            case '8':
                cout << "\n\n\tEnter the account No. : ";
                cin >> num;
                account_statement(num);
                break;
            case '9':
                cout << "\n\n\tEnter the name to search: ";
                cin.ignore();
                getline(cin, name);
                search_by_name(name);
                break;
            case '10':
                calculate_interest();
                break;
            case '11':
                cout << "\n\n\tThanks for using bank management system";
                break;
            default:
                cout << "\a";
        }

        cin.ignore();
        cin.get();
        system("cls");
    } while(ch != '11');

    return 0;
}

void write_account() {
    account ac;
    ofstream outFile;
    outFile.open("account.dat", ios::binary | ios::app);

    cout << "\nEnter the account No. : ";
    cin >> ac.accNo;

    cout << "\n\nEnter the Name of the account Holder : ";
    cin.ignore();
    cin.getline(ac.name, 50);

    cout << "\nEnter address: ";
    getline(cin, ac.address);

    cout << "\nEnter phone number: ";
    getline(cin, ac.phone);

    cout << "\nEnter type of the account (C/S) : ";
    cin >> ac.type;
    ac.type = toupper(ac.type);

    cout << "\nEnter the initial amount (>=500 for saving and >=1000 for current) : ";
    cin >> ac.deposit;

    ac.creationDate = time(nullptr);

    cout << "\n\n\nAccount Created..";
    outFile.write(reinterpret_cast<char *>(&ac), sizeof(account));
    outFile.close();
}

void deposit_withdraw(int n, int option) {
    int amt;
    bool found = false;
    account ac;
    fstream File;

    File.open("account.dat", ios::binary | ios::in | ios::out);
    if (!File) {
        cout << "File could not be opened! Press any Key...";
        return;
    }

    while (File.read(reinterpret_cast<char *>(&ac), sizeof(account)) && !found) {
        if (ac.accNo == n) {
            cout << "\nAccount No. : " << ac.accNo;
            cout << "\nAccount Holder Name : " << ac.name;
            cout << "\nType of Account : " << ac.type;
            cout << "\nBalance amount : " << ac.deposit << endl << endl;

            if (option == 1) {
                cout << "\n\n\tTO DEPOSIT AMOUNT";
                cout << "\n\nEnter the amount to be deposited: ";
                cin >> amt;
                ac.deposit += amt;
            } else if (option == 2) {
                cout << "\n\n\tTO WITHDRAW AMOUNT";
                cout << "\n\nEnter the amount to be withdrawn: ";
                cin >> amt;
                int bal = ac.deposit - amt;
                if ((bal < 500 && ac.type == 'S') || (bal < 1000 && ac.type == 'C')) {
                    cout << "Insufficient balance";
                } else {
                    ac.deposit -= amt;
                }
            }

            int pos = (-1) * static_cast<int>(sizeof(ac));
            File.seekp(pos, ios::cur);
            File.write(reinterpret_cast<char *>(&ac), sizeof(account));
            cout << "\n\n\tRecord Updated";
            found = true;
        }
    }

    File.close();
    if (!found) {
        cout << "\n\nRecord not found";
    }
}

void display_sp(int n) {
    account ac;
    bool flag = false;
    ifstream inFile;

    inFile.open("account.dat", ios::binary);
    if (!inFile) {
        cout << "File could not be opened! Press any key...";
        return;
    }

    cout << "\nBALANCE DETAILS\n";
    while (inFile.read(reinterpret_cast<char *>(&ac), sizeof(account))) {
        if (ac.accNo == n) {
            cout << "\nAccount No. : " << ac.accNo;
            cout << "\nAccount Holder Name : " << ac.name;
            cout << "\nAddress : " << ac.address;
            cout << "\nPhone : " << ac.phone;
            cout << "\nType of Account : " << ac.type;
            cout << "\nBalance amount : " << ac.deposit;
            cout << "\nAccount created on : " << ctime(&ac.creationDate);
            flag = true;
        }
    }

    inFile.close();
    if (!flag) {
        cout << "\n\nAccount number doesn't exist";
    }
}

void display_all() {
    account ac;
    ifstream inFile;

    inFile.open("account.dat", ios::binary);
    if (!inFile) {
        cout << "File could not be opened! Press any key...";
        return;
    }

    cout << "\n\n\tACCOUNT HOLDER LIST\n\n";
    cout << "====================================================================================\n";
    cout << "A/c No.      Name           Address        Phone        Type    Balance    Created On\n";
    cout << "====================================================================================\n";

    while (inFile.read(reinterpret_cast<char *>(&ac), sizeof(account))) {
        cout << ac.accNo << setw(15) << ac.name << setw(15) << ac.address.substr(0, 10)
             << setw(15) << ac.phone << setw(8) << ac.type << setw(10) << ac.deposit
             << setw(20) << ctime(&ac.creationDate);
    }

    inFile.close();
}

void delete_account(int n) {
    account ac;
    ifstream inFile;
    ofstream outFile;

    inFile.open("account.dat", ios::binary);
    if (!inFile) {
        cout << "File could not be opened! Press any key...";
        return;
    }

    outFile.open("Temp.dat", ios::binary);
    inFile.seekg(0, ios::beg);

    while (inFile.read(reinterpret_cast<char *>(&ac), sizeof(account))) {
        if (ac.accNo != n) {
            outFile.write(reinterpret_cast<char *>(&ac), sizeof(account));
        }
    }

    inFile.close();
    outFile.close();
    remove("account.dat");
    rename("Temp.dat", "account.dat");
    cout << "\n\n\tRecord Deleted...";
}

void modify_account(int n) {
    bool found = false;
    account ac;
    fstream File;

    File.open("account.dat", ios::binary | ios::in | ios::out);
    if (!File) {
        cout << "File could not be opened! Press any Key...";
        return;
    }

    while (File.read(reinterpret_cast<char *>(&ac), sizeof(account)) && !found) {
        if (ac.accNo == n) {
            cout << "\nAccount No. : " << ac.accNo;
            cout << "\nAccount Holder Name : " << ac.name;
            cout << "\nType of Account : " << ac.type;
            cout << "\nBalance amount : " << ac.deposit << endl << endl;

            cout << "\n\nEnter the new Details of account\n";
            cout << "\nModify Account Holder Name : ";
            cin.ignore();
            cin.getline(ac.name, 50);

            cout << "\nModify Address: ";
            getline(cin, ac.address);

            cout << "\nModify Phone: ";
            getline(cin, ac.phone);

            cout << "\nModify Type of Account : ";
            cin >> ac.type;
            ac.type = toupper(ac.type);

            cout << "\nModify Balance amount : ";
            cin >> ac.deposit;

            int pos = (-1) * static_cast<int>(sizeof(account));
            File.seekp(pos, ios::cur);
            File.write(reinterpret_cast<char *>(&ac), sizeof(account));
            cout << "\n\n\tRecord Updated";
            found = true;
        }
    }

    File.close();
    if (!found) {
        cout << "\n\nRecord Not Found";
    }
}

void account_statement(int n) {
    account ac;
    bool flag = false;
    ifstream inFile;

    inFile.open("account.dat", ios::binary);
    if (!inFile) {
        cout << "File could not be opened! Press any key...";
        return;
    }

    cout << "\nACCOUNT STATEMENT\n";
    cout << "----------------------------------------------------------------\n";

    while (inFile.read(reinterpret_cast<char *>(&ac), sizeof(account))) {
        if (ac.accNo == n) {
            cout << "Account No.      : " << ac.accNo << endl;
            cout << "Holder Name      : " << ac.name << endl;
            cout << "Address          : " << ac.address << endl;
            cout << "Phone            : " << ac.phone << endl;
            cout << "Account Type     : " << ac.type << endl;
            cout << "Current Balance  : " << ac.deposit << endl;
            cout << "Account Created  : " << ctime(&ac.creationDate);
            cout << "Last Transaction : " << ctime(&ac.creationDate) << endl; // In real app, would have transaction history
            flag = true;
        }
    }

    inFile.close();
    if (!flag) {
        cout << "\n\nAccount number doesn't exist";
    }
}

void search_by_name(const string& name) {
    account ac;
    bool found = false;
    ifstream inFile;

    inFile.open("account.dat", ios::binary);
    if (!inFile) {
        cout << "File could not be opened! Press any key...";
        return;
    }

    cout << "\nSEARCH RESULTS\n";
    cout << "----------------------------------------------------------------\n";

    while (inFile.read(reinterpret_cast<char *>(&ac), sizeof(account))) {
        if (string(ac.name).find(name) != string::npos) {
            cout << "Account No. : " << ac.accNo << endl;
            cout << "Name        : " << ac.name << endl;
            cout << "Address     : " << ac.address << endl;
            cout << "Phone       : " << ac.phone << endl;
            cout << "Type        : " << ac.type << endl;
            cout << "Balance     : " << ac.deposit << endl;
            cout << "Created On  : " << ctime(&ac.creationDate) << endl;
            cout << "----------------------------------------------------------------\n";
            found = true;
        }
    }

    inFile.close();
    if (!found) {
        cout << "No accounts found with that name.\n";
    }
}

void calculate_interest() {
    account ac;
    ifstream inFile;
    time_t now = time(nullptr);
    double interest;

    inFile.open("account.dat", ios::binary);
    if (!inFile) {
        cout << "File could not be opened! Press any key...";
        return;
    }

    cout << "\nINTEREST CALCULATION\n";
    cout << "----------------------------------------------------------------\n";

    while (inFile.read(reinterpret_cast<char *>(&ac), sizeof(account))) {
        double years = difftime(now, ac.creationDate) / (60 * 60 * 24 * 365.25);
        if (ac.type == 'S') {
            interest = ac.deposit * years * 0.04; // 4% for savings
        } else {
            interest = ac.deposit * years * 0.02; // 2% for current
        }

        cout << "Account No. : " << ac.accNo << endl;
        cout << "Name        : " << ac.name << endl;
        cout << "Account Age : " << fixed << setprecision(1) << years << " years" << endl;
        cout << "Balance     : " << ac.deposit << endl;
        cout << "Interest    : " << fixed << setprecision(2) << interest << endl;
        cout << "----------------------------------------------------------------\n";
    }

    inFile.close();
}

void intro() {
    cout << "**********************************************************\n";
    cout << "\n->\tBank Management System\n->";
    cout << "\tDeveloped by Janbuca Teshome\n->";
    cout << "\tVersion 2.0 with enhanced features\n->";
    cout << "\tStay tuned for more updates!\n\n";
    cout << "**********************************************************\n";
    cout << endl;
    cout << "\tPress any key to get started!!!!";
    cin.get();
}
