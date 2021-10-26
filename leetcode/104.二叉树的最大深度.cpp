/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
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
    int maxDepth(TreeNode* root) {
        if(!root){
            return 0;
        }
        queue<TreeNode *> que;
        que.push(root);
        int ans=0,next=1;
        while(!que.empty()){
            int cur=next;
            next=0;
            while(cur){
                TreeNode *tmp=que.front();
                que.pop();
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
            ++ans;
        }
        return ans;
    }
};
// @lc code=end

