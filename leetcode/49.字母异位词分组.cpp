/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */
#include<vector>
#include<string>
#include<unordered_map>
#include<algorithm>
using namespace std;
// @lc code=start
class Solution_me {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> hash;
        for(string str:strs){
            vector<int> table(26,0);
            for(char s:str){
                ++table[s-'a'];
            }
            string ans;
            for(int i=0;i<26;++i){
                if(table[i]>0){
                    ans.append(table[i],'a'+i);
                }
            }
            hash[ans].push_back(str);
        }
        vector<vector<string>> ans;
        for(auto &v:hash){
            ans.push_back(v.second);
        }
        return ans;
    }
};
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        for(string& s:strs){
            string key=s;
            sort(key.begin(),key.end());
            mp[key].emplace_back(s);
        }
        vector<vector<string>> ans;
        for(auto it=mp.begin();it!=mp.end();it++){
            ans.emplace_back(it->second);
        }
        return ans;
    }
};
// @lc code=end

