/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */

// @lc code=start
class Solution {
   public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end());

        int l = intervals[0][0], r = intervals[0][1];
        for (int i = 0; i < intervals.size(); i++) {
            if (intervals[i][0] > r) {
                res.push_back({l, r});
                l = intervals[i][0], r = intervals[i][1];
            } else
                r = max(r, intervals[i][1]);
        }
        res.push_back({l, r});
        return res;
    }
};

class Solution {
   public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        int left = intervals[0][0], right = intervals[0][1];
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] <= right) {
                right = max(right, intervals[i][1]);
                left = min(left, intervals[i][0]);
            } else {
                res.push_back({left, right});
                left = intervals[i][0], right = intervals[i][1];
            }
        }
        res.push_back({left, right});
        return res;
    }
};
// @lc code=end
