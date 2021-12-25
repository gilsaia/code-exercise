/*
 * @lc app=leetcode.cn id=201 lang=cpp
 *
 * [201] 数字范围按位与
 */

// @lc code=start
class Solution2 {
public:
    int rangeBitwiseAnd(int left, int right) {
        int res=0;
        int digit=0;
        long long l=left,r=right;
        long long cur=left;
        while(cur){
            if(cur&1){
                long long nowleft=cur<<digit;
                if((nowleft+(1<<digit))>right){
                    res|=(1<<digit);
                }
            }
            ++digit;
            cur>>=1;
        }
        return res;
    }
};
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        while(left<right){
            right&=(right-1);
        }
        return right;
    }
};
// @lc code=end

