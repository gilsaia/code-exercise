/*
 * @lc app=leetcode.cn id=220 lang=cpp
 *
 * [220] 存在重复元素 III
 */
#include<unordered_map>
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int getId(int x,long w){
        return x<0?(x+1ll)/w-1:x/w;
    }
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        unordered_map<int,int> hash;
        for(int i=0;i<nums.size();++i){
            long x=nums[i];
            int id=getId(x,t+1ll);
            if(hash.count(id)){
                return true;
            }
            if(hash.count(id-1)&&abs(x-hash[id-1])<=t){
                return true;
            }
            if(hash.count(id+1)&&abs(x-hash[id+1])<=t){
                return true;
            }
            hash[id]=x;
            if(i>=k){
                hash.erase(getId(nums[i-k],t+1ll));
            }
        }
        return false;
    }
};
// @lc code=end

