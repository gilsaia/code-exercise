/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int find(vector<int> &nums,int l,int r,int k){
        int mid=(l+r)/2;
        swap(nums[mid],nums[r]);
        int x=nums[r];
        int i=l-1;
        for(int j=l;j<r;++j){
            if(nums[j]>=x){
                ++i;
                swap(nums[i],nums[j]);
            }
        }
        swap(nums[i+1],nums[r]);
        mid=i+1;
        if(mid>k){
            return find(nums,l,mid-1,k);
        }else if(mid<k){
            return find(nums,mid+1,r,k);
        }else{
            return nums[mid];
        }
    }
    int findKthLargest(vector<int>& nums, int k) {
        return find(nums,0,nums.size()-1,k-1);
    }
};
// @lc code=end

