/*
 * @lc app=leetcode.cn id=1005 lang=cpp
 *
 * [1005] K 次取反后最大化的数组和
 */

// @lc code=start
/*
第一步：将数组按照绝对值大小从大到小排序，注意要按照绝对值的大小
第二步：从前向后遍历，遇到负数将其变为正数，同时K--
第三步：如果K还大于0，那么反复转变数值最小的元素，将K用完
第四步：求和
*/
class Solution {
public:
    static bool cmp(int a, int b){
        return abs(a) > abs(b);
    }
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), cmp);    // 这个会按照绝对值从大到小排列
        for(int i = 0; i < nums.size(); i++){   // 找最小的负数改成正数
            if(nums[i] < 0 && k > 0){
                nums[i] *= -1;
                k--;
            }
        }
        if(k % 2 == 1)  // 如果剩下的k为单数，说明可以让最后一个数变成负数。如果为双数，那么就不用变
            nums[nums.size() - 1] *= -1;
        int res = 0;
        for(int num : nums)
            res += num;
        return res;
    }
};
// @lc code=end

