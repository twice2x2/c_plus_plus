#include <iostream>
#include <windows.h>
using namespace std;

int main() {
	setlocale(LC_ALL, "ru");
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	int text, back;
	cout << "Выберите цвет фона (От 0 до 15): ";
	cin >> back;

	cout << "Выберите цвет текста (От 0 до 15): ";
	cin >> text;

	SetConsoleTextAttribute(hConsole, (back << 4) | text);



	return 0;
}