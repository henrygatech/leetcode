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
    bool isSymmetric(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!root) return true;
        return is(root->left,root->right);
    }
    
    bool is(TreeNode *a, TreeNode *b){
        if(!a && !b) return true;
        if(!a || !b) return false;
        return a->val==b->val && is(a->left,b->right) && is(a->right,b->left);
    }
};
