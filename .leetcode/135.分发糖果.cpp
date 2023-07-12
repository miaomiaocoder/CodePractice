/*
 * @lc app=leetcode.cn id=135 lang=cpp
 *
 * [135] 分发糖果
 */

// @lc code=start
class Solution {
    vector<int> f;
    vector<int> w;
    int n;

   public:
    int candy(vector<int>& ratings) {
        n = ratings.size();
        w = ratings;
        f.resize(n, -1);

        int res = 0;
        for (int i = 0; i < n; i++) res += dp(i);
        return res;
    }

    int dp(int x) {
        if (f[x] != -1) return f[x];
        f[x] = 1;
        if (x && w[x - 1] < w[x]) f[x] = max(f[x], dp(x - 1) + 1);
        if (x + 1 < n && w[x + 1] < w[x]) f[x] = max(f[x], dp(x + 1) + 1);
        return f[x];
    }
};

class Solution {
   public:
    int candy(vector<int>& ratings) {
        vector<int> candy(ratings.size(), 1);

        // 从前向后
        for (int i = 1; i < ratings.size(); ++i)
            if (ratings[i] > ratings[i - 1]) candy[i] = candy[i - 1] + 1;

        // 从后向前和取max是为了利用之前的结果
        for (int i = ratings.size() - 2; i >= 0; --i)
            if (ratings[i] > ratings[i + 1])
                candy[i] = max(candy[i], candy[i + 1] + 1);

        int res;
        for (int x : candy) res += x;
        return res;
    }
};
// @lc code=end
