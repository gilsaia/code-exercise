/*
 * @lc app=leetcode.cn id=63 lang=cpp
 *
 * [63] 不同路径 II
 */
#include<vector>
#include<algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>> dp(2,vector<int>(obstacleGrid[0].size(),0));
        dp[0][0]=1;
        int m=obstacleGrid.size(),n=obstacleGrid[0].size();
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(obstacleGrid[i][j]==1){
                    dp[i%2][j]=0;
                    dp[(i+1)%2][j]=0;
                    continue;
                }
                if((i+1)<m){
                    dp[(i+1)%2][j]=dp[i%2][j];
                }
                if((j+1)<n){
                    dp[i%2][j+1]+=dp[i%2][j];
                }
            }
        }
        return dp[(m-1)%2][n-1];
    }
};
// @lc code=end

