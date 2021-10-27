/*
 * @lc app=leetcode.cn id=107 lang=cpp
 *
 * [107] 二叉树的层序遍历 II
 */
#include<vector>
#include<algorithm>
#include<stack>
#include<queue>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        queue<TreeNode *>que;
        vector<vector<int>> res;
        if(!root){
            return res;
        }
        vector<int> ans;
        que.push(root);
        int next=1,cur=0;
        while(next){
            cur=next;
            next=0;
            ans.clear();
            while(cur){
                TreeNode *tmp=que.front();
                que.pop();
                ans.push_back(tmp->val);
                if(tmp->left){
                    que.push(tmp->left);
                    ++next;
                }
                if(tmp->right){
                    que.push(tmp->right);
                    ++next;
                }
                --cur;
            }
            res.push_back(ans);
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
// @lc code=end

