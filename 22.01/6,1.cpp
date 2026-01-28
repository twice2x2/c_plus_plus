#include <iostream>
using namespace std;

int main(){
    setlocale(LC_ALL, "ru");

    int a = 10;
    int b = 20;

    cout << a << b << "\n";

    int *ptra = &a;
    int *ptrb = &b;

    int temp = *ptra;
    *ptra = *ptrb;
    *ptrb = temp;

    cout << a << b;

    return 0;
}