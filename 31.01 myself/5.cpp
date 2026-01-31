#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    string filename;
    int lines = 0;
    string line;

    //Ввод имени файла
    cout << "Введите имя файла: ";
    cin >> filename;

    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Не удалось открыть файл!" << endl;
        return 1;
    }

    //Подсчёт строк
    while (getline(file, line)) {
        lines++;
    }

    file.close();

    cout << "Количество строк в файле: " << lines << endl;

    return 0;
}
