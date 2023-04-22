/*
 * @lc app=leetcode.cn id=1356 lang=cpp
 *
 * [1356] 根据数字二进制下 1 的数目排序
 */

// @lc code=start
class Solution {
    static int bitCount(int n) {
        int count = 0;
        while (n) {
            n &= (n - 1);
            count++;
        }
        return count;
    }

   public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [](int a, int b) {
            int bitA = bitCount(a);
            int bitB = bitCount(b);
            if (bitA == bitB) return a < b;
            return bitA < bitB;
        });
        return arr;
    }
};
// @lc code=end
