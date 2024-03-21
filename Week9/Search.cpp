#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

const int MAX_DAYS = 100;

struct StockRecord {
    string date;
    double price;
};

void inputStockPrices(StockRecord records[], int numDays) {
    for (int i = 0; i < numDays; i++) { 
        cout << "Day " << i+1 << ":\n";
        cout << "Date (YYYY-MM-DD): ";
        cin >> records[i].date;
        cout << "Stock Price: ";
        cin >> records[i].price;
    } 
}

void bubbleSort(StockRecord records[], int numDays) {
    int flag = 0;
    for (int i = 0; i < numDays - 1; i++) {
        for (int j = 0; j < numDays - i - 1; j++) {
            if (records[j].price > records[j + 1].price) {
                StockRecord temp = records[j];
                records[j] = records[j + 1];
                records[j + 1] = temp;
                flag = 1;
            }
        }
        if (flag == 0) {
            return;
        }
    }
    cout << "Stock prices sorted successfully.\n";
}

void displayBubbleSort(StockRecord records[], int days) {
    for (int i = 0; i < days; i++) {
        cout << records[i].date << ", " << records[i].price << endl;
    }
}

double calculateAveragePrice(StockRecord records[], int numDays) {
    double sum = 0;
    for (int i = 0; i < numDays; i++) {
        sum += records[i].price;
    }
    return sum / numDays;
}

void findHighestAndLowestPrices(StockRecord records[], int numDays) {
    double highest = INT_MIN;
    double lowest = INT_MAX;
    for (int i = 0; i < numDays; i++) {
        if (records[i].price < lowest) {
            lowest = records[i].price;
        } else if (records[i].price > highest) {
            highest = records[i].price;
        }
    }
    cout << "\nHighest number is: " << highest << endl;
    cout << "Lowest number is: " << lowest << endl;
}

void searchStockPricesInRange(StockRecord records[], int numDays) {
    string startDate, endDate;
    cout << "Enter start date (YYYY-MM-DD): ";
    cin >> startDate;
    cout << "Enter end date (YYYY-MM-DD): ";
    cin >> endDate;
    for (int i = 0; i < numDays; i++) {
        if (records[i].date > startDate && records[i].date < endDate) {
            cout << "Date: " << records[i].date << ", Price: " << records[i].price << endl;
        }
    }
}

int countPricesAboveThreshold(StockRecord records[], int numDays, int threshold) {
    int count = 0;
    for (int i = 0; i < numDays; i++) {
        if (records[i].price > threshold) {
            count++;
        }
    }
    return count;
}

int main() {
    int days;
    StockRecord arr[MAX_DAYS];

    cout << "Welcome to the program!" << endl;
    cout << "Enter the number of days with historical stock prices (up to 100): ";
    cin >> days;
    inputStockPrices(arr, days);
    bubbleSort(arr, days);
    displayBubbleSort(arr, days);

    while (true) {
        int userInput;
        cout << "\nAdditional features:" << endl;
        cout << "1. Calculate average price\n";
        cout << "2. Find highest and lowest prices\n";
        cout << "3. Search stock prices in range\n";
        cout << "4. Count prices above threshold\n";
        cout << "5. Exit\n";
        cout << "Select an option (1-5): ";
        cin >> userInput;
        switch (userInput) {
            case 1:
                cout << calculateAveragePrice(arr, days) << endl;
                break;
            case 2:
                findHighestAndLowestPrices(arr, days);
                break;
            case 3:
                searchStockPricesInRange(arr, days);
                break;
            case 4:
                double threshold;
                int z;
                cout << "Enter the price threshold: ";
                cin >> threshold;
                z = countPricesAboveThreshold(arr, days, threshold);
                cout << "\nNumber of days with stockprice above the threshold: " << z << endl;
                break;
            case 5:
                cout << "Quitting." << endl;
                return 0;
            default:
                cout << "Entered input is invalid.\n";
                break;
        }
    }
}