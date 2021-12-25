/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        int dp[2]={0,0};
        for(int i=0;i<nums.size();++i){
            dp[i%2]=max(dp[(i+1)%2],dp[i%2]+nums[i]);
        }
        return max(dp[0],dp[1]);
    }
};
// @lc code=end

