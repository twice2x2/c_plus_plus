#include <iostream>
using namespace std;

bool SimpleNumber(int a){
    for(int i = 2; i * i <= a; i++){
        if(a % i == 0){
            return false;
        }
    }
    return true;
}

int main(){
    setlocale(LC_ALL, "ru");

    int a;

    cout << "a: ";
    cin >> a;

    if(SimpleNumber(a)){
        cout << "Simple";
    }
    else{
        cout << "Not Simple";
    }

    return 0;
}