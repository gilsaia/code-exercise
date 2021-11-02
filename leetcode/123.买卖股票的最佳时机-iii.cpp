/*
 * @lc app=leetcode.cn id=123 lang=cpp
 *
 * [123] 买卖股票的最佳时机 III
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int dp[4]={0,0,0,0};
        dp[0]-=prices[0];
        dp[2]-=prices[0];
        for(int i=1;i<prices.size();++i){
            dp[3]=max(dp[3],dp[2]+prices[i]);
            dp[2]=max(dp[2],dp[1]-prices[i]);
            dp[1]=max(dp[1],dp[0]+prices[i]);
            dp[0]=max(dp[0],-prices[i]);
        }
        return dp[3];
    }
};
// @lc code=end

