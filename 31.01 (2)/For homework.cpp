#include <iostream>
using namespace std;

//Меньшее из двух чисел
#define MIN(a, b) ((a) < (b) ? (a) : (b))

//Большее из двух чисел
#define MAX(a, b) ((a) > (b) ? (a) : (b))

//Квадрат числа
#define SQR(x) ((x) * (x))

//Возведение числа в степень
#define POW(x, y) (pow((x), (y)))

//Проверка на четность
#define IS_EVEN(x) ((x) % 2 == 0)

//Проверка на нечетность
#define IS_ODD(x) ((x) % 2 != 0)

int main() {
    setlocale(LC_ALL, "Russian");
    int a = 5, b = 8;

    cout << "Минимум: " << MIN(a, b) << endl;
    cout << "Максимум: " << MAX(a, b) << endl;
    cout << "Квадрат a: " << SQR(a) << endl;
    cout << "a в степени 3: " << POW(a, 3) << endl;

    if (IS_EVEN(a))
        cout << "a — четное число\n";
    else
        cout << "a — нечетное число\n";

    return 0;
}
