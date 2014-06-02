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
    int sumNumbers(TreeNode *root) {
        int sum=0, path=0;
        if(root)
            cal(root,path,sum);
        return sum;
    }
    
    void cal(TreeNode *root, int num, int &sum){
        if(!root) return;
        num=10*num+root->val;
        if(!root->left && !root->right){
            sum+=num;
            return;
        }
        cal(root->left,num,sum);
        cal(root->right,num,sum);
    }
};
