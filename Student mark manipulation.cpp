#include <iomanip>
#include <iostream>
#include <limits>
#include <string>
#include <vector>


using namespace std;

class Student {
private:
  int rollNo;
  string name;
  int marks[5];
  int total;
  double average;
  char grade;

public:
  // Function to accept student details
  void getDetails() {
    cout << "Enter Roll No: ";
    while (!(cin >> rollNo)) {
      cout << "Invalid input. Please enter a numeric Roll No: ";
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cin.ignore(); // Consume newline

    cout << "Enter Name: ";
    getline(cin, name);

    cout << "Enter Marks for 5 subjects:" << endl;
    for (int i = 0; i < 5; ++i) {
      cout << "Subject " << (i + 1) << ": ";
      while (!(cin >> marks[i]) || marks[i] < 0 || marks[i] > 100) {
        cout << "Invalid mark. Please enter a value between 0 and 100: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
      }
    }
    calculateResult();
  }

  // Function to calculate total, average and grade
  void calculateResult() {
    total = 0;
    for (int i = 0; i < 5; ++i) {
      total += marks[i];
    }
    average = total / 5.0;

    if (average >= 90)
      grade = 'A';
    else if (average >= 80)
      grade = 'B';
    else if (average >= 70)
      grade = 'C';
    else if (average >= 60)
      grade = 'D';
    else if (average >= 50)
      grade = 'E';
    else
      grade = 'F';
  }

  // Function to display student details
  void displayDetails() const {
    cout << "\n---------------------------------" << endl;
    cout << "Roll No : " << rollNo << endl;
    cout << "Name    : " << name << endl;
    cout << "Marks   : ";
    for (int i = 0; i < 5; ++i) {
      cout << marks[i] << " ";
    }
    cout << endl;
    cout << "Total   : " << total << endl;
    cout << "Average : " << fixed << setprecision(2) << average << endl;
    cout << "Grade   : " << grade << endl;
    cout << "---------------------------------" << endl;
  }
};

int main() {
  int numStudents;
  cout << "Enter the number of students: ";
  while (!(cin >> numStudents) || numStudents <= 0) {
    cout << "Invalid input. Please enter a positive integer: ";
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
  }

  vector<Student> students(numStudents);

  // Input details
  for (int i = 0; i < numStudents; ++i) {
    cout << "\nEnter details for Student " << (i + 1) << ":" << endl;
    students[i].getDetails();
  }

  // Display details
  cout << "\n\n=== Student Records ===" << endl;
  for (int i = 0; i < numStudents; ++i) {
    students[i].displayDetails();
  }

  return 0;
}
