// "I pledge my honor that I have abided by the Stevens Honor System" - Justin Ferber

#include <iostream>
#include <cstring>

using namespace std;

// Structure for a single contact
struct Contact {
    char firstName[50];
    char lastName[50];
    char phoneNumber[15];
    char emailAddress[100];
    struct Contact *next;
};

// Function to create a new contact and add it to the linked list, returning the new head
Contact* createAndAddContact(Contact* head) {
    struct Contact *newContact = (struct Contact*)malloc(sizeof(struct Contact));
    cout << "Enter First Name: ";
    cin >> newContact -> firstName;
    cout << "Enter Last Name: ";
    cin >> newContact -> lastName;
    cout << "Enter Phone Number: ";
    cin >> newContact -> phoneNumber;
    cout << "Enter Email Address: ";
    cin >> newContact -> emailAddress;
    struct Contact *current = head;
    if (current == NULL) {
        current = newContact;
        return current;
    };
    while (current -> next != NULL) {
        current = current -> next;
    };
    current -> next = newContact;
    return head;
};

// Function to display all contacts
void displayContacts(Contact* head) {
    struct Contact *current = head;
    if (current == NULL) {
        cout << "There are no contacts in the list." << endl;
    };
    while (current != NULL) {
        cout << "First Name: " << current -> firstName << endl << "Last Name: " << current -> lastName << endl << "Phone Number: " << current -> phoneNumber << endl << "Email Address: " << current -> emailAddress << endl << "---------------" << endl;
        current = current -> next;
    };
};

// Function to search for a contact by name
void searchContact(Contact* head, char* name) {    
    struct Contact *current = head;
    bool found = false;
    while (current != NULL) {
        if (strcmp(current -> firstName, name) == 0 || strcmp(current -> lastName, name) == 0) {
            found = true;
            cout << endl << "First Name: " << current -> firstName << endl << "Last Name: " << current -> lastName << endl << "Phone Number: " << current -> phoneNumber << endl << "Email Address: " << current -> emailAddress << endl << "---------------" << endl;
            break;
        }
        else {
            current = current -> next;
        };
    };
    if (!found) {
        cout << "Name not found in list.";
    };
};

Contact* searchAndDeleteContact(Contact* head, char* name) {    
    struct Contact *current = head;
    struct Contact *prev = NULL;
    bool found = false;
    if (current -> next == NULL) {
        return current -> next;
    } else {
        while (current != NULL) {
            if (strcmp(current -> firstName, name) == 0 || strcmp(current -> lastName, name) == 0) {
                found = true;
                prev -> next = current -> next;
                return head;
            }
            else {
                prev = current;
                current = current -> next;
            };
        };
        if (!found) {
            cout << "Name not found in list.";
        };
    };
    return head;
};

int main() {
    Contact* contacts = nullptr;
    int choice;
    char searchName[50];

    while (true) {
        cout << "\nContact Management System\n";
        cout << "1. Add Contact\n";
        cout << "2. Display Contacts\n";
        cout << "3. Search Contact\n";
        cout << "4. Exit\n";
        cout << "5. Search and Delete Contact\n";
        cin >> choice;

        switch (choice) {
            case 1:
                contacts = createAndAddContact(contacts);
                break;
            case 2:
                displayContacts(contacts);
                break;
            case 3:
                cout << "Enter the name to search for: ";
                cin >> searchName;
                searchContact(contacts, searchName);
                break;
            case 4:
                return 0;
            case 5:
                cout << "Enter the contact you want to delete: ";
                cin >> searchName;
                contacts = searchAndDeleteContact(contacts, searchName);
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
