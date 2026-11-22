#include <iostream>
#include <clocale>
using namespace std;

// n дисков, переносим со стержня `from` на `to`.
// `free` — битовая маска свободных стержней (5 стержней => биты 0..4).
void han(int n, int from, int to, int free) {
    if (n <= 0) return;

    // Собираем список доступных стержней
    int avail[5], cnt = 0;
    for (int i = 0; i < 5; ++i)
        if (free & (1 << i)) avail[cnt++] = i;

    if (n == 1 || cnt == 2) {   // классический случай: 2 стержня в работе (from,to)
        if (n == 1) {
            cout << from + 1 << " => " << to + 1 << endl;
            return;
        }
        // cnt == 2 — только from и to, переносим n-1 через второй
        int aux = (avail[0] == from) ? avail[1] : avail[0];
        han(n - 1, from, aux, free);
        cout << from + 1 << " => " << to + 1 << endl;
        han(n - 1, aux, to, free);
        return;
    }

    // Frame-Stewart: m верхних перекладываем отдельно
    int m = n / 2;
    int aux = (avail[0] == from || avail[0] == to) ? avail[1] : avail[0];
    // корректнее: выбрать любой стержень, не равный from и to
    for (int i = 0; i < cnt; ++i)
        if (avail[i] != from && avail[i] != to) { aux = avail[i]; break; }

    // 1) m верхних: from -> aux (все доступные стержни)
    han(m, from, aux, free);
    // 2) n-m нижних: from -> to (aux занят, убираем его из free)
    han(n - m, from, to, free & ~(1 << aux));
    // 3) m с aux -> to (снова все стержни)
    han(m, aux, to, free);
}

int main() {
    int n;
    setlocale(LC_ALL, ".UTF8");
    cout << "Введите количество дисков: "; cin >> n;
    han(n, 0, 2, 0b11111); // 5 стержней (0..4), с 0 на 2
    return 0;
}


