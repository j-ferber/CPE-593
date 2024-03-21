#include <iostream>
#include <string>

using namespace std;

struct DeliveryOrder {
    string recipientName;
    string destination;
    string deliveryAddress;
    int estimatedTime;
    int orderID;
};

int partition(DeliveryOrder orders[], int left, int right) {
    int pivot = orders[right].estimatedTime;
    int i = left - 1;
    for (int j = left; j <= right; j++) {
        if (orders[j].estimatedTime < pivot) {
            i++;
            DeliveryOrder temp = orders[i];
            orders[i] = orders[j];
            orders[j] = temp;
        }
    }
    DeliveryOrder temp = orders[i+1];
    orders[i+1] = orders[right];
    orders[right] = temp;
    return i + 1;
}

void quicksortDeliveryOrders(DeliveryOrder orders[], int left, int right) {
    if (left < right) {
        int pIndex = partition(orders, left, right);
        quicksortDeliveryOrders(orders, left, pIndex - 1);
        quicksortDeliveryOrders(orders, pIndex + 1, right);
    }
}

void inputDeliveryOrders(DeliveryOrder orders[], int numOrders) {
    for (int i = 0; i < numOrders; i++) {
        cout << "\nDelivery " << i + 1 << ":\n";
        cout << "Recipient's name: ";
        cin.ignore();
        getline(cin, orders[i].recipientName);
        cout << "Destination: ";
        getline(cin, orders[i].destination);
        cout << "Delivery address: ";
        getline(cin, orders[i].deliveryAddress);
        cout << "Estimated time (minutes): ";
        cin >> orders[i].estimatedTime;
        cout << "Order ID: ";
        cin >> orders[i].orderID;
    }
}

void displaySortedOrders(DeliveryOrder orders[], int numOrders) {
    cout << "\nSorted delivery orders:\n";
    for (int i = 0; i < numOrders; i++) {
        cout << "Order ID: " << orders[i].orderID << endl;
        cout << "Recipient's name: " << orders[i].recipientName << endl;
        cout << "Destination: " << orders[i].destination << endl;
        cout << "Delivery address: " << orders[i].deliveryAddress << endl;
        cout << "Estimated Time: " << orders[i].estimatedTime << endl;
        cout << "--------------------------------\n";
    }
}

void searchByRecipientName(DeliveryOrder orders[], int numOrders, const string& recipientName) {
    cout << "\nDelivery orders for Recipient: " << recipientName << endl;
    for (int i = 0; i < numOrders; i++) {
        if (orders[i].recipientName == recipientName) {
            cout << "Order ID: " << orders[i].orderID << endl;
            cout << "Destination: " << orders[i].destination << endl;
            cout << "Estimated time: " << orders[i].estimatedTime << endl;
            cout << "--------------------------------\n";
        }
    }
}

void calculateTotalEstimatedTime(DeliveryOrder orders[], int numOrders) {
    int sum = 0;
    for (int i = 0; i < numOrders; i++) {
        sum += orders[i].estimatedTime;
    }
    cout << "\nTotal Estimated Time for All Delivery Orders: " << sum << endl;
}

void findFastestAndSlowest(DeliveryOrder orders[], int numOrders) {
    DeliveryOrder slowest = orders[0];
    DeliveryOrder fastest = orders[numOrders - 1];
    cout << "\nFastest Delivery Order:\n";
    cout << "Recipient's Name: " <<  fastest.recipientName << endl;
    cout << "Destination: " << fastest.destination << endl;
    cout << "Estimated Time: " << fastest.estimatedTime << endl;
    cout << "\nSlowest Delivery Order:\n";
    cout << "Recipient's Name: " <<  slowest.recipientName << endl;
    cout << "Destination: " << slowest.destination << endl;
    cout << "Estimated Time: " << slowest.estimatedTime << endl;
}

void displayOrdersWithinTimeRange(DeliveryOrder orders[], int numOrders, int minTime, int maxTime) {
    cout << "\nDelivery Orders Within Time Range (" << minTime << " - " << maxTime << " minutes):\n";
    for (int i = 0; i < numOrders; i++) {
        if (orders[i].estimatedTime > minTime && orders[i].estimatedTime < maxTime) {
            cout << "Order ID: " << orders[i].orderID << endl;
            cout << "Recipient's Name: " << orders[i].recipientName << endl;
            cout << "Destination: " << orders[i].destination << endl;
            cout << "Estimated Time: " << orders[i].estimatedTime << endl;
            cout << "--------------------------------" << endl;
        }
    }
}

int main() {
    int numOrders;
    cout << "Welcome to the Delivery Order Management System!\n";
    cout << "Enter the number of delivery orders: ";
    cin >> numOrders;

    DeliveryOrder orders[numOrders];

    // Input delivery orders
    inputDeliveryOrders(orders, numOrders);

    // Perform Quick Sort to sort delivery orders by estimated time
    quicksortDeliveryOrders(orders, 0, numOrders - 1);

    // Display sorted delivery orders
    displaySortedOrders(orders, numOrders);

    // Additional Tasks:

    // Task 3: Search for delivery orders by recipient's name
    string searchRecipient;
    cout << "\nEnter recipient's name to search for delivery orders: ";
    cin.ignore();
    getline(cin, searchRecipient);
    searchByRecipientName(orders, numOrders, searchRecipient);

    // Task 4: Calculate and display total estimated time
    calculateTotalEstimatedTime(orders, numOrders);

    // Task 5: Find and display the fastest and slowest delivery orders
    findFastestAndSlowest(orders, numOrders);

    // Task 6: Display delivery orders within a specific time range
    int minTime, maxTime;
    cout << "\nEnter minimum and maximum estimated time range (in minutes): ";
    cin >> minTime >> maxTime;
    displayOrdersWithinTimeRange(orders, numOrders, minTime, maxTime);

    return 0;
}
