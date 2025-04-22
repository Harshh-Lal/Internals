#include <iostream>
using namespace std;

enum State { ON_SHELF, ON_LOAN, RESERVED, MISSING };

class Book {
    int classMark;
    State status;
public:
    Book(int cm) : classMark(cm), status(ON_SHELF) {}
    void loan() { status = ON_LOAN; }
    void reserved() { status = RESERVED; }
    void returned() { status = ON_SHELF; }
    void missing() { status = MISSING; }
    State getState() { return status; }
};

int main() {
    Book book(42);
    book.loan();
    if (book.getState() == ON_LOAN)
        cout << "Book is on loan." << endl;
    return 0;
}