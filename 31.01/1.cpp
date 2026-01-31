#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    string filename;
    char ch;
    int count = 0;

    //Ввод имени файла и символа
    cout << "Введите имя файла: ";
    cin >> filename;

    cout << "Введите символ: ";
    cin >> ch;

    ch = tolower(ch); //Для сравнения без учёта регистра

    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Не удалось открыть файл!" << endl;
        return 1;
    }

    string word;
    while (file >> word) {
        //Проверяем первый символ слова
        if (tolower(word[0]) == ch) {
            count++;
        }
    }

    file.close();

    cout << "Количество слов, начинающихся с символа '"
        << ch << "': " << count << endl;

    return 0;
}
