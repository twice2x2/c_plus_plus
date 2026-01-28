#include <iostream>
using namespace std;

int MaxNumber(int a, int b){
    return(a > b) ? a : b;
}

int main(){
    setlocale(LC_ALL, "ru");

    int x;
    int y;

    cout << "x: ";
    cin >> x;

    cout << "y: ";
    cin >> y;

    cout << "Max = " << max(x,y);

    return 0;
}