/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *dummy=new ListNode(-1,head);
        ListNode *cur=dummy->next,*last=dummy;
        while(cur){
            if(cur->val==val){
                last->next=cur->next;
                cur=cur->next;
            }else{
                last=last->next;
                cur=cur->next;
            }
        }
        return dummy->next;
    }
};
// @lc code=end

