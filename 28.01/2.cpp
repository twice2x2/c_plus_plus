#include <iostream>
#include <cmath>

using namespace std;

struct Point {
    double x;
    double y;
};

// Функция вычисления расстояния между двумя точками
double distanceBetweenPoints(const Point& a, const Point& b) {

    return sqrt((b.x - a.x) * (b.x - a.x) +
        (b.y - a.y) * (b.y - a.y));
}

int main() {
    setlocale(LC_ALL, "Russian");

    Point p1, p2;

    cout << "Введите координаты первой точки (x y): ";
    cin >> p1.x >> p1.y;

    cout << "Введите координаты второй точки (x y): ";
    cin >> p2.x >> p2.y;

    double dist = distanceBetweenPoints(p1, p2);

    cout << "Расстояние между точками: " << dist << endl;

    return 0;
}
