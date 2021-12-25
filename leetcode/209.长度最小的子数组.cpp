/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l=0,r=1;
        long long res=nums[0];
        int ans=nums.size()+1;
        while(l<nums.size()){
            if(res>=target){
                ans=min(ans,r-l);
                if(ans==1){
                    return ans;
                }
                res-=nums[l];
                ++l;
            }else{
                if(r==nums.size()){
                    break;
                }
                res+=nums[r];
                ++r;
            }
        }
        if(ans==(nums.size()+1)){
            return 0;
        }
        return ans;
    }
};
// @lc code=end

