// 开放寻址法
#include <cstring>
#include <iostream>

using namespace std;

const int N = 2e5 + 3, null = 0x3f3f3f3f;

int h[N];

int find(int x) {
    int k = (x % N + N) % N;

    while (h[k] != null && h[k] != x) {
        k++;
        if (k == N) k = 0;
    }
    return k;
}

int main() {
    memset(h, 0x3f, sizeof h);

    int n;
    cin >> n;
    while (n--) {
        string op;
        int x;
        cin >> op >> x;
        int k = find(x);
        if (op == "I")
            h[k] = x;
        else {
            if (h[k] == null)
                cout << "No" << endl;
            else
                cout << "Yes" << endl;
        }
    }
    return 0;
}