// "I pledge my honor that I have abided by the Stevens Honor System" - Justin Ferber

#include <iostream>
#include <string>

using namespace std;

int main() {
    int first, second;
    char c;
    while (true) {
        cout << "Enter an odd integer number between 1-15, inclusively: ";
        cin >> first;
        if (first >= 1 && first <= 15 && first % 2 != 0) {
            while (true) {
                cout << "Enter a second odd integer number between " << first+2 << "-17 inclusively: ";
                cin >> second;
                if (second >= first + 2 && second <= 17 && second % 2 != 0) {
                    break;
                } else {
                    cout <<"Entered number is not valid for second number. Please try again." << endl;
                };
            }
            break;
        } else {
            cout << "Entered number is invalid. Please try again." << endl;
        };
    };

    cout << "Enter a character to make the trapezoid with: ";
    cin >> c;

    string strChar;
    for (int i = 0; i < first; i++) {
        strChar += c;
    };

    int totalRows = (second-first) / 2 + 1;
    for (int i = 0; i < totalRows; i++) {
        string spaces;
        for (int j = 0; j < totalRows - 1 - i; j++) {
            spaces.append(" ");
        };
        cout << spaces << strChar << endl;
        strChar = strChar + c + c;
    };

    return 0;
};