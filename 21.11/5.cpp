#include <iostream>
using namespace std;

int Max(int a, int b){
    if(a > b){
        return a;
    }
    else{
        return b;
    }
}

int Max(int a, int b, int c){
    if(a > b & a > c){
        return a;
    }
    if(b > a & b > c){
        return b;
    }
    else{
        return c;
    }
}



int main(){
    setlocale(LC_ALL, "ru");

    cout << "Максимальное из двух: " << Max(5,7) << endl;
    cout << "Максимальное из трех: " << Max(6,3,8) << endl; 


    return 0;
}