/*
 * @lc app=leetcode.cn id=205 lang=cpp
 *
 * [205] 同构字符串
 */
#include<string>
#include<cstring>
using namespace std;
// @lc code=start
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int fun[260];
        int used[260];
        memset(fun,0,sizeof(fun));
        memset(used,0,sizeof(used));
        for(int i=0;i<s.size();++i){
            if(fun[s[i]]==0){
                if(used[t[i]]==0){
                    fun[s[i]]=t[i];
                    used[t[i]]=1;
                }else{
                    return false;
                }
            }else if(fun[s[i]]!=t[i]){
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

