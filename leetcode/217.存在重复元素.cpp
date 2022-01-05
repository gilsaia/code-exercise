/*
 * @lc app=leetcode.cn id=217 lang=cpp
 *
 * [217] 存在重复元素
 */
#include<unordered_set>
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> hash;
        for(int &item:nums){
            if(hash.count(item)){
                return true;
            }
            hash.insert(item);
        }
        return false;
    }
};
// @lc code=end

