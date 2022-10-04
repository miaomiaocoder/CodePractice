#include <algorithm>
#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int n;
int t[N];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> t[i];

    sort(t, t + n);

    long long res = 0;
    for (int i = 0; i < n; i++) res += t[i] * (n - 1 - i);

    cout << res << endl;

    return 0;
}