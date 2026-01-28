#include <iostream>
using namespace std;

//Функция сложения
int sum(int a, int b){  
    return a + b;
}

//Функция вычитания
int sub(int a, int b){  
    return a - b;
}

//Функция умножения
int mul(int a, int b){ 
    return a * b;
}

//Функция деления
int dib(int a, int b){  
    return a / b;
}

int main(){
    setlocale(LC_ALL, "ru");

    //Указатель на функцию 
    int(*operation)(int, int);
    //Переменные чисел
    int x;
    int y;
    //Переменная знака
    char choose;

    //Меню пользователя
    cout << "First number: " << endl;
    cin >> x;
    cout << "Second number: " << endl;
    cin >> y;
    cout << "Choose: " << endl;
    cin >> choose;

    //Switch: выполняется команда в зависимости от введенного знака
    switch(choose){
        case '+': operation = sum; break;
        case '-': operation = sub; break;
        case '*': operation = mul; break;
        case '/': operation = dib; break;
        default: cout << "Ошибка!";
    }

    //Вывод результата
    cout << "Result: " << x << choose << y << " = " << operation(x,y);

    return 0;
}