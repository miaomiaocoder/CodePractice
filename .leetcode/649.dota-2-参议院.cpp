/*
 * @lc app=leetcode.cn id=649 lang=cpp
 *
 * [649] Dota2 参议院
 */

// @lc code=start
class Solution {
   public:
    string predictPartyVictory(string senate) {
        // R = true表示本轮循环结束后，字符串里依然有R。D同理
        bool R = true, D = true;
        // 当flag大于0时，R在D前出现，R可以消灭D。当flag小于0时，D在R前出现，D可以消灭R
        int flag = 0;
        // 一旦R或者D为false，就结束循环，说明本轮结束后只剩下R或者D了
        while (R && D) {
            R = false;
            D = false;
            for (int i = 0; i < senate.size(); i++) {
                if (senate[i] == 'R') {
                    if (flag < 0)
                        senate[i] = 0;  // 消灭R，R此时为false
                    else
                        R = true;  // 如果没被消灭，本轮循环结束有R
                    flag++;
                }
                if (senate[i] == 'D') {
                    if (flag > 0)
                        senate[i] = 0;
                    else
                        D = true;
                    flag--;
                }
            }
        }
        // 循环结束之后，R和D只能有一个为true
        return R == true ? "Radiant" : "Dire";
    }
};
// @lc code=end
