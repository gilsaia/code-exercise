/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */
#include<vector>
#include<algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int cur=0,n=nums.size();
        for(int i=0;i<=cur;++i){
            cur=max(cur,i+nums[i]);
            if(cur>=(n-1)){
                return true;
            }
        }
        return false;
    }
};
// @lc code=end

