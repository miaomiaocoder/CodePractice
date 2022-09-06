#include <cstring>
#include <iostream>

using namespace std;

const int N = 1e5 + 10, M = 2e5 + 10;
int n, m;
int h[N], e[M], ne[M], idx;
int color[N];
// 邻接表方式存储图, 无向图可能会连接M条边
// color[N], 为0代表还未染色省去一个bool数组,1代表染颜色1,2代表染颜色2

void add(int a, int b) { e[idx] = b, ne[idx] = h[a], h[a] = idx++; }

// 返回是否可以成功将u染色为c
bool dfs(int u, int c) {
    color[u] = c;                             // 修改当前颜色
    for (int i = h[u]; i != -1; i = ne[i]) {  // 尝试染链接边的颜色
        int j = e[i];
        if (!color[j]) {                       // 如果color[j]没有染过色
            if (!dfs(j, 3 - c)) return false;  // 如果不可以将j成功染色
        } else if (color[j] == c)  // 如果染过颜色且和c相同
            return false;
    }
    return true;
}

int main() {
    memset(h, -1, sizeof h);
    cin >> n >> m;
    while (m--) {
        int a, b;
        cin >> a >> b;
        add(a, b), add(b, a);
    }
    bool flag = true;
    for (int i = 1; i <= n; i++)
        if (!color[i])  // 如果未染色
            if (!dfs(i, 1)) {
                flag = false;
                break;
            }

    if (flag == true)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}