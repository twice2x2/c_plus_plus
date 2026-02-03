#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

struct Song {
    string title;
    string author;
    int year;
    string text;
};

vector<Song> catalog;

//Вывод каталога песен с номерами
void showCatalog() {
    if (catalog.empty()) {
        cout << "Каталог пуст!\n";
        return;
    }
    cout << "--- Список песен ---\n";
    for (int i = 0; i < catalog.size(); i++) {
        cout << i + 1 << ". " << catalog[i].title << " (" << catalog[i].author << ")\n";
    }
    cout << "-------------------\n";
}

//Добавление песни
void addSong() {
    setlocale(LC_ALL, "RU_ru.UTF-8");
    Song s;
    cout << "Название песни: ";
    getline(cin, s.title);

    cout << "Автор текста: ";
    getline(cin, s.author);

    cout << "Год создания (0 если неизвестен): ";
    cin >> s.year;
    cin.ignore();

    cout << "1 - Ввести текст с клавиатуры\n2 - Загрузить текст из файла\nВыбор: ";
    int choice;
    cin >> choice;
    cin.ignore();

    if (choice == 1) {
        cout << "Введите текст песни (конец — пустая строка):\n";
        string line;
        while (true) {
            getline(cin, line);
            if (line.empty()) break;
            s.text += line + "\n";
        }
    }
    else if (choice == 2) {
        cout << "Имя файла: ";
        string filename;
        getline(cin, filename);
        ifstream file(filename);
        if (!file) {
            cout << "Ошибка открытия файла!\n";
            return;
        }
        string line;
        while (getline(file, line)) {
            s.text += line + "\n";
        }
        file.close();
    }
    else {
        cout << "Неверный выбор!\n";
        return;
    }

    catalog.push_back(s);
    cout << "Песня добавлена!\n";
}

//Удаление песни
void deleteSong() {
    setlocale(LC_ALL, "RU_ru.UTF-8");
    if (catalog.empty()) {
        cout << "Каталог пуст!\n";
        return;
    }
    showCatalog();
    cout << "Введите номер песни: ";
    int index;
    cin >> index;
    cin.ignore();

    if (index < 1 || index > catalog.size()) {
        cout << "Неверный номер!\n";
        return;
    }
    catalog.erase(catalog.begin() + index - 1);
    cout << "Песня удалена!\n";
}

//Изменение текста
void editSong() {
    setlocale(LC_ALL, "RU_ru.UTF-8");
    if (catalog.empty()) {
        cout << "Каталог пуст!\n";
        return;
    }
    showCatalog();
    cout << "Введите номер песни: ";
    int index;
    cin >> index;
    cin.ignore();

    if (index < 1 || index > catalog.size()) {
        cout << "Неверный номер!\n";
        return;
    }

    cout << "Введите новый текст (конец — пустая строка):\n";
    catalog[index - 1].text.clear();
    string line;
    while (true) {
        getline(cin, line);
        if (line.empty()) break;
        catalog[index - 1].text += line + "\n";
    }

    cout << "Текст изменён!\n";
}

//Показ текста песни
void showSong() {
    setlocale(LC_ALL, "RU_ru.UTF-8");
    if (catalog.empty()) {
        cout << "Каталог пуст!\n";
        return;
    }
    showCatalog();
    cout << "Введите номер песни: ";
    int index;
    cin >> index;
    cin.ignore();

    if (index < 1 || index > catalog.size()) {
        cout << "Неверный номер!\n";
        return;
    }

    Song s = catalog[index - 1];
    cout << "\nНазвание: " << s.title
        << "\nАвтор: " << s.author
        << "\nГод: " << (s.year == 0 ? "неизвестен" : to_string(s.year))
        << "\n\nТекст:\n" << s.text << endl;
}

//Сохранение песни в файл
void saveToFile() {
    setlocale(LC_ALL, "RU_ru.UTF-8");
    if (catalog.empty()) {
        cout << "Каталог пуст!\n";
        return;
    }
    showCatalog();
    cout << "Введите номер песни: ";
    int index;
    cin >> index;
    cin.ignore();

    if (index < 1 || index > catalog.size()) {
        cout << "Неверный номер!\n";
        return;
    }

    cout << "Имя файла: ";
    string filename;
    getline(cin, filename);

    ofstream file(filename);
    Song s = catalog[index - 1];
    file << s.title << "\n" << s.author << "\n" << s.year << "\n\n" << s.text;
    file.close();

    cout << "Сохранено в файл!\n";
}

//Поиск по автору
void searchByAuthor() {
    setlocale(LC_ALL, "RU_ru.UTF-8");
    cout << "Введите автора: ";
    string author;
    getline(cin, author);

    bool found = false;
    for (int i = 0; i < catalog.size(); i++) {
        if (catalog[i].author == author) {
            cout << i + 1 << ". " << catalog[i].title << endl;
            found = true;
        }
    }
    if (!found) cout << "Песни данного автора не найдены.\n";
}

//Поиск по слову
void searchByWord() {
    setlocale(LC_ALL, "RU_ru.UTF-8");
    cout << "Введите слово: ";
    string word;
    getline(cin, word);

    bool found = false;
    for (int i = 0; i < catalog.size(); i++) {
        if (catalog[i].text.find(word) != string::npos) {
            cout << i + 1 << ". " << catalog[i].title << endl;
            found = true;
        }
    }
    if (!found) cout << "Песен с этим словом не найдено.\n";
}

//Меню
int main() {
    setlocale(LC_ALL, "RU_ru.UTF-8");
    while (true) {
        cout << "--- Каталог текстов песен ---\n";
        cout << "1. Добавить песню\n";
        cout << "2. Удалить песню\n";
        cout << "3. Изменить текст песни\n";
        cout << "4. Показать текст песни\n";
        cout << "5. Сохранить песню в файл\n";
        cout << "6. Поиск по автору\n";
        cout << "7. Поиск по слову\n";
        cout << "0. Выход\n";
        cout << "Выбор: ";

        int choice;
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1: addSong(); break;
        case 2: deleteSong(); break;
        case 3: editSong(); break;
        case 4: showSong(); break;
        case 5: saveToFile(); break;
        case 6: searchByAuthor(); break;
        case 7: searchByWord(); break;
        case 0: return 0;
        default: cout << "Неверный выбор!\n";
        }
    }
}
