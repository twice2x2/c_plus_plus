#include <iostream>
using namespace std;

int main(){
    setlocale(LC_ALL, "ru");

    int n;
    cout << "n = ";
    cin >> n;

    int sum = 0;

    for(int i = 1; i <= n; i++){
        sum += i;
    }

    cout << "Otvet: " << sum;

    return 0;
}