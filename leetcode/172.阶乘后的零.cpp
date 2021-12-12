/*
 * @lc app=leetcode.cn id=172 lang=cpp
 *
 * [172] 阶乘后的零
 */
#include<algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    int trailingZeroes(int n) {
        int sec=0,fiv=0;
        int cur=n;
        while(cur){
            sec+=(cur/2);
            cur/=2;
        }
        cur=n;
        while(cur){
            fiv+=(cur/5);
            cur/=5;
        }
        return min(sec,fiv);
    }
};
// @lc code=end

