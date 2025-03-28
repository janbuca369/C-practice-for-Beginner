#include <iostream>
#include <fstream>
#include <cstring>
#include <ctime>
#include <vector>
#include <iomanip>
#include <windows.h> // For color functions
using namespace std;

// Color functions
void setColor(int textColor, int bgColor = 0) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, (bgColor << 4) | textColor);
}

void resetColor() {
    setColor(7, 0);
}

// Constants
const int MAX_BOOKS = 1000;
const int MAX_USERS = 500;
const int MAX_BORROWED = 5;
const int MAX_ADMINS = 10;

// Date structure
struct Date {
    int day, month, year;

    Date() {
        time_t now = time(0);
        tm *ltm = localtime(&now);
        day = ltm->tm_mday;
        month = 1 + ltm->tm_mon;
        year = 1900 + ltm->tm_year;
    }

    string toString() {
        return to_string(day) + "/" + to_string(month) + "/" + to_string(year);
    }
};

// Book class
class Book {
    int book_id;
    string book_name;
    string author;
    string publisher;
    string category;
    int publication_year;
    int status; // 0=available, 1=borrowed
    string borrowed_by;
    Date due_date;

public:
    void acceptBook() {
        system("cls");
        setColor(11); // Light cyan
        cout << "********** ADD NEW BOOK **********\n";
        resetColor();

        cout << "Enter book ID: ";
        cin >> book_id;
        cin.ignore();

        cout << "Enter book name: ";
        getline(cin, book_name);

        cout << "Enter author name: ";
        getline(cin, author);

        cout << "Enter publisher: ";
        getline(cin, publisher);

        cout << "Enter category: ";
        getline(cin, category);

        cout << "Enter publication year: ";
        cin >> publication_year;

        status = 0; // Available by default
        borrowed_by = "";
    }

    void display() {
        system("cls");
        setColor(10); // Light green
        cout << "********** BOOK DETAILS **********\n";
        resetColor();

        cout << left << setw(15) << "ID:" << book_id << endl;
        cout << setw(15) << "Name:" << book_name << endl;
        cout << setw(15) << "Author:" << author << endl;
        cout << setw(15) << "Publisher:" << publisher << endl;
        cout << setw(15) << "Category:" << category << endl;
        cout << setw(15) << "Year:" << publication_year << endl;

        if (status == 0) {
            setColor(10);
            cout << setw(15) << "Status:" << "Available" << endl;
            resetColor();
        } else {
            setColor(12); // Light red
            cout << setw(15) << "Status:" << "Borrowed by " << borrowed_by << endl;
            cout << setw(15) << "Due Date:" << due_date.toString() << endl;
            resetColor();
        }

        cout << string(40, '-') << endl;
    }

    // Getters and setters
    int getId() { return book_id; }
    string getName() { return book_name; }
    string getAuthor() { return author; }
    int getStatus() { return status; }
    string getBorrowedBy() { return borrowed_by; }

    void borrowBook(string username) {
        status = 1;
        borrowed_by = username;

        // Set due date to 2 weeks from now
        time_t now = time(0);
        now += 14 * 24 * 60 * 60; // Add 14 days in seconds
        tm *ltm = localtime(&now);
        due_date.day = ltm->tm_mday;
        due_date.month = 1 + ltm->tm_mon;
        due_date.year = 1900 + ltm->tm_year;
    }

    void returnBook() {
        status = 0;
        borrowed_by = "";
    }

    // File operations
    void saveToFile(ofstream &file) {
        file << book_id << "|" << book_name << "|" << author << "|"
             << publisher << "|" << category << "|" << publication_year << "|"
             << status << "|" << borrowed_by << "|"
             << due_date.day << "|" << due_date.month << "|" << due_date.year << endl;
    }

