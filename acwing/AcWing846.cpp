#include <cstring>
#include <iostream>

using namespace std;

const int N = 1e5 + 10;
const int M = N * 2;

int n;
int h[N], e[M], ne[M], idx;
int ans = N;
bool st[N];

void add(int a, int b) { e[idx] = b, ne[idx] = h[a], h[a] = idx++; }

// 返回以u为根的子树中节点的个数，包括u节点
int dfs(int u) {
    int sum = 1;
    int res = 0;
    st[u] = true;

    // 访问u的每个子节点
    for (int i = h[u]; i != -1; i = ne[i]) {
        int j = e[i];
        if (!st[j]) {
            int s = dfs(j);
            res = max(res, s);
            sum += s;
        }
    }
    res = max(res, n - sum);  // 选择u节点为重心，最大的连通子图节点数
    ans = min(ans, res);  // 遍历过的假设重心中，最小的最大联通子图的节点数
    return sum;
}

int main() {
    memset(h, -1, sizeof h);

    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        add(a, b), add(b, a);
    }

    dfs(1);

    cout << ans << endl;

    return 0;
}