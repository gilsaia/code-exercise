/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 */
#include<vector>
#include<string>
#include<unordered_set>
#include<cstring>
using namespace std;
// @lc code=start
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> hash;
        for(string &s:wordDict){
            hash.insert(s);
        }
        vector<int> succ;
        succ.push_back(0);
        for(int i=0;i<s.size();++i){
            for(int &ind:succ){
                if(hash.count(s.substr(ind,(i+1)-ind))){
                    succ.push_back(i+1);
                    break;
                }
            }
        }
        return succ.back()==(s.size());
    }
};
// @lc code=end

