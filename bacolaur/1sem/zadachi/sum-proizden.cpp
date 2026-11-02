#include <iostream>
using namespace std;

int main() {
    int n,s,x=1;
    cin >> n;
    for (int i = 1, i <= n; ++i){
        for (int j=1; j<= (2*i);++j)
        x*=j;
        s+=x;
        x=1;
    }
    cout << s;
    return 0;

}