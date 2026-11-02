#include <iostream>
#include <clocale>
using namespace std;

int main() {
    setlocale(LC_ALL, ".UTF8");
    int n;
    cout << "Введите длину катета: ";
    cin >> n;

    for (int i = 1; i <= n; i++) {
        // сначала пробелы для выравнивания по правому краю
        for (int s = 0; s < n - i; s++) {
            cout << ' ';
        }
        // затем звёздочки
        for (int j = 0; j < i; j++) {
            cout << '*';
        }
        cout << '\n';
    }

    return 0;
}