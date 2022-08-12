#include <iostream>
#include <string>

using namespace std;

const int N = 1e5 + 10;

int q[N], hh = 0, tt = -1;

int main() {
    int m;
    cin >> m;
    while (m--) {
        int x;
        string op;
        cin >> op;

        if (op == "push") {
            cin >> x;
            q[++tt] = x;
        } else if (op == "pop")
            hh++;
        else if (op == "empty") {
            if (hh <= tt)
                cout << "NO" << endl;
            else
                cout << "YES" << endl;
        } else
            cout << q[hh] << endl;
    }
    return 0;
}