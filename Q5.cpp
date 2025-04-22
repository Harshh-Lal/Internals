#include <iostream>
#include <string>
using namespace std;

class Books {
    string* author;
    string* title;
    double price;
    string* publisher;
    int stock;
public:
    Books(string a, string t, double p, string pub, int s) {
        author = new string(a);
        title = new string(t);
        price = p;
        publisher = new string(pub);
        stock = s;
    }
    ~Books() {
        delete author, title, publisher;
    }
    bool search(string t, string a) {
        return (*title == t && *author == a);
    }
    void processOrder(int copies) {
        if (stock >= copies) {
            cout << "Total Cost: $" << price * copies << endl;
            stock -= copies;
        } else {
            cout << "Required copies not in stock!" << endl;
        }
    }
};

int main() {
    Books book("J.K. Rowling", "Harry Potter", 20.5, "Bloomsbury", 10);
    if (book.search("Harry Potter", "J.K. Rowling")) {
        book.processOrder(3);
    } else {
        cout << "Book not found!" << endl;
    }
    return 0;
}