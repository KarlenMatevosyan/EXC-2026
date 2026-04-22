#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Book {
public:
    string title;
    string author;
    bool isTaken;

    Book(string t, string a) : title(t), author(a), isTaken(false) {}

    void takeBook() {
        if (isTaken) {
            cout << "Sorry, " << title << " is already taken." << endl;
        } else {
            isTaken = true;
            cout << "Success! You have taken " << title << "." << endl;
        }
    }

    void returnBook() {
        if (!isTaken) {
            cout << "This book is already in the library." << endl;
        } else {
            isTaken = false;
            cout << "You have returned " << title << "." << endl;
        }
    }
};

int main() {
    vector<Book> books;
    ifstream file("books.csv");
    
    if (!file.is_open()) {
        cout << "Error opening file!" << endl;
        return 1;
    }

    string line;
    while (getline(file, line)) {
        int pos = line.find(" — "); 
        if (pos != string::npos) {
            string title = line.substr(0, pos);
            string author = line.substr(pos + 4);
            books.push_back(Book(title, author));
        }
    }
    file.close();

    string command;
    while (true) {
        cout << "\nEnter command (take, return, available, exit): ";
        cin >> command;

        if (command == "exit") {
            break;
        }

        if (command == "available") {
            cout << "\n--- Available Books ---" << endl;
            for (const auto& rec : books) {
                if (!rec.isTaken) {
                    cout << rec.title << " by " << rec.author << endl;
                }
            }
        } else if (command == "take" || command == "return") {
            string title;
            cout << "Enter the book title: ";
            cin.ignore(); 
            getline(cin, title);

            bool found = false;
            for (auto& rec : books) {
                if (rec.title == title) {
                    if (command == "take") {
                        rec.takeBook();
                    } else {
                        rec.returnBook();
                    }
                    found = true;
                    break;
                }
            }
            if (!found) cout << "Book not found in catalog." << endl;
        } 
        else {
            cout << "Unknown command!" << endl;
        }
    }

    return 0;
}
