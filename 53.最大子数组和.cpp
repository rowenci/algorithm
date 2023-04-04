/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */

// @lc code=start
class Solution {
public:

    /*
    1. 第一个数一定要是正数
    2. 如果加上负数之后结果也变负数，那么就要重新开始找
    */
    int maxSubArray(vector<int>& nums) {
        int res = INT32_MIN;
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            if(sum > res) res = sum;
            if(sum <= 0) sum = 0;
        }
        return res;
    }
};
// @lc code=end

