/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 */
#include<vector>
#include<algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        for(int i=1;i<nums.size();++i){
            nums[i]+=nums[i-1];
        }
        int left=0,right=1,res=nums[0],tmpmin=min(0,nums[0]),ans=nums[0];
        while(right<nums.size()){
            res=nums[right]-tmpmin;
            ans=max(ans,res);
            if(nums[right]<tmpmin){
                tmpmin=nums[right];
            }
            ++right;
        }
        return ans;
    }
};
// @lc code=end

