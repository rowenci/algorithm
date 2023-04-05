/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

// @lc code=start
class Solution {
public:
    /*
    这个cover就是记录能跳跃的覆盖范围
    也就是说，如果cover大于数组大小 - 1，那么就能跳过去
    那么就可以从前往后遍历过去，记录一下cover的大小。
    这个cover如何改变呢？就是通过当前元素下标与元素的和，与cover比较，取较大值
    */
    bool canJump(vector<int>& nums) {
        int cover = 0;
        if(nums.size() == 1) return true;
        for(int i = 0; i <= cover; i++){
            cover = max(i + nums[i], cover);
            if(cover >= nums.size() - 1) return true;
        }
        return false;
    }
};
// @lc code=end

