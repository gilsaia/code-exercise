/*
 * @lc app=leetcode.cn id=152 lang=cpp
 *
 * [152] 乘积最大子数组
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.empty()){
            return 0;
        }
        int maxele=nums[0],minele=nums[0];
        int res=nums[0];
        for(int i=1;i<nums.size();++i){
            int maxtmp=maxele;
            maxele=max(maxele*nums[i],nums[i]);
            maxele=max(maxele,minele*nums[i]);
            minele=min(minele*nums[i],nums[i]);
            minele=min(minele,maxtmp*nums[i]);
            res=max(res,maxele);
        }
        return res;
    }
};
// @lc code=end

