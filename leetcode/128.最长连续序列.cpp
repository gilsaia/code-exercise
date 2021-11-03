/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 */
#include<vector>
#include<unordered_set>
using namespace std;
// @lc code=start
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> fin;
        for(int &num:nums){
            fin.insert(num);
        }
        int ans=0;
        for(const int &num:fin){
            if(fin.find(num-1)!=fin.end()){
                continue;
            }
            int cur=num+1;
            while(fin.find(cur)!=fin.end()){
                ++cur;
            }
            ans=max(ans,cur-num);
        }
        return ans;
    }
};
// @lc code=end

