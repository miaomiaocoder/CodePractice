/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
// 注意区分子串和子序列
class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        unordered_map<char, int> hash;
        for (int i = 0, j = 0; i < s.size(); i++) {
            hash[s[i]]++;
            while (hash[s[i]] > 1) hash[s[j++]]--;
            // 如果这里不用i - j + 1，而是用hash.size(), 求的是子序列
            res = max(res, i - j + 1);
        }
        return res;
    }
};
// @lc code=end
