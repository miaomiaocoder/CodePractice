/*
 * @lc app=leetcode.cn id=538 lang=cpp
 *
 * [538] 把二叉搜索树转换为累加树
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
    TreeNode* convertBST(TreeNode* root) {
        dfs(root);
        return root;
    }
    int last = 0;
    void dfs(TreeNode*& root) {
        if (!root) return;
        dfs(root->right);
        root->val += last;
        last = root->val;
        dfs(root->left);
    }
};

class Solution {
   public:
    vector<int> res;

    TreeNode* convertBST(TreeNode* root) {
        dfs(root);
        queue<TreeNode*> q;
        if (!root) return nullptr;
        q.push(root);
        while (q.size()) {
            int len = q.size();
            while (len--) {
                TreeNode* t = q.front();
                q.pop();
                int sum = 0;
                for (int i = 0; i < res.size(); i++)
                    if (t->val <= res[i]) sum += res[i];
                t->val = sum;
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
            }
        }
        return root;
    }

    void dfs(TreeNode* root) {
        if (!root) return;
        dfs(root->left);
        res.push_back(root->val);
        dfs(root->right);
    }
};
// @lc code=end
