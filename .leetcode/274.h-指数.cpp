/*
 * @lc app=leetcode.cn id=274 lang=cpp
 *
 * [274] H 指数
 */

// @lc code=start
class Solution {
   public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end(), greater<int>());
        for (int h = citations.size(); h > 0; --h) {
            if (citations[h - 1] >= h) return h;
        }
        return 0;
    }
};
// @lc code=end
