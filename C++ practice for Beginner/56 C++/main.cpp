#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <windows.h> // For color functions
using namespace std;

// Color constants
const int BLACK = 0;
const int BLUE = 1;
const int GREEN = 2;
const int CYAN = 3;
const int RED = 4;
const int MAGENTA = 5;
const int YELLOW = 6;
const int WHITE = 7;
const int GRAY = 8;
const int LIGHT_BLUE = 9;
const int LIGHT_GREEN = 10;
const int LIGHT_CYAN = 11;
const int LIGHT_RED = 12;
const int LIGHT_MAGENTA = 13;
const int LIGHT_YELLOW = 14;
const int BRIGHT_WHITE = 15;

// Function to set console text color
void setColor(int textColor, int bgColor = BLACK) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, (bgColor << 4) | textColor);
}

// Reset to default colors
void resetColor() {
    setColor(WHITE, BLACK);
}

struct Student {
    int idNumber;
    string fullName;
    float subjects[8]; // Amharic, English, Math, Physics, Geography, Sport, Chemistry, Civic
};

vector<Student> students;
const int NUM_SUBJECTS = 8;
const string SUBJECT_NAMES[] = {
    "Amharic", "English", "Mathematics", "Physics",
    "Geography", "Sport", "Chemistry", "Civic"
};

void displayHeader(const string& title) {
    setColor(LIGHT_CYAN);
    cout << "\n*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*\n";
    cout << "*               " << setw(30) << left << title << "           *\n";
    cout << "*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*\n";
    resetColor();
}

void introduction() {
    setColor(LIGHT_YELLOW);
    cout << setw(50) << " " << "Welcome to\n";
    cout << setw(50) << " " << "Ethio Parents School\n";
    cout << setw(50) << " " << "Student Management System\n\n";
    resetColor();
    cout << "Press Enter to continue...";
    cin.ignore();
    system("cls");
}

void addStudent() {
    Student newStudent;

    displayHeader("ADD NEW STUDENT");

    setColor(LIGHT_GREEN);
    cout << "Enter Student ID: ";
    cin >> newStudent.idNumber;

    cout << "Enter Full Name: ";
    cin.ignore();
    getline(cin, newStudent.fullName);

    for (int i = 0; i < NUM_SUBJECTS; i++) {
        cout << "Enter score for " << SUBJECT_NAMES[i] << " (0-100): ";
        cin >> newStudent.subjects[i];

        // Validate score
        while (newStudent.subjects[i] < 0 || newStudent.subjects[i] > 100) {
            setColor(LIGHT_RED);
            cout << "Invalid score! Please enter between 0-100: ";
            resetColor();
            cin >> newStudent.subjects[i];
        }
    }

    students.push_back(newStudent);

    setColor(LIGHT_GREEN);
    cout << "\nStudent added successfully!\n";
    resetColor();
}

void displayAllStudents() {
    if (students.empty()) {
        setColor(LIGHT_RED);
        cout << "No student records found!\n";
        resetColor();
        return;
    }

    displayHeader("ALL STUDENT RECORDS");

    for (size_t i = 0; i < students.size(); i++) {
        setColor(LIGHT_BLUE);
        cout << "\nStudent #" << i+1 << "\n";
        cout << "ID: " << students[i].idNumber << "\n";
        cout << "Name: " << students[i].fullName << "\n";

        setColor(WHITE);
        cout << "Scores:\n";
        for (int j = 0; j < NUM_SUBJECTS; j++) {
            cout << setw(12) << left << SUBJECT_NAMES[j] << ": "
                 << fixed << setprecision(1) << students[i].subjects[j] << "\n";
        }
        cout << string(40, '-') << "\n";
    }
    resetColor();
}

void calculateTotal() {
    if (students.empty()) {
        setColor(LIGHT_RED);
        cout << "No student records found!\n";
        resetColor();
        return;
    }

    displayHeader("TOTAL SCORES");

    for (size_t i = 0; i < students.size(); i++) {
        float total = 0;
        for (int j = 0; j < NUM_SUBJECTS; j++) {
            total += students[i].subjects[j];
        }

        setColor(LIGHT_MAGENTA);
        cout << "\nStudent: " << students[i].fullName << "\n";
        cout << "Total Score: " << total << "/800\n";
        cout << string(40, '-') << "\n";
    }
    resetColor();
}

