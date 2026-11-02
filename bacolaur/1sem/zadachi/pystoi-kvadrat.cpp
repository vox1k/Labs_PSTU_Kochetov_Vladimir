#include <iostream>
using namespace std;

int main () {
    int n;
    cin >> n;
    for (int i = 1; i<=n;i++) {
        cout << "*";
    }
    cout << endl;
    for (int j=1;j <= (n-2); j++){
        cout << "*";
        for (int z=1;z<= (n-2);z++){
            cout << " ";
        }
        cout << "*" << endl;

    }
    for (int i=1; i<=n;i++){
        cout << "*";
    }
    return 0;

}