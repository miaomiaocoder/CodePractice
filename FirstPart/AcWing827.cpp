#include <iostream>
#include <string>

using namespace std;

const int N = 1e5 + 10;
int m;
int e[N], l[N], r[N], idx;

void init() {
    l[1] = 0, r[0] = 1;
    idx = 2;
}

void add(int k, int x) {
    e[idx] = x;
    r[idx] = r[k];
    l[idx] = k;
    l[r[k]] = idx;
    r[k] = idx;
    idx++;
}

void remove(int k) {
    l[r[k]] = l[k];
    r[l[k]] = r[k];
}

int main() {
    cin >> m;

    init();

    while (m--) {
        int k, x;
        string op;

        cin >> op;
        if (op == "L") {
            cin >> x;
            add(0, x);
        } else if (op == "R") {
            cin >> x;
            add(l[1], x);
        } else if (op == "D") {
            cin >> k;
            remove(k + 1);
        } else if (op == "IL") {
            cin >> k >> x;
            add(l[k + 1], x);
        } else if (op == "IR") {
            cin >> k >> x;
            add(k + 1, x);
        }
    }

    for (int i = r[0]; i != 1; i = r[i]) cout << e[i] << " ";
    cout << endl;
    return 0;
}