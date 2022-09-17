#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int res = 0;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if (i & 1) res ^= x;
    }

    if (res)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}