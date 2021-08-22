/*
 * @lc app=leetcode.cn id=38 lang=cpp
 *
 * [38] 外观数列
 */
#include<string>
#include<iostream>
#include<sstream>
using namespace std;
// @lc code=start
class Solution {
public:
    string transform(string input){
        char last='\0';
        int num=0;
        ostringstream s;
        for(char i:input){
            if(i!=last){
                if(last!='\0'){
                    s<<num<<last;
                }
                last=i;
                num=1;
            }else{
                ++num;
            }
        }
        s<<num<<last;
        return s.str();
    }
    string find(int n){
        if(n==1){
            return "1";
        }
        return transform(find(n-1));
    }
    string countAndSay(int n) {
        return find(n);
    }
};
// @lc code=end

