/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 */

// @lc code=start
class Solution {
   public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<int> f(s.size() + 1, 0);
        f[0] = 1;
        for (int i = 1; i <= s.size(); i++)
            for (int j = 0; j <= i; j++) {
                string word = s.substr(j, i - j);
                if (wordSet.find(word) != wordSet.end() && f[j])
                    f[i] = 1;
            }
        return f[s.size()];
    }
};
// @lc code=end
