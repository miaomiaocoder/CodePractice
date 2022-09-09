#include <iostream>

using namespace std;

int phi(int x) {
    int res = x;
    for (int i = 2; i <= x / i; i++) {
        if (x % i == 0) res = res / i * (i - 1);
        while (x % i == 0) x /= i;
    }
    if (x > 1) res = res / x * (x - 1);
    return res;
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        cout << phi(x) << endl;
    }
    return 0;
}