/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */

// @lc code=start
// 使用哈希表
class Solution {
   public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> hash1, hash2;
        for (auto &x : s) hash1[x]++;
        for (auto &y : t) hash2[y]++;
        return hash1 == hash2;
    }
};

// 模拟哈希表
class Solution {
   public:
    bool isAnagram(string s, string t) {
        int record[26] = {};
        for (int i = 0; i < s.size(); i++) record[s[i] - 'a']++;
        for (int i = 0; i < t.size(); i++) record[t[i] - 'a']--;
        for (int i = 0; i < 26; i++)
            if (record[i] != 0) return false;
        return true;
    }
};
// @lc code=end
