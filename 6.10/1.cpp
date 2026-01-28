#include <iostream>
using namespace std;

enum Pizza {
    MOZZARELLA,
    PEPPERONI,
    CHEESE,
    MEAT
};

enum Drink {
    COCACOLA,
    LIPTON,
    PEPSI
};

int main() {
    setlocale(LC_ALL, "ru");

    int pizzaCode, pizza_count;
    int drinkCode, drink_count;


    cout << "Меню:\nПиццы:\n";
    cout << "0. Моцарелла - $8\n";
    cout << "1. Пепперони - $10\n";
    cout << "2. Сырная - $9\n";
    cout << "3. Мясная - $11\n";

    cout << "Напитки:\n";
    cout << "0. Кока-кола - $1\n";
    cout << "1. Липтон - $3\n";
    cout << "2. Пепси - $2\n";


    cout << "Выберите пиццу: ";
    cin >> pizzaCode;
    cout << "Введите количество: ";
    cin >> pizza_count;

 
    cout << "Выберите напиток: ";
    cin >> drinkCode;
    cout << "Введите количество: ";
    cin >> drink_count;


    int pizzaPrice;
    string pizzaName;

    switch (pizzaCode) {
    case MOZZARELLA: 
        pizzaPrice = 8; 
        pizzaName = "Моцарелла"; 
        break;

    case PEPPERONI:  
        pizzaPrice = 10; 
        pizzaName = "Пепперони"; 
        break;

    case CHEESE:     
        pizzaPrice = 9; 
        pizzaName = "Сырная"; 
        break;

    case MEAT:       
        pizzaPrice = 11; 
        pizzaName = "Мясная"; 
        break;
    }



    int drinkPrice;
    string drinkName;

    switch (drinkCode) {
    case COCACOLA: 
        drinkPrice = 1; 
        drinkName = "Кока-кола";
        break;

    case LIPTON:    
        drinkPrice = 3; 
        drinkName = "Липтон"; 
        break;

    case PEPSI:     
        drinkPrice = 2; 
        drinkName = "Пепси"; 
        break;
    }


    int FreePizza = pizza_count / 5;
    int PayPizza = pizza_count - FreePizza;
    int TotalPizza = PayPizza * pizzaPrice;


    int DrinkTotal = drink_count * drinkPrice;
    if (drinkPrice > 2 && drink_count > 3) {
        DrinkTotal = DrinkTotal * 85 / 100;
    }


    
    
    int Total = TotalPizza + DrinkTotal;
    if (Total > 50) {
        Total = Total * 80 / 100;
    }
    
    cout << "Пицца: " << pizzaName << " " << pizza_count << " шт. Цена: " << TotalPizza << "\n";
    cout << "Напитки: " << pizzaName << " " << pizza_count << " шт. Цена: " << DrinkTotal << "\n";
    cout << "Оплата: " << Total;

}