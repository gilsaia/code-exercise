/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 */
#include<unordered_set>
using namespace std;
// @lc code=start
class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> occur;
        occur.insert(n);
        int cur=n;
        while(true){
            int tmp=0;
            while(cur){
                int i=cur%10;
                tmp+=(i*i);
                cur/=10;
            }
            if(tmp==1){
                return true;
            }
            if(occur.count(tmp)){
                return false;
            }
            occur.insert(tmp);
            cur=tmp;
        }
        return false;
    }
};
// @lc code=end

