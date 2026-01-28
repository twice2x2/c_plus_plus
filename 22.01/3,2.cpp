#include <iostream>
using namespace std;

int main(){
    setlocale(LC_ALL, "ru");

    int n;
     
    cout << "n = ";
    cin >> n;

    for(int i = 1; i <= 10; i++){
        cout << n << " x " << i << " = " << n*i;
        cout << "\n\n";
    }

    return 0;
}