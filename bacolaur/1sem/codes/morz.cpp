// #include <iostream>
// using namespace std;

// int main(){
//     int n;
//     cin >> n;
//     long long a[34];
//     a[0]=1;
//     a[1]=2;
//     a[2]=4;
//     for (int i = 3; i <= n; i++)
//         a[i] = a[i-1] + a[i-2] + a[i-3];
//     cout << a[n] << endl;
//     return 0;



// }


#include <iostream>
using namespace std;

long long c[10005], dp[10005];
int prv[10005], q[10005], path[10005];

int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 2; i <= n - 1; i++) cin >> c[i];

    int head = 0, tail = 0;
    q[tail++] = 1;

    for (int i = 2; i <= n; i++) {
        while (q[head] < i - k) head++;
        int p = q[head];
        dp[i] = dp[p] + c[i];
        prv[i] = p;
        while (tail > head && dp[q[tail - 1]] <= dp[i]) tail--;
        q[tail++] = i;
    }

    int cnt = 0;
    for (int v = n; v != 0; v = prv[v]) path[cnt++] = v;

    cout << dp[n] << "\n";
    cout << cnt - 1 << "\n";
    for (int i = cnt - 1; i >= 0; i--)
        cout << path[i] << (i > 0 ? " " : "\n");
    return 0;
}