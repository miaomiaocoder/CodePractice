/*
 * @lc app=leetcode.cn id=1002 lang=cpp
 *
 * [1002] 查找共用字符
 */

// @lc code=start
class Solution {
   public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> cnt(26, 101);
        for (auto& word : words) {
            unordered_map<int, int> hash;
            for (auto& c : word) hash[c - 'a']++;
            for (int i = 0; i < 26; ++i) cnt[i] = min(cnt[i], hash[i]);
        }

        vector<string> res;
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < cnt[i]; ++j)
                res.emplace_back(string(1, i + 'a'));
        }
        return res;
    }
};
// @lc code=end
