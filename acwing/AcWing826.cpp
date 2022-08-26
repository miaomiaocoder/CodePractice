#include <iostream>
#include <string>

using namespace std;

const int N = 1e5 + 10;

int head, e[N], ne[N], idx;
int m;

void init() {
    head = -1;
    idx = 0;
}

void add_head(int x) { e[idx] = x, ne[idx] = head, head = idx++; }

void add(int k, int x) { e[idx] = x, ne[idx] = ne[k], ne[k] = idx++; }

void remove(int k) { ne[k] = ne[ne[k]]; }

int main() {
    cin >> m;

    init();

    while (m--) {
        int k, x;
        string op;

        cin >> op;
        if (op == "H") {
            cin >> x;
            add_head(x);
        } else if (op == "D") {
            cin >> k;
            if (!k) head = ne[head];
            remove(k - 1);
        } else {
            cin >> k >> x;
            add(k - 1, x);
        }
    }

    for (int i = head; i != -1; i = ne[i]) cout << e[i] << " ";
    cout << endl;

    return 0;
}