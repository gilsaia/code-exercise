/*
 * @lc app=leetcode.cn id=154 lang=cpp
 *
 * [154] 寻找旋转排序数组中的最小值 II
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=0,r=nums.size();
        int res=min(nums[l],nums[r-1]);
        while(l<r){
            int mid=(l+r)/2;
            res=min(res,nums[mid]);
            if(nums[mid]>nums[r-1]){
                l=mid+1;
            }else if(nums[mid]<nums[r-1]){
                r=mid;
            }else{
                --r;
            }
        }
        return res;
    }
};
// @lc code=end

