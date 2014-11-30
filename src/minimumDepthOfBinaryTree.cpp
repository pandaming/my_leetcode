// Given a binary tree, find its minimum depth.

// The minimum depth is the number of nodes along 
// the shortest path from the root node down to the nearest leaf node.

class Solution{
public:
	int minDepth(TreeNode *root){
		if(root == NULL) return 0;
		if(root->left == NULL && root->right == NULL) return 1;
		int leftDepth = 10000;
		if(root->left){
			leftDepth = minDepth(root->left);
		}	
		int rightDepth = 10000;
		if(root->right){
			rightDepth = minDepth(root->right);
		}
		return leftDepth<rightDepth ?leftDepth+1 : rightDepth+1;
	}
};