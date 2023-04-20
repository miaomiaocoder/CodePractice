/*
 * @lc app=leetcode.cn id=801 lang=cpp
 *
 * [801] 使序列递增的最小交换次数
 */

// @lc code=start
class Solution {
   private:
    void dfs(vector<vector<int>>& rooms, int key, vector<int>& visted) {
        if (visted[key] == 1) return;
        visted[key] = 1;
        for (auto& x : rooms[key]) dfs(rooms, x, visted);
    }

   public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<int> visted(rooms.size(), 0);
        dfs(rooms, 0, visted);
        for (int i : visted)
            if (i == 0) return false;
        return true;
    }
};
// @lc code=end
