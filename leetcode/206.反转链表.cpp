/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x,ListNode *next): val(x),next(next){}
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
    ListNode* reverseList(ListNode* head) {
        if(!head){
            return nullptr;
        }
        ListNode *dummy=new ListNode(0,head);
        ListNode *cur=head,*last=dummy,*next=cur->next;
        cur->next=nullptr;
        while(next){
            ListNode *tmp=next->next;
            next->next=cur;
            last->next=next;
            cur=next;
            next=tmp;
        }
        return dummy->next;
    }
};
// @lc code=end

