/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
class Solution {
public:
    vector<int> item;
    vector<vector<int>> res;
    void backTrace(vector<int>& nums, int startIndex){
        res.push_back(item);

        for(int i = startIndex; i < nums.size(); i++){
            item.push_back(nums[i]);
            backTrace(nums, i + 1);
            item.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        item.clear();
        res.clear();
        backTrace(nums, 0);
        return res;
    }
};
// @lc code=end

