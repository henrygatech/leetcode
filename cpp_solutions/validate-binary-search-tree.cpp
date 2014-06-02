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
    bool isValidBST(TreeNode *root) {
        return valid(root,INT_MIN,INT_MAX);
    }
    
    bool valid(TreeNode *node, int min, int max){
        if(!node) return true;
        if(valid(node->left,min,node->val) && valid(node->right,node->val,max) && node->val>min && node->val<max)
            return true;
        else
            return false;
    }
};
