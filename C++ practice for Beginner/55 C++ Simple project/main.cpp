#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <iomanip>
#include <limits>
#include <conio.h> // For password masking
using namespace std;

const int MAX_CAPACITY = 2300;

struct Student {
    int Id, age, grade;
    char name[50], gender, department[20], phone[10], email[50], bank;
    double price, paid;
};

vector<Student> students;
int studentCount = 0;

// Function prototypes
void clearScreen();
void displayHeader();
int getValidAge();
int generateId();
void studentRegistration();
void viewAllStudents();
void searchStudentById();
void registerUser();
void loginUser();
void adminMenu();
void studentMenu();
void mainMenu();
string maskPassword();

// Utility functions
void clearScreen() {
    system("cls");
}

void displayHeader() {
    cout << "\033[1;36m"; // Cyan color
    cout << "\n*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*\n";
    cout << "*               UNITY UNIVERSITY REGISTRATION SYSTEM           *\n";
    cout << "*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*\n";
    cout << "\033[0m"; // Reset color
}

int getValidAge() {
    int age;
    while (true) {
        cout << "Enter student's age (18-60): ";
        cin >> age;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\033[1;31mInvalid input. Please enter a number.\033[0m\n";
            continue;
        }

        if (age < 18) {
            cout << "\033[1;31mStudent's age must be above 18\033[0m\n";
        } else if (age > 60) {
            cout << "\033[1;31mStudent's age must be below 60\033[0m\n";
        } else {
            cin.ignore(); // Clear the input buffer
            return age;
        }
    }
}

int generateId() {
    int currentId = 0;
    ifstream file("Id_file.txt");

    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            currentId++;
        }
        file.close();
    }

    int newId = currentId + 1;

    ofstream outfile("Id_file.txt", ios::app);
    outfile << newId << endl;
    outfile.close();

    return newId;
}

string maskPassword() {
    string password;
    char ch;
    while ((ch = _getch()) != '\r') { // Until Enter is pressed
        if (ch == '\b') { // Handle backspace
            if (!password.empty()) {
                cout << "\b \b";
                password.pop_back();
            }
        } else {
            cout << '*';
            password += ch;
        }
    }
    cout << endl;
    return password;
}

