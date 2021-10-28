/*
 * @lc app=leetcode.cn id=114 lang=cpp
 *
 * [114] 二叉树展开为链表
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
    TreeNode *dfs(TreeNode *root){
        TreeNode *tmpright=root->right;
        TreeNode *tmpleft=nullptr;
        if(root->left){
            tmpleft=dfs(root->left);
            tmpleft->right=root->right;
            root->right=root->left;
            root->left=nullptr;
        }
        if(tmpright){
            return dfs(tmpright);
        }
        if(tmpleft){
            return tmpleft;
        }
        return root;
    }
    void flatten(TreeNode* root) {
        if(!root){
            return;
        }
        dfs(root);
        return;
    }
};
// @lc code=end

