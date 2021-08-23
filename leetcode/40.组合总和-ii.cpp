/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */
#include<vector>
#include<algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    void find(vector<int>& list,int target,int ind,vector<int>& cur,vector<vector<int>>& res,vector<int>& indlist){
        for(int i=ind;i<list.size();i=indlist[i]){
            int element=list[i];
            if(element<target){
                cur.push_back(element);
                find(list,target-element,i+1,cur,res,indlist);
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
    vector<int> findind(vector<int>& list){
        int ele=0,num=0;
        vector<int> res;
        for(int i=0;i<list.size();++i){
            if(list[i]!=ele){
                for(int j=0;j<num;++j){
                    res.push_back(i);
                }
                ele=list[i];
                num=1;
            }else{
                ++num;
            }
        }
        for(int j=0;j<num;++j){
            res.push_back(list.size());
        }
        return res;
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> indlist=findind(candidates);
        vector<int> cur;
        vector<vector<int>> res;
        find(candidates,target,0,cur,res,indlist);
        return res;
    }
};
// @lc code=end

