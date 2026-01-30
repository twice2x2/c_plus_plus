#include <iostream>
#include <clocale>

using namespace std;

struct Fraction {
    int num; //числитель
    int den; //знаменатель
};

//НОД (для сокращения)
int gcd(int a, int b) {

    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

//Сокращение дроби
Fraction reduce(Fraction f) {

    int d = gcd(abs(f.num), abs(f.den));
    f.num /= d;
    f.den /= d;
    return f;
}

//Сложение
Fraction add(Fraction a, Fraction b) {

    Fraction r;
    r.num = a.num * b.den + b.num * a.den;
    r.den = a.den * b.den;
    return reduce(r);
}

//Вычитание
Fraction subtract(Fraction a, Fraction b) {

    Fraction r;
    r.num = a.num * b.den - b.num * a.den;
    r.den = a.den * b.den;
    return reduce(r);
}

//Умножение
Fraction multiply(Fraction a, Fraction b) {

    Fraction r;
    r.num = a.num * b.num;
    r.den = a.den * b.den;
    return reduce(r);
}

//Деление
Fraction divide(Fraction a, Fraction b) {

    Fraction r;
    r.num = a.num * b.den;
    r.den = a.den * b.num;
    return reduce(r);
}

//Печать дроби (смешанная форма)
void printFraction(Fraction f) {

    if (f.num >= f.den) {
        int whole = f.num / f.den;
        int rest = f.num % f.den;
        if (rest == 0)
            cout << whole << endl;
        else
            cout << whole << " " << rest << "/" << f.den << endl;
    }
    else {
        cout << f.num << "/" << f.den << endl;
    }
}

int main() {
    setlocale(LC_ALL, "Russian");

    Fraction a, b;

    cout << "Введите первую дробь (числитель знаменатель): ";
    cin >> a.num >> a.den;

    cout << "Введите вторую дробь (числитель знаменатель): ";
    cin >> b.num >> b.den;

    cout << "\nСумма: ";
    printFraction(add(a, b));

    cout << "Разность: ";
    printFraction(subtract(a, b));

    cout << "Произведение: ";
    printFraction(multiply(a, b));

    cout << "Частное: ";
    printFraction(divide(a, b));

    return 0;
}
