/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 */

// @lc code=start
class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        std::set<int> S(nums.begin(), nums.end());
        int res = 0;
        for (auto x : nums) {
            if (!S.count(x - 1)) {
                int y = x;
                S.erase(x);
                while (S.count(y + 1)) {
                    y++;
                    S.erase(y);
                }
                res = max(res, y - x + 1);
            }
        }
        return res;
    }
};
// @lc code=end
