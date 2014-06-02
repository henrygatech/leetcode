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
    ListNode *deleteDuplicates(ListNode *head) {
        if(!head || !head->next) return head;
        ListNode *pre=head, *cur=head->next;
        while(cur){
            if(pre->val==cur->val){
                ListNode *post=cur->next;
                delete cur;
                pre->next=post;
                cur=post;
            }
            else{
                pre=cur;
                cur=cur->next;
            }
        }
        return head;
    }
};
