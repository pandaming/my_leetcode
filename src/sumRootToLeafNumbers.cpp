 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution{
public:
	int sumNumbers(TreeNode *root){
		if(root == NULL) return NULL;
		vector<int> vec;
		vector<TreeNode*> stack;
		stack.push_back(root);
		int sum = 0;

		while(stack.size()>0){
			TreeNode *node = stack.back();
			stack.pop_back();
			if(node->left == NULL && node->right == NULL){
				vec.push_back(node->val);
			}
			if(node->left){
				node->left->val = 10 * node->val + node->left->val;
				stack.push_back(node->left);
			}
			if(node->right){
				node->right->val = 10 * node->val + node->right->val;
				stack.push_back(node->right);
			}
		}

		for(int i=0; i<vec.size(); i++){
			sum += vec[i];
		}
		return sum;
	}
};