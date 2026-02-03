#include <iostream>
#include <stack>
#include <string>

using namespace std;

//Приоритет операций
int priority(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

//Выполнение операции
double applyOperation(double a, double b, char op) {
    switch (op) {
    case '+': return a + b;
    case '-': return a - b;
    case '*': return a * b;
    case '/': return a / b;
    }
    return 0;
}

//Функция вычисления выражения
double calculate(string expr, bool& valid) {
    stack<double> numbers;
    stack<char> ops;
    valid = true;

    for (int i = 0; i < expr.size(); ++i) {
        char c = expr[i];

        if (c == ' ') continue;

        //Число
        if (isdigit(c) || c == '.') {
            double value = 0;
            double fraction = 0.1;
            bool isFraction = false;

            while (i < expr.size() && (isdigit(expr[i]) || expr[i] == '.')) {
                if (expr[i] == '.') {
                    if (isFraction) { valid = false; return 0; } //Две точки → ошибка
                    isFraction = true;
                }
                else {
                    if (!isFraction)
                        value = value * 10 + (expr[i] - '0');
                    else {
                        value += (expr[i] - '0') * fraction;
                        fraction /= 10;
                    }
                }
                ++i;
            }
            numbers.push(value);
            --i;
        }
        //Открывающая скобка
        else if (c == '(') {
            ops.push(c);
        }
        //Закрывающая скобка
        else if (c == ')') {
            while (!ops.empty() && ops.top() != '(') {
                if (numbers.size() < 2) { valid = false; return 0; }
                double b = numbers.top(); numbers.pop();
                double a = numbers.top(); numbers.pop();
                char op = ops.top(); ops.pop();
                numbers.push(applyOperation(a, b, op));
            }
            if (ops.empty()) { valid = false; return 0; } //Нет открывающей скобки
            ops.pop(); //Убираем '('
        }
        //Оператор
        else if (c == '+' || c == '-' || c == '*' || c == '/') {
            while (!ops.empty() && priority(ops.top()) >= priority(c)) {
                if (numbers.size() < 2) { valid = false; return 0; }
                double b = numbers.top(); numbers.pop();
                double a = numbers.top(); numbers.pop();
                char op = ops.top(); ops.pop();
                numbers.push(applyOperation(a, b, op));
            }
            ops.push(c);
        }
        //Любой другой символ → ошибка
        else {
            valid = false;
            return 0;
        }
    }

    //Выполнение оставшихся операций
    while (!ops.empty()) {
        if (numbers.size() < 2) { valid = false; return 0; }
        double b = numbers.top(); numbers.pop();
        double a = numbers.top(); numbers.pop();
        char op = ops.top(); ops.pop();
        numbers.push(applyOperation(a, b, op));
    }

    if (numbers.size() != 1) { valid = false; return 0; }

    return numbers.top();
}

//Главная функция
int main() {
    setlocale(LC_ALL, "RU_ru.UTF-8");

    string expression;
    cout << "Введите арифметическое выражение: ";
    getline(cin, expression);

    bool valid;
    double result = calculate(expression, valid);

    if (valid)
        cout << "Результат: " << result << endl;
    else
        cout << "Это не арифметическое выражение" << endl;

    return 0;
}
