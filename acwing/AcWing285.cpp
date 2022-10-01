//题解参考 https://www.acwing.com/solution/content/105019/

#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

const int N = 6010;

int n;
int happy[N];
int h[N], e[N], ne[N], idx;
bool has_far[N];
int f[N][2];

void add(int a, int b) { e[idx] = b, ne[idx] = h[a], h[a] = idx++; }

void dfs(int u) {
    f[u][1] = happy[u];

    for (int i = h[u]; ~i; i = ne[i]) {
        int j = e[i];
        dfs(j);
        f[u][0] += max(f[j][0], f[j][1]);
        f[u][1] += f[j][0];
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> happy[i];
    memset(h, -1, sizeof h);

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        add(b, a);
        has_far[a] = true;
    }

    int root = 1;
    while (has_far[root]) root++;

    dfs(root);

    cout << max(f[root][0], f[root][1]) << endl;

    return 0;
}