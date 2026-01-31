#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    const int N = 5; // количество строк
    string arr[N];

    // Ввод массива строк
    cout << "Введите " << N << " строк:" << endl;
    for (int i = 0; i < N; i++) {
        getline(cin, arr[i]);
    }

    ofstream file("output.txt");
    if (!file.is_open()) {
        cout << "Не удалось создать файл!" << endl;
        return 1;
    }

    // Запись массива в файл
    for (int i = 0; i < N; i++) {
        file << arr[i] << endl;
    }

    file.close();

    cout << "Массив строк успешно записан в файл output.txt" << endl;

    return 0;
}
