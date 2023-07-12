/*
 * @lc app=leetcode.cn id=58 lang=cpp
 *
 * [58] 最后一个单词的长度
 */

// @lc code=start
// 反向遍历即可
class Solution {
   public:
    int lengthOfLastWord(string s) {
        int i = s.size() - 1;
        while (s[i] == ' ') --i;

        int res = 0;
        while (i >= 0 && s[i] != ' ') {
            ++res;
            --i;
        }
        return res;
    }
};
// @lc code=end
