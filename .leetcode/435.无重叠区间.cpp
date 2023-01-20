/*
 * @lc app=leetcode.cn id=435 lang=cpp
 *
 * [435] 无重叠区间
 */

// @lc code=start
class Solution {
   public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals) {
        if (intervals.empty()) return 0;
        sort(intervals.begin(), intervals.end(),
             [](vector<int> &a, vector<int> &b) { return a[1] < b[1]; });

        int res = 1, r = intervals[0][1];
        for (int i = 0; i < intervals.size(); i++) {
            if (intervals[i][0] >= r) {
                res++;
                r = intervals[i][1];
            }
        }

        return intervals.size() - res;
    }
};
// @lc code=end
