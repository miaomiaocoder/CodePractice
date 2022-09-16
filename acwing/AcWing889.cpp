#include <iostream>

using namespace std;

typedef long long LL;

const int mod = 1e9 + 7;

int qmi(int a, int b, int p) {
    int res = 1;
    while (b) {
        if (b & 1) res = (LL)res * a % p;
        a = (LL)a * a % p;
        b >>= 1;
    }
    return res;
}

int main() {
    int n;
    cin >> n;

    int res = 1;
    for (int i = 2 * n; i > n; i--) res = (LL)res * i % mod;
    for (int i = 1; i <= n; i++) res = (LL)res * qmi(i, mod - 2, mod) % mod;
    res = (LL)res * qmi(n + 1, mod - 2, mod) % mod;

    cout << res << endl;
    return 0;
}