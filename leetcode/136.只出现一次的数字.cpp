/*
 * @lc app=leetcode.cn id=136 lang=cpp
 *
 * [136] 只出现一次的数字
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res=0;
        for(int &x:nums){
            res^=x;
        }
        return res;
    }
};
// @lc code=end

