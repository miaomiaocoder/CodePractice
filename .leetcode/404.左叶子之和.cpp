/*
 * @lc app=leetcode.cn id=404 lang=cpp
 *
 * [404] 左叶子之和
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
    int sumOfLeftLeaves(TreeNode* root) {
        int res = 0;
        if (!root) return 0;
        if (root->left && !root->left->left && !root->left->right)
            res = root->left->val;
        return res + sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
    }
};

class Solution {
   public:
    int sum = 0;
    int sumOfLeftLeaves(TreeNode* root) {
        dfs(root);
        return sum;
    }

    void dfs(TreeNode* root) {
        if (!root) return;
        dfs(root->left);
        dfs(root->right);
        if (root->left)
            if (!root->left->left && !root->left->right) sum += root->left->val;
    }
};
// @lc code=end
