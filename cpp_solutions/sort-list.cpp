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
    ListNode *findmiddle(ListNode *head){
        ListNode *slow=head, *fast=head->next;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    
    ListNode *merge(ListNode *l1, ListNode *l2){
        if(!l1) return l2;
        if(!l2) return l1;
        ListNode *head=NULL, *cur=NULL;
        if(l1->val<l2->val){
            head=l1;
            l1=l1->next;
        }
        else{
            head=l2;
            l2=l2->next;
        }
        cur=head;
        
        while(l1 && l2){
            if(l1->val<l2->val){
                cur->next=l1;
                l1=l1->next;
                cur=cur->next;
            }
            else{
                cur->next=l2;
                l2=l2->next;
                cur=cur->next;
            }
        }
        if(l1) cur->next=l1;
        else cur->next=l2;
        return head;
    }
    
    ListNode *sortList(ListNode *head) {
        if(!head || !head->next) return head;
        ListNode *mid=findmiddle(head);
        ListNode *right=sortList(mid->next);
        mid->next=NULL;
        ListNode *left=sortList(head);
        return merge(left,right);
    }
};
