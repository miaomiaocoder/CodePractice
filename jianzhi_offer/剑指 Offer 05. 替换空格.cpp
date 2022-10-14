// 原地替换
// 题解参考代码随想录
class Solution {
   public:
    string replaceSpace(string s) {
        int cnt = 0;
        int oldSize = s.size();
        for (auto &x : s)
            if (x == ' ') cnt++;

        s.resize(s.size() + cnt * 2);
        int newSize = s.size();
        for (int i = newSize - 1, j = oldSize - 1; j < i; j--, i--)
            if (s[j] != ' ')
                s[i] = s[j];
            else {
                s[i] = '0';
                s[i - 1] = '2';
                s[i - 2] = '%';
                i -= 2;
            }
        return s;
    }
};

class Solution {
   public:
    string replaceSpace(string s) {
        string res;
        for (int i = 0; i < s.size(); i++)
            if (s[i] == ' ')
                res += "%20";
            else
                res += s[i];
        return res;
    }
};

// c++11
class Solution {
   public:
    string replaceSpaces(string &str) {
        string res;
        for (auto &x : str)
            if (x == ' ')
                res += "%20";
            else
                res += x;
        return res;
    }
};
