/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] 二叉树的右视图
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        queue<TreeNode*> q;
        if (!root) return res;
        q.push(root);
        while (q.size()) {
            int len = q.size();
            int tmp;
            while (len--) {
                TreeNode* t = q.front();
                q.pop();
                tmp = t->val;
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
            }
            res.push_back(tmp);
        }
        return res;
    }
};
// @lc code=end
