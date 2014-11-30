// Given a binary tree, return the inorder traversal of its nodes' values.

// For example:
// Given binary tree {1,#,2,3},
//    1
//     \
//      2
//     /
//    3
// return [1,3,2].

class Solution{
public:
	vector<int> inorderTraversal(TreeNode *root){
		vector<int> vec;
		vector<TreeNode *> stack;

		while(stack.size() > 0 || root != NULL){
			if(root != NULL){
				stack.push_back(root);
				root = root->left;
			}else{
				TreeNode *node = stack.back();
				vec.push_back(node->val);
				root = node->right;
				stack.pop_back();
			}
		}
		return vec;
	}
};