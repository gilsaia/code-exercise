/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */
#include<vector>
#include<algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    void find(vector<int>& now,vector<vector<int>>& list,int ind,int& swpsiz){
       for(int i=swpsiz;i>ind;--i){
           if(ind<(swpsiz-1)){
               find(now,list,ind+1,swpsiz);
           }
            swap(now[ind],now[i]);
            reverse(now.begin()+ind+1,now.end());
            list.push_back(now);
       }
       if(ind<(swpsiz-1)){
           find(now,list,ind+1,swpsiz);
       }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        res.push_back(nums);
        int swpsiz=nums.size()-1;
        find(nums,res,0,swpsiz);
        return res;
    }
};
// @lc code=end

