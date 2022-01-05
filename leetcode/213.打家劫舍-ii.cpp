/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 */
#include<vector>
#include<algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }
        int dp[2]={0,0};
        int ans=0;
        for(int i=0;i<nums.size()-1;++i){
            dp[i%2]=max(dp[i%2]+nums[i],dp[(i+1)%2]);
        }
        ans=max(dp[0],dp[1]);
        dp[0]=0,dp[1]=0;
        for(int i=1;i<nums.size();++i){
            dp[i%2]=max(dp[i%2]+nums[i],dp[(i+1)%2]);
        }
        ans=max(ans,dp[0]);
        ans=max(ans,dp[1]);
        return ans;
    }
};
// @lc code=end

