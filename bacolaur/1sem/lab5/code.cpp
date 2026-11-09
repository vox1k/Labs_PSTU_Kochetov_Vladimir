#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <clocale>

using namespace std;

const int ROWS = 5;
const int COLS = 5;

// Функция проверяет, есть ли в указанной строке отрицательные элементы
bool hasNegative(const int arr[][COLS], int row) {
    for (int j = 0; j < COLS; ++j) {
        if (arr[row][j] < 0) {
            return true;
        }
    }
    return false;
}

// Функция удаления строк с отрицательными элементами:
// сдвигает "плохие" строки в конец, заполняя их нулями
void removeNegativeRows(int arr[][COLS], int& rows) {
    int writeIndex = 0; // Индекс для записи "хороших" строк

    // Проходим по всем строкам
    for (int i = 0; i < rows; ++i) {
        if (!hasNegative(arr, i)) {
            // Если строка "хорошая", и её нужно переместить
            if (writeIndex != i) {
                for (int j = 0; j < COLS; ++j) {
                    arr[writeIndex][j] = arr[i][j];
                }
            }
            writeIndex++;
        }
    }

    // Все оставшиеся строки (с writeIndex до rows-1) заполняем нулями
    for (int i = writeIndex; i < rows; ++i) {
        for (int j = 0; j < COLS; ++j) {
            arr[i][j] = 0;
        }
    }
}

// Вспомогательная функция для вывода массива
void printArray(const int arr[][COLS], int rows) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < COLS; ++j) {
            cout << setw(4) << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    // Устанавливаем русскую локализацию для корректного вывода в консоль
    setlocale(LC_ALL, "Russian");
    
    // Инициализация генератора случайных чисел
    srand(time(0));

    int arr[ROWS][COLS];

    // Заполнение массива случайными числами от -10 до 10
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            arr[i][j] = rand() % 21 - 10;
        }
    }

    int currentRows = ROWS;

    cout << "Исходный массив:" << endl;
    printArray(arr, currentRows);

    removeNegativeRows(arr, currentRows);

    cout << "Массив после удаления строк с отрицательными элементами:" << endl;
    printArray(arr, currentRows);

    return 0;
}