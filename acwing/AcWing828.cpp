#include <iostream>
#include <string>

using namespace std;

const int N = 1e5 + 10;
int stk[N], tt;

int main() {
    int m;
    cin >> m;
    while (m--) {
        int x;
        string op;
        cin >> op;
        if (op == "push") {
            cin >> x;
            stk[++tt] = x;
        } else if (op == "pop") {
            tt--;
        } else if (op == "empty") {
            if (tt)
                cout << "NO" << endl;
            else
                cout << "YES" << endl;

        } else if (op == "query") {
            cout << stk[tt] << endl;
        }
    }
    return 0;
}