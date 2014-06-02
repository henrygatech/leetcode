
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
        if(!head || !head->next) return head;
        
        ListNode *nextnode=head->next;
        ListNode *remain=swapPairs(nextnode->next);
        nextnode->next=head;
        head->next=remain;
        return nextnode;
    }
};
