#include <iostream>
#include <clocale>
using namespace std;

const int N = 8;

int board[N];          // board[col] = row, где стоит ферзь в столбце col
bool colUsed[N];       // занятые строки
bool diag1[2 * N];     // главная диагональ (row - col + N)
bool diag2[2 * N];     // побочная диагональ (row + col)

int solutions = 0;
bool findAll = false;  // true — все решения, false — только первое

void printBoard() {
    cout << "\nРешение #" << solutions << ":\n";
    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < N; ++c)
            cout << (board[c] == r ? " 0" : " .");
        cout << "\n";
    }
}

void solve(int col) {
    if (col == N) {
        ++solutions;
        printBoard();
        if (!findAll) exit(0);   // первое решение — выходим
        return;
    }

    for (int row = 0; row < N; ++row) {
        int d1 = row - col + N;
        int d2 = row + col;
        if (colUsed[row] || diag1[d1] || diag2[d2]) continue;

        // ставим ферзя
        board[col] = row;
        colUsed[row] = diag1[d1] = diag2[d2] = true;

        solve(col + 1);

        // снимаем ферзя (backtracking)
        colUsed[row] = diag1[d1] = diag2[d2] = false;
    }
}

int main() {
    setlocale(LC_ALL, ".UTF-8");

    cout << "Вывести все решения? (1 — да, 0 — только первое): ";
    cin >> findAll;

    solve(0);

    cout << "\nВсего решений: " << solutions << "\n";
    return 0;
}