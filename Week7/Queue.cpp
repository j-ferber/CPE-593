#include <iostream>
#include <string>
using namespace std;

const int MAX_SIZE = 100; // Maximum number of reservations
string arr[MAX_SIZE];
int front = 0;
int rear = -1;

bool isFull() {
    if (rear == MAX_SIZE) {
        cout << "\nThe queue is full." << endl;
        return true;
    }
    return false;
}

bool isEmpty() {
    if (rear == front - 1) {
        cout << "\nThe queue is empty." << endl;
        return true;
    };
    return false;
}

void enqueue(string customerName) {
    rear++;
    arr[rear] = customerName;
    cout << "\nReservation for " << customerName << " added to the queue." << endl;
}

void dequeue() {
    if (rear >= front) {
        front++;
    };
}

void display() {
    if (rear == front - 1) {
        cout << "\nThe queue is empty." << endl;
    } else {
        for (int i = front; i <= rear; i++) {
            cout << i - front + 1 << ". " << arr[i] << endl;
        };
    }
}

void cancelReservation(string customerName) {
    for (int i = front; i <= rear; i++) {
        if (arr[i] == customerName) {
            for (int j = i; j <= rear; j++) {
                arr[j] = arr[j+1];
            }
            rear--;
            cout << "\nReservation for " << customerName << " was cancelled." <<endl;
        }
    }
}

bool checkAvailability(string customerName) {
    for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++) {
        if (arr[i] == customerName) {
            cout << "You already have a reservation." << endl;
            return true;
        };
    };
    cout << "No reservation found." << endl;
    return false;
}

void clearQueue() {
    if (rear != -1) {
        front = rear + 1;
    }
}

int getQueueSize() {
    if (rear == -1) {
        return 0;
    } else {
        return rear - front + 1;
    };
}

void peekFront() {
    if (rear >= 0) {
        cout << arr[front] << " is at the front of the line." << endl;
    } else {
        cout << "The queue is empty." << endl;
    }
}

void peekRear() {
    if (rear >= 0) {
        cout << arr[rear] << " is at the back of the line." << endl;
    } else {
        cout << "The queue is empty." << endl;
    }
}

int main() {
    int choice;
    string customerName;
    cout << "Welcome to the Movie Theater Ticket Booking System!" << endl;
    do {
        cout << "\n1. Book a ticket\n2. Cancel a reservation\n3. Display reservations\n";
        cout << "4. Check availability\n5. Clear all reservations\n6. Get queue size\n";
        cout << "7. Peek at front\n8. Peek at rear\n9. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter customer name: ";
                cin >> customerName;
                enqueue(customerName);
                break;
            case 2:
                cout << "Enter customer name to cancel: ";
                cin >> customerName;
                cancelReservation(customerName);
                cout << "Reservation for " << customerName << " canceled." << endl;
                break;
            case 3:
                display();
                break;
            case 4:
                cout << "Enter customer name to check availability: ";
                cin >> customerName;
                checkAvailability(customerName);
                break;
            case 5:
                clearQueue();
                break;
            case 6:
                cout << "Queue size: " << getQueueSize() << " reservations." << endl;
                break;
            case 7:
                peekFront();
                break;
            case 8:
                peekRear();
                break;
            case 9:
                cout << "Exiting the program. Thank you!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
        } while (choice != 9);
        return 0;
}