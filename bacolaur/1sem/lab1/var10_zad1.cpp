#include <iostream>
using namespace std;

int main()
{
    // ================= FLOAT =================
    cout << "=== РАСЧЕТ В ТИПЕ FLOAT ===" << endl;
    float a_f = 100.0f;
    float b_f = 0.001f;

    cout << "a_f = " << a_f << endl;
    cout << "b_f = " << b_f << endl;

    // 1. (a - b)^4
    float num1f = (a_f - b_f) * (a_f - b_f) * (a_f - b_f) * (a_f - b_f);
    cout << "\n1) num1f = (a - b)^4 = " << num1f << endl;

    // 2. a^4 - 4a^3 b + 6a^2 b^2
    float t1 = a_f*a_f*a_f*a_f;
    float t2 = 4.0f*a_f*a_f*a_f*b_f;
    float t3 = 6.0f*a_f*a_f*b_f*b_f;
    float num2f = t1 - t2 + t3;
    cout << "2) num2f = a^4 - 4a^3b + 6a^2b^2 = " << num2f << endl;
    cout << "   слагаемые: a^4 = " << t1
         << " | -4a^3b = " << t2
         << " | +6a^2b^2 = " << t3 << endl;

    // 3. знаменатель b^4 - 4a b^3
    float d1 = b_f*b_f*b_f*b_f;
    float d2 = 4.0f*a_f*b_f*b_f*b_f;
    float denf = d1 - d2;
    cout << "3) denf = b^4 - 4ab^3 = " << denf << endl;
    cout << "   слагаемые: b^4 = " << d1
         << " | -4ab^3 = " << d2 << endl;

    // 4. разность числителя
    float diff_f = num1f - num2f;
    cout << "\n4) num1f - num2f = " << diff_f << endl;
    cout << "   должно быть b^4 = " << (b_f*b_f*b_f*b_f) << endl;
    cout << "   но из-за вычитания двух чисел ~1e8 результат искажён" << endl;

    // 5. итог
    float finf = diff_f / denf;
    cout << "5) finf = diff_f / denf = " << finf << endl;
    cout << "--> Результат с float: " << finf << endl;

    // ================= DOUBLE =================
    cout << "\n\n=== РАСЧЕТ В ТИПЕ DOUBLE ===" << endl;
    double a_d = 100.0;
    double b_d = 0.001;

    cout << "a_d = " << a_d << endl;
    cout << "b_d = " << b_d << endl;

    double num1d = (a_d - b_d) * (a_d - b_d) * (a_d - b_d) * (a_d - b_d);
    cout << "\n1) num1d = (a - b)^4 = " << num1d << endl;

    double dt1 = a_d*a_d*a_d*a_d;
    double dt2 = 4.0*a_d*a_d*a_d*b_d;
    double dt3 = 6.0*a_d*a_d*b_d*b_d;
    double num2d = dt1 - dt2 + dt3;
    cout << "2) num2d = a^4 - 4a^3b + 6a^2b^2 = " << num2d << endl;
    cout << "   слагаемые: a^4 = " << dt1
         << " | -4a^3b = " << dt2
         << " | +6a^2b^2 = " << dt3 << endl;

    double dd1 = b_d*b_d*b_d*b_d;
    double dd2 = 4.0*a_d*b_d*b_d*b_d;
    double dend = dd1 - dd2;
    cout << "3) dend = b^4 - 4ab^3 = " << dend << endl;
    cout << "   слагаемые: b^4 = " << dd1
         << " | -4ab^3 = " << dd2 << endl;

    double diff_d = num1d - num2d;
    cout << "\n4) num1d - num2d = " << diff_d << endl;
    cout << "   должно быть b^4 = " << (b_d*b_d*b_d*b_d) << endl;

    double find = diff_d / dend;
    cout << "5) find = diff_d / dend = " << find << endl;
    cout << "--> Результат с double: " << find << endl;

    return 0;
}