/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */
#include<vector>
#include<algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    void find(vector<int>& list,int target,int ind,vector<int>& cur,vector<vector<int>>& res){
        for(int i=ind;i<list.size();++i){
            int element=list[i];
            if(element<target){
                cur.push_back(element);
                find(list,target-element,i,cur,res);
                cur.pop_back();
            }else if(element==target){
                cur.push_back(element);
                res.push_back(cur);
                cur.pop_back();
                return;
            }else if(element>target){
                return;
            }
        }
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> cur;
        vector<vector<int>> res;
        find(candidates,target,0,cur,res);
        return res;
    }
};
// @lc code=end

