/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 */

// @lc code=start
class Solution {
public:
    vector<int> item;
    vector<vector<int>> res;
    void backTrace(vector<int>& nums, int startIndex){
        res.push_back(item);

        for(int i = startIndex; i < nums.size(); i++){
            // 要大于startIndex，不然会数组越界，如果startIndex为0
            if(i > startIndex && nums[i] == nums[i - 1])
                continue;
            item.push_back(nums[i]);
            backTrace(nums, i + 1);
            item.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        item.clear();
        res.clear();
        sort(nums.begin(), nums.end());
        backTrace(nums, 0);
        return res;
    }
};
// @lc code=end

