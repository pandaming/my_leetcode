// Given a binary tree, return the zigzag level order traversal 
// of its nodes' values.(ie, from left to right, then right to 
// left for the next level and alternate between).

// For example:
// Given binary tree {3,9,20,#,#,15,7},
//     3
//    / \
//   9  20
//     /  \
//    15   7
// return its zigzag level order traversal as:
// [
//   [3],
//   [20,9],
//   [15,7]
// ]
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        
        vector<vector<int> > result;
        if(root == NULL) return result;
        queue<TreeNode* > q1;
        vector<int> vec;

        int num = 1;
        q1.push(root);

        while(q1.size() > 0){
        	queue<TreeNode* > q2;
        	while(q1.size() > 0){
        		TreeNode *tmp = q1.front();
        		q1.pop();
        		if(tmp->left){
        			q2.push(tmp->left);
        		}
        		if(tmp->right){
        			q2.push(tmp->right);
        		}
        		vec.push_back(tmp->val);
        	}
        	if(num%2 == 0){
        		reverse(vec.begin(),vec.end());
        	}
        	num++;
        	result.push_back(vec);
        	vec.clear();
        	q1 = q2; 	
        }
       	return result;
    }
};