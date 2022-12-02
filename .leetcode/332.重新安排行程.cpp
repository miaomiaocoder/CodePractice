/*
 * @lc app=leetcode.cn id=332 lang=cpp
 *
 * [332] 重新安排行程
 */

// @lc code=start
class Solution {
   private:
    unordered_map<string, map<string, int>> targets;
    bool backtrack(int ticketNum, vector<string>& result) {
        if (result.size() == ticketNum + 1) {
            return true;
        }

        for (pair<const string, int>& target :
             targets[result[result.size() - 1]]) {
            if (target.second > 0) {
                result.emplace_back(target.first);
                target.second--;
                if (backtrack(ticketNum, result)) return true;
                target.second++;
                result.pop_back();
            }
        }

        return false;
    }

   public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        vector<string> result;
        for (const vector<string>& vec : tickets) targets[vec[0]][vec[1]]++;
        result.emplace_back("JFK");
        backtrack(tickets.size(), result);
        return result;
    }
};
// @lc code=end
