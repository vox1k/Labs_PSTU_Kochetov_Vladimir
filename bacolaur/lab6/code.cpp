#include <iostream>
#include <cstdio>
#include <cstring>
#include <clocale>
using namespace std;

bool isPalindrome(const char* word) {
    int len = strlen(word);
    for (int i = 0; i < len / 2; i++) {
        if (word[i] != word[len - 1 - i])
            return false;
    }
    return true;
}

int main() {
    setlocale(LC_ALL, ".UTF-8");
    char s[256];
    char word[256];

    cout << "Введите строку: ";
    gets_s(s, sizeof(s));

    int len = strlen(s);
    int i = 0, j;
    bool found = false;

    while (i < len) {
        // пропускаем пробелы
        while (i < len && s[i] == ' ')
            i++;

        // собираем слово (до пробела или точки)
        j = 0;
        while (i < len && s[i] != ' ' && s[i] != '.') {
            word[j++] = s[i++];
        }
        word[j] = '\0';

        // проверяем на палиндром
        if (j > 0 && isPalindrome(word)) {
            cout << word << endl;
            found = true;
        }
    }

    if (!found)
        cout << "Слов-палиндромов не найдено." << endl;

    return 0;
}
