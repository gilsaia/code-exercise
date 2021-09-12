/*
 * @lc app=leetcode.cn id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
class Solution {
public:
    double positivePow(double x,long long n){
        double ans=1;
        while(n){
            if(n&1){
                ans*=x;
            }
            x*=x;
            n>>=1;
        }
        return ans;
    }

    double myPow(double x, int n) {
        double ans=1;
        long long nl=n;
        if(nl<0){
            ans=positivePow(x,-nl);
            ans=1/ans;
        }else if(nl>0){
            ans=positivePow(x,nl);
        }
        return ans;
    }
};
// @lc code=end

