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
        if(root == NULL) return true;
        return isSymmetricHelper(root->left, root->right);
    }
    
    bool isSymmetricHelper(TreeNode *root1, TreeNode *root2){
        if(root1 == NULL && root2 == NULL) return true;
        if(root1 == NULL || root2 == NULL) return false;
        return root1->val==root2->val 
            &&isSymmetricHelper(root1->left, root2->right)
            &&isSymmetricHelper(root1->right, root2->left);
        
    }
};