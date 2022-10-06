/*
 * @lc app=leetcode.cn id=904 lang=cpp
 *
 * [904] 水果成篮
 */

// @lc code=start
class Solution {
   public:
    int totalFruit(vector<int>& fruits) {
        int res = 0;
        unordered_map<int, int> cnt;
        for (int i = 0, j = 0, s = 0; i < fruits.size(); i++) {
            if (++cnt[fruits[i]] == 1) s++;
            while (s > 2) {
                if (--cnt[fruits[j]] == 0) s--;
                j++;
            }
            res = max(res, i - j + 1);
        }
        return res;
    }
};
// @lc code=end
