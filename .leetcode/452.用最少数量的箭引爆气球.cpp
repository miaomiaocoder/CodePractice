/*
 * @lc app=leetcode.cn id=452 lang=cpp
 *
 * [452] 用最少数量的箭引爆气球
 */

// @lc code=start
class Solution {
   public:
    int findMinArrowShots(vector<vector<int>> &points) {
        if (points.empty()) return 0;
        sort(points.begin(), points.end(),
             [](vector<int> &a, vector<int> &b) { return a[1] < b[1]; });

        int res = 1, r = points[0][1];
        for (int i = 0; i < points.size(); i++) {
            if (points[i][0] > r) {
                res++;
                r = points[i][1];
            }
        }

        return res;
    }
};
// @lc code=end
