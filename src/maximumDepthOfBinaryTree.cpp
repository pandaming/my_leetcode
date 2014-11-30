// Given a binary tree, find its maximum depth.

// The maximum depth is the number of nodes along 
// the longest path from the root node down to the farthest leaf node.


class Solution{
public:
	int maxDepth(TreeNode *root){
		if(root == NULL) return 0;
		if(root->right == NULL && root->left == NULL) return 1;
		int leftDepth = maxDepth(root->left);
		int rightDepth = maxDepth(root->right);
		return leftDepth>rightDepth?leftDepth+1:rightDepth+1;
	}
};