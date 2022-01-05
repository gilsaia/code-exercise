/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
 */
#include<vector>
#include<algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    void dfs(vector<vector<int>> &list,vector<int> &res,int k,int n,int ind){
        if(!k){
            return;
        }
        for(int i=ind;i>0;--i){
            if(i<=n){
                res.push_back(i);
                if(i==n){
                    if(k==1){
                        list.push_back(res);
                    }
                    res.pop_back();
                    continue;
                }else{
                    dfs(list,res,k-1,n-i,i-1);
                    res.pop_back();
                }
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> list;
        vector<int> res;
        dfs(list,res,k,n,9);
        return list;
    }
};
// @lc code=end

