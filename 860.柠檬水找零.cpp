/*
 * @lc app=leetcode.cn id=860 lang=cpp
 *
 * [860] 柠檬水找零
 */

// @lc code=start
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int profile5 = 0, profile10 = 0, profile20 = 0;
        for (int bill : bills) {
            // 情况一
            if (bill == 5) profile5++;
            // 情况二
            if (bill == 10) {
                if (profile5 <= 0) return false;
                profile10++;
                profile5--;
            }
            // 情况三
            if (bill == 20) {
                // 优先消耗10美元，因为5美元的找零用处更大，能多留着就多留着
                if (profile5 > 0 && profile10 > 0) {
                    profile5--;
                    profile10--;
                    profile20++; // 其实这行代码可以删了，因为记录20已经没有意义了，不会用20来找零
                } else if (profile5 >= 3) {
                    profile5 -= 3;
                    profile20++; // 同理，这行代码也可以删了
                } else
                    return false;
            }
        }
        return true;
    }
};
// @lc code=end

