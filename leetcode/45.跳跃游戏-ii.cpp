/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> ind(nums.size());
        ind[0]=0;
        int tail=1;
        for(int i=0;i<nums.size();++i){
            int last=i+nums[i];
            for(;tail<ind.size()&&tail<=last;++tail){
                ind[tail]=ind[i]+1;
            }
        }
        return ind[nums.size()-1];
    }
};
// @lc code=end

