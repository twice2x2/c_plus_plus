#include <iostream>
using namespace std;

int main(){
    setlocale(LC_ALL, "ru");

    int c;
    
    cout << "Temperature in C*: ";
    cin >> c;

    int temp = c * 9 / 5 + 32;

    cout << "Temperature in F* = " << temp;

    return 0;
}