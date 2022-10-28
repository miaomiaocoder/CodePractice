/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
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
// 层序遍历
class Solution {
   public:
    int minDepth(TreeNode* root) {
        int mind = 0;
        int d = 0;
        queue<TreeNode*> q;
        if (!root) return mind;
        q.push(root);
        while (q.size()) {
            int len = q.size();
            d++;
            while (len--) {
                TreeNode* t = q.front();
                q.pop();
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
                if (!t->left && !t->right) {
                    mind = d;
                    return d;
                }
            }
        }
        return d;
    }
};

// 递归
class Solution {
   public:
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        if (!root->left) return minDepth(root->right) + 1;
        if (!root->right) return minDepth(root->left) + 1;
        return min(minDepth(root->right), minDepth(root->left)) + 1;
    }
};

// y总的code
class Solution {
   public:
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        if (!root->left && !root->right) return 1;
        if (root->left && root->right)
            return min(minDepth(root->left), minDepth(root->right)) + 1;
        if (root->left) return minDepth(root->left) + 1;
        return minDepth(root->right) + 1;
    }
};

// @lc code=end
