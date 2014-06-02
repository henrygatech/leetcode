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
    int maxPathSum(TreeNode *root) {
        int other=INT_MIN;
        int endbyroot=getmax(root,other);
        return max(endbyroot,other);
    }
    
    int getmax(TreeNode *node, int &other){
        if(!node) return 0;
        int left=getmax(node->left,other);
        int right=getmax(node->right,other);
        int cmax=node->val;
        if(left>0) cmax+=left;
        if(right>0) cmax+=right;
        other=max(other,cmax);
        return max(node->val,max(node->val+left, node->val+right));
    }
};
