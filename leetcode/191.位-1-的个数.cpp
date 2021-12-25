/*
 * @lc app=leetcode.cn id=191 lang=cpp
 *
 * [191] 位1的个数
 */
#include<cstdint>
using namespace std;
// @lc code=start
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res=0;
        while(n){
            ++res;
            n&=(n-1);
        }
        return res;
    }
};
// @lc code=end

