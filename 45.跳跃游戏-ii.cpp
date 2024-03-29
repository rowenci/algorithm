/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */

// @lc code=start
class Solution {
public:
    /*
    这里是有两个距离，一个是当前能走的最远距离，另一个是下一步能走的最远距离
    当前能走的最远距离
    */
    int jump(vector<int>& nums) {
        if (nums.size() == 1) return 0;
        int curDistance = 0;                                    // 当前覆盖最远距离下标
        int nextDistance = 0;                                   // 下一步覆盖最远距离下标
        int res = 0;                                            // 记录走的最大步数
        for (int i = 0; i < nums.size(); i++) {
            nextDistance = max(nums[i] + i, nextDistance);      // 更新下一步覆盖最远距离下标
            if (i == curDistance) {                             // 遇到当前覆盖最远距离下标
                if (curDistance < nums.size() - 1) {            // 如果当前覆盖最远距离下标不是终点
                    res++;                                      // 需要走下一步
                    curDistance = nextDistance;                 // 更新当前覆盖最远距离下标（相当于加油了）
                    if (nextDistance >= nums.size() - 1) break; // 下一步的覆盖范围已经可以达到终点，结束循环
                } else break;                                   // 当前覆盖最远距到达集合终点，不用做res++操作了，直接结束
            }
        }
        return res;
    }
};
// @lc code=end

