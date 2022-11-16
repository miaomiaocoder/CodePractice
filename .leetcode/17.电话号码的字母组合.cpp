/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
class Solution {
   private:
    const string letterMap[10] = {"",    "",    "abc",  "def", "ghi",
                                  "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> res;
    string path;

    void getCombinations(string& digits, int idx) {
        if (idx == digits.size()) {
            res.emplace_back(path);
            return;
        }

        for (char c : letterMap[digits[idx] - '0']) {
            path.push_back(c);
            getCombinations(digits, idx + 1);
            path.pop_back();
        }
    }

   public:
    vector<string> letterCombinations(string digits) {
        res.clear();
        if (digits.empty()) return res;
        getCombinations(digits, 0);
        return res;
    }
};
// @lc code=end
