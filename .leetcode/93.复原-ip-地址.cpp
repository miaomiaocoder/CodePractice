/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原 IP 地址
 */

// @lc code=start
class Solution {
   private:
    vector<string> res;

    void dfs(const string& s, int start, int num, string path) {
        if (start == s.size()) {
            if (num == 4) {
                path.pop_back();
                res.emplace_back(path);
            }
            return;
        }
        if (num == 4) return;

        for (int i = start, t = 0; i < s.size(); i++) {
            if (i > start && s[start] == '0') break;  // 有前导0
            t = t * 10 + s[i] - '0';
            if (t <= 255)
                dfs(s, i + 1, num + 1, path + to_string(t) + '.');
            else
                break;
        }
    }

   public:
    vector<string> restoreIpAddresses(string s) {
        dfs(s, 0, 0, "");
        return res;
    }
};

class Solution {
   private:
    vector<string> result;  // 记录结果
    // startIndex: 搜索的起始位置，pointNum:添加逗点的数量
    void backtracking(string& s, int startIndex, int pointNum) {
        if (pointNum == 3) {  // 逗点数量为3时，分隔结束
            // 判断第四段子字符串是否合法，如果合法就放进result中
            if (isValid(s, startIndex, s.size() - 1)) {
                result.push_back(s);
            }
            return;
        }
        for (int i = startIndex; i < s.size(); i++) {
            // 判断 [startIndex,i] 这个区间的子串是否合法
            if (isValid(s, startIndex, i)) {
                s.insert(s.begin() + i + 1, '.');  // 在i的后面插入一个逗点
                pointNum++;
                // 插入逗点之后下一个子串的起始位置为i+2
                backtracking(s, i + 2, pointNum);
                pointNum--;                  // 回溯
                s.erase(s.begin() + i + 1);  // 回溯删掉逗点
            } else
                break;  // 不合法，直接结束本层循环
        }
    }
    // 判断字符串s在左闭又闭区间[start, end]所组成的数字是否合法
    bool isValid(const string& s, int start, int end) {
        if (start > end) {
            return false;
        }
        if (s[start] == '0' && start != end) {  // 0开头的数字不合法
            return false;
        }
        int num = 0;
        for (int i = start; i <= end; i++) {
            if (s[i] > '9' || s[i] < '0') {  // 遇到非数字字符不合法
                return false;
            }
            num = num * 10 + (s[i] - '0');
            if (num > 255) {  // 如果大于255了不合法
                return false;
            }
        }
        return true;
    }

   public:
    vector<string> restoreIpAddresses(string s) {
        result.clear();
        if (s.size() < 4 || s.size() > 12) return result;  // 算是剪枝了
        backtracking(s, 0, 0);
        return result;
    }
};

class Solution {
    vector<string> res;
    void backtrack(std::string& s, int idx, int pointNum) {
        if (pointNum == 3) {
            if (isValid(s, idx, s.size() - 1)) {
                res.emplace_back(s);
                return;
            }
        }

        for (int i = idx; i < s.size(); ++i) {
            if (isValid(s, idx, i)) {
                s.insert(s.begin() + i + 1, '.');
                pointNum++;
                backtrack(s, i + 2, pointNum);
                pointNum--;
                s.erase(s.begin() + i + 1);
            } else
                break;
            // 这里应该使用break更好
            // continue;
        }
    }

    bool isValid(const std::string& s, int l, int r) {
        if (l > r) return false;

        if (s[l] == '0' && l != r) return false;

        int num = 0;
        for (int i = l; i <= r; ++i) {
            if (s[i] > '9' || s[i] < '0') return false;
            num = num * 10 + (s[i] - '0');
            if (num > 255) return false;
        }
        return true;
    }

   public:
    vector<string> restoreIpAddresses(string s) {
        res.clear();
        backtrack(s, 0, 0);
        return res;
    }
};
// @lc code=end