    void loadFromFile(ifstream &file) {
        string line;
        getline(file, line);

        size_t pos = 0;
        string token;
        int part = 0;

        while ((pos = line.find("|")) != string::npos) {
            token = line.substr(0, pos);

            switch(part) {
                case 0: book_id = stoi(token); break;
                case 1: book_name = token; break;
                case 2: author = token; break;
                case 3: publisher = token; break;
                case 4: category = token; break;
                case 5: publication_year = stoi(token); break;
                case 6: status = stoi(token); break;
                case 7: borrowed_by = token; break;
                case 8: due_date.day = stoi(token); break;
                case 9: due_date.month = stoi(token); break;
                case 10: due_date.year = stoi(token); break;
            }

            line.erase(0, pos + 1);
            part++;
        }
    }
};

// User class
class User {
    string username;
    string password;
    vector<int> borrowed_books;

public:
    void registerUser() {
        system("cls");
        setColor(11);
        cout << "********** USER REGISTRATION **********\n";
        resetColor();

        cout << "Enter username: ";
        cin >> username;

        cout << "Enter password: ";
        cin >> password;
    }

    bool login(string uname, string pwd) {
        return (username == uname && password == pwd);
    }

    bool canBorrow() {
        return borrowed_books.size() < MAX_BORROWED;
    }

    void borrowBook(int book_id) {
        borrowed_books.push_back(book_id);
    }

    void returnBook(int book_id) {
        for (auto it = borrowed_books.begin(); it != borrowed_books.end(); ++it) {
            if (*it == book_id) {
                borrowed_books.erase(it);
                break;
            }
        }
    }

    // File operations
    void saveToFile(ofstream &file) {
        file << username << "|" << password << "|";
        for (int id : borrowed_books) {
            file << id << ",";
        }
        file << endl;
    }

    void loadFromFile(ifstream &file) {
        string line;
        getline(file, line);

        size_t pos = line.find("|");
        username = line.substr(0, pos);
        line.erase(0, pos + 1);

        pos = line.find("|");
        password = line.substr(0, pos);
        line.erase(0, pos + 1);

        // Parse borrowed books
        while ((pos = line.find(",")) != string::npos) {
            string token = line.substr(0, pos);
            if (!token.empty()) {
                borrowed_books.push_back(stoi(token));
            }
            line.erase(0, pos + 1);
        }
    }
};

// Library management system
class LibrarySystem {
    vector<Book> books;
    vector<User> users;
    vector<User> admins;

    void loadBooks() {
        ifstream file("books.dat");
        if (file.is_open()) {
            while (!file.eof()) {
                Book book;
                book.loadFromFile(file);
                if (book.getId() != 0) {
                    books.push_back(book);
                }
            }
            file.close();
        }
    }

    void saveBooks() {
        ofstream file("books.dat");
        for (Book &book : books) {
            book.saveToFile(file);
        }
        file.close();
    }

    void loadUsers() {
        ifstream file("users.dat");
        if (file.is_open()) {
            while (!file.eof()) {
                User user;
                user.loadFromFile(file);
                if (!user.login("", "")) { // Check if user is not empty
                    users.push_back(user);
                }
            }
            file.close();
        }
    }

    void saveUsers() {
        ofstream file("users.dat");
        for (User &user : users) {
            user.saveToFile(file);
        }
        file.close();
    }

    void loadAdmins() {
        ifstream file("admins.dat");
        if (file.is_open()) {
            while (!file.eof()) {
                User admin;
                admin.loadFromFile(file);
                if (!admin.login("", "")) { // Check if admin is not empty
                    admins.push_back(admin);
                }
            }
            file.close();
        }
    }

    void saveAdmins() {
        ofstream file("admins.dat");
        for (User &admin : admins) {
            admin.saveToFile(file);
        }
        file.close();
    }

public:
    LibrarySystem() {
        loadBooks();
        loadUsers();
        loadAdmins();
    }

    ~LibrarySystem() {
        saveBooks();
        saveUsers();
        saveAdmins();
    }

    // Book management
    void addBook() {
        Book book;
        book.acceptBook();
        books.push_back(book);
        saveBooks();

        setColor(10);
        cout << "\nBook added successfully!\n";
        resetColor();
        system("pause");
    }

