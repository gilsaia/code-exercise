/*
 * @lc app=leetcode.cn id=168 lang=cpp
 *
 * [168] Excel表列名称
 */
#include<string>
#include<algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans;
        while (columnNumber > 0) {
            --columnNumber;
            ans += columnNumber % 26 + 'A';
            columnNumber /= 26;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
// @lc code=end

