/*
 * @lc app=leetcode.cn id=1047 lang=cpp
 *
 * [1047] 删除字符串中的所有相邻重复项
 */

// @lc code=start
class Solution {
   public:
    string removeDuplicates(string s) {
        string res;
        for (auto &x : s)
            if (res.size() && res.back() == x)
                res.pop_back();
            else
                res += x;
        return res;
    }
};
// @lc code=end
