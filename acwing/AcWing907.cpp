#include <algorithm>
#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int n;
struct Range {
    int l, r;
    bool operator<(const struct Range &W) const { return l < W.l; }
} range[N];

int main() {
    int st, ed;
    cin >> st >> ed;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> range[i].l >> range[i].r;

    sort(range, range + n);

    int res = 0;
    bool flag = false;

    for (int i = 0; i < n; i++) {
        int j = i, r = -2e9;
        while (j < n && range[j].l <= st) {
            r = max(r, range[j].r);
            j++;
        }

        if (r < st) {
            res = -1;
            break;
        }

        res++;
        if (r >= ed) {
            flag = true;
            break;
        }

        st = r;
        i = j - 1;
    }

    if (!flag) res = -1;

    cout << res << endl;
    return 0;
}
// 1.将左端点从小到大排序
// 2.从前往后依次枚举每个区间，在所有能覆盖start的区间中，选择右端点最大的区间
// 然后将start更新成右端点最大值