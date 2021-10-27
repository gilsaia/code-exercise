/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
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
class Solution2 {
public:
    pair<bool,int> find(TreeNode *root){
        if(!root){
            return make_pair(true,0);
        }
        pair<bool,int> left=find(root->left),right=find(root->right);
        if(!left.first||!right.first||abs(left.second-right.second)>1){
            return make_pair(false,0);
        }
        return make_pair(true,max(left.second,right.second)+1);
    }
    bool isBalanced(TreeNode* root) {
        return find(root).first;
    }
};
class Solution {
public:
    int find(TreeNode *root){
        if(!root){
            return 0;
        }
        int left=find(root->left),right=find(root->right);
        if(left==-1||right==-1||abs(left-right)>1){
            return -1;
        }
        return max(left,right)+1;
    }
    bool isBalanced(TreeNode* root) {
        return find(root)!=-1;
    }
};
// @lc code=end

