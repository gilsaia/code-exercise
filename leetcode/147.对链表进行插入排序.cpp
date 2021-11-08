/*
 * @lc app=leetcode.cn id=147 lang=cpp
 *
 * [147] 对链表进行插入排序
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
    ListNode* insertionSortList(ListNode* head) {
        if(!head){
            return head;
        }
        ListNode *dummyhead=new ListNode(0,head);
        ListNode *cur=head->next,*last=head;
        ListNode *tmp,*next;
        while(cur){
            if(last->val<=cur->val){
                last=last->next;
                cur=cur->next;
                continue;
            }
            tmp=dummyhead;
            next=cur->next;
            while(tmp->next){
                if(tmp->next->val<cur->val){
                    tmp=tmp->next;
                    continue;
                }
                break;
            }
            last->next=cur->next;
            cur->next=tmp->next;
            tmp->next=cur;
            cur=next;
            if(last==tmp){
                last=last->next;
            }
        }
        return dummyhead->next;
    }
};
// @lc code=end

