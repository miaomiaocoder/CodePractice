#include <iostream>

using namespace std;

typedef unsigned long long ULL;

const int N = 1e5 + 10, P = 131;

ULL h[N], p[N];

ULL get(int l, int r) { return h[r] - h[l - 1] * p[r - l + 1]; }

int main() {
    int n, m;
    char str[N];
    cin >> n >> m >> str + 1;

    p[0] = 1;
    for (int i = 1; i <= n; i++) {
        p[i] = p[i - 1] * P;
        h[i] = h[i - 1] * P + str[i];
    }

    while (m--) {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        if (get(l1, r1) == get(l2, r2))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}