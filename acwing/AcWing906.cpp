// 注意这里是按左端点排序

#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

const int N = 1e5 + 10;

int n;
struct Range {
    int l, r;
    bool operator<(const struct Range &W) const { return l < W.l; }
} range[N];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> range[i].l >> range[i].r;

    sort(range, range + n);

    priority_queue<int, vector<int>, greater<int>> heap;
    for (int i = 0; i < n; i++) {
        auto t = range[i];
        if (heap.empty() || heap.top() >= range[i].l)
            heap.push(t.r);
        else {
            heap.pop();
            heap.push(t.r);
        }
    }

    cout << heap.size() << endl;

    return 0;
}