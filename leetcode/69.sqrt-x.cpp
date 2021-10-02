/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] Sqrt(x)
 */

// @lc code=start
class Solution2 {
public:
    int mySqrt(int x) {
        if(x==0){
            return 0;
        }else if(x<4){
            return 1;
        }
        long long res=x;
        long long l=1,r=res/2;
        while(l<r){
            long long m=(l+r)/2;
            if((m*m<=res)&&((m+1)*(m+1)>res)){
                return m;
            }
            if(m*m<res){
                l=m+1;
            }else{
                r=m;
            }
        }
        return l;
    }
};
// 牛顿迭代法-官方题解
class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) {
            return 0;
        }

        double C = x, x0 = x;
        while (true) {
            double xi = 0.5 * (x0 + C / x0);
            if (fabs(x0 - xi) < 1e-7) {
                break;
            }
            x0 = xi;
        }
        return int(x0);
    }
};
// @lc code=end

