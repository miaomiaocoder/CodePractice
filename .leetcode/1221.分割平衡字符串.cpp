/*
 * @lc app=leetcode.cn id=1221 lang=cpp
 *
 * [1221] 分割平衡字符串
 */

// @lc code=start
class Solution {
   public:
    int balancedStringSplit(string s) {
        int res = 0;
        int count = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == 'R')
                count++;
            else
                count--;
            if (count == 0) res++;
        }
        return res;
    }
};
// @lc code=end
