#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    // Исходные данные
    const double a = 0.1, b = 1.0;   // границы отрезка [a, b]
    const int k = 10;                // число шагов
    const int n = 20;                // число слагаемых для случая а)
    const double eps = 0.0001;       // точность для случая б)
    const double h = (b - a) / k;    // шаг изменения x

    // Заголовок таблицы
    cout << setw(6) << "x"
         << setw(12) << "S(n=20)"
         << setw(12) << "S(eps)"
         << setw(8)  << "chlenov"
         << setw(12) << "tochnoe" << endl;

    // Цикл по x от a до b с шагом h
    for (int i = 0; i <= k; i++) {
        double x = a + i * h;

        // а) сумма ряда для заданного n
        double sN = 1.0;      // нулевое слагаемое ряда равно 1
        double fact = 1.0;    // текущее значение j!
        for (int j = 1; j <= n; j++) {
            fact *= j;                   // j! = (j-1)! * j
            sN += cos(j * x) / fact;     // добавляем слагаемое cos(jx)/j!
        }

        // б) сумма ряда для заданной точности eps
        double sE = 1.0;      // начальное значение суммы
        double t;             // текущее слагаемое
        int j = 0;            // счётчик слагаемых
        fact = 1.0;           // сбрасываем факториал
        do {
            j++;
            fact *= j;
            t = cos(j * x) / fact;
            sE += t;
        } while (fabs(t) >= eps);   // продолжаем, пока слагаемое не станет меньше eps

        // Точное значение функции
        double exact = exp(cos(x)) * cos(sin(x));

        // Вывод строки таблицы
        cout << fixed << setprecision(6)
             << setw(6)  << x
             << setw(12) << sN
             << setw(12) << sE
             << setw(8)  << j
             << setw(12) << exact << endl;
    }
    return 0;
}


