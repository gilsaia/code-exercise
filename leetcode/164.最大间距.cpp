/*
 * @lc app=leetcode.cn id=164 lang=cpp
 *
 * [164] 最大间距
 */
#include<vector>
#include<algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size()<2){
            return 0;
        }
        sort(nums.begin(),nums.end());
        int res=0;
        for(int i=0;i<nums.size()-1;++i){
            res=max(res,nums[i+1]-nums[i]);
        }
        return res;
    }
};
// @lc code=end

