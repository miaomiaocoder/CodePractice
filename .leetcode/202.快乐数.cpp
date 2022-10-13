/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 */

// @lc code=start
// 快慢指针
class Solution {
   public:
    int get(int x) {
        int res = 0;
        while (x) {
            res += (x % 10) * (x % 10);
            x /= 10;
        }
        return res;
    }
    bool isHappy(int n) {
        int fast = get(n), slow = n;
        while (fast != slow) {
            fast = get(get(fast));
            slow = get(slow);
        }
        return fast == 1;
    }
};

// 哈希表
class Solution {
   public:
    int get(int x) {
        int res = 0;
        while (x) {
            res += (x % 10) * (x % 10);
            x /= 10;
        }
        return res;
    }
    bool isHappy(int n) {
        unordered_set<int> S;
        while (1) {
            int sum = get(n);
            if (sum == 1) return true;
            if (S.count(sum))
                return false;
            else
                S.insert(sum);
            n = sum;
        }
    }
};
// @lc code=end
