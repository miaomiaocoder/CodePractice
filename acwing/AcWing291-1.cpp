#include <cstring>
#include <iostream>

using namespace std;

const int N = 12, M = 1 << N;

int n, m;
long long f[N][M];
// 存储每种状态是否有奇数个连续的0，如果奇数个0是无效状态，如果是偶数个零置为true。
bool st[M];

int main() {
    while (cin >> n >> m, n || m) {
        // 对于每种状态，先预处理每列不能有奇数个连续的0
        for (int i = 0; i < 1 << n; i++) {
            st[i] = true;
            int cnt = 0;  //  记录合并列中连续0的个数
            for (int j = 0; j < n; j++) {
                if (i >> j & 1) {
                    if (cnt & 1) {
                        st[i] = false;
                        break;
                    }
                } else
                    cnt++;  // 如果是0记录0的个数
            }
            if (cnt & 1) st[i] = false;
        }

        memset(f, 0, sizeof f);
        f[0][0] = 1;  // 第0列不横放是一种合法方案
        for (int i = 1; i <= m; i++)
            for (int j = 0; j < 1 << n; j++)  // 对于第i列的所有状态
                for (int k = 0; k < 1 << n; k++)  // 对于第i-1列所有状态
                    // （1）(j & k) == 0 说明没有重叠的1 （2）st[j | k] 中 j | k
                    // 就是当前 第i-1列的到底有几个1，即哪几行是横着放格子的
                    // （3）k = 10101; j = 01000;  j | k = 01000 | 10101 =
                    // 11101, i-1列有4个1
                    if ((j & k) == 0 && st[j | k]) f[i][j] += f[i - 1][k];

        // f[m][0]表示 前m-1列都处理完，并且第m-1列没有伸出来的所有方案数。
        // 即整个棋盘处理完的方案数
        cout << f[m][0] << endl;
    }

    return 0;
}