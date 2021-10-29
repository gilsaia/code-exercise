/*
 * @lc app=leetcode.cn id=117 lang=cpp
 *
 * [117] 填充每个节点的下一个右侧节点指针 II
 */
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root){
            return nullptr;
        }
        Node *leftmost=root;
        while(leftmost){
            Node *cur=leftmost;
            while(cur){
                Node *next=nullptr;
                if(cur->next){
                    Node *rootnext=cur->next;
                    while(rootnext){
                        if(rootnext->left){
                            next=rootnext->left;
                            break;
                        }
                        if(rootnext->right){
                            next=rootnext->right;
                            break;
                        }
                        rootnext=rootnext->next;
                    }
                }
                if(cur->left){
                    if(cur->right){
                        cur->left->next=cur->right;
                    }else{
                        cur->left->next=next;
                    }
                }
                if(cur->right){
                    cur->right->next=next;
                }
                cur=cur->next;
            }
            cur=leftmost;
            leftmost=nullptr;
            while(cur){
                if(cur->left){
                    leftmost=cur->left;
                    break;
                }
                if(cur->right){
                    leftmost=cur->right;
                    break;
                }
                cur=cur->next;
            }
        }
        return root;
    }
};
// @lc code=end

