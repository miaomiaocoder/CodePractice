/*
 * @lc app=leetcode.cn id=437 lang=cpp
 *
 * [437] 路径总和 III
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
    int res = 0;
    unordered_map<long long, int> cnt;
    void dfs(TreeNode* root, int sum, long long cur) {
        if (!root) return;
        cur += root->val;
        res += cnt[cur - sum];
        cnt[cur]++;
        dfs(root->left, sum, cur);
        dfs(root->right, sum, cur);
        cnt[cur]--;
    }

   public:
    int pathSum(TreeNode* root, int targetSum) {
        cnt[0] = 1;
        dfs(root, targetSum, 0);
        return res;
    }
};
// @lc code=end