    void viewAllBooks() {
        system("cls");
        setColor(11);
        cout << "********** ALL BOOKS **********\n\n";
        resetColor();

        if (books.empty()) {
            setColor(12);
            cout << "No books found in the library.\n";
            resetColor();
        } else {
            cout << left << setw(10) << "ID" << setw(30) << "Title"
                 << setw(20) << "Author" << setw(10) << "Status" << endl;
            cout << string(70, '-') << endl;

            for (Book &book : books) {
                cout << setw(10) << book.getId() << setw(30) << book.getName().substr(0, 27)
                     << setw(20) << book.getAuthor().substr(0, 17);

                if (book.getStatus() == 0) {
                    setColor(10);
                    cout << setw(10) << "Available" << endl;
                    resetColor();
                } else {
                    setColor(12);
                    cout << setw(10) << "Borrowed" << endl;
                    resetColor();
                }
            }
        }
        system("pause");
    }

    void searchBook() {
        system("cls");
        setColor(11);
        cout << "********** SEARCH BOOK **********\n\n";
        resetColor();

        cout << "1. Search by title\n";
        cout << "2. Search by author\n";
        cout << "3. Search by category\n";
        cout << "Enter choice: ";

        int choice;
        cin >> choice;
        cin.ignore();

        string search_term;
        cout << "Enter search term: ";
        getline(cin, search_term);

        vector<Book> results;

        for (Book &book : books) {
            bool match = false;

            switch(choice) {
                case 1:
                    match = book.getName().find(search_term) != string::npos;
                    break;
                case 2:
                    match = book.getAuthor().find(search_term) != string::npos;
                    break;
                case 3:
                    match = book.getCategory().find(search_term) != string::npos;
                    break;
                default:
                    cout << "Invalid choice!\n";
                    return;
            }

            if (match) {
                results.push_back(book);
            }
        }

        system("cls");
        if (results.empty()) {
            setColor(12);
            cout << "No books found matching your search.\n";
            resetColor();
        } else {
            setColor(10);
            cout << "Found " << results.size() << " matching books:\n\n";
            resetColor();

            for (Book &book : results) {
                book.display();
                cout << endl;
            }
        }
        system("pause");
    }

    void deleteBook() {
        system("cls");
        setColor(11);
        cout << "********** DELETE BOOK **********\n\n";
        resetColor();

        cout << "Enter book ID to delete: ";
        int id;
        cin >> id;

        for (auto it = books.begin(); it != books.end(); ++it) {
            if (it->getId() == id) {
                books.erase(it);
                saveBooks();

                setColor(10);
                cout << "Book deleted successfully!\n";
                resetColor();
                system("pause");
                return;
            }
        }

        setColor(12);
        cout << "Book not found!\n";
        resetColor();
        system("pause");
    }

    // User management
    void registerUser() {
        User user;
        user.registerUser();
        users.push_back(user);
        saveUsers();

        setColor(10);
        cout << "\nUser registered successfully!\n";
        resetColor();
        system("pause");
    }

    bool loginUser(string username, string password) {
        for (User &user : users) {
            if (user.login(username, password)) {
                return true;
            }
        }
        return false;
    }

    bool loginAdmin(string username, string password) {
        for (User &admin : admins) {
            if (admin.login(username, password)) {
                return true;
            }
        }
        return false;
    }

    // Borrow/return functions
    void borrowBook(string username, int book_id) {
        for (Book &book : books) {
            if (book.getId() == book_id) {
                if (book.getStatus() == 0) {
                    book.borrowBook(username);
                    saveBooks();

                    for (User &user : users) {
                        if (user.login(username, "")) { // Check username only
                            user.borrowBook(book_id);
                            saveUsers();
                            break;
                        }
                    }

                    setColor(10);
                    cout << "Book borrowed successfully!\n";
                    resetColor();
                } else {
                    setColor(12);
                    cout << "Book is already borrowed!\n";
                    resetColor();
                }
                return;
            }
        }

        setColor(12);
        cout << "Book not found!\n";
        resetColor();
    }

    void returnBook(string username, int book_id) {
        for (Book &book : books) {
            if (book.getId() == book_id && book.getStatus() == 1 && book.getBorrowedBy() == username) {
                book.returnBook();
                saveBooks();

                for (User &user : users) {
                    if (user.login(username, "")) { // Check username only
                        user.returnBook(book_id);
                        saveUsers();
                        break;
                    }
                }

                setColor(10);
                cout << "Book returned successfully!\n";
                resetColor();
                return;
            }
        }

        setColor(12);
        cout << "Book not found or not borrowed by this user!\n";
        resetColor();
    }

