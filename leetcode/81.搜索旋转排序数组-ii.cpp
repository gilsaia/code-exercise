/*
 * @lc app=leetcode.cn id=81 lang=cpp
 *
 * [81] 搜索旋转排序数组 II
 */
#include<vector>
#include<algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        auto it=unique(nums.begin(),nums.end());
        nums.erase(it,nums.end());
        int l=0,r=nums.size();
        if(nums[0]==target||nums[nums.size()-1]==target){
            return true;
        }
        while(l<r){
            int mid=(l+r)/2;
            int tmp=nums[mid];
            if(tmp==target){
                return true;
            }
            if(tmp>nums[0]){
                if(tmp>target){
                    if(nums[0]>target){
                        l=mid+1;
                    }else{
                        r=mid;
                    }
                }else{
                    l=mid+1;
                }
            }else{
                if(tmp>target){
                    r=mid;
                }else{
                    if(nums[nums.size()-1]>target){
                        l=mid+1;
                    }else{
                        r=mid;
                    }
                }
            }
        }
        return false;
    }
};
// @lc code=end

