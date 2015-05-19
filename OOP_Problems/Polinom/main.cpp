#include <iostream>
#include <iomanip>
#include "Polinom.h"
using namespace std;

int main()
{
    int arr[] = {1, 2, 3};
    int arr2[] = {-2, 1};

    Polinom p(arr2, 1), a(arr, 2);

    cout << setw(10) <<"p: " << setw(2) << p << endl;
    cout << setw(10) <<"a: "<< setw(2) << a << endl;
    cout << setw(10) <<"a+p: "<< setw(2) <<a+p << endl;
    cout << setw(0) <<"(a+p)(1): " << setw(2) << (a+p)(1) << endl;
    cout << setw(10) << "--a: " << setw(2) << --a << endl;
    cout << setw(10) << "++a: " << setw(2) << ++a << endl;
    cout << setw(10) << "a[2]: " << setw(2) << a[2] << endl;
    Polinom m = a-=p;
    cout << setw(10) << "a += p: " << setw(2) << m << endl;
    cout << setw(10) << "a: " << setw(2) << a <<endl;
    p *= -1;
    cout << setw(10) << "p *= -1: " << setw(2) << p << endl;
    cout << setw(10) << "a*p: " << setw(2) << a*p << endl;

    return 0;
}
