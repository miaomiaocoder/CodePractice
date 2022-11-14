/*
 * @lc app=leetcode.cn id=2438 lang=cpp
 *
 * [2438] 二的幂数组中查询范围内的乘积
 */

// @lc code=start
class Solution {
   public:
    const int mod = 1e9 + 7;
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> powers;
        vector<int> result;
        int res = 1;
        while (n) {
            while (n % 2 == 0) {
                n >>= 1;
                res *= 2;
            }
            powers.push_back(res);
            n >>= 1;
            res *= 2;
        }
        long long tmp = 0;
        for (auto& x : queries) {
            tmp = 1;
            for (int i = x[0]; i <= x[1]; i++) {
                tmp *= powers[i];
                tmp = tmp % mod;
            }
            result.push_back(tmp % mod);
        }
        return result;
    }
};
// @lc code=end
