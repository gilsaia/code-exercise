/*
 * @lc app=leetcode.cn id=96 lang=cpp
 *
 * [96] 不同的二叉搜索树
 */

// @lc code=start
class Solution {
public:
    int numTrees(int n) {
        int dp[22];
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=n;++i){
            int tmp=0;
            for(int j=1;j<=i;++j){
                tmp+=(dp[j-1]*dp[i-j]);
            }
            dp[i]=tmp;
        }
        return dp[n];
    }
};
// @lc code=end

