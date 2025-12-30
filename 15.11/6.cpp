#include <iostream>
#include <cstdlib>
using namespace std;

void MinAndMax() {
    const int row = 5;
    const int col = 5;
    int array[row][col];

    int min = 10;
    int max = 0;

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            array[i][j] = rand() % 10;
            cout << array[i][j] << " ";
            if (array[i][j] > max) {
                max = array[i][j];
            }
            if (array[i][j] < min) {
                min = array[i][j];
            }
        }
        cout << "\n";
    }
    cout << "Min: " << min << endl;
    cout << "Max: " << max << endl;
}

int main() {
    setlocale(LC_ALL, "ru");

    MinAndMax();

    return 0;
}