
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode* result = new ListNode(-1);
        ListNode* pre = result;
        ListNode *a = l1, *b = l2;
        int carry = 0;
        while (a!=NULL && b!=NULL){
            int value_a = a->val;
            int value_b = b->val;
            ListNode* node = new ListNode((value_a+value_b+carry)%10);
            carry = (value_a+value_b+carry)/10;
            pre->next = node;
            pre = pre->next;
            a = a->next;
            b = b->next;
        }
        
        while (a!=NULL){
            int value_a = a->val;
            ListNode* node = new ListNode((value_a+carry)%10);
            carry = (value_a+carry)/10;
            pre->next = node;
            pre = pre->next;
            a = a->next;
        }
        
        while (b!=NULL){
            int value_b = b->val;
            ListNode* node = new ListNode((value_b+carry)%10);
            carry = (value_b+carry)/10;
            pre->next = node;
            pre = pre->next;
            b = b->next;
        }
        
        if (carry>0){
            ListNode* node = new ListNode(1);
            pre->next = node;
        }
        
        pre = result->next;
        delete result;
        return pre;
    }
};
