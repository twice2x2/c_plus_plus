﻿#include <iostream>
using namespace std;

int main() {
	setlocale(LC_ALL, "ru");

	int first, second, function;

	cout << "Первое число: ";
	cin >> first;

	cout << "Второе число: ";
	cin >> second;

	cout << "Выбор действия:\n1.+\n2.-\n3./\n4.*\nОтвет: ";
	cin >> function;

	switch (function) {
	case 1:
		cout << "Результат: " << first + second;
		break;

	case 2:
		cout << "Результат: " << first - second;
		break;

	case 3:
		cout << "Результат: " << first / second;
		break;

	case 4:
		cout << "Результат: " << first * second;
		break;
	}
	return 0;
}