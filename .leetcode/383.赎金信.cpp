/*
 * @lc app=leetcode.cn id=383 lang=cpp
 *
 * [383] 赎金信
 */

// @lc code=start
// 模拟哈希表
class Solution {
   public:
    bool canConstruct(string ransomNote, string magazine) {
        int record[26] = {};

        for (int i = 0; i < ransomNote.size(); i++)
            record[ransomNote[i] - 'a']++;

        for (int i = 0; i < magazine.size(); i++) record[magazine[i] - 'a']--;

        for (int i = 0; i < 26; i++)
            if (record[i] > 0) return false;
        return true;
    }
};

// 哈希表写法一
class Solution {
   public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> hash;
        for (auto &x : ransomNote) hash[x]++;
        for (auto &y : magazine) hash[y]--;
        for (auto &x : ransomNote)
            if (hash[x] > 0) return false;
        return true;
    }
};

// 哈希表写法二
class Solution {
   public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> hash;
        for (auto &y : magazine) hash[y]++;
        for (auto &x : ransomNote) {
            hash[x]--;
            if (hash[x] < 0) return false;
        }
        return true;
    }
};
// @lc code=end
