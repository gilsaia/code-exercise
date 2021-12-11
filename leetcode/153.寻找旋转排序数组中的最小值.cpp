/*
 * @lc app=leetcode.cn id=153 lang=cpp
 *
 * [153] 寻找旋转排序数组中的最小值
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=0,r=nums.size();
        int res=min(nums[0],nums[r-1]);
        while(l<r){
            int mid=(l+r)/2;
            res=min(res,nums[mid]);
            if(nums[mid]>nums[l]&&nums[mid]>nums[r-1]){
                l=mid+1;
            }else{
                r=mid;
            }
        }
        return res;
    }
};
// @lc code=end

