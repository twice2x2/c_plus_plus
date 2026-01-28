#include <iostream>
using namespace std;

int main(){
    setlocale(LC_ALL, "ru");

    int a;
    int b;

    cout << "First number: ";
    cin >> a;

    cout << "Second number: ";
    cin >> b;

    cout << a << " + " << b << " = " << a+b;
}