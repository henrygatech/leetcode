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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        return build(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1);
    }
    
    TreeNode *build(vector<int> &preorder, int ps ,int pe, vector<int> &inorder, int is, int ie){
        if(ps>pe) return NULL;
        int pivot=preorder[ps];
        int i=is;
        for(;i<=ie;i++)
            if(inorder[i]==pivot)
                break;
        TreeNode *node=new TreeNode(pivot);
        node->left=build(preorder,ps+1,i-is+ps,inorder,is,i-1);
        node->right=build(preorder,i-is+ps+1,pe,inorder,i+1,ie);
        return node;
    }
};
