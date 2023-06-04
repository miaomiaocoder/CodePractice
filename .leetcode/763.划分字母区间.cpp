/*
 * @lc app=leetcode.cn id=763 lang=cpp
 *
 * [763] 划分字母区间
 */

// @lc code=start
// 统计每一个字符最后出现的位置
// 从头遍历字符，并更新字符的最远出现下标，如果找到字符最远出现位置下标和当前下标相等了，则找到了分割点
class Solution {
   public:
    vector<int> partitionLabels(string s) {
        unordered_map<int, int> last;
        // 记录一下每个字母出现的最后一个位置
        for (int i = 0; i < s.size(); i++) last[s[i]] = i;
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
