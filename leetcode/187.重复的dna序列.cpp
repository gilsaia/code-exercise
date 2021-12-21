/*
 * @lc app=leetcode.cn id=187 lang=cpp
 *
 * [187] 重复的DNA序列
 */
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<int,int> hash;
        vector<string> res;
        if(s.size()<10){
            return res;
        }
        const int maxint=1048576;
        int cur=0;
        for(int i=0;i<9;++i){
            cur*=4;
            switch (s[i])
            {
            case 'A':
                cur+=0;
                break;
            case 'C':
                cur+=1;
                break;
            case 'G':
                cur+=2;
                break;
            case 'T':
                cur+=3;
                break;
            }
        }
        for(int i=9;i<s.length();++i){
            cur*=4;
            switch (s[i])
            {
            case 'A':
                cur+=0;
                break;
            case 'C':
                cur+=1;
                break;
            case 'G':
                cur+=2;
                break;
            case 'T':
                cur+=3;
                break;
            }
            cur%=maxint;
            ++hash[cur];
        }
        for(auto item:hash){
            if(item.second>1){
                int cur=item.first;
                string tmp;
                for(int i=0;i<10;++i){
                    switch (cur%4)
                    {
                    case 0:
                        tmp+='A';
                        break;
                    case 1:
                        tmp+='C';
                        break;
                    case 2:
                        tmp+='G';
                        break;
                    case 3:
                        tmp+='T';
                        break;
                    }
                    cur/=4;
                }
                reverse(tmp.begin(),tmp.end());
                res.push_back(tmp);
            }
        }
        return res;
    }
};
// @lc code=end

