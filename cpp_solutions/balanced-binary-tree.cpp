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
    bool isBalanced(TreeNode *root) {
        return maxdepth(root)!=-1;
    }
    
    int maxdepth(TreeNode *node){
        if(!node) return 0;
        int left=maxdepth(node->left);
        int right=maxdepth(node->right);
        if(left==-1 || right==-1 || abs(left-right)>1)
            return -1;
        else
            return max(left,right)+1;
    }
};
