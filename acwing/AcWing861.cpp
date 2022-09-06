#include <cstring>
#include <iostream>

using namespace std;

const int N = 510, M = 1e5 + 10;

int n1, n2, m;
int h[N], e[M], ne[M], idx;
bool st[M];  // st[]数组为临时预定数组
             // st[j]=a表示一轮模拟匹配中，女孩j被男孩a预定了。
int match[N];  // match[j]=a,表示女孩j的现有配对男友是a

void add(int a, int b) { e[idx] = b, ne[idx] = h[a], h[a] = idx++; }

bool find(int x) {
    for (int i = h[x]; i != -1; i = ne[i]) {
        int j = e[i];
        if (!st[j]) {  // 如果在这一轮模拟匹配中,这个女孩尚未被预定
            st[j] = true;
            // 如果女孩j没有男朋友，或者她原来的男朋友能够预定其它喜欢的女孩。配对成功,更新match
            if (match[j] == 0 || find(match[j])) {
                match[j] = x;
                return true;
            }
        }
    }
    return false;  // 自己中意的全部都被预定了。配对失败。
}

int main() {
    memset(h, -1, sizeof h);
    cin >> n1 >> n2 >> m;
    while (m--) {
        int a, b;
        cin >> a >> b;
        add(a, b);
    }

    int res = 0;
    for (int i = 1; i <= n1; i++) {
        // 因为每次模拟匹配的预定情况都是不一样的所以每轮模拟都要初始化
        memset(st, false, sizeof st);
        if (find(i)) res++;
    }
    cout << res << endl;

    return 0;
}