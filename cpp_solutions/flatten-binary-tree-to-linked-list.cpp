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
    TreeNode *lastnode=NULL;

public:
    void flatten(TreeNode *root) {
        if(!root) return;
        if(lastnode){
            lastnode->left=NULL;
            lastnode->right=root;
        }
        lastnode=root;
        TreeNode *right=root->right;
        flatten(root->left);
        flatten(right);
    }
};
