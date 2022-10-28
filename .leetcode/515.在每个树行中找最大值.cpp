/*
 * @lc app=leetcode.cn id=515 lang=cpp
 *
 * [515] 在每个树行中找最大值
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
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        queue<TreeNode*> q;
        if (!root) return res;
        q.push(root);
        while (q.size()) {
            int len = q.size();
            int tmp = INT_MIN;
            while (len--) {
                TreeNode* t = q.front();
                q.pop();
                tmp = max(tmp, t->val);
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
            }
            res.push_back(tmp);
        }
        return res;
    }
};

// dfs
class Solution {
   public:
    unordered_map<int, int> hash;
    int maxd = 0;
    void dfs(TreeNode* cur, int d) {
        if (!cur) return;
        maxd = max(maxd, d);
        if (hash.count(d) == 0)
            hash[d] = cur->val;
        else
            hash[d] = max(hash[d], cur->val);
        dfs(cur->left, d + 1);
        dfs(cur->right, d + 1);
    }
    vector<int> largestValues(TreeNode* root) {
        dfs(root, 1);
        vector<int> res;
        for (int i = 1; i <= maxd; i++) res.push_back(hash[i]);
        return res;
    }
};
// @lc code=end
