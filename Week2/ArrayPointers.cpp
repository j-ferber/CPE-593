#include <iostream>
using namespace std;

// int main (){
//     int A[] = {15, 20, 25, 30, 35};
//     cout << A << endl;
//     cout << &A[0] << endl;
//     cout << A[0] << endl;
//     cout << *(A+1) << endl;
// }

int main (){
    int A[] = {15, 20, 25, 30, 35};
    for (int i = 0; i < 5; i++) {
        cout << &A[i] << endl;
        cout << A+i << endl;
        cout << A[i] << endl;
        cout << *(A+i) << endl;
    };
}

