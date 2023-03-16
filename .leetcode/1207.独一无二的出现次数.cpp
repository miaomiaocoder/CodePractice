/*
 * @lc app=leetcode.cn id=1207 lang=cpp
 *
 * [1207] 独一无二的出现次数
 */

// @lc code=start
class Solution {
   public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> hash1;
        for (const auto& x : arr) {
            hash1[x + 1000]++;
        }

        unordered_map<int, int> hash2;
        for (const auto& x : hash1) {
            hash2[x.second]++;
        }
        return hash1.size() == hash2.size();
    }
};

class Solution {
   public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> hash1;
        for (const auto& x : arr) {
            hash1[x + 1000]++;
        }

        unordered_set<int> hash2;
        for (const auto& x : hash1) {
            hash2.insert(x.second);
        }
        return hash1.size() == hash2.size();
    }
};
// @lc code=end
