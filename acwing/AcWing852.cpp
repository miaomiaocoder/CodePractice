#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

const int N = 2010, M = 10010;

int n, m;
int h[N], w[M], e[M], ne[M], idx;
int dist[N];
int cnt[N];  // cnt[x] 表示当前从1-x的最短路的边数
bool st[N];

void add(int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

bool spfa() {
    // 这里不需要初始化dist数组为正无穷/初始化的原因是，如果存在负环，那么dist不管初始化为多少，都会被更新
    queue<int> q;
    for (int i = 1; i <= n; i++) {  // 把所有点都加入队列, 可能不是以1为起点的环
        q.push(i);
        st[i] = true;
    }
    while (q.size()) {
        int t = q.front();
        q.pop();
        st[t] = false;
        for (int i = h[t]; i != -1; i = ne[i]) {
            int j = e[i];
            if (dist[j] > dist[t] + w[i]) {
                dist[j] = dist[t] + w[i];
                cnt[j] = cnt[t] + 1;
                if (cnt[j] >= n) return true;
                if (!st[j]) {
                    q.push(j);
                    st[j] = false;
                }
            }
        }
    }
    return false;
}

int main() {
    memset(h, -1, sizeof h);
    cin >> n >> m;
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
    }

    if (spfa())
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}