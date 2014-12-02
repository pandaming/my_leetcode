// Given a binary tree, return the preorder traversal of its nodes' values.

// For example:
// Given binary tree {1,#,2,3},
//    1
//     \
//      2
//     /
//    3
// return [1,2,3].

class Solution{
public:
	vector<int> preorderTraversal(TreeNode *root){
		
		vector<int> vec;
		vector<TreeNode*> stack;
		
		while(stack.size()>0 || root != NULL){
			if(root != NULL){
				vec.push_back(root->val);
				stack.push_back(root);
				root = root->left;
			}else{
				TreeNode *node = stack.back();
				stack.pop_back();
				root = node->right;
			}
		}
		return vec;
	}
};