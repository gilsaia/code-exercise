/*
 * @lc app=leetcode.cn id=188 lang=cpp
 *
 * [188] 买卖股票的最佳时机 IV
 */
#include<vector>
#include<algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int dp[120][2];
        for(int i=0;i<=k;++i){
            dp[i][0]=-1000020;
            dp[i][1]=0;
        }
        for(int i=0;i<prices.size();++i){
            for(int j=k;j>0;--j){
                dp[j][0]=max(dp[j-1][1]-prices[i],dp[j][0]);
                dp[j][1]=max(dp[j][0]+prices[i],dp[j][1]);
            }
        }
        return dp[k][1];
    }
};
// @lc code=end

