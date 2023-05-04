/*
 * @lc app=leetcode.cn id=509 lang=cpp
 *
 * [509] 斐波那契数
 */

// @lc code=start
class Solution {
public:
    int fib(int n) {
        /*
        1. 确定dp数组及下标的含义：dp[i]（第i个数的斐波那契数为dp[i]）
        2. 确定递推公式：dp[i] = dp[i - 1] + dp[i - 2]
        3. dp数组如何初始化：dp[0] = 0; dp[1] = 1;
        4. 确定遍历顺序：因为i依赖于i - 1和i - 2，所以需要从前往后遍历
        5. 距离推导dp数组：N为10的时候，dp数组应该是：0 1 1 2 3 5 8 13 21 34 55
        */
        if(n <= 1)
            return n;
        vector<int> dp(n + 1);
        dp[0] = 0;
        dp[1] = 1;
        for(int i = 2; i <= n; i++)
            dp[i] = dp[i - 1] + dp[i - 2];
        return dp[n];
    }
};
// @lc code=end

