/*
 * @lc app=leetcode.cn id=455 lang=cpp
 *
 * [455] 分发饼干
 */

// @lc code=start
// y总思路
// 找到满足排序以后前面小孩的饼干
class Solution {
   public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int res = 0;
        for (int i = 0, j = 0; i < g.size(); i++) {
            while (j < s.size() && s[j] < g[i]) j++;
            if (j < s.size()) {
                res++;
                j++;
            } else
                break;
        }
        return res;
    }
};

// 局部最优就是大饼干喂给胃口大的，充分利用饼干尺寸喂饱一个，全局最优就是喂饱尽可能多的小孩。
class Solution {
   public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int idx = s.size() - 1;
        int res = 0;
        for (int i = g.size() - 1; i >= 0; --i) {
            if (idx >= 0 && s[idx] >= g[i]) {
                ++res;
                --idx;
            }
        }
        return res;
    }
};

// 小饼干先喂饱小胃口
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int idx = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (idx < g.size() && g[idx] <= s[i]) {
                ++idx;
            }
        }
        return idx;
    }
};
// @lc code=end
