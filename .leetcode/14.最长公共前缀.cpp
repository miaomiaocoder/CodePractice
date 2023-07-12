/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */

// @lc code=start
// 纵向扫描
class Solution {
   public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        int length = strs[0].size();
        int cnt = strs.size();
        for (int i = 0; i < length; ++i) {
            char c = strs[0][i];
            for (int j = 1; j < cnt; ++j) {
                if (i == strs[j].size() || strs[j][i] != c)
                    return strs[0].substr(0, i);
            }
        }
        return strs[0];
    }
};
// @lc code=end
