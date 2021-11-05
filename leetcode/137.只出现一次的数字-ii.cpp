/*
 * @lc app=leetcode.cn id=137 lang=cpp
 *
 * [137] 只出现一次的数字 II
 */
#include<vector>
#include<cstring>
using namespace std;
// @lc code=start
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int digit[34];
        memset(digit,0,sizeof(digit));
        for(int &x:nums){
            for(int i=0;i<32;++i){
                digit[i]+=((x>>i)&1);
            }
        }
        int ans=0;
        for(int i=0;i<32;++i){
            if(digit[i]%3){
                ans|=(1<<i);
            }
        }
        return ans;
    }
};
// @lc code=end

