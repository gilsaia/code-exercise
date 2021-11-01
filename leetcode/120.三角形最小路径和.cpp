/*
 * @lc app=leetcode.cn id=120 lang=cpp
 *
 * [120] 三角形最小路径和
 */
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int dp[2][220];
        memset(dp,0x3f,sizeof(dp));
        dp[0][0]=0;
        for(int i=0;i<triangle.size();++i){
            for(int j=0;j<=i;++j){
                dp[(i+1)%2][j]=min(dp[i%2][j]+triangle[i][j],dp[(i+1)%2][j]);
                dp[(i+1)%2][j+1]=min(dp[i%2][j]+triangle[i][j],dp[(i+1)%2][j+1]);
                dp[i%2][j]=0x3f3f3f3f;
            }
        }
        int ans=0x3f3f3f3f;
        for(int i=0;i<=triangle.size();++i){
            ans=min(ans,dp[triangle.size()%2][i]);
        }
        return ans;
    }
};
// @lc code=end

