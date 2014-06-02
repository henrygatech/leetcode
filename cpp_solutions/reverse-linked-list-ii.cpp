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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        int step=n-m;
        ListNode *g=new ListNode(-1);
        g->next=head;
        head=g;
        ListNode *pre=head;
        
        while(m>1){
            pre=pre->next;
            m--;
        }
        
        ListNode *cur=pre->next, *post=cur->next;
        if(step>=1){
            while(step>0 && post!=NULL){
                ListNode *temp=post->next;
                post->next=cur;
                cur=post;
                post=temp;
                step--;
            }
            ListNode *temp=pre->next;
            pre->next=cur;
            temp->next=post;
        }
        head=g->next;
        delete g;
        return head;
    }
};
