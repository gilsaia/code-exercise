/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
 */
#include<vector>
#include<algorithm>
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
    vector<int> dfs(TreeNode *root){
        int left=root->val;
        int right=root->val;
        if(root->left){
            vector<int> leftres=dfs(root->left);
            if(!leftres[0]){
                return {0,left,right};
            }
            if(leftres[2]>=root->val){
                return {0,left,right};
            }
            left=min(left,leftres[1]);
        }
        if(root->right){
            vector<int> rightres=dfs(root->right);
            if(!rightres[0]){
                return {0,left,right};
            }
            if(rightres[1]<=root->val){
                return {0,left,right};
            }
            right=max(right,rightres[2]);
        }
        return {1,left,right};
    }
    bool isValidBST(TreeNode* root) {
        if(!root){
            return true;
        }
        return (dfs(root)[0]);
    }
};
class Solution {
public:
    bool helper(TreeNode* root, long long lower, long long upper) {
        if (root == nullptr) {
            return true;
        }
        if (root -> val <= lower || root -> val >= upper) {
            return false;
        }
        return helper(root -> left, lower, root -> val) && helper(root -> right, root -> val, upper);
    }
    bool isValidBST(TreeNode* root) {
        return helper(root, LONG_MIN, LONG_MAX);
    }
};
// @lc code=end

