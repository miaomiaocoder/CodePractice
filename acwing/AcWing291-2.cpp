#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

const int N = 12, M = 1 << N;

int n, m;
long long f[N][M];
vector<int> state[M];
bool st[M];

int main() {
    while (cin >> n >> m, n || m) {
        for (int i = 0; i < 1 << n; i++) {
            st[i] = true;
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if (i >> j & 1) {
                    if (cnt & 1) {
                        st[i] = false;
                        break;
                    }
                } else
                    cnt++;
            }
            if (cnt & 1) st[i] = false;
        }

        for (int j = 0; j < 1 << n; j++) {
            state[j].clear();
            for (int k = 0; k < 1 << n; k++)
                if ((j & k) == 0 && (st[j | k])) state[j].push_back(k);
        }

        memset(f, 0, sizeof f);
        f[0][0] = 1;
        for (int i = 1; i <= m; i++)
            for (int j = 0; j < 1 << n; j++)
                for (auto &k : state[j]) f[i][j] += f[i - 1][k];

        cout << f[m][0] << endl;
    }

    return 0;
}