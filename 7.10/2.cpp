#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    double rub, usd, eur;
    const double RUB_TO_USD = 0.013; // 1 рубль = 0.013 долларов
    const double RUB_TO_EUR = 0.012; // 1 рубль = 0.012 евро
    const double USD_TO_RUB = 77.0;  // 1 доллар = 77 рублей
    const double EUR_TO_RUB = 83.0;  // 1 евро = 83 рубля

    int choice;

    do {
        cout << "\n=== Конвертер валют ===\n";
        cout << "1. Рубли -> Доллары\n";
        cout << "2. Рубли -> Евро\n";
        cout << "3. Доллары -> Рубли\n";
        cout << "4. Евро -> Рубли\n";
        cout << "5. Выход\n";
        cout << "Выберите действие: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Введите сумму в рублях: ";
            cin >> rub;
            usd = rub * RUB_TO_USD;
            cout << rub << " RUB = " << usd << " USD\n";
            break;
        case 2:
            cout << "Введите сумму в рублях: ";
            cin >> rub;
            eur = rub * RUB_TO_EUR;
            cout << rub << " RUB = " << eur << " EUR\n";
            break;
        case 3:
            cout << "Введите сумму в долларах: ";
            cin >> usd;
            rub = usd * USD_TO_RUB;
            cout << usd << " USD = " << rub << " RUB\n";
            break;
        case 4:
            cout << "Введите сумму в евро: ";
            cin >> eur;
            rub = eur * EUR_TO_RUB;
            cout << eur << " EUR = " << rub << " RUB\n";
            break;
        case 5:
            cout << "Выход из программы.\n";
            break;
        default:
            cout << "Неверный выбор. Попробуйте снова.\n";
        }
    } while (choice != 5);

    return 0;
}
