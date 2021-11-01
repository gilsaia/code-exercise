/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprice[100020];
        maxprice[prices.size()-1]=prices[prices.size()-1];
        for(int i=prices.size()-2;i>=0;--i){
            maxprice[i]=max(prices[i],maxprice[i+1]);
        }
        int ans=0;
        for(int i=0;i<prices.size();++i){
            ans=max(maxprice[i]-prices[i],ans);
        }
        return ans;
    }
};
// @lc code=end

