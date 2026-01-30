#include <iostream>
#include <ctime>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    srand(time(0));
    int secret = rand() % 500 + 1;
    int guess;
    int attempts = 0;

    time_t startTime = time(0);

    cout << "Игра «Угадай число»" << endl;
    cout << "Я загадал число от 1 до 500." << endl;
    cout << "Введите 0, чтобы выйти." << endl;

    while (true) {
        setlocale(LC_ALL, "Russian");

        cout << "\nВведите число: ";
        cin >> guess;

        if (guess == 0) {
            cout << "Вы вышли из игры." << endl;
            return 0;
        }

        attempts++;

        if (guess < secret) {
            cout << "Загаданное число БОЛЬШЕ." << endl;
        }
        else if (guess > secret) {
            cout << "Загаданное число МЕНЬШЕ." << endl;
        }
        else {
            time_t endTime = time(0);
            double seconds = difftime(endTime, startTime);

            cout << "\nПоздравляем! Вы угадали число!" << endl;
            cout << "Количество попыток: " << attempts << endl;
            cout << "Затраченное время: " << seconds << " секунд" << endl;
            break;
        }
    }

    return 0;
}
