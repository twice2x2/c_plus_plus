#include <iostream>
#include <cmath>
using namespace std;

//Структура прямоугольника
struct Rectangle{
    int x; //Координата x
    int y; //Координата y
    int width; //Ширина
    int height; //Высота
};

//Функция перемещения прямоугольника
void MoveRectangle(Rectangle &rectangle, int new_x, int new_y){
    rectangle.x += new_x;
    rectangle.y += new_y;
} 

//Функция изменения размера прямоугольника
void ChangeSize(Rectangle &rectangle, int new_widht, int new_height){
    rectangle.width = new_widht;
    rectangle.height = new_height;
}

//Функция печати прямоугольника
void PrintRectangle(Rectangle &rectangle){
    //Цикл внутри цикла: будет печататься прямоугольник до тех пор, пока не достигнет заданную высоту и ширину
    for(int i = 0; i < rectangle.height; i++){
        for(int j = 0; j < rectangle.width; j++){
            cout << "*";
        }
        cout << "\n";
    }
}

//Структура точки в двумерной системе координат
struct Point{
    double x;
    double y;
};

//Функция для расчета расстояния между точками
double DistancePoint(const Point &a_1, const Point &a_2){
    //Использование sqrt из cmath и использование формулы для расчета рассстояние точек
    return sqrt((a_2.x - a_1.x) * (a_2.x - a_1.x) + (a_2.y - a_1.y) * (a_2.y - a_1.y));
}

//Структура обычной дроби
struct Fraction{
    int a; //Числитель
    int b; //Знаменатель
};

//Функция сложения дробей
Fraction Fraction_Sum(const Fraction &a, const Fraction &b){
    Fraction result;
    result.a = a.a * b.b + b.a * a.b;
    result.b = a.b * b.b; 
    return result;
}

//Функция вычитания дробей
Fraction Fraction_Sub(const Fraction &a, const Fraction &b) {
    Fraction result;
    result.a = a.a * b.b - b.a * a.b;
    result.b = a.b * b.b;
    return result;
}

// Функция умножения дробей
Fraction Fraction_Mul(const Fraction &a, const Fraction &b) {
    Fraction result;
    result.a = a.a * b.a;
    result.b = a.b * b.b;
    return result;
}

// Функция деления дробей
Fraction Fraction_Div(const Fraction &a, const Fraction &b) {
    Fraction result;
    result.a = a.a * b.b;
    result.b = a.b * b.a;
    return result;
}

int main(){
    setlocale(LC_ALL, "ru");

    //Данные для прямоугольника
    Rectangle rectangle = {0, 0, 5, 5};

    cout << "ПЕРВОЕ ЗАДАНИЕ" << endl;
    //Вызов функции печати прямоугольника
    PrintRectangle(rectangle);

    cout << "Координаты до смещения: " << rectangle.x << ", " << rectangle.y << endl;
    //Вызов функции перемещения прямоугольника
    MoveRectangle(rectangle, 2, 2);
    cout << "Координаты после смещения: " << rectangle.x << ", " << rectangle.y << endl;

    cout << "Размер до изменения: " << rectangle.height << " высота, " << rectangle.width << " ширина" << endl;
    //Вызов функции изменения размера прямоугольника
    ChangeSize(rectangle, 2, 2);
    cout << "Размер после смещения: " << rectangle.height << " высота, " << rectangle.width << " ширина" << endl;

    cout << endl;
    cout << endl;

    //Задаем координаты двум точкам
    Point a{1.0, 1.0}; //Точка x
    Point b{5.0, 5.0}; //Точка y

    cout << "Точка x: " << a.x << " " << a.y << endl;
    cout << "Точка y: " << b.y << " " << b.y << endl;
    //Вызов функции для показа расстояния между точками
    cout << "Расстояние между точками: " << DistancePoint(a, b);

    cout << endl;
    cout << endl;

    Fraction f_1{2,5};
    Fraction f_2{3,4};

    //С выводом результата дробей не разобрался

    return 0;
}