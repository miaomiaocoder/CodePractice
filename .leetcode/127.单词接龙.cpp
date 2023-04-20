/*
 * @lc app=leetcode.cn id=127 lang=cpp
 *
 * [127] 单词接龙
 */

// @lc code=start
class Solution {
   public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        // 将vector转成unordered_set，提高查询速度
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        // 如果endWord没有在wordSet出现，直接返回0
        if (!wordSet.count(endWord)) return 0;
        // 记录word是否访问过
        unordered_map<string, int> visitMap;  // <word, 查询到这个word路径长度>
        // 初始化队列
        queue<string> que;
        que.push(beginWord);
        // 初始化visitMap
        visitMap[beginWord] = 1;

        while (!que.empty()) {
            string word = que.front();
            que.pop();
            int path = visitMap[word];  // 这个word的路径长度
            for (int i = 0; i < word.size(); i++) {
                string newWord =
                    word;  // 用一个新单词替换word，因为每次置换一个字母
                for (int j = 0; j < 26; j++) {
                    newWord[i] = j + 'a';
                    if (newWord == endWord)
                        return path + 1;  // 找到了end，返回path+1
                    // wordSet出现了newWord，并且newWord没有被访问过
                    if (wordSet.count(newWord) && !visitMap.count(newWord)) {
                        // 添加访问信息
                        visitMap[newWord] = path + 1;
                        que.push(newWord);
                    }
                }
            }
        }
        return 0;
    }
};
// @lc code=end
