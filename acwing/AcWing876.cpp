#include <iostream>

using namespace std;

typedef long long LL;

int qmi(int a, int b, int p) {
    LL res = 1;
    while (b) {
        if (b & 1) res = (LL)res * a % p;
        b >>= 1;
        a = (LL)a * a % p;
    }
    return res;
}

int main() {
    int n;
    cin >> n;

    while (n--) {
        int a, p;
        scanf("%d%d", &a, &p);

        if (a % p == 0)
            printf("impossible\n");
        else
            printf("%lld\n", qmi(a, p - 2, p));
    }
    return 0;
}