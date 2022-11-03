/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
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
    int odrder(TreeNode* root) {
        int res = 0;
        queue<TreeNode*> q;
        if (!root) return 0;
        q.push(root);
        while (q.size()) {
            int len = q.size();
            res++;
            while (len--) {
                TreeNode* t = q.front();
                q.pop();
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
            }
        }
        return res;
    }

    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        if (odrder(root->left) - odrder(root->right) > 1 ||
            odrder(root->right) - odrder(root->left) > 1)
            return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
};

class Solution {
   public:
    bool ans = true;
    int dfs(TreeNode* root) {
        if (!root) return 0;
        int l = dfs(root->left), r = dfs(root->right);
        if (abs(l - r) > 1) ans = false;
        return max(l, r) + 1;
    }
    bool isBalanced(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
// @lc code=end
