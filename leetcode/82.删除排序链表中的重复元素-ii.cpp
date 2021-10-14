/*
 * @lc app=leetcode.cn id=82 lang=cpp
 *
 * [82] 删除排序链表中的重复元素 II
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==nullptr){
            return nullptr;
        }
        ListNode *cur=head;
        ListNode *lasthead=new ListNode(0,cur);
        ListNode *last=lasthead;
        while(cur->next){
            if(cur->next->val==cur->val){
                cur->next=cur->next->next;
                last->next=cur->next;
            }else{
                cur=cur->next;
                if(last->next!=cur){
                    last=last->next;
                }
            }
        }
        return lasthead->next;
    }
};
// @lc code=end

