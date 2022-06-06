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
        int n1 = 0, n2 = 0;
        ListNode *tmp = headA;
        while(tmp){
            n1++;
            tmp = tmp->next;
        }
        tmp = headB;
        while(tmp){
            n2++;
            tmp = tmp->next;
        }
        
        ListNode *strt1, *strt2;
        strt1 = headA;
        strt2 = headB;
        
        while(n1 > n2){
            strt1 = strt1->next;
            n1--;
        }
        while(n2 > n1){
            strt2 = strt2->next;
            n2--;
        }
        
        while(1){
            if(strt1 == strt2) return strt1;
            strt1 = strt1->next;
            strt2 = strt2->next;
        }
        
        return NULL;
    }
};