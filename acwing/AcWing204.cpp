#include <algorithm>
#include <iostream>

using namespace std;

typedef long long LL;

LL exgcd(LL a, LL b, LL &x, LL &y) {
    if (!b) {
        x = 1, y = 0;
        return a;
    }
    LL d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

int main() {
    int n;
    cin >> n;

    LL a1, m1, x = 0;
    cin >> a1 >> m1;
    for (int i = 0; i < n - 1; i++) {
        LL a2, m2;
        cin >> a2 >> m2;
        LL k1, k2;
        LL d = exgcd(a1, a2, k1, k2);
        if ((m2 - m1) % d) {
            x = -1;
            break;
        }

        k1 *= (m2 - m1) / d;
        k1 = (k1 % (a2 / d) + a2 / d) % (a2 / d);

        x = k1 * a1 + m1;
        LL a = abs(a1 / d * a2);
        m1 = k1 * a1 + m1;
        a1 = a;
    }

    if (x != -1) x = (m1 % a1 + a1) % a1;

    cout << x << endl;
    return 0;
}