/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        int len=0;
        ListNode *p=head;
        while(p){
            p=p->next;
            len++;
        }
        return build(head,0,len-1);
    }
    
    TreeNode *build(ListNode * &list, int start, int end){
        if(start>end) return NULL;
        int mid=(start+end)/2;
        TreeNode *lefttree=build(list,start,mid-1);
        TreeNode *node=new TreeNode(list->val);
        node->left=lefttree;
        list=list->next;
        node->right=build(list,mid+1,end);
        return node;
    }
};
