// Given preorder and inorder traversal of a tree, 
// construct the binary tree.

// Note:
// You may assume that duplicates do not exist in the tree.




struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x):val(x), left(NULL), right(NULL){}
};

class Solution{
public:
	TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder){
		return buildTree(preorder, 0, inorder, 0, inorder.size());
	}

	TreeNode *buildTree(vector<int> &preorder, int pre_offset, vector<int> &inorder, int in_offset, int n){

		if( n == 0 || preorder.size() == 0 || inorder.size() == 0) return NULL;

		int root_num = preorder[pre_offset];
		TreeNode *root = new TreeNode(root_num);

		if(n == 1) return root;

		int pos;
		for(pos=in_offset; pos<in_offset+n; pos++){
			if(inorder[pos] == root_num){
				break;
			}
		}


		int left_n = pos-in_offset;
		int right_n = in_offset+n-pos-1;
		root->left = buildTree(preorder, pre_offset+1, inorder, in_offset, left_n);
		root->right = buildTree(preorder, pre_offset+1+left_n, inorder, pos+1, right_n);

		return root;
	}
};
