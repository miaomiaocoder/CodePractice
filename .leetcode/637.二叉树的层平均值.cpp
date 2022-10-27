/*
 * @lc app=leetcode.cn id=637 lang=cpp
 *
 * [637] 二叉树的层平均值
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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        queue<TreeNode*> q;
        if (!root) return res;
        q.push(root);
        while (q.size()) {
            int len = q.size();
            int cnt = len;
            double sum = 0;
            while (len--) {
                TreeNode* t = q.front();
                q.pop();
                sum += t->val;
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
            }
            res.push_back(sum / cnt);
        }
        return res;
    }
};
// @lc code=end
