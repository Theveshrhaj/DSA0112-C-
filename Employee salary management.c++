#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

class Employee {
private:
    int empId;
    string name;
    double basicPay;
    double HRA;
    double DA;

public:
    // Function to input employee details
    void getDetails() {
        cout << "Enter Employee ID: ";
        while (!(cin >> empId)) {
            cout << "Invalid input. Please enter a numeric Employee ID: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cin.ignore(); // Consume newline left by cin

        cout << "Enter Name: ";
        getline(cin, name);

        cout << "Enter Basic Pay: ";
        while (!(cin >> basicPay)) {
            cout << "Invalid input. Please enter a numeric Basic Pay: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        cout << "Enter HRA: ";
        while (!(cin >> HRA)) {
            cout << "Invalid input. Please enter a numeric HRA: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        cout << "Enter DA: ";
        while (!(cin >> DA)) {
            cout << "Invalid input. Please enter a numeric DA: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    // Function to calculate gross salary
    double calculateGrossSalary() const {
        return basicPay + HRA + DA;
    }

    // Function to display pay slip
    void displayPaySlip() const {
        cout << "\n---------------------------------" << endl;
        cout << "        PAY SLIP" << endl;
        cout << "---------------------------------" << endl;
        cout << "Employee ID : " << empId << endl;
        cout << "Name        : " << name << endl;
        cout << "Basic Pay   : " << basicPay << endl;
        cout << "HRA         : " << HRA << endl;
        cout << "DA          : " << DA << endl;
        cout << "Gross Salary: " << calculateGrossSalary() << endl;
        cout << "---------------------------------" << endl;
    }

    // Accessor for gross salary
    double getGrossSalary() const {
        return calculateGrossSalary();
    }
    
    // Accessor for name (optional, but good for display)
    string getName() const {
        return name;
    }
};

int main() {
    int numEmployees;
    cout << "Enter the number of employees: ";
    while (!(cin >> numEmployees) || numEmployees <= 0) {
        cout << "Invalid input. Please enter a positive integer for number of employees: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    vector<Employee> employees(numEmployees);

    // Input details for all employees
    for (int i = 0; i < numEmployees; ++i) {
        cout << "\nEnter details for Employee " << (i + 1) << ":" << endl;
        employees[i].getDetails();
    }

    // Display pay slips
    cout << "\n\n--- Employee Pay Slips ---" << endl;
    for (int i = 0; i < numEmployees; ++i) {
        employees[i].displayPaySlip();
    }

    // Display employees with gross salary above a given value
    double salaryThreshold;
    cout << "\nEnter salary threshold to find employees earning above it: ";
    while (!(cin >> salaryThreshold)) {
        cout << "Invalid input. Please enter a numeric salary threshold: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "\nEmployees with Gross Salary > " << salaryThreshold << ":" << endl;
    bool found = false;
    for (const auto& emp : employees) {
        if (emp.getGrossSalary() > salaryThreshold) {
            cout << "- " << emp.getName() << " (Gross: " << emp.getGrossSalary() << ")" << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "No employees found with salary above " << salaryThreshold << "." << endl;
    }

    // Find total salary expenditure
    double totalExpenditure = 0;
    for (const auto& emp : employees) {
        totalExpenditure += emp.getGrossSalary();
    }
    cout << "\nTotal Salary Expenditure of the Company: " << totalExpenditure << endl;

    return 0;
}
