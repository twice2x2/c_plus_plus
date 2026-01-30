#include <iostream>
#include <windows.h>  // Для работы с цветами в консоли Windows

using namespace std;

int main() {
    setlocale(LC_ALL, "ru");
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);  // Получаем доступ к консоли

    SetConsoleTextAttribute(hConsole, 5);
    cout << "\"У лукоморья дуб зелёный\"\n";

    SetConsoleTextAttribute(hConsole, 1);
    cout << "Златая цепь на дубе том\n";

    SetConsoleTextAttribute(hConsole, 2);
    cout << "И днём и ночью кот учёный\n";

    SetConsoleTextAttribute(hConsole, 3);
    cout << "Всё ходит по цепи кругом\"\n";

    SetConsoleTextAttribute(hConsole, 4);
    cout << "А.С. Пушкин\n";

    SetConsoleTextAttribute(hConsole, 15);  // Возвращаем стандартный цвет

    return 0;
}