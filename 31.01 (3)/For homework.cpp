#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <clocale>

using namespace std;

struct Employee {
    string surname;
    string name;
    int age;
};

vector<Employee> employees;

//Загрузка из файла
void loadFromFile(const string& filename) {
    setlocale(LC_ALL, "Russian");

    ifstream file(filename);
    if (!file) {
        cout << "Файл не найден.\n";
        return;
    }

    employees.clear();
    Employee e;
    while (file >> e.surname >> e.name >> e.age) {
        employees.push_back(e);
    }
    file.close();
}

//Сохранение в файл
void saveToFile(const string& filename) {
    setlocale(LC_ALL, "Russian");

    ofstream file(filename);
    for (const auto& e : employees) {
        file << e.surname << " " << e.name << " " << e.age << endl;
    }
    file.close();
}

//Добавление
void addEmployee() {
    setlocale(LC_ALL, "Russian");

    Employee e;
    cout << "Фамилия: ";
    cin >> e.surname;
    cout << "Имя: ";
    cin >> e.name;
    cout << "Возраст: ";
    cin >> e.age;

    employees.push_back(e);
}

//Показ всех
void showAll() {
    setlocale(LC_ALL, "Russian");

    for (const auto& e : employees) {
        cout << e.surname << " " << e.name
            << ", возраст: " << e.age << endl;
    }
}

//Удаление
void deleteEmployee() {
    setlocale(LC_ALL, "Russian");

    string surname;
    cout << "Введите фамилию для удаления: ";
    cin >> surname;

    for (size_t i = 0; i < employees.size(); i++) {
        if (employees[i].surname == surname) {
            employees.erase(employees.begin() + i);
            cout << "Сотрудник удален\n";
            return;
        }
    }
    cout << "Сотрудник не найден\n";
}

//Редактирование
void editEmployee() {
    setlocale(LC_ALL, "Russian");

    string surname;
    cout << "Введите фамилию для редактирования: ";
    cin >> surname;

    for (auto& e : employees) {
        if (e.surname == surname) {
            cout << "Новое имя: ";
            cin >> e.name;
            cout << "Новый возраст: ";
            cin >> e.age;
            return;
        }
    }
    cout << "Сотрудник не найден\n";
}

//Поиск по фамилии
void searchBySurname() {
    setlocale(LC_ALL, "Russian");

    string surname;
    cout << "Введите фамилию: ";
    cin >> surname;

    ofstream file("found.txt");
    for (const auto& e : employees) {
        if (e.surname == surname) {
            cout << e.surname << " " << e.name << " " << e.age << endl;
            file << e.surname << " " << e.name << " " << e.age << endl;
        }
    }
    file.close();
}

//Поиск по возрасту
void searchByAge() {
    setlocale(LC_ALL, "Russian");

    int age;
    cout << "Введите возраст: ";
    cin >> age;

    for (const auto& e : employees) {
        if (e.age == age) {
            cout << e.surname << " " << e.name << endl;
        }
    }
}

//Поиск по первой букве
void searchByLetter() {
    setlocale(LC_ALL, "Russian");

    char letter;
    cout << "Введите первую букву фамилии: ";
    cin >> letter;

    for (const auto& e : employees) {
        if (e.surname[0] == letter) {
            cout << e.surname << " " << e.name << endl;
        }
    }
}

int main() {
    setlocale(LC_ALL, "Russian");

    string filename;
    cout << "Введите имя файла для загрузки: ";
    cin >> filename;

    loadFromFile(filename);

    int choice;
    do {
        cout << "\n1. Добавить сотрудника"
            << "\n2. Показать всех"
            << "\n3. Редактировать"
            << "\n4. Удалить"
            << "\n5. Поиск по фамилии"
            << "\n6. Поиск по возрасту"
            << "\n7. Поиск по первой букве фамилии"
            << "\n8. Сохранить в файл"
            << "\n0. Выход\n";
        cin >> choice;

        switch (choice) {
        case 1: addEmployee(); break;
        case 2: showAll(); break;
        case 3: editEmployee(); break;
        case 4: deleteEmployee(); break;
        case 5: searchBySurname(); break;
        case 6: searchByAge(); break;
        case 7: searchByLetter(); break;
        case 8: saveToFile(filename); break;
        }
    } while (choice != 0);

    saveToFile(filename); //автосохранение
    return 0;
}
