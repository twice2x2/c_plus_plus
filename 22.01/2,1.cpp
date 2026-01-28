#include <iostream>
using namespace std;

int main(){
    setlocale(LC_ALL, "ru");

    int number;
    
    cout << "Number: ";
    cin >> number;

    if(number % 2 == 0){
        cout << "Chet";
    }
    else{
        cout << "NeChet";
    }


    return 0;
}