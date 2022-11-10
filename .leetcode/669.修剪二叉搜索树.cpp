/*
 * @lc app=leetcode.cn id=669 lang=cpp
 *
 * [669] 修剪二叉搜索树
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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if (!root) return nullptr;
        if (root->val < low) return trimBST(root->right, low, high);
        if (root->val > high) return trimBST(root->left, low, high);
        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);
        return root;
    }
};

class Solution {
   public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        dfs(root, low, high);
        return root;
    }

    void dfs(TreeNode*& root, int low, int high) {
        if (!root) return;
        dfs(root->left, low, high);
        dfs(root->right, low, high);
        if (root->val < low || root->val > high) del(root, root->val);
    }

    void del(TreeNode*& root, int key) {
        if (!root) return;
        if (key == root->val) {
            if (!root->left && !root->right)
                root = nullptr;
            else if (!root->left)
                root = root->right;
            else if (!root->right)
                root = root->left;
            else {
                TreeNode* q = root->right;
                while (q->left) q = q->left;
                root->val = q->val;
                root->right = q;
            }
        } else if (key < root->val)
            del(root->left, key);
        else
            del(root->right, key);
    }
};
// @lc code=end
