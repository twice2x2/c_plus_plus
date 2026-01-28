#include <iostream>
using namespace std;

int main(){
    setlocale(LC_ALL, "ru");

    int numbers[10];

    cout << "10 number = ";
    for(int i = 1; i < 10; i++){
        cin >> numbers[i];
    }

    int min = numbers[0];

    for(int i = 1; i < 10; i++){
        if(numbers[i] < min){
            min = numbers[i];
        }
    }

    cout << "Min = " << min;

    return 0;
}