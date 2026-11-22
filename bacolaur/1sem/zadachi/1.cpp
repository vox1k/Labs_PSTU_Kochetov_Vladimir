#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        string n;
        cin >> n;
        int len = n.size();
        int zero_count = 0;
        int max_len = 0;
        for (int i = 0; i < len; i++) {
            char c = n[i];
            if (c == '0') {
                zero_count++;
            } else {
                int candidate = zero_count + 1;
                if (candidate > max_len) {
                    max_len = candidate;
                }
            }
        }
        cout << len - max_len << "\n";
    }
    return 0;
}