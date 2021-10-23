/*
 * @lc app=leetcode.cn id=86 lang=cpp
 *
 * [86] 分隔链表
 */
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(!head){
            return nullptr;
        }
        ListNode *left=new ListNode();
        ListNode *right=new ListNode();
        ListNode *leftcur=left,*rightcur=right;
        while(head){
            if(head->val<x){
                leftcur->next=head;
                leftcur=leftcur->next;
            }else{
                rightcur->next=head;
                rightcur=rightcur->next;
            }
            head=head->next;
        }
        leftcur->next=nullptr;
        rightcur->next=nullptr;
        if(left->next){
            leftcur->next=right->next;
            return left->next;
        }else{
            return right->next;
        }
    }
};
// @lc code=end

