/*
 * @lc app=leetcode.cn id=95 lang=cpp
 *
 * [95] 不同的二叉搜索树 II
 */
#include<vector>
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
    vector<TreeNode*> buildtree(int start,int end){
        vector<TreeNode *>res;
        if(start>end){
            res.push_back(nullptr);
            return res;
        }
        for(int i=start;i<=end;++i){
            vector<TreeNode *>left=buildtree(start,i-1);
            vector<TreeNode *>right=buildtree(i+1,end);
            for(TreeNode *leftleave:left){
                for(TreeNode *rightleave:right){
                    TreeNode *cur=new TreeNode(i);
                    cur->left=leftleave;
                    cur->right=rightleave;
                    res.push_back(cur);
                }
            }
        }
        return res;
    }
    vector<TreeNode*> generateTrees(int n) {
        return buildtree(1,n);
    }
};
// @lc code=end

