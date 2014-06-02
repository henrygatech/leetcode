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
    vector<int> inorderTraversal(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> result;
        inorder(root, result);
        return result;
    }
    
    void inorder(TreeNode *node, vector<int> &result){
        if(node==NULL) return;
        inorder(node->left,result);
        result.push_back(node->val);
        inorder(node->right,result);
    }
};
