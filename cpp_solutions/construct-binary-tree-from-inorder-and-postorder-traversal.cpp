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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        return build(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1);
    }
    
    TreeNode *build(vector<int> &inorder, int is, int ie, vector<int> &postorder, int ps, int pe){
        if(is>ie) return NULL;
        int pivot=postorder[pe];
        int i=is;
        for(;i<=ie;i++){
            if(inorder[i]==pivot)
                break;
        }
        TreeNode *node=new TreeNode(pivot);
        node->left=build(inorder,is,i-1,postorder,ps, i-1+ps-is);
        node->right=build(inorder,i+1,ie,postorder,i+ps-is,pe-1);
        return node;
    }
};
