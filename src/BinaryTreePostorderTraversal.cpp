// Given a binary tree, return the postorder traversal of its nodes' values.

// For example:
// Given binary tree {1,#,2,3},
//    1
//     \
//      2
//     /
//    3
// return [3,2,1].

struct FlagTreeNode{
	bool isFirst;
	TreeNode *treenode;
	FlagTreeNode(TreeNode *root):isFirst(true), treenode(root){}
};

class Solution {
public:
   	vector<int> postorderTraversal(TreeNode *root){
		vector<int> vec;
		vector<FlagTreeNode *> stack;

		while(stack.size() > 0 || root != NULL){
			if(root != NULL){
				FlagTreeNode *node = new FlagTreeNode(root);
				stack.push_back(node);
				root = root->left;
			}else{
				FlagTreeNode *tmp = stack.back();
				if(tmp->isFirst == true){
					root = tmp->treenode->right;
					tmp->isFirst = false;
				}else{
					vec.push_back(tmp->treenode->val);
					stack.pop_back();
				}
			}
		}
		return vec;
	}
};