void studentRegistration() {
    if (studentCount >= MAX_CAPACITY) {
        cout << "\033[1;31mSorry, the university has reached its maximum capacity of "
             << MAX_CAPACITY << " students. No more registrations allowed.\033[0m\n";
        return;
    }

    Student student;

    displayHeader();
    cout << "\n\033[1;33mSTUDENT REGISTRATION\033[0m\n\n";

    // Get student name
    cout << "Enter student's full name: ";
    cin.getline(student.name, 50);

    // Get valid age
    student.age = getValidAge();

    // Get valid gender
    while (true) {
        cout << "Enter student's gender (M/F): ";
        cin >> student.gender;
        student.gender = toupper(student.gender);
        if (student.gender == 'M' || student.gender == 'F') {
            break;
        }
        cout << "\033[1;31mInvalid input. Please enter 'M' or 'F'.\033[0m\n";
    }

    // Get department
    while (true) {
        cout << "\nDepartments Available:\n";
        cout << "1. Computer Science\n";
        cout << "2. Accounting\n";
        cout << "3. Nursing\n";
        cout << "4. Management\n";
        cout << "Select department (1-4): ";

        int choice;
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\033[1;31mInvalid input. Please enter a number.\033[0m\n";
            continue;
        }

        switch(choice) {
            case 1:
                strcpy(student.department, "Computer Science");
                student.price = 7200.0;
                break;
            case 2:
                strcpy(student.department, "Accounting");
                student.price = 6900.0;
                break;
            case 3:
                strcpy(student.department, "Nursing");
                student.price = 7150.0;
                break;
            case 4:
                strcpy(student.department, "Management");
                student.price = 5200.0;
                break;
            default:
                cout << "\033[1;31mInvalid choice. Please try again.\033[0m\n";
                continue;
        }
        break;
    }

    cout << "\nDepartment price per semester: \033[1;32m" << student.price << " ETB\033[0m\n";

    // Payment processing
    cout << "\nPayment Options:\n";
    cout << "1. Commercial Bank of Ethiopia\n";
    cout << "2. Bank of Abyssinia\n";
    cout << "Select bank (1-2): ";

    int bankChoice;
    cin >> bankChoice;

    if (bankChoice != 1 && bankChoice != 2) {
        cout << "\033[1;31mInvalid bank selection. Registration cancelled.\033[0m\n";
        return;
    }

    // Get account numbers
    string studentAccount, universityAccount;
    cout << "Enter student's account number (13 digits): ";
    cin >> studentAccount;
    while (studentAccount.length() != 13) {
        cout << "\033[1;31mAccount number must be exactly 13 digits. Try again: \033[0m";
        cin >> studentAccount;
    }

    cout << "Enter university account number (13 digits): ";
    cin >> universityAccount;
    while (universityAccount.length() != 13) {
        cout << "\033[1;31mAccount number must be exactly 13 digits. Try again: \033[0m";
        cin >> universityAccount;
    }

    // Get payment amount
    cout << "Enter payment amount: ";
    cin >> student.paid;

    if (student.paid != student.price) {
        cout << "\033[1;31mPayment amount must match the department price. Registration cancelled.\033[0m\n";
        return;
    }

    // Get matric result
    cout << "Enter student's matric result (350-700): ";
    cin >> student.grade;

    if (student.grade < 350 || student.grade > 700) {
        cout << "\033[1;31mSorry, your matric result is not sufficient for admission.\033[0m\n";
        return;
    }

    // Get phone number
    cout << "Enter student's phone number (+251): ";
    cin >> student.phone;
    while (strlen(student.phone) != 9) {
        cout << "\033[1;31mPhone number must be 9 digits (excluding +251). Try again: \033[0m";
        cin >> student.phone;
    }

    // Get email
    cout << "Enter student's email address: ";
    cin >> student.email;

    // Generate ID and save record
    student.Id = generateId();

    ofstream file("students.txt", ios::app);
    if (file.is_open()) {
        file << "UU" << student.Id << "|" << student.name << "|" << student.age << "|"
             << student.gender << "|" << student.department << "|" << student.phone
             << "|" << student.email << "|" << student.price << endl;
        file.close();
    }

    cout << "\n\033[1;32mREGISTRATION SUCCESSFUL!\033[0m\n";
    cout << "Student ID: \033[1;33mUU" << student.Id << "\033[0m\n";
    cout << "Department: " << student.department << endl;
    cout << "Semester Fee: " << student.price << " ETB\n";

    studentCount++;
}

void viewAllStudents() {
    displayHeader();
    cout << "\n\033[1;33mALL REGISTERED STUDENTS\033[0m\n\n";

    ifstream file("students.txt");
    if (!file.is_open()) {
        cout << "\033[1;31mNo student records found.\033[0m\n";
        return;
    }

    cout << left << setw(10) << "ID" << setw(25) << "Name" << setw(5) << "Age"
         << setw(8) << "Gender" << setw(20) << "Department" << setw(15) << "Phone"
         << setw(25) << "Email" << setw(10) << "Fee" << endl;
    cout << string(120, '-') << endl;

    string line;
    while (getline(file, line)) {
        cout << line << endl;
    }
    file.close();
}

void searchStudentById() {
    displayHeader();
    cout << "\n\033[1;33mSEARCH STUDENT BY ID\033[0m\n\n";

    cout << "Enter student ID to search: ";
    string searchId;
    cin >> searchId;

    ifstream file("students.txt");
    if (!file.is_open()) {
        cout << "\033[1;31mNo student records found.\033[0m\n";
        return;
    }

    bool found = false;
    string line;
    while (getline(file, line)) {
        if (line.find(searchId) != string::npos) {
            cout << "\n\033[1;32mSTUDENT FOUND:\033[0m\n";
            cout << line << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "\033[1;31mNo student found with ID: " << searchId << "\033[0m\n";
    }
    file.close();
}

void registerUser() {
    displayHeader();
    cout << "\n\033[1;33mUSER REGISTRATION\033[0m\n\n";

    string username;
    cout << "Enter username (max 12 characters): ";
    cin >> username;
    if (username.length() > 12) {
        cout << "\033[1;31mUsername must be 12 characters or less.\033[0m\n";
        return;
    }

    cout << "Enter password (min 8 characters): ";
    string password = maskPassword();
    if (password.length() < 8) {
        cout << "\033[1;31mPassword must be at least 8 characters.\033[0m\n";
        return;
    }

    ofstream file("user_pass.txt", ios::app);
    if (file.is_open()) {
        file << username << " " << password << endl;
        file.close();
        cout << "\033[1;32mRegistration successful!\033[0m\n";
    } else {
        cout << "\033[1;31mError saving user credentials.\033[0m\n";
    }
}

void adminMenu() {
    int choice;
    do {
        displayHeader();
        cout << "\n\033[1;33mADMIN MENU\033[0m\n\n";
        cout << "1. Register New Admin\n";
        cout << "2. View All Students\n";
        cout << "3. Search Student by ID\n";
        cout << "4. Logout\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        clearScreen();
        switch(choice) {
            case 1:
                registerUser();
                break;
            case 2:
                viewAllStudents();
                break;
            case 3:
                searchStudentById();
                break;
            case 4:
                cout << "\033[1;32mLogged out successfully.\033[0m\n";
                break;
            default:
                cout << "\033[1;31mInvalid choice. Try again.\033[0m\n";
        }
        if (choice != 4) {
            cout << "\nPress Enter to continue...";
            cin.ignore();
            clearScreen();
        }
    } while (choice != 4);
}

void studentMenu() {
    int choice;
    do {
        displayHeader();
        cout << "\n\033[1;33mSTUDENT MENU\033[0m\n\n";
        cout << "1. Register New Student\n";
        cout << "2. View My Information\n";
        cout << "3. Logout\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        clearScreen();
        switch(choice) {
            case 1:
                studentRegistration();
                break;
            case 2:
                searchStudentById();
                break;
            case 3:
                cout << "\033[1;32mLogged out successfully.\033[0m\n";
                break;
            default:
                cout << "\033[1;31mInvalid choice. Try again.\033[0m\n";
        }
        if (choice != 3) {
            cout << "\nPress Enter to continue...";
            cin.ignore();
            clearScreen();
        }
    } while (choice != 3);
}

bool authenticate(const string& filename) {
    string username, password;

    cout << "Enter username: ";
    cin >> username;

    cout << "Enter password: ";
    password = maskPassword();

    ifstream file(filename);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            size_t space = line.find(' ');
            if (space != string::npos &&
                line.substr(0, space) == username &&
                line.substr(space + 1) == password) {
                file.close();
                return true;
            }
        }
        file.close();
    }
    return false;
}

