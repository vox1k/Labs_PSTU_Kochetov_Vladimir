#include <iostream>
using namespace std;

int main()
{
    // float
    float a_f = 100.0f;
    float b_f = 0.001f;

    // (a - b)^4
    float num1f = (a_f - b_f) * (a_f - b_f) * (a_f - b_f) * (a_f - b_f);

    // a^4 - 4a^3 b + 6a^2 b^2 — раскрытие без -4ab^3 + b^4
    float num2f = a_f*a_f*a_f*a_f
                - 4.0f*a_f*a_f*a_f*b_f
                + 6.0f*a_f*a_f*b_f*b_f;

    // знаменатель: b^4 - 4a b^3
    float denf  = b_f*b_f*b_f*b_f - 4.0f*a_f*b_f*b_f*b_f;

    float finf  = (num1f - num2f) / denf;
    cout << "Результат с float:  " << finf << endl; // -0

    // double
    double a_d = 100.0;
    double b_d = 0.001;

    double num1d = (a_d - b_d) * (a_d - b_d) * (a_d - b_d) * (a_d - b_d);

    double num2d = a_d*a_d*a_d*a_d
                 - 4.0*a_d*a_d*a_d*b_d
                 + 6.0*a_d*a_d*b_d*b_d;

    double dend  = b_d*b_d*b_d*b_d - 4.0*a_d*b_d*b_d*b_d;

    double find  = (num1d - num2d) / dend;
    cout << "Результат с double: " << find << endl; // 1.04308

    return 0;
}
/* Расхождение результатов для float и double объясняется разной точностью этих типов.
Float хранит меньше значащих цифр, чем double, из-за чего при округлении теряется часть точности.
Деление на очень малое число, в свою очередь, сильно усиливает накопленную погрешность.*/