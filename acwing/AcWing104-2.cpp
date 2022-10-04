#include <algorithm>
#include <iostream>

using namespace std;

const int N = 1e6 + 10;

int n;
int q[N];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> q[i];

    sort(q, q + n);

    int res = 0;
    for (int i = 0; i < n; i++) res += q[i] - q[i / 2];

    cout << res << endl;

    return 0;
}