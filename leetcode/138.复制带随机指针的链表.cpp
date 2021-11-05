/*
 * @lc app=leetcode.cn id=138 lang=cpp
 *
 * [138] 复制带随机指针的链表
 */
#include<queue>
#include<unordered_map>
using namespace std;
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head){
            return nullptr;
        }
        Node *root=new Node(head->val);
        unordered_map<Node *,Node *>hash;
        hash[head]=root;
        queue<Node *> que;
        que.push(root);
        que.push(head);
        while(!que.empty()){
            Node *cur=que.front();
            que.pop();
            Node *remain=que.front();
            que.pop();
            if(remain->next){
                if(!hash.count(remain->next)){
                    hash[remain->next]=new Node(remain->next->val);
                    que.push(hash[remain->next]);
                    que.push(remain->next);
                }
                cur->next=hash[remain->next];
            }
            if(remain->random){
                if(!hash.count(remain->random)){
                    hash[remain->random]=new Node(remain->random->val);
                    que.push(hash[remain->random]);
                    que.push(remain->random);
                }
                cur->random=hash[remain->random];
            }
        }
        return root;
    }
};

class Solution2 {
public:
    Node* copyRandomList(Node* head) {
        if(!head){
            return nullptr;
        }
        Node *cur=head;
        while(cur){
            Node *tmp=new Node(cur->val);
            tmp->next=cur->next;
            cur->next=tmp;
            cur=tmp->next;
        }
        cur=head;
        while(cur){
            if(cur->random){
                cur->next->random=cur->random->next;
            }
            Node *tmp=cur->next;
            if(cur->next&&cur->next->next){
                tmp->next=cur->next->next->next;
            }
            cur=cur->next->next;
        }
        return head->next;
    }
};
// @lc code=end

