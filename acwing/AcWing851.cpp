#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

const int N = 1e5 + 10;

int n, m;
int h[N], w[N], e[N], ne[N], idx;
int dist[N];
bool st[N];

void add(int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

int spfa() {
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    queue<int> q;
    q.push(1);
    st[1] = true;
    while (q.size()) {
        int t = q.front();
        q.pop();
        st[t] =
            false;  // 从队列中取出来之后该节点st被标记为false,代表之后该节点如果发生更新可再次入队
        for (int i = h[t]; i != -1; i = ne[i]) {
            int j = e[i];
            if (dist[j] > dist[t] + w[i]) {
                dist[j] = dist[t] + w[i];
                if (!st[j]) {  // 当前已经加入队列的结点，无需再次加入队列，即便发生了更新也只用更新数值即可，重复添加降低效率
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }

    return dist[n];
}

int main() {
    memset(h, -1, sizeof h);
    cin >> n >> m;
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
    }

    int t = spfa();

    if (t == 0x3f3f3f3f)
        cout << "impossible" << endl;
    else
        cout << t << endl;

    return 0;
}
