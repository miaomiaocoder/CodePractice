/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
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
    vector<int> path;
    bool ans = false;
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root) dfs(root, targetSum);
        return ans;
    }

    void dfs(TreeNode* root, int targetSum) {
        path.push_back(root->val);
        if (!root->left && !root->right) {
            int sum = 0;
            for (int i = 0; i < path.size(); i++) sum += path[i];
            if (sum == targetSum) ans = true;
        } else {
            if (root->left) dfs(root->left, targetSum);
            if (root->right) dfs(root->right, targetSum);
        }
        path.pop_back();
    }
};

class Solution {
   public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;
        targetSum -= root->val;
        if (!root->left && !root->right) return !targetSum;
        return hasPathSum(root->left, targetSum) ||
               hasPathSum(root->right, targetSum);
    }
};
// @lc code=end
