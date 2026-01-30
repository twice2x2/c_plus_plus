#include <iostream>

using namespace std;

struct Rectangle {
    int x;
    int y;
    int width;
    int height;
};

// Печать прямоугольника
void printRectangle(const Rectangle& r) {
    setlocale(LC_ALL, "Russian");

    cout << "Координаты: (" << r.x << ", " << r.y << ")\n";
    cout << "Ширина: " << r.width << endl;
    cout << "Высота: " << r.height << endl;
}

// Перемещение прямоугольника
void moveRectangle(Rectangle& r, int dx, int dy) {

    r.x += dx;
    r.y += dy;
}

// Изменение размера прямоугольника
void resizeRectangle(Rectangle& r, int newWidth, int newHeight) {

    r.width = newWidth;
    r.height = newHeight;
}

int main() {
    setlocale(LC_ALL, "Russian");

    Rectangle rect;

    cout << "Введите координаты x y: ";
    cin >> rect.x >> rect.y;
    cout << "Введите ширину и высоту: ";
    cin >> rect.width >> rect.height;

    cout << "\nИсходный прямоугольник:\n";
    printRectangle(rect);

    cout << "\nПеремещение (dx dy): ";
    int dx, dy;
    cin >> dx >> dy;
    moveRectangle(rect, dx, dy);

    cout << "\nПосле перемещения:\n";
    printRectangle(rect);

    cout << "\nНовый размер (ширина высота): ";
    int w, h;
    cin >> w >> h;
    resizeRectangle(rect, w, h);

    cout << "\nПосле изменения размера:\n";
    printRectangle(rect);

    return 0;
}