void calculateAverage() {
    if (students.empty()) {
        setColor(LIGHT_RED);
        cout << "No student records found!\n";
        resetColor();
        return;
    }

    displayHeader("AVERAGE SCORES");

    for (size_t i = 0; i < students.size(); i++) {
        float total = 0;
        for (int j = 0; j < NUM_SUBJECTS; j++) {
            total += students[i].subjects[j];
        }
        float average = total / NUM_SUBJECTS;

        setColor(LIGHT_YELLOW);
        cout << "\nStudent: " << students[i].fullName << "\n";
        cout << "Average Score: " << fixed << setprecision(2) << average << "\n";
        cout << string(40, '-') << "\n";
    }
    resetColor();
}

void calculateGrade() {
    if (students.empty()) {
        setColor(LIGHT_RED);
        cout << "No student records found!\n";
        resetColor();
        return;
    }

    displayHeader("GRADE REPORT");

    for (size_t i = 0; i < students.size(); i++) {
        float total = 0;
        for (int j = 0; j < NUM_SUBJECTS; j++) {
            total += students[i].subjects[j];
        }
        float average = total / NUM_SUBJECTS;

        setColor(LIGHT_GREEN);
        cout << "\nStudent: " << students[i].fullName << "\n";
        cout << "Average: " << fixed << setprecision(2) << average << " - ";

        // Determine grade
        if (average >= 90) {
            setColor(BRIGHT_WHITE);
            cout << "A+ (Excellent)";
        } else if (average >= 85) {
            setColor(LIGHT_CYAN);
            cout << "A (Very Good)";
        } else if (average >= 80) {
            setColor(LIGHT_BLUE);
            cout << "B+ (Good)";
        } else if (average >= 75) {
            setColor(CYAN);
            cout << "B (Above Average)";
        } else if (average >= 70) {
            setColor(YELLOW);
            cout << "C+ (Average)";
        } else if (average >= 65) {
            setColor(LIGHT_YELLOW);
            cout << "C (Below Average)";
        } else if (average >= 60) {
            setColor(LIGHT_RED);
            cout << "D+ (Poor)";
        } else if (average >= 50) {
            setColor(RED);
            cout << "D (Very Poor)";
        } else {
            setColor(LIGHT_RED);
            cout << "F (Fail)";
        }

        cout << "\n";
        resetColor();
        cout << string(40, '-') << "\n";
    }
}

void aboutUs() {
    displayHeader("ABOUT THE SYSTEM");

    setColor(LIGHT_MAGENTA);
    cout << "Developed by: Kidest Maru and Abigiya Negash\n";
    cout << "Contact: 09-21-55-50-59\n";
    cout << "Email: info@ethioparents.edu\n";
    cout << "Version: 2.0\n\n";

    setColor(LIGHT_CYAN);
    cout << "This system is designed to manage student academic records,\n";
    cout << "calculate grades, and generate reports for Ethio Parents School.\n";
    resetColor();
}

void mainMenu() {
    int choice;

    do {
        system("cls");
        displayHeader("MAIN MENU");

        setColor(LIGHT_GREEN);
        cout << "1. Add New Student\n";
        cout << "2. View All Students\n";
        cout << "3. Calculate Total Scores\n";
        cout << "4. Calculate Average Scores\n";
        cout << "5. Calculate Grades\n";
        cout << "6. About the System\n";
        cout << "7. Exit\n";

        setColor(LIGHT_YELLOW);
        cout << "\nEnter your choice (1-7): ";
        cin >> choice;
        resetColor();

        system("cls");

        switch(choice) {
            case 1: addStudent(); break;
            case 2: displayAllStudents(); break;
            case 3: calculateTotal(); break;
            case 4: calculateAverage(); break;
            case 5: calculateGrade(); break;
            case 6: aboutUs(); break;
            case 7:
                setColor(LIGHT_YELLOW);
                cout << "Thank you for using Ethio Parents School System!\n";
                resetColor();
                return;
            default:
                setColor(LIGHT_RED);
                cout << "Invalid choice! Please try again.\n";
                resetColor();
        }

        cout << "\n";
        setColor(GRAY);
        system("pause");
    } while (choice != 7);
}

int main() {
    // Set console title
    SetConsoleTitle("Ethio Parents School - Student Management System");

    // Set initial color scheme
    system("color 1F"); // Blue background with white text

    introduction();
    mainMenu();

    return 0;
}
