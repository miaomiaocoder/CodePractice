/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */

// @lc code=start
// 维护一个大小为k的小根堆
class Solution {
   public:
    vector<int> topKFrequent(vector<int> &nums, int k) {
        unordered_map<int, int> hash;
        for (auto &x : nums) hash[x]++;
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            heap;
        int i = 0;
        for (auto &x : hash)
            if (i < k) {
                i++;
                heap.push({x.second, x.first});
            } else {
                heap.push({x.second, x.first});
                heap.pop();
            }
        vector<int> res;
        for (int i = 0; i < k; i++) {
            res.push_back(heap.top().second);
            heap.pop();
        }
        return res;
    }
};

// 维护一个大根堆，最后取出来堆顶前k个元素就行
class Solution {
   public:
    vector<int> topKFrequent(vector<int> &nums, int k) {
        unordered_map<int, int> hash;
        for (auto &x : nums) hash[x]++;
        priority_queue<pair<int, int>> heap;
        for (auto &x : hash) heap.push({x.second, x.first});
        vector<int> res;
        for (int i = 0; i < k; i++) {
            res.push_back(heap.top().second);
            heap.pop();
        }
        return res;
    }
};

// 计数排序
class Solution {
   public:
    vector<int> topKFrequent(vector<int> &nums, int k) {
        unordered_map<int, int> hash;
        for (auto &x : nums) hash[x]++;
        int n = nums.size();
        vector<int> s(n + 1);
        for (auto &[x, c] : hash) s[c]++;
        int i = n, t = 0;
        while (t < k) t += s[i--];
        vector<int> res;
        for (auto &[x, c] : hash)
            if (c > i) res.push_back(x);
        return res;
    }
};
// @lc code=end
