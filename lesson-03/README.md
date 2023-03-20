# This directory contains solution to the lesson-03
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Book {
private:
    string title_;
    string author_;

public:
    Book(string title, string author) : title_(title), author_(author) {}

    string Title() { return title_; }
    string Author() { return author_; }


};

class Library {

private:
    vector<Book> books_;

public:
    Library(){}

    void addBook(Book book) {
        books_.push_back(book);
    }

    void showBooks() {
        cout << "ksiazki w bibliotece:" << endl;
        for (int i = 0; i < books_.size(); i++) {
            cout <<"ksiazka: "<< books_[i].Title() << " autor " << books_[i].Author() << endl;
        }
    }
};

int main() {
    Library library;
    Book book1("ksiazka1", "autor1");
    Book book2("ksiazka2", "autor2");
    Book book3("ksiazka3", "autor3");
    library.addBook(book1);
    library.addBook(book2);
    library.addBook(book3);
    library.showBooks();

    return 0;
}
