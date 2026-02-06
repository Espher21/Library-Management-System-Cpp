#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Book {
private:
    int id;
    string title;
    string author;
    bool available;

public:
    Book(int id, string title, string author) {
        this->id = id;
        this->title = title;
        this->author = author;
        available = true;
    }

    int getId() { return id; }
    string getTitle() { return title; }
    string getAuthor() { return author; }
    bool isAvailable() { return available; }

    void borrowBook() { available = false; }
    void returnBook() { available = true; }
};

class User {
private:
    int userId;
    string name;

public:
    User(int userId, string name) {
        this->userId = userId;
        this->name = name;
    }

    int getUserId() { return userId; }
};

class Library {
private:
    vector<Book> books;
    vector<User> users;

public:
    void addBook(Book book) {
        books.push_back(book);
        cout << "Book added successfully\n";
    }

    void searchBook(string title) {
        for (auto &book : books) {
            if (book.getTitle() == title) {
                cout << "Found: " << book.getTitle()
                     << " by " << book.getAuthor() << endl;
                return;
            }
        }
        cout << "Book not found\n";
    }
};

int main() {
    Library library;
    library.addBook(Book(1, "C++ Programming", "Bjarne Stroustrup"));
    library.searchBook("C++ Programming");
    return 0;
}
