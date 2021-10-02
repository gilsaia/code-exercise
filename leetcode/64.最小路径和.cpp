/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 */
#include<vector>
#include<algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(2,vector<int>(grid[0].size(),0));
        int m=grid.size(),n=grid[0].size();
        dp[0][0]=grid[0][0];
        for(int j=1;j<n;++j){
            dp[0][j]=grid[0][j]+dp[0][j-1];
        }
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if((i+1)<m){
                    dp[(i+1)%2][j]=dp[i%2][j]+grid[i+1][j];
                }
                if((j+1)<n){
                    dp[i%2][j+1]=min(dp[i%2][j+1],dp[i%2][j]+grid[i][j+1]);
                }
            }
        }
        return dp[(m-1)%2][n-1];
    }
};
// @lc code=end

