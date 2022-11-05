/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
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
   public:
    vector<vector<int>> res;
    vector<int> path;
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (root) dfs(root, targetSum);
        return res;
    }

    void dfs(TreeNode* root, int targetSum) {
        path.push_back(root->val);
        if (!root->left && !root->right) {
            int sum = 0;
            for (int i = 0; i < path.size(); i++) sum += path[i];
            if (sum == targetSum) res.push_back(path);
        } else {
            if (root->left) dfs(root->left, targetSum);
            if (root->right) dfs(root->right, targetSum);
        }
        path.pop_back();
    }
};
// @lc code=end
