/*
 * @lc app=leetcode.cn id=65 lang=cpp
 *
 * [65] 有效数字
 */
#include<string>
using namespace std;
// @lc code=start
class Solution {
public:
    /*  0:''
    *   1:'+/-'
    *   2:'(+/-).'
    *   3:'(num)e/E'
    *   4:'(num)e/E +/-'
    *   5:'(+/-)(0-9)+'
    *   6:'(num).(0-9)*'
    *   7:'(num)e/E(num)'
    */
    bool isNumber(string s) {
        int curstate=0;
        for(char i:s){
            switch (curstate)
            {
            case 0:
                if(i=='-'||i=='+'){
                    curstate=1;
                }else if(i>='0'&&i<='9'){
                    curstate=5;
                }else if(i=='.'){
                    curstate=2;
                }else{
                    return false;
                }
                break;
            case 1:
                if(i=='.'){
                    curstate=2;
                }else if(i>='0'&&i<='9'){
                    curstate=5;
                }else{
                    return false;
                }
                break;
            case 2:
                if(i>='0'&&i<='9'){
                    curstate=6;
                }else{
                    return false;
                }
                break;
            case 3:
                if(i=='+'||i=='-'){
                    curstate=4;
                }else if(i>='0'&&i<='9'){
                    curstate=7;
                }else{
                    return false;
                }
                break;
            case 4:
                if(i>='0'&&i<='9'){
                    curstate=7;
                }else{
                    return false;
                }
                break;
            case 5:
                if(i>='0'&&i<='9'){
                    curstate=5;
                }else if(i=='.'){
                    curstate=6;
                }else if(i=='e'||i=='E'){
                    curstate=3;
                }else{
                    return false;
                }
                break;
            case 6:
                if(i>='0'&&i<='9'){
                    curstate=6;
                }else if(i=='E'||i=='e'){
                    curstate=3;
                }else{
                    return false;
                }
                break;
            case 7:
                if(i>='0'&&i<='9'){
                    curstate=7;
                }else{
                    return false;
                }
                break;
            default:
                break;
            }
        }
        if(curstate<=4){
            return false;
        }
        return true;
    }
};
// @lc code=end

