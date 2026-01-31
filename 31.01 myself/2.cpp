#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    string inputFile, outputFile;

    //Ввод имён файлов
    cout << "Введите имя исходного файла: ";
    cin >> inputFile;

    cout << "Введите имя выходного файла: ";
    cin >> outputFile;

    ifstream fin(inputFile);
    ofstream fout(outputFile);

    if (!fin.is_open()) {
        cout << "Не удалось открыть исходный файл!" << endl;
        return 1;
    }

    if (!fout.is_open()) {
        cout << "Не удалось создать выходной файл!" << endl;
        return 1;
    }

    string line;
    while (getline(fin, line)) {
        for (char& c : line) {
            if (c == '0')
                c = '1';
            else if (c == '1')
                c = '0';
        }
        fout << line << endl;
    }

    fin.close();
    fout.close();

    cout << "Файл успешно обработан!" << endl;

    return 0;
}
