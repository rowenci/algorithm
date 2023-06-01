/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 */

// @lc code=start
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        vector<int> res(temperatures.size(), 0);
        st.push(0);

        for(int i = 0; i < temperatures.size(); i++){
            if(temperatures[i] < temperatures[st.top()])
                st.push(i);
            else if(temperatures[i] == temperatures[st.top()])
                st.push(i);
            else{
                while(!st.empty() && temperatures[i] > temperatures[st.top()]){
                    res[st.top()] = i - st.top();
                    st.pop();
                }
                st.push(i);
            }
        }
        return res;
    }
};
// @lc code=end

