/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int color[3]={0,0,0};
        for(int a:nums){
            color[a]++;
        }
        nums=vector<int>(color[0],0);
        vector<int> res1(color[1],1),res2(color[2],2);
        nums.insert(nums.end(),res1.begin(),res1.end());
        nums.insert(nums.end(),res2.begin(),res2.end());
        return;
    }
};
// @lc code=end

