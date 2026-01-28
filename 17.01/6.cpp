#include <iostream>
using namespace std;

//Типизированное пееречисление координат
enum Direction {
    NORTH = 'N',
    EAST = 'E',
    SOUTH = 'S',
    WEST = 'W'
};

//Функция для поворота координаты
void Move(Direction dir, int &x, int &y) {
    switch(dir) {
        case NORTH: y++; break; //Вверх +1
        case EAST: x++; break; //Вправо +1
        case SOUTH: y--; break; //Вверх -1
        case WEST: x--; break; //Вправо -1
    }
}

int main(){
    setlocale(LC_ALL, "ru");

    //Начальные координаты
    int x = 0;
    int y = 0;

    cout << "Текущие координаты" << endl;
    cout << "x = " << x << " y = " << y << endl; 

    //Перемещение координат с помощью функции
    Move(NORTH, x, y);
    cout << "Новые координаты" << endl;
    cout << "x = " << x << " y = " << y << endl;

    Move(EAST, x, y);
    cout << "Новые координаты" << endl;
    cout << "x = " << x << " y = " << y << endl;

    return 0;
}