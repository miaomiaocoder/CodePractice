/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */

// @lc code=start
class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        unordered_map<string, vector<string>> hash;
        for (auto &x : strs) {
            string nstr = x;
            sort(nstr.begin(), nstr.end());
            hash[nstr].push_back(x);
        }
        vector<vector<string>> res;
        for (auto &item : hash) res.push_back(item.second);
        return res;
    }
};
// @lc code=end
