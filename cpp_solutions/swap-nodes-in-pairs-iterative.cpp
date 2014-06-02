
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
    ListNode *swapPairs(ListNode *head) {
        ListNode *g= new ListNode(-1);
        g->next=head;
        ListNode *pre=g;
        while(pre->next){
            ListNode *cur=pre->next;
            if(!cur->next) break;
            ListNode *post=cur->next;
            cur->next=post->next;
            pre->next=post;
            post->next=cur;
            pre=cur;
        }
        head=g->next;
        delete g;
        return head;
    }
};
