/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
 */
#include<vector>
#include<stack>
#include<string>
using namespace std;
// @lc code=start
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> sta;
        for(string &s:tokens){
            if(s.size()==1){
                int x,y;
                switch (s[0])
                {
                case '+':
                    x=sta.top();
                    sta.pop();
                    y=sta.top();
                    sta.pop();
                    sta.push(x+y);
                    break;
                case '-':
                    x=sta.top();
                    sta.pop();
                    y=sta.top();
                    sta.pop();
                    sta.push(y-x);
                    break;
                case '*':
                    x=sta.top();
                    sta.pop();
                    y=sta.top();
                    sta.pop();
                    sta.push(x*y);
                    break;
                case '/':
                    x=sta.top();
                    sta.pop();
                    y=sta.top();
                    sta.pop();
                    sta.push(y/x);
                    break;
                default:
                    sta.push(s[0]-'0');
                    break;
                }
            }else{
                int neg=s[0]=='-'?-1:1;
                int res=0;
                for(char &c:s){
                    if(c>='0'&&c<='9'){
                        res*=10;
                        res+=(c-'0');
                    }
                }
                res*=neg;
                sta.push(res);
            }
        }
        return sta.top();
    }
};
// @lc code=end