void mainMenu() {
    system("color 0A"); // Black background with green text

    int option;
    do {
        displayHeader();
        cout << "\n1. Admin Login\n";
        cout << "2. Student Registration\n";
        cout << "3. Student Login\n";
        cout << "4. Exit\n";
        cout << "Enter option: ";
        cin >> option;
        cin.ignore();

        clearScreen();
        switch(option) {
            case 1:
                if (authenticate("admin_pass.txt")) {
                    cout << "\033[1;32mLogin successful!\033[0m\n";
                    adminMenu();
                } else {
                    cout << "\033[1;31mInvalid credentials. Access denied.\033[0m\n";
                }
                break;
            case 2:
                studentRegistration();
                break;
            case 3:
                if (authenticate("user_pass.txt")) {
                    cout << "\033[1;32mLogin successful!\033[0m\n";
                    studentMenu();
                } else {
                    cout << "\033[1;31mInvalid credentials. Access denied.\033[0m\n";
                }
                break;
            case 4:
                cout << "\n\033[1;36mThank you for using Unity University Registration System.\033[0m\n";
                break;
            default:
                cout << "\033[1;31mInvalid option. Try again.\033[0m\n";
        }
        if (option != 4) {
            cout << "\nPress Enter to continue...";
            cin.ignore();
            clearScreen();
        }
    } while (option != 4);
}

int main() {
    mainMenu();
    return 0;
}
