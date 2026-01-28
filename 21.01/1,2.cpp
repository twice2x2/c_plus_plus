#include <iostream>
#include <cstring>
using namespace std;

//Функция
int compareStrings(const char* a, const char* b){
    return strcmp(a,b); //Возвращает значение в зависимости от сравнения строк 
}                       // 0 - равны, >0 - первая строка больше второй, <0 - вторая строка больше первой

int main(){
    setlocale(LC_ALL, "ru");

    //Указатель на функцию
    int(*compare)(const char*, const char*) = compareStrings;

    //Переменные с строками
    char a[100];
    char b[100];

    //Меню пользователя
    cout << "First string: ";
    cin >> a;
    cout << "Second string: ";
    cin >> b;

    //Результат с функции
    int result = compare(a,b);

    //Условие проверки сравнения строк
    if(result > 0){
        cout << "First > Second";
    }
    else if(result = 0){
        cout << "First = Second";
    }
    else{
        cout << "First < Second";
    }

    return 0;
}