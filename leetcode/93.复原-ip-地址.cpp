/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原 IP 地址
 */
#include<vector>
#include<string>
using namespace std;
// @lc code=start
class Solution {
public:
    void dfs(vector<string> &res,string &cur,string &s,int ind,int hei){
        if(hei==3){
            if(s.size()==ind){
                res.push_back(cur);
            }
            return;
        }
        if(s.size()<=ind||s.size()<(ind+3-hei)){
            return;
        }
        if(s[ind]=='0'){
            cur+=".0";
            dfs(res,cur,s,ind+1,hei+1);
        }else{
            cur+='.';
            int curind=0;
            for(int i=0;i<3&&s.size()>(ind+i);++i){
                curind=(curind*10)+s[ind+i]-'0';
                if(curind<=255){
                    cur+=s[ind+i];
                    dfs(res,cur,s,ind+i+1,hei+1);
                }else{
                    break;
                }
            }
        }
        cur.erase(ind+hei);
        return;
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        string cur;
        if(s.size()<4||s.size()>12){
            return res;
        }
        int curind=0;
        bool findzero=(s[0]=='0');
        if(findzero){
            cur+=s[0];
            dfs(res,cur,s,1,0);
        }else{
            for(int i=0;i<3;++i){
                curind=(curind*10)+s[i]-'0';
                if(curind<=255){
                    cur+=s[i];
                    dfs(res,cur,s,i+1,0);
                }else{
                    break;
                }
            }
        }
        return res;
    }
};
// @lc code=end

