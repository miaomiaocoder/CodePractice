/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */

// @lc code=start
// 滑动窗口
class Solution {
   public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        unordered_map<char, int> hash;
        for (auto &x : p) hash[x]++;
        int len = hash.size();
        for (int i = 0, j = 0, cnt = 0; i < s.size(); i++) {
            if (--hash[s[i]] == 0) cnt++;
            while (i - j + 1 > p.size())
                if (hash[s[j++]]++ == 0) cnt--;
            if (cnt == len) res.push_back(j);
        }
        return res;
    }
};
// @lc code=end
