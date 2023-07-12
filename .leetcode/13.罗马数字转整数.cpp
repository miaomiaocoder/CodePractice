/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */

// @lc code=start
class Solution {
    unordered_map<char, int> hash = {
        {'I', 1},   {'V', 5},   {'X', 10},   {'L', 50},
        {'C', 100}, {'D', 500}, {'M', 1000},
    };

   public:
    int romanToInt(string s) {
        int n = s.length();
        int res = 0;
        for (int i = 0; i < n; ++i) {
            int value = hash[s[i]];
            if (i < n - 1 && value < hash[s[i + 1]]) {
                res -= value;
            } else {
                res += value;
            }
        }
        return res;
    }
};
// @lc code=end
