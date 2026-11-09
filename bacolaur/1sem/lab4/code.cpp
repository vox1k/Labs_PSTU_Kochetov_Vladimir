#include <iostream>
#include <clocale>
#include <stdlib.h>
using namespace std;

int main()
{
    setlocale(LC_ALL, ".UTF-8");

    int n;
    cout << "Введите размер массива: ";
    cin >> n;

    // Вместо int a[n] — динамический массив
    int *a = new int[n];

    cout << endl << "Первоначальный массив: " << endl;
    for (int i = 0; i <= (n - 1); ++i)
    {
        a[i] = rand() % 100;
        cout << a[i] << ' ';
    }
    cout << endl;

    // После удаления 5 первых элементов и добавления 3 новых:
    // итоговый размер: n - 5 + 3 = n - 2
    int ns = n - 5 + 3;

    // Вместо int z[ns] — динамический массив
    int *z = new int[ns];
    int j = 0;

    // Копируем элементы, начиная с индекса 5 (удаляем первые 5)
    for (int i = 5; i <= (n - 1); ++i)
    {
        z[j] = a[i];
        ++j;
    }

    // Добавляем 3 новых случайных элемента в конец
    for (int k = 0; k < 3; ++k)
    {
        z[j] = rand() % 100;
        ++j;
    }

    cout << endl << "Полученный после преобразования массив:" << endl;
    for (int j = 0; j <= (ns - 1); ++j)
    {
        cout << z[j] << ' ';
    }
    cout << endl;

    // Освобождаем память
    delete[] a;
    delete[] z;

    return 0;
}