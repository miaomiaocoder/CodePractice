/*
 * @lc app=leetcode.cn id=763 lang=cpp
 *
 * [763] 划分字母区间
 */

// @lc code=start
class Solution {
   public:
    vector<int> partitionLabels(string s) {
        unordered_map<int, int> last;
        for (int i = 0; i < s.size(); i++) 
            last[s[i]] = i;
        vector<int> res;
        int start = 0, end = 0;
        for (int i = 0; i < s.size(); i++) {
            end = max(end, last[s[i]]);
            if (i == end) {
                res.push_back(end - start + 1);
                start = end = i + 1;
            }
        }
        return res;
    }
};
// @lc code=end
