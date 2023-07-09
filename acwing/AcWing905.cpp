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


// 1.将每个区间按照右端点从小到大进行排序
// 2.从前往后枚举区间，end值初始化为无穷小
//     如果本次区间不能覆盖掉上次区间的右端点， ed < vec[i].first
//     说明需要选择一个新的点， res ++ ; ed = vec[i].second;
#include <algorithm>
#include <iostream>
#include <vector>

int n, res;

int main() {
    std::cin >> n;
    std::vector<std::pair<int, int>> vec(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> vec[i].first >> vec[i].second;
    }

    std::sort(vec.begin(), vec.end(),
              [](std::pair<int, int> a, std::pair<int, int> b) {
                  return a.second < b.second;
              });

    int res = 0, ed = -2e9;
    for (int i = 0; i < n; i++)
        if (vec[i].first > ed) {
            res++;
            ed = vec[i].second;
        }

    std::cout << res << "\n";
    return 0;
}
