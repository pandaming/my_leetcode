struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x):val(x), left(NULL), right(NULL){}
};

class Solution{
public:
	bool isValidBST(TreeNode *root){
		vector<int> vec;
		vector<TreeNode *> stack;
		// if(head == NULL) return NULL;
		while(stack.size() > 0 || root != NULL){
			if(root != NULL){
				stack.push_back(root);
				root = root->left;
			}else{
				root = stack.back();
				vec.push_back(root->val);
				stack.pop_back();
				root = root->right
			}
		}

		for(int i=1;i<vec.size();i++){
			if(vec[i-1] >=vec[i]){
				return false;
			}
		}
		return true;
	}
}