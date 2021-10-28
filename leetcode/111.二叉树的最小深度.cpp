/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
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
    int minDepth(TreeNode* root) {
        if(!root){
            return 0;
        }
        queue<TreeNode *> que;
        que.push(root);
        int next=1,cur=0,hei=1;
        while(next){
            cur=next;
            next=0;
            while(cur){
                TreeNode *tmp=que.front();
                que.pop();
                if(!tmp->left&&!tmp->right){
                    return hei;
                }
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
            ++hei;
        }
        return hei;
    }
};
// @lc code=end

