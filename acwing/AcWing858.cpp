#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

const int N = 510, INF = 0x3f3f3f3f;

int n, m;
int dist[N];  // 存储各个节点到生成树的距离
int g[N][N];  // 存储图
bool st[N];   // 节点是否被加入到生成树中

int prim() {
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    int res = 0;
    for (int i = 0; i < n; i++) {  // 每次循环选出一个点加入到生成树
        int t = -1;
        for (int j = 1; j <= n; j++)
            if (!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;  // 如果没有在树中，且到树的距离最短，则选择该点
        if (dist[t] == INF) return INF;
        res += dist[t];
        st[t] = true;
        for (int j = 1; j <= n; j++)
            dist[j] = min(dist[j], g[t][j]);  // 更新生成树外的点到生成树的距离
    }
    return res;
}

int main() {
    memset(g, 0x3f, sizeof g);
    cin >> n >> m;
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a][b] = g[b][a] = min(g[a][b], c);
    }

    int t = prim();

    if (t == INF)
        cout << "impossible" << endl;
    else
        cout << t << endl;

    return 0;
}