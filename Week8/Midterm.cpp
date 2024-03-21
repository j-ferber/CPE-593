// "I pledge my Honor that I have abided by the Stevens Honor System" - Justin Ferber

#include <iostream>

using namespace std;

struct Student {
    char firstName[50];
    char lastName[50];
    int rollNumber;
    float gpa;
    struct Student* next;
};

Student* students = nullptr;

Student* addStudent(Student *head) {
    struct Student *newStudent = (struct Student*)malloc(sizeof(struct Student));
    cout << "Enter first name: ";
    cin >> newStudent -> firstName;
    cout << "Enter last name: ";
    cin >> newStudent -> lastName;
    cout << "Enter roll number: ";
    cin >> newStudent -> rollNumber;
    cout << "Enter GPA: ";
    cin >> newStudent -> gpa;
    cout << "Student added successfully." << endl;
    struct Student *current = head;
    if (current == NULL) {
        current = newStudent;
        return current;
    }
    newStudent->next = head;
    return newStudent;
};

void displayAllStudents(Student *head) {
    if (head == NULL) {
        cout << "The list is empty" << endl;
    } else {
        struct Student *current = head;
        while (current != NULL) {
            cout << "First name: " << current->firstName << ", " << "Last name: " << current->lastName << ", " << "Roll number: " << current->rollNumber << ", " << "GPA: " << current->gpa << endl;
            current = current -> next;
        }
    }
}

void calculateAverageGPA(Student *head) {
    if (head == NULL) {
        cout << "The list is empty." << endl;
    } else {
        float sum = 0;
        int length = 0;
        struct Student *current = head;
        while (current != NULL) {
            sum += current->gpa;
            length += 1;
            current = current -> next;
        }
        cout << "Average of all students: " << sum/length << endl;
    }
}

Student* removeStudent(Student* head) {
    if (head == NULL) {
        cout << "The list is empty." << endl;
        return head;
    } else {
        int choice;
        cout << "Enter the roll number of the student to remove: ";
        cin >> choice;
        struct Student *current = head;
        struct Student *prev = NULL;
        if (current -> next == NULL) {
            cout << "Student removed successfully." << endl;
            return current -> next;
        }
        while (current != NULL) {
            if (current->rollNumber == choice) {
                if (current == head) {
                    cout << "Student removed successfully." << endl;
                    return current -> next;
                }
                prev->next = current->next;
                cout << "Student removed successfully." << endl;
                return head;
            } else {
                prev = current;
                current = current->next;
            }
        }
        return head;
    }
}

int main() {
    int choice;
    while (true) {
        cout << "Options:\n";
        cout << "1. Add a student\n";
        cout << "2. Remove a student\n";
        cout << "3. Display all students\n";
        cout << "4. Calculate the average GPA of all students\n";
        cout << "5. Quit the program\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                students = addStudent(students);
                break;
            case 2:
                students = removeStudent(students);
                break;
            case 3:
                displayAllStudents(students);
                break;
            case 4:
                calculateAverageGPA(students);
                break;
            case 5:
                cout << "Goodbye!";
                return 0;
            default:
                cout << "Invalid input. Please try again.";
        }
    }
}