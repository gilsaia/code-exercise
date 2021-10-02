/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
class Solution {
public:
    int climbStairs(int n) {
        int fib[3]={1,0,0};
        for(int i=1;i<=n;++i){
            fib[i%3]=fib[(i+2)%3]+fib[(i+1)%3];
        }
        return fib[n%3];
    }
};
// @lc code=end

