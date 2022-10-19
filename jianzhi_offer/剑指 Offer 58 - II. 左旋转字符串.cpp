// 不使用额外空间
class Solution {
   public:
    string reverseLeftWords(string s, int n) {
        reverse(s.begin(), s.end());
        reverse(s.begin(), s.end() - n);
        reverse(s.end() - n, s.end());
        return s;
    }
};

class Solution {
   public:
    string reverseLeftWords(string s, int n) {
        string res;
        for (int i = n; i < s.size(); i++) res += s[i];
        for (int i = 0; i < n; i++) res += s[i];
        return res;
    }
};