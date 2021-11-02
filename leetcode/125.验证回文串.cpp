/*
 * @lc app=leetcode.cn id=125 lang=cpp
 *
 * [125] 验证回文串
 */
#include<string>
using namespace std;
// @lc code=start
class Solution {
public:
    bool isPalindrome(string s) {
        int l=0,r=s.size()-1;
        while(l<r){
            while(l<s.size()&&!((s[l]>='0'&&s[l]<='9')||(s[l]>='a'&&s[l]<='z')||(s[l]>='A'&&s[l]<='Z'))){
                ++l;
            }
            while(r<s.size()&&!((s[r]>='0'&&s[r]<='9')||(s[r]>='a'&&s[r]<='z')||(s[r]>='A'&&s[r]<='Z'))){
                --r;
            }
            if(l>=r){
                break;
            }
            if(s[l]>='A'&&s[l]<='Z'){
                s[l]=s[l]-'A'+'a';
            }
            if(s[r]>='A'&&s[r]<='Z'){
                s[r]=s[r]-'A'+'a';
            }
            if(s[l]!=s[r]){
                return false;
            }
            ++l,--r;
        }
        return true;
    }
};
// @lc code=end

