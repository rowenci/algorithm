/*
 * @lc app=leetcode.cn id=376 lang=cpp
 *
 * [376] 摆动序列
 */

// @lc code=start
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size() <= 1)
            return nums.size();
        int preSub = 0, curSub = 0;
        int res = 1;
        for(int i = 0; i < nums.size() - 1; i++){
            curSub = nums[i + 1] - nums[i];
            if((preSub <= 0 && curSub > 0) || (preSub >= 0 && curSub < 0)){
                res++;
                preSub = curSub;
            }
        }
        return res;
    }
};
// @lc code=end

