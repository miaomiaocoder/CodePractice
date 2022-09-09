#include <iostream>

using namespace std;

typedef long long LL;

LL qmi(int a, int b, int p) {
    int res = 1 % p;
    while (b) {
        if (b & 1) res = (LL)res * a % p;
        b >>= 1;
        a = (LL)a * a % p;
    }
    return res;
}

int main() {
    int n;
    scanf("%d", &n);
    while (n--) {
        int a, b, p;
        scanf("%d%d%d", &a, &b, &p);
        cout << qmi(a, b, p) << endl;
    }
    return 0;
}