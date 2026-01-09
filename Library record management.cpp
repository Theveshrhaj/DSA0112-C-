#include <iostream>
#include <limits>
#include <string>


using namespace std;

class Book {
private:
  int bookId;
  string title;
  string author;
  double price;

public:
  // Function to accept book details
  void acceptDetails() {
    cout << "Enter Book ID: ";
    while (!(cin >> bookId)) {
      cout << "Invalid input. Please enter a numeric Book ID: ";
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cin.ignore(); // Consume newline left by cin

    cout << "Enter Title: ";
    getline(cin, title);

    cout << "Enter Author: ";
    getline(cin, author);

    cout << "Enter Price: ";
    while (!(cin >> price)) {
      cout << "Invalid input. Please enter a numeric Price: ";
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
  }

  // Function to display book details
  void displayDetails() const {
    cout << "---------------------------------" << endl;
    cout << "Book ID: " << bookId << endl;
    cout << "Title:   " << title << endl;
    cout << "Author:  " << author << endl;
    cout << "Price:   " << price << endl;
    cout << "---------------------------------" << endl;
  }

  // Getter for title to help with searching
  string getTitle() const { return title; }

  // Getter for price to help with filtering
  double getPrice() const { return price; }
};

int main() {
  const int MAX_BOOKS = 100;
  Book books[MAX_BOOKS];
  int bookCount = 0;
  int choice;

  do {
    cout << "\n=== Library Book Record System ===" << endl;
    cout << "1. Add Book Details" << endl;
    cout << "2. Display All Books" << endl;
    cout << "3. Search for a Book by Title" << endl;
    cout << "4. Display Books below a specified Price" << endl;
    cout << "5. Exit" << endl;
    cout << "Enter your choice: ";

    if (!(cin >> choice)) {
      cout << "Invalid input. Please enter a number." << endl;
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      continue;
    }

    switch (choice) {
    case 1: {
      if (bookCount < MAX_BOOKS) {
        cout << "\nEnter details for book " << bookCount + 1 << ":" << endl;
        books[bookCount].acceptDetails();
        bookCount++;
        cout << "Book added successfully!" << endl;
      } else {
        cout << "Library is full! Cannot add more books." << endl;
      }
      break;
    }
    case 2: {
      if (bookCount == 0) {
        cout << "\nNo books in the library." << endl;
      } else {
        cout << "\nList of all books:" << endl;
        for (int i = 0; i < bookCount; ++i) {
          books[i].displayDetails();
        }
      }
      break;
    }
    case 3: {
      if (bookCount == 0) {
        cout << "\nNo books to search." << endl;
      } else {
        cin.ignore(); // Consume newline
        string searchTitle;
        cout << "\nEnter title to search: ";
        getline(cin, searchTitle);

        bool found = false;
        for (int i = 0; i < bookCount; ++i) {
          if (books[i].getTitle() == searchTitle) {
            cout << "\nBook Found:" << endl;
            books[i].displayDetails();
            found = true;
            // Don't break, in case there are multiple books with same title?
            // Usually unique, but let's show all matches or just first.
            // Requirement says "Search for a book", usually implies finding one
            // or all. Let's show all matches just in case.
          }
        }
        if (!found) {
          cout << "Book with title '" << searchTitle << "' not found." << endl;
        }
      }
      break;
    }
    case 4: {
      if (bookCount == 0) {
        cout << "\nNo books to filter." << endl;
      } else {
        double maxPrice;
        cout << "\nEnter maximum price: ";
        while (!(cin >> maxPrice)) {
          cout << "Invalid input. Please enter a numeric Price: ";
          cin.clear();
          cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        cout << "\nBooks with price below " << maxPrice << ":" << endl;
        bool found = false;
        for (int i = 0; i < bookCount; ++i) {
          if (books[i].getPrice() < maxPrice) {
            books[i].displayDetails();
            found = true;
          }
        }
        if (!found) {
          cout << "No books found below price " << maxPrice << "." << endl;
        }
      }
      break;
    }
    case 5:
      cout << "Exiting program..." << endl;
      break;
    default:
      cout << "Invalid choice! Please try again." << endl;
    }
  } while (choice != 5);

  return 0;
}
