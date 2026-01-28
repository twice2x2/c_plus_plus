#include <iostream>
using namespace std;

//Типизированное пееречисление фигур
enum ShapeType {
    SQUARE,     //Квадрат
    CIRCLE,     //Круг
    TRIANGLE    //Треугольник
};

//Функция для расчета для каждой фигуры
float Calculate(ShapeType shape, float a, float b = 0){
    switch(shape){
        case SQUARE: return a * a;          //a - сторона
        case CIRCLE: return 3.14 * a * a;   //a - радиус
        case TRIANGLE: return 0.5 * a * b;  //a - основание, b - высота
        default: return 0;
    }
}

int main(){
    setlocale(LC_ALL, "ru");

    //Пример квадрата
    float square = Calculate(SQUARE, 2);
    cout << "Площадь квадрата = " << square << endl;

    //Пример круга
    float circle = Calculate(CIRCLE, 3);
    cout << "Площадь круга = " << circle << endl;

    //Пример треугольника
    float triangle = Calculate(TRIANGLE, 3, 4);
    cout << "Площадь треугольника = " << triangle << endl;

    return 0;
}