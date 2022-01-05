/*
 * @lc app=leetcode.cn id=219 lang=cpp
 *
 * [219] 存在重复元素 II
 */
#include<unordered_set>
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> hash;
        for(int i=0;i<k&&i<nums.size();++i){
            if(hash.count(nums[i])){
                return true;
            }
            hash.insert(nums[i]);
        }
        int l=0,i=k;
        while(i<nums.size()){
            if(hash.count(nums[i])){
                return true;
            }
            hash.insert(nums[i]);
            hash.erase(nums[l]);
            ++l,++i;
        }
        return false;
    }
};
// @lc code=end

