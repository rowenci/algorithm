/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
class Solution {
public:
    const string letterMap[10] = {
        "", // 0
        "", // 1
        "abc", // 2
        "def", // 3
        "ghi", // 4
        "jkl", // 5
        "mno", // 6
        "pqrs", // 7
        "tuv", // 8
        "wxyz", // 9
    };
    string item;
    vector<string> res;
    void backTrace(const string& digits, int startIndex){
        if(item.size() == digits.size()){
            res.push_back(item);
            return;
        }
        int digitIndex = digits[startIndex] - '0';
        string letter = letterMap[digitIndex];
        for(int i = 0; i < letter.size(); i++){
            item.push_back(letter[i]);
            backTrace(digits, startIndex + 1);
            item.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0)
            return res;
        backTrace(digits, 0);
        return res;
    }
};
// @lc code=end

