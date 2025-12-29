﻿#include <iostream>
using namespace std;

int main() {
	setlocale(LC_ALL, "ru");

	int one, two, three, four, five;

	cout << "Введите первую оценку студента: ";
	cin >> one;

	cout << "Введите вторую оценку студента: ";
	cin >> two;

	cout << "Введите третью оценку студента: ";
	cin >> three;

	cout << "Введите четвертую оценку студента: ";
	cin >> four;

	cout << "Введите пятую оценку студента: ";
	cin >> five;

	int summa = one + two + three + four + five;

	if ((summa / 5) >= 4) {
		cout << "Допуск";
	}
	else {
		cout << "Не допуск";
	}

	return 0;
}