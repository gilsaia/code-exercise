/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        int size=height.size();
        int ans=0;
        int left=0,right=size-1,leftmax=height[left],rightmax=height[right];
        while(left<right){
            if(height[left]<height[right]){
                ans+=(leftmax-height[left]);
                leftmax=max(leftmax,height[left+1]);
                ++left;
            }else{
                ans+=(rightmax-height[right]);
                rightmax=max(rightmax,height[right-1]);
                --right;
            }
        }
        return ans;
    }
};
// @lc code=end

