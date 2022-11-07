/*
 * @lc app=leetcode.cn id=501 lang=cpp
 *
 * [501] 二叉搜索树中的众数
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
// 使用哈希表统计
class Solution {
   public:
    unordered_map<int, int> hash;
    void dfs(TreeNode* root) {
        if (!root) return;

        dfs(root->left);
        hash[root->val]++;
        dfs(root->right);
    }
    vector<int> findMode(TreeNode* root) {
        dfs(root);
        vector<int> res;
        int mode = 0;
        for (auto& x : hash) mode = max(mode, x.second);
        for (auto& x : hash)
            if (x.second == mode) res.push_back(x.first);
        return res;
    }
};

// y总方法
class Solution {
   public:
    vector<int> ans;
    int maxCnt = 0, curCnt = 0, last = 1e5 + 10;
    vector<int> findMode(TreeNode* root) {
        dfs(root);
        return ans;
    }

    void dfs(TreeNode* root) {
        if (!root) return;

        dfs(root->left);
        if (root->val == last)
            curCnt++;
        else
            curCnt = 1;
        last = root->val;
        if (curCnt > maxCnt)
            ans = {last}, maxCnt = curCnt;
        else if (curCnt == maxCnt)
            ans.push_back(last);
        dfs(root->right);
    }
};
// @lc code=end
