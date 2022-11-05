/*
 * @lc app=leetcode.cn id=513 lang=cpp
 *
 * [513] 找树左下角的值
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
// bfs
class Solution {
   public:
    int findBottomLeftValue(TreeNode* root) {
        int ans;
        queue<TreeNode*> q;
        q.push(root);
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
            ans = vec[0];
        }
        return ans;
    }
};

// dfs
class Solution {
   public:
    int ans, maxd = 0;
    int findBottomLeftValue(TreeNode* root) {
        dfs(root, 1);
        return ans;
    }
    void dfs(TreeNode* root, int d) {
        if (!root) return;
        if (d > maxd) {
            maxd = d;
            ans = root->val;
        }
        dfs(root->left, d + 1), dfs(root->right, d + 1);
    }
};
// @lc code=end
