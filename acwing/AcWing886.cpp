#include <iostream>

using namespace std;

typedef long long LL;

const int N = 1e5 + 10;
const int mod = 1e9 + 7;

int n;
int fact[N], infact[N];

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
    fact[0] = infact[0] = 1;
    for (int i = 1; i < N; i++) {
        fact[i] = (LL)fact[i - 1] * i % mod;
        infact[i] = (LL)infact[i - 1] * qmi(i, mod - 2, mod) % mod;
    }

    cin >> n;
    while (n--) {
        int a, b;
        cin >> a >> b;
        cout << (LL)fact[a] * infact[b] % mod * infact[a - b] % mod << endl;
    }

    return 0;
}