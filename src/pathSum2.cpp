// Given a binary tree and a sum, find all root-to-leaf paths where 
// each path's sum equals the given sum.

// For example:
// Given the below binary tree and sum = 22,
//               5
//              / \
//             4   8
//            /   / \
//           11  13  4
//          /  \    / \
//         7    2  5   1
// return
// [
//    [5,4,11,2],
//    [5,8,4,5]
// ]

class Solution{
public:
	vector<vector<int> > pathSum(TreeNode *root, int sum){
		vector<vector<int> > result;
		vector<int> vec;
		generatePathSum(root, sum, vec, result);
		return result;
	}

	void generatePathSum(TreeNode *root, int sum, vector<int> vec, vector<vector<int> > &result){
		if(root == NULL) return;

		if(root->left == NULL && root->right == NULL){
			if(root->val == sum){
				vec.push_back(root->val);
				result.push_back(vec);
			}
		}
		vec.push_back(root->val);

		if(root->left){
			generatePathSum(root->left, sum-root->val, vec, result);
		}
		if(root->right){
			generatePathSum(root->right, sum-root->val, vec, result);
		}
	}
};