#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int n, m;
int p[N], cnt[N];

int find(int x) {
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        p[i] = i;
        cnt[i] = 1;
    }

    while (m--) {
        int a, b;
        string op;
        cin >> op;
        if (op == "C") {
            cin >> a >> b;
            a = find(a);
            b = find(b);
            if (a != b) {
                p[a] = b;
                cnt[b] += cnt[a];
            }
        } else if (op == "Q1") {
            cin >> a >> b;
            if (find(a) == find(b))
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        } else {
            cin >> a;
            cout << cnt[find(a)] << endl;
        }
    }
    return 0;
}