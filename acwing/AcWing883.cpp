#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>

using namespace std;

const int N = 110;
const double eps = 1e-8;

int n;
double a[N][N];

int gauss() {
    int c, r;
    for (c = 0, r = 0; c < n; c++) {
        int t = r;
        for (int i = r; i < n; i++)  // 找绝对值最大的行
            if (fabs(a[i][c]) > fabs(a[t][c])) t = i;

        if (fabs(a[t][c]) < eps) continue;

        for (int j = c; j <= n; j++)
            swap(a[t][j], a[r][j]);  // 将绝对值最大的行换到最顶端
        for (int j = n; j >= c; j--) a[r][j] /= a[r][c];  // 将当前行的首位变成1
        for (int i = r + 1; i < n; i++)  // 用当前行将下面所有的列消成0
            if (fabs(a[i][c]) > eps)
                for (int j = n; j >= c; j--) a[i][j] -= a[r][j] * a[i][c];

        r++;
    }

    if (r < n) {
        for (int i = r; i < n; i++) {
            if (fabs(a[i][n]) > eps) return 2;
        }
        return 1;
    }

    for (int i = n - 1; i >= 0; i--)
        for (int j = i + 1; j < n; j++) a[i][n] -= a[i][j] * a[j][n];

    return 0;
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n + 1; j++) scanf("%lf", &a[i][j]);

    int t = gauss();

    if (t == 2)
        cout << "No solution" << endl;
    else if (t == 1)
        cout << "Infinite group solutions" << endl;
    else {
        for (int i = 0; i < n; i++) {
            if (fabs(a[i][n]) < eps) a[i][n] = 0;
            printf("%.2f\n", a[i][n]);
        }
    }

    return 0;
}