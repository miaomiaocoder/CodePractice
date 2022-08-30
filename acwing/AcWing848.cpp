#include <cstring>
#include <iostream>

using namespace std;

const int N = 1e5 + 10;
int n, m;
int h[N], e[N], ne[N], idx;
int q[N], d[N];

void add(int a, int b) { e[idx] = b, ne[idx] = h[a], h[a] = idx++; }

bool topsort() {
    int hh = 0, tt = -1;
    for (int i = 1; i <= n; i++)
        if (!d[i]) q[++tt] = i;  // 将入度为零的点入队

    while (hh <= tt) {
        int t = q[hh++];

        for (int i = h[t]; i != -1; i = ne[i]) {
            int j = e[i];
            d[j]--;                      // 删除点t指向点j的边
            if (d[j] == 0) q[++tt] = j;  // 如果点j的入度为零了,就将点j入队
        }
    }

    return tt == n - 1;
}

int main() {
    cin >> n >> m;

    memset(h, -1, sizeof h);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        add(a, b);
        d[b]++;
    }

    if (topsort()) {
        for (int i = 0; i < n; i++) cout << q[i] << " ";
    } else
        cout << "-1" << endl;
    return 0;
}