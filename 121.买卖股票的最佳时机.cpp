/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
class Solution {
public:
    /*
    这道题用没用贪心不知道
    思路就是，用minPrice记录最低的一个价格
    如果价格更低，就更改minPrice。这时候可能会有疑问，如果是2412序列呢？因为profit记录了最大的利润，所以这种情况没问题
    利润修改就用当前利润和之前记录的利润相比较
    */
    int maxProfit(vector<int>& prices) {
        int minPrice = INT32_MAX;   // 用于记录谷底
        int profit = 0;
        for(int i = 0; i < prices.size(); i++){
            if(minPrice > prices[i])
                minPrice = prices[i];
            else
                profit = prices[i] - minPrice > profit ? prices[i] - minPrice : profit;
        }
        return profit;
    }
};
// @lc code=end

