/*
 * @lc app=leetcode.cn id=166 lang=cpp
 *
 * [166] 分数到小数
 */
#include<string>
#include<unordered_map>
using namespace std;
// @lc code=start
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if((int64_t)numerator % denominator == 0) return to_string((int64_t)numerator / denominator);

        int64_t up = abs((int64_t)numerator), down = abs((int64_t)denominator);
        string ans(((numerator < 0) ^ (denominator < 0) ? "-" : "") + to_string(up / down) + '.');
        unordered_map<int64_t, int> index;

        for(int i = ans.size(); up = up % down * 10; ++i){
            if(index.count(up)) {
                ans.insert(begin(ans) + index[up], '(');
                ans.push_back(')');
                break;
            }
            index[up] = i;
            ans.push_back('0' + up / down);
        }
        return ans;
    }
};
// @lc code=end

