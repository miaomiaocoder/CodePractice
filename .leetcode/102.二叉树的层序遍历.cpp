/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
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
// 递归法
class Solution {
   public:
    vector<vector<int>> res;
    void order(TreeNode* cur, int depth) {
        if (cur == nullptr) return;
        if (depth == res.size()) res.push_back(vector<int>());
        res[depth].push_back(cur->val);
        if (cur->left) order(cur->left, depth + 1);
        if (cur->right) order(cur->right, depth + 1);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        int depth = 0;
        order(root, depth);
        return res;
    }
};

// bfs
class Solution {
   public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> q;
        if (root) q.push(root);
        while (q.size()) {
            int len = q.size();
            vector<int> vec;
            while (len--) {
                TreeNode* t = q.front();
                q.pop();
                vec.push_back(t->val);
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
            }
            res.push_back(vec);
        }
        return res;
    }
};
// @lc code=end
