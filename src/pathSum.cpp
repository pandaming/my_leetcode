// Given a binary tree and a sum, determine if the tree has a root-to-leaf 
// path such that adding up all the values along the path equals the given sum.

// For example:
// Given the below binary tree and sum = 22,
//               5
//              / \
//             4   8
//            /   / \
//           11  13  4
//          /  \      \
//         7    2      1
// return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum){
    	if(!root) return false;
    	vector<TreeNode *> stack;
    	stack.push_back(root);
    	while(stack.size() > 0){
    		TreeNode *node = stack.back();
    		stack.pop_back();
    		if(!node->left && !node->right){
    			if(node->val == sum)
    				return true;
    		}
    		if(node->left){
    			node->left->val += node->val;
    			stack.push_back(node->left);
    		}
    		if(node->right){
    			node->right->val += node->val;
    			stack.push_back(node->right);
    		}
    	}
    	return false;
    }
};