    // Admin functions
    void registerAdmin() {
        User admin;
        admin.registerUser();
        admins.push_back(admin);
        saveAdmins();

        setColor(10);
        cout << "\nAdmin registered successfully!\n";
        resetColor();
        system("pause");
    }
};

// Menu functions
void adminMenu(LibrarySystem &lib) {
    int choice;
    do {
        system("cls");
        setColor(14); // Yellow
        cout << "********** ADMIN MENU **********\n\n";
        resetColor();

        cout << "1. Add Book\n";
        cout << "2. View All Books\n";
        cout << "3. Search Book\n";
        cout << "4. Delete Book\n";
        cout << "5. Register New Admin\n";
        cout << "6. Logout\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1: lib.addBook(); break;
            case 2: lib.viewAllBooks(); break;
            case 3: lib.searchBook(); break;
            case 4: lib.deleteBook(); break;
            case 5: lib.registerAdmin(); break;
            case 6: return;
            default:
                setColor(12);
                cout << "Invalid choice!\n";
                resetColor();
                system("pause");
        }
    } while (true);
}

void userMenu(LibrarySystem &lib, string username) {
    int choice;
    do {
        system("cls");
        setColor(11); // Light cyan
        cout << "********** USER MENU **********\n\n";
        resetColor();

        cout << "Welcome, " << username << "!\n\n";
        cout << "1. View All Books\n";
        cout << "2. Search Book\n";
        cout << "3. Borrow Book\n";
        cout << "4. Return Book\n";
        cout << "5. Logout\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1: lib.viewAllBooks(); break;
            case 2: lib.searchBook(); break;
            case 3: {
                cout << "Enter book ID to borrow: ";
                int id;
                cin >> id;
                lib.borrowBook(username, id);
                system("pause");
                break;
            }
            case 4: {
                cout << "Enter book ID to return: ";
                int id;
                cin >> id;
                lib.returnBook(username, id);
                system("pause");
                break;
            }
            case 5: return;
            default:
                setColor(12);
                cout << "Invalid choice!\n";
                resetColor();
                system("pause");
        }
    } while (true);
}

void mainMenu() {
    LibrarySystem lib;
    int choice;

    do {
        system("cls");
        setColor(14); // Yellow
        cout << "********** LIBRARY MANAGEMENT SYSTEM **********\n\n";
        resetColor();

        cout << "1. Admin Login\n";
        cout << "2. User Login\n";
        cout << "3. User Registration\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        string username, password;

        switch(choice) {
            case 1: {
                system("cls");
                cout << "********** ADMIN LOGIN **********\n\n";
                cout << "Username: ";
                cin >> username;
                cout << "Password: ";
                cin >> password;

                if (lib.loginAdmin(username, password)) {
                    adminMenu(lib);
                } else {
                    setColor(12);
                    cout << "\nInvalid credentials!\n";
                    resetColor();
                    system("pause");
                }
                break;
            }
            case 2: {
                system("cls");
                cout << "********** USER LOGIN **********\n\n";
                cout << "Username: ";
                cin >> username;
                cout << "Password: ";
                cin >> password;

                if (lib.loginUser(username, password)) {
                    userMenu(lib, username);
                } else {
                    setColor(12);
                    cout << "\nInvalid credentials!\n";
                    resetColor();
                    system("pause");
                }
                break;
            }
            case 3: {
                lib.registerUser();
                break;
            }
            case 4: {
                setColor(10);
                cout << "\nThank you for using the Library Management System!\n";
                resetColor();
                return;
            }
            default: {
                setColor(12);
                cout << "Invalid choice!\n";
                resetColor();
                system("pause");
            }
        }
    } while (true);
}

int main() {
    // Set console title
    SetConsoleTitle("Library Management System");

    // Set console size
    system("mode con: cols=80 lines=30");

    mainMenu();
    return 0;
}
