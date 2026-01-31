#include <iostream>
#include <fstream>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    string filename;
    int count = 0;
    char ch;

    //Ввод имени файла
    cout << "Введите имя файла: ";
    cin >> filename;

    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Не удалось открыть файл!" << endl;
        return 1;
    }

    //Подсчёт символов
    while (file.get(ch)) {
        count++;
    }

    file.close();

    cout << "Количество символов в файле: " << count << endl;

    return 0;
}
