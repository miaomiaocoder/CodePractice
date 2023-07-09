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
            while (i - j + 1 > p.size()) {
                if (hash[s[j]] == 0) cnt--;
                ++hash[s[j++]];
            }
            // 注意这个比较的len是最开始读取p得到的哈希表的长度，也就是字符的种类数量
            if (cnt == len) res.push_back(j);
        }
        return res;
    }
};

class Solution {
   public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        if (p.size() > s.size()) return res;
        unordered_map<char, int> hashp;
        for (auto c : p) hashp[c]++;
        unordered_map<char, int> hashs;
        int len = p.size();
        for (int i = 0, j = 0; i < s.size(); ++i) {
            hashs[s[i]]++;
            while (hashs[s[i]] > hashp[s[i]]) hashs[s[j++]]--;
            if (hashs == hashp) res.push_back(i - len + 1);
        }
        return res;
    }
};
// @lc code=end
