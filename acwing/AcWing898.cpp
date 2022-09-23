#include <algorithm>
#include <iostream>

using namespace std;

const int N = 510, INF = 1e9;

int n;
int f[N][N];
int a[N][N];

int main() {
    cin >> n;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++) cin >> a[i][j];

    for (int i = 0; i <= n + 1; i++)
        for (int j = 0; j <= i + 1; j++) f[i][j] = -INF;

    f[1][1] = a[1][1];

    for (int i = 2; i <= n; i++)
        for (int j = 1; j <= i; j++)
            f[i][j] = max(f[i - 1][j - 1] + a[i][j], f[i - 1][j] + a[i][j]);

    int res = -INF;
    for (int i = 0; i <= n; i++) res = max(f[n][i], res);

    cout << res << endl;

    return 0;
}