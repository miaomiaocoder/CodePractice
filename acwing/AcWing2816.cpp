#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int n, m;
int a[N], b[N];

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    int i = 0, j = 0;
    while (i < n && j < m) {
        if (a[i] == b[j]) i++;
        j++;
    }

    if (i == n)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}