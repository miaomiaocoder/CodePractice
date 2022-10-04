#include <algorithm>
#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int n;

struct Range {
    int l, r;
    bool operator<(struct Range &W) { return r < W.r; }
} range[N];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> range[i].l >> range[i].r;

    sort(range, range + n);  // 按照右端点排序

    int res = 0, ed = -2e9;
    for (int i = 0; i < n; i++)
        if (range[i].l > ed) {
            res++;
            ed = range[i].r;
        }

    cout << res << endl;

    return 0;
}