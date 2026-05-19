#include <iostream>
#include <vector>
using namespace std;

// Book Class
class Book {
public:
    int id;
    string title;
    string author;
    bool isIssued;

    Book(int i, string t, string a) {
        id = i;
        title = t;
        author = a;
        isIssued = false;
    }
};

// Member Class
class Member {
public:
    int id;
    string name;

    Member(int i, string n) {
        id = i;
        name = n;
    }
};

// Library Class
class Library {
private:
    vector<Book> books;
    vector<Member> members;

public:
    // Add Book
    void addBook(int id, string title, string author) {
        books.push_back(Book(id, title, author));
        cout << "Book added successfully!\n";
    }

    // Add Member
    void addMember(int id, string name) {
        members.push_back(Member(id, name));
        cout << "Member added successfully!\n";
    }

    // Issue Book
    void issueBook(int bookId) {
        for (auto &book : books) {
            if (book.id == bookId) {
                if (!book.isIssued) {
                    book.isIssued = true;
                    cout << "Book issued successfully!\n";
                } else {
                    cout << "Book already issued!\n";
                }
                return;
            }
        }
        cout << "Book not found!\n";
    }

    // Return Book
    void returnBook(int bookId) {
        for (auto &book : books) {
            if (book.id == bookId) {
                if (book.isIssued) {
                    book.isIssued = false;
                    cout << "Book returned successfully!\n";
                } else {
                    cout << "Book was not issued!\n";
                }
                return;
            }
        }
        cout << "Book not found!\n";
    }

    // Search by Title
    void searchByTitle(string title) {
        for (auto &book : books) {
            if (book.title == title) {
                cout << "Found: " << book.title << " by " << book.author << endl;
                return;
            }
        }
        cout << "Book not found!\n";
    }

    // Search by Author
    void searchByAuthor(string author) {
        for (auto &book : books) {
            if (book.author == author) {
                cout << "Found: " << book.title << " by " << book.author << endl;
            }
        }
    }

    // Display All Books
    void displayBooks() {
        for (auto &book : books) {
            cout << book.id << " | " << book.title << " | " << book.author
                 << " | " << (book.isIssued ? "Issued" : "Available") << endl;
        }
    }
};

// Main Function
int main() {
    Library lib;
    int choice;

    do {
        cout << "\n--- Library Menu ---\n";
        cout << "1. Add Book\n2. Add Member\n3. Issue Book\n4. Return Book\n";
        cout << "5. Search by Title\n6. Search by Author\n7. Display Books\n0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        int id;
        string title, author, name;

        switch (choice) {
            case 1:
                cout << "Enter Book ID, Title, Author: ";
                cin >> id >> title >> author;
                lib.addBook(id, title, author);
                break;

            case 2:
                cout << "Enter Member ID, Name: ";
                cin >> id >> name;
                lib.addMember(id, name);
                break;

            case 3:
                cout << "Enter Book ID to issue: ";
                cin >> id;
                lib.issueBook(id);
                break;

            case 4:
                cout << "Enter Book ID to return: ";
                cin >> id;
                lib.returnBook(id);
                break;

            case 5:
                cout << "Enter Title: ";
                cin >> title;
                lib.searchByTitle(title);
                break;

            case 6:
                cout << "Enter Author: ";
                cin >> author;
                lib.searchByAuthor(author);
                break;

            case 7:
                lib.displayBooks();
                break;
        }

    } while (choice != 0);

    return 0;
}
