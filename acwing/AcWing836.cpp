#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int n, m;
int p[N];

int find(int x) {
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) p[i] = i;

    while (m--) {
        string op;
        int a, b;
        cin >> op >> a >> b;
        if (op[0] == 'M')
            p[find(a)] = p[find(b)];
        else {
            if (find(a) == find(b))
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
    }

    return 0;
}