/*
 * @lc app=leetcode.cn id=135 lang=cpp
 *
 * [135] 分发糖果
 */

// @lc code=start
class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> candyNum(ratings.size(), 1);

        for(int i = 1; i < ratings.size(); i++){    // 比较左边
            if(ratings[i] > ratings[i - 1])
                candyNum[i] = candyNum[i - 1] + 1;
        }

        for(int i = ratings.size() - 2; i >= 0; i--){   // 比较右边
            if(ratings[i] > ratings[i + 1])
                candyNum[i] = max(candyNum[i], candyNum[i + 1] + 1);    // 左边因为已经比较过了，所以需要判断当前的大小和右边+1后的大小
        }

        int num = 0;
        for(int i : candyNum)
            num += i;
        return num;
    }
};
// @lc code=end

