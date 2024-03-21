#include <iostream>
#include <vector>
using namespace std;

void increment(int *p);
int main()
{
    int a;
    a=15;
    increment(&a);
    cout<<"a value is: "<<a<<endl;
}

void increment(int *p)
{
    *p=*p+1;
}

// 1. 50
// 2. 20
// 3. 100
// 4. 16
// 5. 15