#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Student class
class Student {
public:
    int id;
    string name;
    int age;

    // Constructor
    Student(int i, string n, int a) {
        id = i;
        name = n;
        age = a;
    }

    // Show student info
    void showInfo() {
        cout << "ID: " << id << ", Name: " << name << ", Age: " << age << endl;
    }
};

// Function to add a new student
void addStudent(vector<Student>& students) {
    int id, age;
    string name;

    cout << "Enter student ID: ";
    cin >> id;
    cin.ignore(); // Ignore leftover newline

    cout << "Enter student name: ";
    getline(cin, name);

    cout << "Enter student age: ";
    cin >> age;

    Student newStudent(id, name, age);
    students.push_back(newStudent);

    cout << "Student added successfully!\n\n";
}

// Function to show all students
void showStudents(const vector<Student>& students) {
    if (students.empty()) {
        cout << "No students available.\n\n";
        return;
    }

    cout << "List of students:\n";
    for (const auto& student : students) {
        student.showInfo();
    }
    cout << endl;
}

// Main function
int main() {
    vector<Student> students;
    int choice;

    while (true) {
        cout << "===== Student Management System =====\n";
        cout << "1. Add student\n";
        cout << "2. Show students\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Ignore leftover newline

        switch (choice) {
            case 1:
                addStudent(students);
                break;
            case 2:
                showStudents(students);
                break;
            case 3:
                cout << "Exiting program. Goodbye!\n";
                return 0;
            default:
                cout << "Invalid choice. Try again.\n\n";
        }
    }

    return 0;
}
