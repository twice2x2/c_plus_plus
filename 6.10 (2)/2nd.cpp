﻿#include <iostream>
using namespace std;

int main() {
	setlocale(LC_ALL, "ru");

	int number, total_1, total_2;

	cout << "Введите число: ";
	cin >> number;



	if (number % 2 == 0) {
		total_1 = number * 3;
		cout << "Число четное\nРезультат: " << total_1;
	}
	else if (number % 2 == 1) {
		total_2 = number / 2;
		cout << "Число нечетное\nРезультат: " << total_2;
	}

	return 0;
}