// "I pledge my honor that I have abided by the Stevens Honor System" - Justin Ferber

#include <iostream>
#include <cstring>

using namespace std;

int contactTop = 0;

struct Contact {
    char FirstName[50];
    char LastName[50];
    char PhoneNumber[15];
    char EmailAddress[100];
};

Contact contactStack[100];

void pushContact(Contact newContact) {
    int size = sizeof(contactStack)/sizeof(contactStack[0]);
    if (contactTop != size) {
        contactStack[contactTop] = newContact;
        contactTop++;
        cout << "Contact added." << endl;
    } else {
        cout << endl << "Stack Overflow" << endl;
    }   
}

void displayContacts() {
    if (contactTop > 0) {
        cout << endl << "Contacts: " << endl;
        cout << "-----------------------------" << endl;
        for (int i = contactTop - 1; i >= 0; i--) {
            cout << "First Name: " << contactStack[i].FirstName << endl;
            cout << "Last Name: " << contactStack[i].LastName << endl;
            cout << "Phone Number: " << contactStack[i].PhoneNumber << endl;
            cout << "Email Address: " << contactStack[i].EmailAddress << endl;
            cout << "-----------------------------" << endl;
        }
    } else {
        cout << endl << "Stack Underflow" << endl;
    }
}

void searchContactByName(const char* name) {
    for (int i = contactTop - 1; i >= 0; i--) {
        if (!strcmp(contactStack[i].FirstName, name) || !strcmp(contactStack[i].LastName, name)) {
            cout << endl << "Search Results: " << endl;
            cout << "-----------------------------" << endl;
            cout << "First Name: " << contactStack[i].FirstName << endl;
            cout << "Last Name: " << contactStack[i].LastName << endl;
            cout << "Phone Number: " << contactStack[i].PhoneNumber << endl;
            cout << "Email Address: " << contactStack[i].EmailAddress << endl;
            cout << "-----------------------------" << endl;
        }
    }
}

void popContact() {
    contactTop--;
    cout << endl << "Deleted Contact: " << endl;
    cout << "-----------------------------" << endl;
    cout << "First Name: " << contactStack[contactTop].FirstName << endl;
    cout << "Last Name: " << contactStack[contactTop].LastName << endl;
    cout << "Phone Number: " << contactStack[contactTop].PhoneNumber << endl;
    cout << "Email Address: " << contactStack[contactTop].EmailAddress << endl;
    cout << "-----------------------------" << endl;
}

int main() {
    int choice;
    while (true) {
        Contact newContact;
        cout << "\nContact Management System\n";
        cout << "1. Add Contact\n";
        cout << "2. Display Contacts\n";
        cout << "3. Search Contact\n";
        cout << "4. Delete most recently added contact\n";
        cout << "5. Exit\n";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter the contact's first name: ";
                cin >> newContact.FirstName;
                cout << "Enter your contact's last name: ";
                cin >> newContact.LastName;
                cout << "Enter your contact's phone number: ";
                cin >> newContact.PhoneNumber;
                cout << "Enter your contacts email address: ";
                cin >> newContact.EmailAddress;
                pushContact(newContact);
                break;
            case 2:
                displayContacts();
                break;
            case 3:
                if (contactTop > 0) {
                    char firstName[50];
                    cout << "Enter contact's first or last name: ";
                    cin >> firstName;
                    searchContactByName(firstName);
                } else {
                    cout << endl << "Stack Underflow" << endl;
                }
                break;
            case 4:
                if (contactTop > 0) {
                    popContact();
                } else {
                    cout << endl << "Stack Underflow" << endl;
                }
                break;
            case 5:
                cout << "Exiting the program.";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
    return 0;
}