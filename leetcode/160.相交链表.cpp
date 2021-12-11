/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
 };
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lena=1,lenb=1;
        ListNode *aLast=headA,*bLast=headB;
        while(aLast->next){
            aLast=aLast->next;
            ++lena;
        }
        while(bLast->next){
            bLast=bLast->next;
            ++lenb;
        }
        if(aLast!=bLast){
            return nullptr;
        }
        aLast=headA;
        bLast=headB;
        while(lena!=lenb){
            if(lena>lenb){
                aLast=aLast->next;
                --lena;
            }else{
                bLast=bLast->next;
                --lenb;
            }
        }
        while(aLast!=bLast){
            aLast=aLast->next;
            bLast=bLast->next;
        }
        return aLast;
    }
};
// @lc code=end

