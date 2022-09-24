#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int n;
int a[N];
int q[N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    int len = 0;
    for (int i = 1; i <= n; i++) {
        int l = 0, r = len;
        while (l < r) {  // 二分寻找在q数组中比a[i]小的最大的值
            int mid = l + r + 1 >> 1;
            if (q[mid] < a[i])
                l = mid;
            else
                r = mid - 1;
        }
        // 如果a[i]比q[len]大的话,那么最大的最长上升子序列的值应当加1
        len = max(len, r + 1);

        // q[r]是比a[i]小的最大的值,所以q[r+1]就一定大于a[i],此时把a[i]插入到q[r]的后面
        // 因为a[i]<q[r+1],所以插入到q[r]的后面后,q[r+1]应当等于a[i]
        q[r + 1] = a[i];
    }

    cout << len << endl;

    return 0;
}

// 题解参考 https://www.acwing.com/solution/content/23960/
